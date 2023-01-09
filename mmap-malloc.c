/*
 * MIT License

Copyright (c) 2023 Mateusz Dukat

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#define DEBUG

#ifdef DEBUG
#include <stdio.h> // fprintf
#endif

#include <sys/mman.h> // mmap
#include <string.h> // memcpy (for realloc)

/*
 * We need to keep in mind what size on which address we allocated.
 * This is useful for realloc and free, since munmap() needs specified size for deallocation
 *
 * Block structure stores:
 *  - next block in line (linked list)
 *  - previous block in line
 *  - pointer we allocated
 *  - size allocated on this address
 *
 * We use NULL for first and last entry in our linked list
 */

struct Block {
  struct Block *next;
  struct Block *prev;
  void* ptr;
  size_t size;
};

struct Block *head = NULL;

/*
 * malloc()
 */

void *malloc(size_t size)
{
  if(size == 0)
    return NULL;

  // Allocate new block
  void *p = NULL;
  p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
#ifdef DEBUG
  fprintf(stderr, "malloc(%ld) = %p\n", size, p);
#endif

  // Add block definiton
  if(head == NULL){
    // if it's a first block in memory
    head = mmap(NULL, sizeof(struct Block), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    head->next = NULL;
    head->prev = NULL;
    head->ptr = p;
    head->size = size;
  }else{
    // if head exists
    struct Block *cur = head;
    
    // step to last block
    while(cur->next != NULL){
      cur = cur->next;
    }

    // make new block
    struct Block *new = mmap(NULL, sizeof(struct Block), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    cur->next = new;
    new->prev = cur;
    cur = new;
    cur->next = NULL;
    cur->size = size;
    cur->ptr = p;
  }


  // Convert mmap error to malloc error
  if(p == (void *) -1)
    return NULL;
  return p;
}

/*
 * free()
 */

void free(void* ptr)
{
#ifdef DEBUG
  fprintf(stderr, "free(%p)\n", ptr);
#endif
  if(ptr == NULL)
    return;
  
  struct Block *cur = head;
  
  while(cur->ptr != ptr){
    cur = cur->next;
  }

  //fprintf(stderr, "Would free: %ld bytes\n", cur->size);

  // Remove this block
  struct Block *prev;
  if(cur->prev != NULL){
    prev = cur->prev;
    prev->next = cur->next;
  }else{
    head = cur->next;
  }

  struct Block *next;
  if(cur->next != NULL){
    next = cur->next;
    next->prev = cur->prev;
  }else{
    prev->next = NULL;
  }

  munmap(cur->ptr, cur->size);
  munmap(cur, sizeof(struct Block));
  
}

/*
 * calloc()
 */

void *calloc(size_t nmemb, size_t size){
  if(nmemb == 0 || size == 0)
    return NULL;

  size_t realsize = nmemb * size;
  void *p = malloc(realsize);
#ifdef DEBUG
  fprintf(stderr, "calloc(%ld, %ld) = %p\n", nmemb, size, p);
#endif
  return p;
}

/*
 * realloc()
 */

void *realloc(void *ptr, size_t size){
  void* newptr = malloc(size);

#ifdef DEBUG
  fprintf(stderr, "realloc(%p, %ld) = %p\n", ptr, size, newptr);
#endif

  if(ptr == NULL){
    return newptr;
  }
  
  //find old block
  struct Block *old = head;
  while(old->ptr != ptr)
    old = old->next;
  
  // copy last block to new block
  memcpy(newptr, ptr, old->size);

  // free old block
  free(ptr);

  return newptr;
}

