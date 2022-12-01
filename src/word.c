#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...)                                                           \
  (((void (**)())(t))[-1](o, b, r, ((void **)(t)) - 1, __VA_ARGS__))
#define O(...) ((void *)(const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&((const void *[]){                                                 \
      cr, __VA_ARGS__, Nargs(cr, __VA_ARGS__)})[Nargs(cr, __VA_ARGS__)])
#define obrt void (***o)(), void (***b)(), long r, void (**t)()

#define rest void *p1, void *p2, void *p3, void *p4
#define frwd p1, p2, p3, p4
#define FUN __FUNCTION__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cr(obrt, rest) { o[r][-1](o[8], b, r, o[r] - 1, frwd); }
void mb(obrt, rest) { t[-1](o, o, r, t - 1, frwd); }
void dot_if_match(obrt, char *s, long l, long p, long d) {
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
    D(O(Tpro, Tpro, Tpro, Tpro, Tpro, Tpro, Tpro, Tpro,                        \
        O(T1, T2, T3, T4, T5, T6, T7, T(ε), o, ar)),                           \
      t, s, l, p, d - 1);                                                      \
  }
V(α, T("a", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(β, T("b", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(αβ, T(α), T(β), T(ε), T(ε), T(ε), T(ε), T(ε))
V(S, T(β), T(S, αβ), T(ε), T(ε), T(ε), T(ε), T(ε))
V(σ, T("a", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(sS, T(σ, sS, sS), T(cr), T(ε), T(ε), T(ε), T(ε), T(ε))
V(plus, T("+", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(mul, T("*", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(oprn, T("(", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(cprn, T(")", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(E, T(α), T(oprn, E, cprn), T(E, mul, E), T(E, plus, E), T(ε), T(ε), T(ε))
void zero(obrt, char *s, long l, long p, long d) {
  printf("%ld %ld >%s< \n", r, d, s + p);
  usleep(10000);
}
int main() {
  void *T0 = T(zero), *Tε = T(ε);
  propeller(O(T(E), Tε, Tε, Tε, Tε, Tε, Tε, Tε,
              O(T0, T0, T0, T0, T0, T0, T0, T0, 0, 0)),
            0, 0, 0, "(a+a)*a", 7, 0, 40);
}
