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
static void *Tcr = T(cr);
void continues(obrt, rest) {
  t = (void *)*t[-1];
  D(o, t, frwd);
}
void propeller(obrt, rest) {
  long a = r;
  for (r = 1; r < a; r++)
    D(o, t, frwd);
  for (r = a; r < 8; r++)
    D(o, t, frwd);
}
void terminal_ray(obrt, char *s) {
  char *m = (char *)*--t;
  if (m[0] == s[0])
    D(o, t, s + 1);
}
static void *Tpr = T(propeller);
void terminal(obrt, char *s) {
  D(O(Tcr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr,
      O(Tcr, T(t[-7], terminal_ray), T(t[-6], terminal_ray),
        T(t[-5], terminal_ray), T(t[-4], terminal_ray), T(t[-3], terminal_ray),
        T(t[-2], terminal_ray), T(t[-1], terminal_ray), o)),
    t - 7, s);
}
void dec17(obrt, rest) {
  t = T(t, continues, "1", "2", "3", "4", "5", "6", "7", terminal);
  D(o, t, frwd);
}
void alfa(obrt, rest) {
  t = T(t, continues, "a", "b", "c", "d", "e", "f", "g", terminal);
  D(o, t, frwd);
}
// sS = (term_s ‘thenS‘ sS ‘thenS‘ sS) ‘orelse‘ empty

void sS(obrt, rest) {
  D(O(Tcr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr,
      O(Tcr, T("s", "s", "s", "s", "s", "s", "s", terminal, sS, sS), T(cr),
        T(cr), T(cr), T(cr), T(cr), T(cr), o)),
    t, frwd);
}
void dec17s(obrt, rest) {
  D(O(Tcr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr, Tpr,
      O(Tcr,
        T(alfa),
        T(dec17s, dec17),
        T(dec17s, alfa),
        T(cr),
        T(cr),
        T(cr),
        T(cr), o)),
    t, frwd);
}
void reduce(obrt, rest) { D(O(T(0), o), t, frwd); }
// void E(obrt, char *s) {
//   void *Tmb = T(mb);
//   D(O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb,
//       O(Tcr, T("1", term, reduce), T("2", term, reduce),
//         T("(", term, E, ")", term, reduce), T(E, "*", term, E, reduce),
//         T(E, "/", term, E, reduce), T(E, "+", term, E, reduce),
//         T(E, "-", term, E, reduce),
//         O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, o))),
//     t, s);
// }
void logger();
void wrap_logger();
void show_rez(obrt, char *s) {
  printf("%s\n", s);
  usleep(200000);
}
int main() {
  long b = 0, r = 4;
  void (**t)() = T(mb, dec17s);
  void *Tshow = T(show_rez);
  void *o[] = {Tshow, Tshow, Tshow, Tshow, Tshow, Tshow, Tshow, Tshow, 0};
  D(o, t, "a123123");
}
