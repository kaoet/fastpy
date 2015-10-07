#pragma once

#ifdef NDEBUG
#define assert(v) if(!(v)) __builtin_unreachable()
#else
#include <cstdio>
#include <cstdlib>
#define assert(v) \
    do \
        if(!(v)) { \
            printf("Assertion %s failed at %s:%d\n", #v, __FILE__, __LINE__); \
            exit(1); \
        } \
    while (false)
#endif