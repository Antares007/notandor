#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...) t[-1](o, b, r, t - 1, __VA_ARGS__)
#define O(r0, r1, r2, r3, o) ((void *)(const void *[]){r0, r1, r2, r3, o})
#define T(...)                                                                 \
  ((void *)&((const void *[]){                                                 \
      cr, __VA_ARGS__, Nargs(cr, __VA_ARGS__)})[Nargs(cr, __VA_ARGS__)])
typedef void (*w_t)(void *, void *, void *, void *, void *, void *, void *,
                    void *);
#define obrtd w_t **o, w_t **b, long r, w_t *t, long d

#define rest void *p1, void *p2, void *p3
#define frwd p1, p2, p3
#define FUN __FUNCTION__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cr(obrtd, rest) { o[r][-1](o[4], b, r, o[r] - 1, d, frwd); }
void dim(obrtd, char *s, long l, long p) {
  char *m = (char *)*--t;
  if (p < l && m[0] == s[p])
    D(o, t, d, s, l, p + 1);
}
void ε() {}
void propeller(obrtd, char *s, long l, long p) {
  if (d < (l - p) + 5)
    for (r = 0; r < 4; r++)
      D(O(T(cr), T(cr), T(cr), T(cr), o), t, d - 1, s, l, p);
}
void print_o_name(obrtd, char *s, long l, long p) {
  printf("%s\n", (char *)*--t);
  D(o, t, d, s, l, p);
}
void br(obrtd, char *s, long l, long p) {
  b = O(T(propeller), T(propeller), T(propeller), T(propeller),
        O(T(ε), T(ε), T(ε), T(ε), b));
  b[4][r] = T(*--t, print_o_name);
  D(o, t, d, s, l, p);
}
void term(obrtd, rest) {
  void *str = *--t;
  void *Tbr = T(str, br);
  o = O(T(propeller), T(propeller), T(propeller), T(propeller),
        O(T(str, dim), T(ε), T(ε), T(ε), O(Tbr, Tbr, Tbr, Tbr, o)));
  D(o, t, d + 1, frwd);
}
#define V(ar, T0, T1, T2, T3)                                                  \
  void ar(obrtd, char *s, long l, long p) {                                    \
    void *Tpro = T(propeller);                                                 \
    void *Tbr = T(#ar, br);                                                    \
    o = O(Tpro, Tpro, Tpro, Tpro,                                              \
          O(Tbr, Tbr, Tbr, Tbr, O(T0, T1, T2, T3, o)));                        \
    D(o, t, d + 1, s, l, p);                                                   \
  }
void *Trid = 0, *Trcat = 0;
V(dot, T(".", dim), T(ε), T(ε), T(ε))

V(plus, T("+", dim), T(ε), T(ε), T(ε))
V(mul, T("*", dim), T(ε), T(ε), T(ε))
V(oprn, T("(", dim), T(ε), T(ε), T(ε))
V(cprn, T(")", dim), T(ε), T(ε), T(ε))
void *ratoi;
V(Nat, T("0", dim), T("1", dim), T("2", dim), T("3", dim))
V(E, T(Nat), T(oprn, E, cprn), T(E, mul, E), T(E, plus, E));
// o b r t s
V(S, T("b", term), T(S, "a", term), T(S, "b", term), T(S, "x", term))

V(sS, T("s", term, sS, sS), T(cr), T(ε), T(ε))
//
// s ::= np vp | s pp
// np ::= noun | det noun | np pp
// pp ::= prep np
// vp ::= verb np
// det ::= ’a’ | ’t’
// noun ::= ’i’ | ’m’ | ’p’ | ’b’
// verb ::= ’s’
// prep ::= ’n’ | ’w’
// V(prep, T("n", dim), T("w", dim), T(ε), T(ε))
// V(verb, T("s", dim), T(ε), T(ε), T(ε))
// V(noun, T("i", dim), T("m", dim), T("p", dim), T("b", dim))
// V(det, T("a", dim), T("t", dim), T(ε), T(ε))
// void pp();
// V(np, T(noun), T(det, noun), T(np, pp), T(ε))
// V(vp, T(verb, np), T(ε), T(ε), T(ε))
// V(pp, T(prep, np), T(ε), T(ε), T(ε))
// V(s, T(np, vp), T(s, pp), T(ε), T(ε))
#include <string.h>
void zero(obrtd, char *s, long l, long p) {
  printf("%ld %ld %s %ld/%ld\n", r, d, s, l, p);
  cr(b, 0, 0, 0, 0, s, l, p);
  usleep(10000);
}
void one(obrtd, char *s, long l, long p) {
  printf("%s\n", s);
  usleep(10000);
}
int main() {
  void *T0 = T(zero);
  void *T1 = T(one);
  void *o = O(T0, T0, T0, T0, 0);
  void *b = O(T1, T1, T1, T1, 1);
  // char *str = "isamntpwab.";
  // w_t *t = T(s, dot);
  char *str = "babaax.";
  w_t *t = T(S, dot);
  // char *str = "ss";
  // w_t *t = T(sS);
  // char *str = "(1+(1+(1+(1+2)*2+1)*2+1)*2+1)*2+1.";
  // w_t *t = T(E, dot);
  t[-1](o, b, 0, t - 1, 0, str, strlen(str), 0);
}
