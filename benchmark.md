# mmap-malloc benchmark

## Benchmark software

I found this random benchmark from glibc: [glibc/benchtests/bench-malloc-simple.c](https://codebrowser.dev/glibc/glibc/benchtests/bench-malloc-simple.c.html)

## Method

3 runs on standard Ubuntu 22.04 LTS malloc, and 3 runs on mmap-malloc, each with size (arg[1]) of 65535.

## Standard Ubuntu 22.04 LTS `malloc()`

```
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7908,
    "main_arena_st_allocs_0025_time": 3940.39,
    "main_arena_st_allocs_0100_time": 4432.2,
    "main_arena_st_allocs_0400_time": 4340.41,
    "main_arena_st_allocs_1600_time": 4349.56,
    "main_arena_mt_allocs_0025_time": 4306.7,
    "main_arena_mt_allocs_0100_time": 4356.08,
    "main_arena_mt_allocs_0400_time": 4881.66,
    "main_arena_mt_allocs_1600_time": 4443.72,
    "thread_arena__allocs_0025_time": 3323.37,
    "thread_arena__allocs_0100_time": 4383.43,
    "thread_arena__allocs_0400_time": 3481.91,
    "thread_arena__allocs_1600_time": 4562.82
   }
  }
 }
}
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7768,
    "main_arena_st_allocs_0025_time": 4281.02,
    "main_arena_st_allocs_0100_time": 4453.48,
    "main_arena_st_allocs_0400_time": 4039.55,
    "main_arena_st_allocs_1600_time": 4417.13,
    "main_arena_mt_allocs_0025_time": 4025.48,
    "main_arena_mt_allocs_0100_time": 4103.92,
    "main_arena_mt_allocs_0400_time": 4558.97,
    "main_arena_mt_allocs_1600_time": 4481.73,
    "thread_arena__allocs_0025_time": 3324.85,
    "thread_arena__allocs_0100_time": 3795.87,
    "thread_arena__allocs_0400_time": 3477.28,
    "thread_arena__allocs_1600_time": 4524.92
   }
  }
 }
}
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7864,
    "main_arena_st_allocs_0025_time": 4518.61,
    "main_arena_st_allocs_0100_time": 4307.9,
    "main_arena_st_allocs_0400_time": 4021.87,
    "main_arena_st_allocs_1600_time": 4409.82,
    "main_arena_mt_allocs_0025_time": 3948.98,
    "main_arena_mt_allocs_0100_time": 4374.32,
    "main_arena_mt_allocs_0400_time": 4391.51,
    "main_arena_mt_allocs_1600_time": 4437.93,
    "thread_arena__allocs_0025_time": 3327.75,
    "thread_arena__allocs_0100_time": 3777.46,
    "thread_arena__allocs_0400_time": 3492.42,
    "thread_arena__allocs_1600_time": 4534.5
   }
  }
 }
}
```

## mmap-malloc

```
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7792,
    "main_arena_st_allocs_0025_time": 24714.4,
    "main_arena_st_allocs_0100_time": 26114.2,
    "main_arena_st_allocs_0400_time": 30787.4,
    "main_arena_st_allocs_1600_time": 56654.2,
    "main_arena_mt_allocs_0025_time": 24407.4,
    "main_arena_mt_allocs_0100_time": 25818.1,
    "main_arena_mt_allocs_0400_time": 31380.3,
    "main_arena_mt_allocs_1600_time": 59957.9,
    "thread_arena__allocs_0025_time": 24358.7,
    "thread_arena__allocs_0100_time": 25807.5,
    "thread_arena__allocs_0400_time": 31530.6,
    "thread_arena__allocs_1600_time": 56185.4
   }
  }
 }
}
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7832,
    "main_arena_st_allocs_0025_time": 24909.6,
    "main_arena_st_allocs_0100_time": 26711.1,
    "main_arena_st_allocs_0400_time": 32899.3,
    "main_arena_st_allocs_1600_time": 57902.5,
    "main_arena_mt_allocs_0025_time": 25840,
    "main_arena_mt_allocs_0100_time": 27573.2,
    "main_arena_mt_allocs_0400_time": 32714.4,
    "main_arena_mt_allocs_1600_time": 56950.6,
    "thread_arena__allocs_0025_time": 25604.1,
    "thread_arena__allocs_0100_time": 27813.4,
    "thread_arena__allocs_0400_time": 33339.3,
    "thread_arena__allocs_1600_time": 57253.1
   }
  }
 }
}
{
 "timing_type": "hp_timing",
 "functions": {
  "malloc": {
   "": {
    "malloc_block_size": 65535,
    "max_rss": 7832,
    "main_arena_st_allocs_0025_time": 25869.7,
    "main_arena_st_allocs_0100_time": 26739.3,
    "main_arena_st_allocs_0400_time": 32080.7,
    "main_arena_st_allocs_1600_time": 56771.1,
    "main_arena_mt_allocs_0025_time": 25744.6,
    "main_arena_mt_allocs_0100_time": 27107.9,
    "main_arena_mt_allocs_0400_time": 31726.6,
    "main_arena_mt_allocs_1600_time": 56524.6,
    "thread_arena__allocs_0025_time": 24935.2,
    "thread_arena__allocs_0100_time": 27441.8,
    "thread_arena__allocs_0400_time": 32701,
    "thread_arena__allocs_1600_time": 56428.1
   }
  }
 }
}
```

## Conclusion

It sucks. 16.8x slower than standard malloc implementation.

