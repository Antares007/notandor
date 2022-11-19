#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&VA(__VA_ARGS__, Nargs(__VA_ARGS__))[Nargs(__VA_ARGS__)])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define N(argo, ...)                                                           \
  void argo(OARS) {                                                            \
    LOG;                                                                       \
    { __VA_ARGS__ }                                                            \
  }
#define OARS void (***o)(), void (**a)(), long r, void **s, void **op, void **os
#define C(Ray) o[Ray][-1](o[-2], &o[Ray][-1], Ray, s, op, os)
#define D(o) a[-1](o, &a[-1], r, s, op, os)
#define LOG printf("%.2ld %s\n", r, __FUNCTION__) //, sleep(1)
#define EndRayTemplate(n)                                                      \
  N(r##n, printf("%s %s %ld\n", __FUNCTION__, (char *)s[-2], (long)s[-1]);)

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

EndRayTemplate(0) EndRayTemplate(1) EndRayTemplate(2) EndRayTemplate(3);
EndRayTemplate(4) EndRayTemplate(5) EndRayTemplate(6) EndRayTemplate(7);

N(cr, C(r);)
N(cn, long newray = *--a; C(newray);)
N(S, D(O(O(O(O(o,
  T(0,cn), T(1,cn), T(2,cn), T(4,cn)),
  T(0,cn), T(1,cn), T(3,cn), T(3,cn)),
  T(0,cn), T(2,cn), T(2,cn), T(3,cn)),
  T(1,cn), T(1,cn), T(2,cn), T(3,cn))
);)
int main() {
  void *mem[3][0x1000];
  void **s = mem[0];
  void **op = mem[1];
  void **os = mem[2];
  void (***o)() = O(0, T(r0), T(r1), T(r2), T(r3), T(r4), T(r5), T(r6), T(r7));
  void (**a)() = T(cr, S);
  long r = 0;
  *s++ = "baaa", *s++ = 0, D(o);
}
