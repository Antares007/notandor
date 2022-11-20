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
#define C(Ray, s, op, os) o[Ray][-1](o[-2], &o[Ray][-1], Ray, s, op, os)
#define D(o, s, op, os) a[-1](o, &a[-1], r, s, op, os)
#define Short(v) (long)(v) & (long)0xffff
#define LOG                                                                    \
  printf("%.4lx %.4lx %.2ld %.4lx %s\n", Short(o), Short(a), r, Short(s),      \
         __FUNCTION__),                                                        \
      logn(o, a, r, s, op, os), sleep(1)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void logn(OARS);
#define EndRayTemplate(n)                                                      \
  N(r##n, printf("%s %s %ld %ld\n", __FUNCTION__, (char *)op[0], (long)op[1],  \
                 (long)s[0]);)
EndRayTemplate(0) EndRayTemplate(1) EndRayTemplate(2) EndRayTemplate(3);
EndRayTemplate(4) EndRayTemplate(5) EndRayTemplate(6) EndRayTemplate(7);
// clang-format off
N(cr,     C(r, s, op, os);)

N(cn,     long newray = *--a; C(newray, s, op, os);)

N(term_,  const char *ms = os[0]; const char *in = op[0]; long len = op[1];
          long pos = s[0];
          if (pos < len && in[pos] == ms[0]) C(r, O(s, pos + 1), op, os[-2]);
          else C(r, s, op, os[-2]);)

N(term,   const char *ms = (void *)*--a;
          D(O(o, T(0, cn), T(1, cn, term_),         T(2, cn)), s, op, O(os, ms));) void S();

N(S_,     D(O(o, T(0, cn), T(1, cn,    "b", term),  T(2, cn)), s, op, os);
          D(O(o, T(0, cn), T(1, cn, S, "a", term),  T(2, cn)), s, op, os);)

N(S,      D(O(o, T(0, cn), T(1, cn, S_),            T(2, cn)), s, op, os);)

void init();
int main() {
          init();
          void (***o)() = O(0, T(r0), T(r1), T(r2), T(r3), T(r4), T(r5), T(r6), T(r7));
          void ( **a)() = T(cr, S);
          long r        = 1;
          void **s      = 0;
          void **op     = 0;
          void **os     = 0;
          D(o, O(s, 0), O(op, "baaa", 4), os);
}
////NNSD
//#define NN(argo, ab, bb) N(argo##a, ab)N(argo##b, bb)
// NN(s, { s = O(s, ((long)s[0]) + 1); C(1); }, { C(1); })
char *names[0x10000] = {};
;
#define NAME(me) names[(long)me & 0xffff] = #me
void init() {
  NAME(r0), NAME(r1), NAME(r2), NAME(r3), NAME(r4), NAME(r5), NAME(r6),
      NAME(r7);
  NAME(cr);
  NAME(cn);
  NAME(term_);
  NAME(term);
  NAME(S_);
  NAME(S);
}
char*data = "NNSD";
void logn(OARS) {
  if (o)
    for (long n = 0; n < (long)o[-1]; n++) {
      printf("|%.2ld:", n);
      for (long m = (long)(o[n][0]); m > 0; m--) {
        char *name = names[(long)(o[n][0 - m]) & 0xffff];
        if (name)
          printf("%s ", name);
        else if ((long)(o[n][0 - m]) < 2000)
          printf("%ld ", (long)(o[n][0 - m]));
        else if (((long)(o[n][0 - m]) >> 24) == ((long)(data) >> 24)) 
          printf("\"%s\" ", (char*)(o[n][0 - m]));
        else
          printf(". ");
      }
      printf(" ");
    }
  printf("\n");
}
