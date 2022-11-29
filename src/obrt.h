#pragma once
#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...)                                                           \
  (((void (**)())(t))[-1](o, b, r, ((void **)(t)) - 1, __VA_ARGS__))
#define O(...) ((void *)(const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(0, __VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define C(o, b, r, ...)                                                        \
  assert(!t[-1]),                                                              \
      ((void (***)())o)[r][-1](((void (***)())o)[8], b, r,                     \
                               ((void (***)())o)[r] - 1, __VA_ARGS__)
#define obrt void (***o)(), void (***b)(), long r, void (**t)()

#define rest void *p1, void *p2, void *p3, void *p4
#define frwd p1, p2, p3, p4
#define FUN __FUNCTION__
