mmap-malloc.so: mmap-malloc.c
	gcc mmap-malloc.c -Ofast -shared -fPIC -o mmap-malloc.so
