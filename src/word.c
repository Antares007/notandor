#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t, ...) t[-1](o, b, r, t - 1, __VA_ARGS__)
#define O(r0, r1, r2, r3, o) ((void *)(const void *[]){r0, r1, r2, r3, o})
#define A(...) ((void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&((const void *[]){                                                 \
      cr, __VA_ARGS__, Nargs(cr, __VA_ARGS__)})[Nargs(cr, __VA_ARGS__)])
typedef void (*w_t)(void *, void *, void *, void *, void *, void *);
#define obrtds w_t **o, w_t **b, long r, w_t *t, long d, void **s

#define rest void *p1, void *p2, void *p3
#define frwd p1, p2, p3
#define FUN __FUNCTION__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cr(obrtds) { o[r][-1](o[4], b, r, o[r] - 1, d, s); }
void c0(obrtds) { cr(o, b, 0, t, d, s); }

void ε() {}
void *Tε = T(ε);

void dim(obrtds) {
  char *in = s[1];
  long len = s[2];
  long pos = s[3];
  char *str = (char *)*--t;
  if (pos < len && str[0] == in[pos])
    D(o, t, d, A(s, in, len, pos + 1));
}
void propeller(obrtds) {
  for (r = 0; r < 4; r++)
    D(o, t, d, s);
}
void check_depth(obrtds) {
  long len = s[2];
  long pos = s[3];
  if (d < (len - pos) + 5)
    D(o, t, d - 1, s);
}
void br(obrtds) {
  void *Tpro = T(propeller);
  b = O(Tpro, Tpro, Tpro, Tpro, //
        O(Tε, Tε, Tε, Tε,       //
          b));
  b[4][r] = *--t;
  D(o, t, d, s);
}
void term(obrtds) {
  void *str = *--t;
  void *Term = T(str, dim);
  void *Tb = T(str, br);
  void *Tc0 = T(c0, check_depth);
  D(O(Tc0, Tc0, Tc0, Tc0, //
      O(Term, 0, 0, 0,    //
        O(Tb, 0, 0, 0, o))),
    t, d + 1, s);
}
// clang-format off
#define V(ar, T0, R0, T1, R1, T2, R2, T3, R3)                                  \
  void ar(obrtds) {                                                            \
    void *Tpro = T(propeller, check_depth);                                    \
    o = O(Tpro,          Tpro,       Tpro,          Tpro,                      \
          O(T(R0, br), T(R1, br), T(R2, br), T(R3, br),                        \
            O(T0,          T1,     T2,           T3,                           \
                               o)));                                           \
    t[-1](o, b, r, t - 1, d + 1, s);                                           \
  }
// clang-format on
void *Trid = 0, *Trcat = 0;
void ps(obrtds) { t = (void *)t[-1], D(o, t, d, s); }
void dot(obrtds) {
  t = T(t, ps, ".", term);
  D(o, t, d, s);
}
void print_s(obrtds) {
  printf("hey\n");
  D(o, t, d, s);
}
V(oprn, T("(", dim), T(print_s), Tε, Tε, Tε, Tε, Tε, Tε);
V(cprn, T(")", dim), T(print_s), Tε, Tε, Tε, Tε, Tε, Tε);
V(plus, T("+", dim), T(print_s), Tε, Tε, Tε, Tε, Tε, Tε);
V(mult, T("*", dim), T(print_s), Tε, Tε, Tε, Tε, Tε, Tε);
V(Nat,                     //
  T("0", dim), T(print_s), //
  T("1", dim), T(print_s), //
  T("2", dim), T(print_s), //
  T("3", dim), T(print_s)  //
);
V(E,                            //
  T(Nat), T(print_s),           //
  T(oprn, E, cprn), T(print_s), //
  T(E, mult, E), T(print_s),    //
  T(E, plus, E), T(print_s)     //
);
#include <string.h>
void zero(obrtds) {
  printf("r:%ld d:%ld \"%s\" %ld/%ld\n", r, d, (char *)s[1], (long)s[2],
         (long)s[3]);
  //  cr(b, 0, 0, 0, 0, s);
  usleep(10000);
}
void one(obrtds) {
  printf("one\n");
  usleep(10000);
}

V(sS, T("s", term, sS, sS), T(ε),
      T(cr), T(ε),
      T(ε), T(ε), T(ε), T(ε))
int main() {
  void *T0 = T(zero);
  void *T1 = T(one);
  void *o = O(T0, T0, T0, T0, 0);
  void *b = O(T1, T1, T1, T1, 0);
  //char *str = "(1+2)+3.";
  //dot(o, b, 0, T(E), 0, A(0, str, strlen(str), 0));
  char *str = "ss";
  sS(o, b, 0, T(cr), 0, A(0, str, strlen(str), 0));
}
// char *str = "isamntpwab.";
// w_t *t = T(s, dot);
// char *str = "(1+(1+(1+(1+2)*2+1)*2+1)*2+1)*2+1.";
// char *str = "(1+2)+3.";
// w_t *t = T(E, dot);
// t[-1](o, b, 0, t - 1, 0, A(str, strlen(str), 0));
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
