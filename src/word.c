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
void terminal_ray(obrt, char *s) {
  char*m = (char*)*--t;
  if(m[0] = s[0]) D(o, t, s+1);
  else D(o, t, s);
}
void terminal(obrt, char *s) {
  void *Tmb = T(mb);
  D(O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb,
      O(Tcr,
        T(t[-7], terminal_ray),
        T(t[-6], terminal_ray),
        T(t[-5], terminal_ray),
        T(t[-4], terminal_ray),
        T(t[-3], terminal_ray),
        T(t[-2], terminal_ray),
        T(t[-1], terminal_ray),
        O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, o))),
    t - 7, s);
}
void dec17(obrt, rest) {
  D(o, T(t, continues, "1", "2", "3", "4", "5", "6", "7", terminal), frwd);
}
void E(obrt, char *s) {
  void *Tmb = T(mb);
  D(O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb,
      O(Tcr,
        T(mb, "1", term),
        T(mb, "2", term),
        T(mb, "(", term, E, ")", term),
        T(mb, E, "*", term, E),
        T(mb, E, "/", term, E),
        T(mb, E, "+", term, E),
        T(mb, E, "-", term, E),
        O(Tcr, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, Tmb, o))),
    t, s);
}
void logger();
void wrap_logger();
void show_rez(obrt, char *s) { printf("%s\n", s); }
void call_back(obrt, char *s) {
  show_rez(o, b, r, t, s);
  if ((long)o == (long)b[8])
    return;
  usleep(200000);
  D(b, t, s);
}
int main() {
  long b = 0, r = 4;
  void (**t)() = T(mb);
  void *o[] = {T(show_rez), 0, 0, 0, T(call_back), 0, 0, 0, 0};
  D(o, t, "baaaa");
}
