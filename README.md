# mmap-malloc
mmap()-based malloc() implementation for fun and wasted memory

## Example

```
wget "https://launcher.mojang.com/v1/objects/a028f00e678ee5c6aef0e29656dca091b5df11c7/server.jar"
make
LD_PRELOAD="./mmap-malloc.so" java -jar server.jar --nogui
```

## Current problems

 - Slow

