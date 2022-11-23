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
#define C(o, Ray, s, op, os)                                                   \
  (LOG,                                                                        \
   ((void (***)())o)[Ray][-1](((void (***)())o)[-3],                           \
                              &((void (***)())o)[Ray][-1], Ray, s, op, os))
#define D_(o, s, op, os)                                                       \
  ((void (**)())a)[-1](o, &((void (**)())a)[-1], r, s, op, os)
#define D(o, s, op, os) (LOG, D_(o, s, op, os))
#define Short(v) (long)(v) & (long)0xffff
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
N(init    )(o[-3] = op[0],
            D_(o, s, op[-3], os))
N(putop   )(D_(o, s, B(op, o), os))
N(soopos  )(D_(s, o, op, os))
N(osopos  )(D_(o, s, op, os))
N(pstr_   )(const char*str=*--a; printf("%ld %s\n", r, str), usleep(225500), D_(o, s, op, os))
N(pstr    )(void*str=*--a;
            D_(B(o,
                 T(str,pstr_),T(str,pstr_),T(str,pstr_),T(str,pstr_)), s, op, os))
N(map     )(D(B(B(o[-3],
                T(osopos),  T("mapP", pstr, osopos),    T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0,putop),    T(c0,putop)),
              B(B(s[-3],
                T(osopos),  T("mapC", pstr, osopos),    T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0, putop),   T(c0, putop)), op, os))
N(putinos )(void *vs = (void*)*--a; D(o,s,op, B(os, vs)))
N(printos )(printf("aaa\n"), D(o,s,op, os[-3]))
N(term    )(const char*match=*--a;(void)match;
            D(B(B(o[-3],
                T(osopos),  T("termP", pstr, osopos),   T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0,putop),    T(c0,putop)),
              B(B(s[-3],
                T(osopos),  T("termC", pstr, osopos),   T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0, putop),   T(c0, putop)), op, os))
N(parse_o1)()
N(show    )(D(o,s,op,os))
N(parse   )(const char*input=*--a;(void)input;
            D(B(B(o[-3],
                T(osopos),  T("parseP", pstr, osopos),  T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0,putop),    T(c0,putop)),
              B(B(s[-3],
                T(osopos),  T("parseC", pstr, osopos),  T(osopos),      T(osopos)),
                T(putop),   T(c0,putop),                T(c0, putop),   T(c0, putop)), op, os))
int main() {
  void(**a)() = T(cr, "baaa", parse, map, "b", term);
  long r = 3;
  D(B(B(B(0,
          T(soopos),    T("P", pstr, soopos), T(soopos),    T(soopos)),
          T(init),      T(cr),                T(cr),        T(cr)),
          T(putop),     T(c0,putop),          T(c0,putop),  T(c0,putop)),
    B(B(B(0,
          T(c1,soopos), T("C", pstr, soopos), T(soopos),    T(soopos)),
          T(init),      T(cr),                T(cr),        T(cr)),
          T(putop),     T(c0,putop),          T(c0,putop),  T(c0,putop)), 0, 0);
}
