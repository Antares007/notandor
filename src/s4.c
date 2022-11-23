#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
#define Ν(...)                                                                 \
  { __VA_ARGS__; }                                                             \
  }
#define N(argo)                                                                \
  void argo(OARS) {                                                            \
    Ν
#define OARS void **o, void **a, long r, void **s, void **op, void **os
#define D_(o, s, op, os)                                                       \
  ((void (**)())a)[-1](o, &((void (**)())a)[-1], r, s, op, os)
#define D(o, s, op, os) (LOG, D_(o, s, op, os))
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(125500)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// clang-format off
N(cr)(((void (***)())o)[r][-1](o[-3], &((void (***)())o)[r][-1], r, s, op, os))
N(c0)(cr(o, a, 0, s, op, os))
N(c1)(cr(o, a, 1, s, op, os))
N(c2)(cr(o, a, 2, s, op, os))
N(c3)(cr(o, a, 3, s, op, os))
N(o0)(D(s,o,op,os))N(o1)(D(s,o,op,os))N(o2)(LOG)
N(s0)(D(s,o,op,os))N(s1)(D(s,o,op,os))N(s2)(LOG)
N(putos)(D(o, s, op, B(os, o, s)))
N(mapo0)(D(o,s,op,os))N(mapo1)(D(o,s,op,os))N(mapo2)(D(o,s,op,os))
N(maps0)(D(o,s,op,os))N(maps1)(D(o,s,op,os))N(maps2)(D(o,s,op,os))
N(main_os )(D(B(0,
                T(o0), T(o1), T(o2)),
              B(0,
                T(c1,s0), T(s1), T(s2)), op, os))
N(map     )(D(B(o,
                T(mapo0), T(mapo1), T(mapo2)),
              B(s,
                T(maps0), T(maps1), T(maps2)), op, os))
N(start_os)(void**bo = os[0], **bs = os[1];
            bo[-3] = o, bs[-3] = s,
            D(o, s, op, os[-3]))
int main() {
  void(**a)() = T(start_os, map, putos, main_os);
  long   r    = 0;
  D(0, 0, 0, 0);
}
