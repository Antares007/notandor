#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define Ν(...)                                                                 \
  { __VA_ARGS__; }                                                             \
  }
#define N(argo)                                                                \
  void argo(OARS) {                                                            \
    Ν
#define OARS void (***o)(), void (**a)(), long r, void **s, void **op, void **os
#define C(o, Ray, s, op, os)                                                   \
  (LOG,                                                                        \
   ((void (***)())o)[Ray][-1](((void (***)())o)[-2],                           \
                              &((void (***)())o)[Ray][-1], Ray, s, op, os))
#define D(o, s, op, os) (LOG, a[-1](o, &a[-1], r, s, op, os))
#define Short(v) (long)(v) & (long)0xffff
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(125500)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// clang-format off
N(cr)(C(o, r, s, op, os))
N(c0)(C(o, 0, s, op, os))
N(c1)(C(o, 1, s, op, os))
N(c2)(C(o, 2, s, op, os))
N(c3)(C(o, 3, s, op, os))
N(c4)(C(o, 4, s, op, os))
N(c5)(C(o, 5, s, op, os))
N(c6)(C(o, 6, s, op, os))
N(c7)(C(o, 7, s, op, os))
N(cn)(r = *--a, C(o, r, s, op, os))
N(init    )(o[-2] = op[0],
            D(o, s, op[-2], os))
N(putop   )(D(o, s, B(op, o), os))
N(soopos  )(D(s, o, op, os))
N(osopos  )(D(o, s, op, os))
N(map     )(D(B(B(o[-2],
                T(osopos),T(osopos),  T(osopos),  T(osopos)),
                T(putop), T(c0,putop),T(c0,putop),T(c0,putop)),
              B(B(s[-2],
                T(osopos),T(osopos),  T(osopos),  T(osopos)),
                T(putop), T(c0,putop),T(c0,putop),T(c0,putop)), op, os))
int main() {
  void(**a)() = T(cr, map);
  long r = 3;
  D(B(B(B(0,
          T(soopos),    T(soopos),  T(soopos),  T(soopos)),
          T(init),      T(cr),      T(cr),      T(cr)),
          T(putop),     T(c0,putop),T(c0,putop),T(c0,putop)),
    B(B(B(0,
          T(c1,soopos), T(soopos),  T(soopos),  T(soopos)),
          T(init),      T(cr),      T(cr),      T(cr)),
          T(putop),     T(c0,putop),T(c0,putop),T(c0,putop)), 0, 0);
}
