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
N(putos     )(D(o, s, op, B(os, o, s)))
N(soopos    )(D_(s,o,op,os))
N(osopos    )(D_(o,s,op,os))
N(pstr      )(printf("%s\n",(char*)*--a), usleep(125500), D_(o,s,op,os))
N(start_os  )(void**bo = os[0], **bs = os[1];
              bo[-3] = o, bs[-3] = s,
              D(o, s, op, os[-3]))
N(term      )(const char*ms = *--a;(void)ms;
              D(B(o,
                  T(osopos),    T( "7", pstr, osopos), T(osopos)),
                B(s,
                  T(osopos),    T("10", pstr, osopos), T(osopos)), op, os))
N(parse     )(const char*in = *--a;(void)in;
              D(B(o,
                  T(osopos),    T( "8", pstr, osopos), T(osopos)),
                B(s,
                  T(osopos),    T("11", pstr, osopos), T(osopos)), op, os))
N(main_os   )(D(B(0,
                  T(soopos),    T( "9", pstr, soopos), T(soopos)),
                B(0,
                  T(c1,soopos), T("12", pstr, soopos), T(soopos)), op, os))
int main() {
  void(**a)() = T(start_os, "b", term, "b", term, "baaa", parse, putos, main_os);
  long   r    = 0;
  D(0, 0, 0, 0);
}
