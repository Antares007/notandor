#include "obrt.h"
#define LOG printf("%ld %s\n", (long)r, __FUNCTION__), usleep(100000)
#include <stdio.h>
#include <unistd.h>

void cr(obrt, void *p1, void *p2, void *p3, void *p4) {
  C(o, b, r, p1, p2, p3, p4); // o[r][-1](o[8], b, r, o[r] - 1, p1, p2, p3, p4);
}
static void *Tcr = T(cr);
void ob(obrt, void *p1, void *p2, void *p3, void *p4) {
  C(o, o, r, p1, p2, p3, p4); // o[4][-1](o[8], b, 4, o[4] - 1, p1, p2, p3, p4);
}
void co(obrt, void *p1, void *p2, void *p3, void *p4) {
  cr(((void **)t)[-1], b, r, t - 1, p1, p2, p3, p4);
}
void term0(obrt, char *s) {
  LOG;
  char *ms = (char *)*--t;
  if (s[0] == ms[0])
    C(b, b, 5, s + 1), C(o, o, 7, s + 1);
  else
    C(b, b, 6, s);
}
void term_(obrt) {}
void term(obrt) {
  void *To = T(o, co), *Tm = T((char *)*--t, term_);
  D(O(T(00), To, To, To, To, To, To, To,
      O(00000, Tm, Tm, Tm, Tm, Tm, Tm, Tm, o)),
    t, 0);
}
// "b" term "a" term parse
void S(obrt, char *);
void reduce(obrt, char *s);
void crpp(obrt, char*s){ C(o, o, (r + 1) % 8, s); }
void S0(obrt, char *s) {
  void*Tcrpp = T(crpp);
  D(O(Tcrpp,Tcrpp,Tcrpp,Tcrpp,Tcrpp,Tcrpp,Tcrpp,Tcrpp, o), t, s);
}
void S(obrt, char *s) {
  void *To = T(o, co);
  D(O(T(S0), To, To, To, To, To, To, To,
      O(T(cr),
        T(ob,    "b", term, reduce),
        T(ob,    "a", term, reduce),
        T(ob, S, "a", term, reduce),
        T(ob, S, "c", term, reduce),
        T(ob, S, "d", term, reduce),
        T(ob, S, "b", term, reduce),
        T(ob, S, "g", term, reduce), o)), t, s);
}

void reduce7(obrt, char *s) { LOG, C(b, b, 0, s); }
void reduce6(obrt, char *s) { LOG, C(b, b, 0, s); }
void reduce5(obrt, char *s) { LOG; }
void reduce0(obrt, char *s) { LOG, C(b, b, 0, s); }

void reduce40(obrt, char *s) { LOG; }
void reduce4(obrt, char *s) {
  LOG, D(O(T(reduce40), Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, s);
}
void reduce(obrt, char *s) {
  D(O(T(reduce0), Tcr, Tcr, Tcr, //
      T(ob, reduce4), T(reduce5), T(reduce6), T(reduce7), o), t, s);
}
void sink(obrt, void *p1, void *p2, void *p3, void *p4) {
  void *ray = *--t;
  D(O(T(000, ray), T(001, ray), T(002, ray), T(003, ray), T(004, ray),
      T(005, ray), T(006, ray), T(007, ray), o),
    t, p1, p2, p3, p4);
}
void incrimental_input(obrt) {
  D(O(T(0), T(1), T(2), T(3), T(4), T(5), T(6), T(7), o), t, 0);
}
void p0(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p1(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p2(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p3(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p4(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p5(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p6(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void p7(obrt) { LOG, C(b, b, (r + 1) % 8, 0); }
void end(obrt, char *s) { printf("%.3lo %s\n", (long)t[-1], s); }
int main() {
  long b = 0, r = 4;
  void *o[] = {T(p0), T(p1), T(p2), T(p3), T(p4), T(p5), T(p6), T(p7), o};
  void (**t)() = T(ob);
  D(o, t, 0);
}
