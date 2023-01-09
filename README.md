# mmap-malloc
mmap()-based malloc() implementation for fun and wasted memory

## Example

```
wget "https://launcher.mojang.com/v1/objects/a028f00e678ee5c6aef0e29656dca091b5df11c7/server.jar"
make
LD_PRELOAD="./mmap-malloc.so" java -jar server.jar --nogui
```

## Current problems

 - Probably threading, java throws:

```
[thread 139885562750720 also had an error]
[thread 139885561558784 also had an error]
[thread 139885559174912 also had an error][thread 139885565134592 also had an error]
#

# A fatal error has been detected by the Java Runtime Environment:
[thread 139885567518464 also had an error]#

#  SIGSEGV (0xb) at pc=0x00007f39b80ce357[thread 139885557982976 also had an error], pid=44810
, tid=0x00007f39a4ebf700[thread 139885560366848 also had an error]

#
# JRE version:  (8.0_345-b01) (build )
# Java VM: OpenJDK 64-Bit Server VM (25.345-b01 mixed mode linux-amd64 compressed oops)
# Problematic frame:
# C[thread 139885566326528 also had an error]
  [malloc.so+0x1357]  free+0x3a
#
# Failed to write core dump. Core dumps have been disabled. To enable core dumping, try "ulimit -c unlimited" before starting Java again
#
# An error report file with more information is saved as:
# /tmp/mallocpreload/hs_err_pid44810.log
[thread 139885858330368 also had an error]
#
# If you would like to submit a bug report, please visit:
#   http://www.azul.com/support/
#
Aborted (core dumped)
```
