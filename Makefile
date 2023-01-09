mmap-malloc.so: mmap-malloc.c
	gcc mmap-malloc.c -shared -fPIC -o mmap-malloc.so
