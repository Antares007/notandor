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
void dot_if_match(obrt, char *s) {
  char *m = (char *)*--t;
  if (m[0] == s[0])
    D(o, t, s + 1);
}
void ε(obrt, rest) {}
void propeller(obrt, char *s) {
  char *name = (char *)*--t;
  for (long i = 1; i < 8; i++)
    if (o[i][-1] == ε)
      continue;
    else {
      void **p = (void *)o;
      while (p)
        printf(" "), p = p[8];
      printf("%s_%ld. %s\n", name, i, s), usleep(100000),
          t[-1](o, b, i, t - 1, s);
    }
}
//    puts(__FUNCTION__), usleep(100000);
#define V(ar, ...)                                                             \
  void ar(obrt, rest) {                                                        \
    void **p = (void *)o;                                                      \
    while (p)                                                                  \
      printf(" "), p = p[8];                                                   \
    printf("%s\n", #ar);                                                       \
    void *Tcr = T(cr);                                                         \
    void *Tmbpro = T(mb, #ar, propeller);                                      \
    D(O(Tcr, Tmbpro, Tmbpro, Tmbpro, Tmbpro, Tmbpro, Tmbpro, Tmbpro,           \
        O(Tcr, __VA_ARGS__, o)),                                               \
      t, frwd);                                                                \
  }
V(α, T("a", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(β, T("b", dot_if_match), T(ε), T(ε), T(ε), T(ε), T(ε), T(ε))
V(S, T(β), T(S, α), T(ε), T(ε), T(ε), T(ε), T(ε))
void zero(obrt, char *s) {
  long isEnd = (long)b[8] == (long)o;
  printf("%.2ld %c b>%s<o \n", r, isEnd ? 'T' : 'F', s);
  usleep(200000);
}
int main() {
  long b = 0, r = 1;
  void (**t)() = T(mb, S);
  void *T0 = T(zero);
  void *o = O(T0, T0, T0, T0, T0, T0, T0, T0, 0);
  D(o, t, "baa.");
}
