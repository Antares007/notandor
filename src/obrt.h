#pragma once
#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...) (((void (**)())t)[-1](o, b, r, ((void **)t) - 1, __VA_ARGS__))
#define B(...) ((void *)(const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(0, __VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define C(o, b, r, ...)                                                        \
  assert(!t[-1]), o[r][-1](o[8], b, r, o[r] - 1, __VA_ARGS__)
#define obrt void (***o)(), void (***b)(), long r, void (**t)()
#include <assert.h>
