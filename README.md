# mmap-malloc
mmap()-based malloc() implementation for fun and wasted memory

## Purpose

To learn how to implement malloc, check if my theory works, document the code correctly (ptmalloc2 was a great learning material) and get into memory management / kernel hacking.

## Example

```
wget "https://launcher.mojang.com/v1/objects/a028f00e678ee5c6aef0e29656dca091b5df11c7/server.jar"
make
LD_PRELOAD="./mmap-malloc.so" java -jar server.jar --nogui
```

## Current problems

 - Slow (I guess it's due to mutex locking for Block linked list, maybe `MAP_ANONYMOUS` mmap() calls)
 - Example minecraft server crashes on world generation due to low value of `vm.max_map_count` kernel parameter. Change the value to `655300` to run the example using `sysctl -w vm.max_map_count=655300`

