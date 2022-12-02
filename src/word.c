#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...) t[-1](o, b, r, t - 1, __VA_ARGS__)
#define O(r0, r1, r2, r3, r4, r5, r6, r7, o, b)                                \
  ((void *)(const void *[]){r0, r1, r2, r3, r4, r5, r6, r7, o, b})
#define T(...)                                                                 \
  ((void *)&((const void *[]){                                                 \
      cr, __VA_ARGS__, Nargs(cr, __VA_ARGS__)})[Nargs(cr, __VA_ARGS__)])
typedef void (*w_t)(void *, void *, void *, void *, void *, void *, void *,
                      void *);
#define obrt w_t **o, w_t **b, long r, w_t *t

#define rest void *p1, void *p2, void *p3, void *p4
#define frwd p1, p2, p3, p4
#define FUN __FUNCTION__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cr(obrt, rest) { o[r][-1](o[8], b, r, o[r] - 1, frwd); }
void mb(obrt, rest) { t[-1](o, o, r, t - 1, frwd); }
void dim(obrt, char *s, long l, long p, long d) {
  char *m = (char *)*--t;
  if (p < l && m[0] == s[p])
    D(o, t, s, l, p + 1, d);
}
void ε() {}
void propeller(obrt, char *s, long l, long p, long d) {
  if (d < 0)
    return;
  for (r = 0; r < 8; r++)
    cr(o, b, r, t, s, l, p, d - 1);
}
#define V(ar, T1, T2, T3, T4, T5, T6, T7)                                      \
  void ar(obrt, char *s, long l, long p, long d) {                             \
    void *Tpro = T(propeller);                                                 \
    o = O(Tpro, Tpro, Tpro, Tpro, Tpro, Tpro, Tpro, Tpro,                      \
          O(T1, T2, T3, T4, T5, T6, T7, T(ε), o, b), b);                       \
    D(o, t, s, l, p, d - 1);                                                   \
  }
V(dot, T(".", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(α, T("a", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(β, T("b", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(αβ, T(α), T(β), T(ε), T(ε), T(ε), T(ε), T(ε))
V(S, T(β), T(S, αβ), T(ε), T(ε), T(ε), T(ε), T(ε))
V(σ, T("a", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(sS, T(σ, sS, sS), T(cr), T(ε), T(ε), T(ε), T(ε), T(ε))
V(plus, T("+", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(mul, T("*", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(oprn, T("(", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(cprn, T(")", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(E, T(α), T(oprn, E, cprn), T(E, mul, E), T(E, plus, E), T(ε), T(ε), T(ε))
// s ::= np vp | s pp
// np ::= noun | det noun | np pp
// pp ::= prep np
// vp ::= verb np
// det ::= ’a’ | ’t’
// noun ::= ’i’ | ’m’ | ’p’ | ’b’
// verb ::= ’s’
// prep ::= ’n’ | ’w’
V(prep, T("n", dim), T("w", dim), T(ε), T(ε), T(ε), T(ε), T(ε))
V(verb, T("s", dim), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(noun, T("i", dim), T("m", dim), T("p", dim), T("b", dim), T(ε), T(ε), T(ε))
V(det, T("a", dim), T("t", dim), T(ε), T(ε), T(ε), T(ε), T(ε))
void pp();
V(np, T(noun), T(det, noun), T(np, pp), T(ε), T(ε), T(ε), T(ε))
V(vp, T(verb, np), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(pp, T(prep, np), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(s, T(np, vp), T(s, pp), T(ε), T(ε), T(ε), T(ε), T(ε))
#include <string.h>
void zero(obrt, char *s, long l, long p, long d) {
  printf("%ld %ld %s %ld/%ld\n", r, d, s, l, p);
  usleep(10000);
}
int main() {
  void *T0 = T(zero); //, *Tε = T(ε);
  void *o = O(T0, T0, T0, T0, T0, T0, T0, T0, 0, 0);
  char *str = "isamntpwab.";
  w_t *t = T(s, dot);
  //////////////////  t[-1](o, 0, 0, t - 1, str, strlen(str), 0, 50);
  //  long b = o, r = 0;
  // D(o, t, str, strlen(str), 0, 50);
  t[-1](o, 0, 0, t - 1, str, strlen(str), 0, 50);
  // cr(o, 0, r, t, str, strlen(str), 0, 50);
  // propeller(O(T(s, dot), Tε, Tε, Tε, Tε, Tε, Tε, Tε, o, 0), 0, 0, 0, str,
  //           strlen(str), 0, 50);
}
