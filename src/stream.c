#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&VA(cr, __VA_ARGS__, Nargs(__VA_ARGS__)+1)[Nargs(__VA_ARGS__)+1])
#define B(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define Ν(...) { __VA_ARGS__; }}
#define N(argo) void argo(OARS) { Ν
#define OARS void (***o)(), void (**a)(), long r, void **s, void **op, void **os
#define C(Ray, s, op, os) LOG, o[Ray][-1](o[-2], &o[Ray][-1], Ray, s, op, os)
#define D(o, s, op, os) LOG, a[-1](o, &a[-1], r, s, op, os)
#define Short(v) (long)(v) & (long)0xffff
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(100000)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// clang-format off
N(cr    )(C(r, s, op, os))
N(cn    )(r = *--a, C(r, s, op, os))
N(err   )(LOG)

N(pc0   )(LOG)
N(pc1   )(assert((long)o == 3),
          D(s, 
            B(o,
            T(pc0), T(pc1)), 0, 0))
N(pc2   )(LOG)
N(p0    )(assert((long)o == 3),
          D(s, 
            B(o,
            T(pc0), T(pc1)), 0, 0))
N(p1    )(LOG)
N(p2    )(LOG)

N(cc0   )(LOG)
N(cc1   )(assert((long)o == 6),
          D(s, 
            B(o,
            T(cc0), T(cc1)), 0, 0))
N(cc2   )(LOG)
N(c0    )(assert((long)o == 6),
          D(B(s,
            T(1,cn)), 
            B(o,
            T(cc0), T(cc1)), 0, 0))
N(c1    )(LOG)
N(c2    )(LOG)
int main() {
  void (**a)() = T(cr);
  long    r    = 0;
  D(B(3,
    T(p0)),
    B(6,
    T(c0)), 0, 0);
}
