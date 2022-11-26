#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__)+1)[Nargs(__VA_ARGS__)+1])
#define B(o, ...) ((void *)&V(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define Ν(...) { __VA_ARGS__; }}
#define N(argo) void argo(OARS) { Ν
#define OARS void (***o)(), void (**a)(), long r, void **s, void **op, void **os
#define C(o, Ray, s, op, os) (LOG, ((void(***)())o)[Ray][-1](((void(***)())o)[-2], &((void(***)())o)[Ray][-1], Ray, s, op, os))
#define D(o, s, op, os) (LOG, a[-1](o, &a[-1], r, s, op, os))
#define Short(v) (long)(v) & (long)0xffff
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(100000)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// clang-format off
N(cr    )(C(o, r, s, op, os))
N(cn    )(r = *--a, C(o, r, s, op, os))
N(err   )(LOG)

N(pc0   )(LOG)
N(pc1   )(assert((long)op == 1 || (long)op == 10),
          ((long*)o)[1] += (long)op,
          D(s, o[0], o[1], 0))
N(pc2   )(LOG)
N(p0    )(o[0] = B(o,
                   T(pc0), T(pc1)),
          o[1] = (void*)op,
          D(s, o[0], o[1], 0))
N(p1    )(LOG)
N(p2    )(LOG)

N(cc0   )(LOG)
N(cc1   )(printf("-------> %ld\n", (long)op),
          (long)op == 150
          ? C(s, 0, 0, 0, 0)
          : D(s, o[0], 10, 0))
N(cc2   )(LOG)
N(c0    )(o[0] = B(o,
                   T(cc0), T(cc1)),
          D(s, o[0], 1, 0))
N(c1    )(LOG)
N(c2    )(LOG)
int main() {
  void (**a)() = T(cr);
  long    r    = 0;
  D(B(V(3, 0),
      T(p0)),
    B(V(6),
      T(1, cn, c0)), 99, 0);
}
