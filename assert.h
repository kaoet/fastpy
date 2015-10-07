#pragma once
#ifdef NDEBUG

#define assert(v) if(!(v)) __builtin_unreachable()

#else

void my_assert(bool value, const char *code);
#define assert(v) my_assert(v, #v)

#endif