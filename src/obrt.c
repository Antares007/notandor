#include "obrt.h"
#define LOG printf("%ld %s %s\n", (long)r, s, __FUNCTION__), usleep(100000)
#include <stdio.h>
#include <unistd.h>

void cr(obrt, void *p1, void *p2, void *p3, void *p4) {
  C(o, b, r, p1, p2, p3, p4); // o[r][-1](o[8], b, r, o[r] - 1, p1, p2, p3, p4);
}
static void *Tcr = T(cr);
void ob(obrt, void *p1, void *p2, void *p3, void *p4) {
  C(o, o, 4, p1, p2, p3, p4); // o[4][-1](o[8], b, 4, o[4] - 1, p1, p2, p3, p4);
}
void term0(obrt, char *s) {
  LOG;
  char *ms = (char *)*--t;
  if (s[0] == ms[0])
    C(b, b, 5, s + 1), C(o, o, 7, s + 1);
  else
    C(b, b, 6, s);
}
void term(obrt, char *s) {
  char *ms = (void *)*--t;
  D(B(T(ms, term0), Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, s);
}
// "b" term "a" term parse
void S(obrt, char *);
void reduce(obrt, char *);
void S0(obrt, char *s) {
  LOG;
  t = T(ob, "b", term, reduce), t[-1](o, b, r, t - 1, s);
  printf(">>> ");
  LOG;
  t = T(ob, S, "a", term, reduce), t[-1](o, b, r, t - 1, s);
}
void S(obrt, char *s) {
  D(B(T(S0), Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, s);
}

void reduce7(obrt, char *s) {
  LOG;
  C(b, b, 0, s);
}
void reduce6(obrt, char *s) {
  LOG;
  C(b, b, 0, s);
}
void reduce5(obrt, char *s) { LOG; }
void reduce0(obrt, char *s) {
  LOG;
  C(b, b, 0, s);
}

void reduce40(obrt, char *s) { LOG; }
void reduce4(obrt, char *s) {
  LOG;
  D(B(T(reduce40), Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, s);
}
void reduce(obrt, char *s) {
  D(B(T(reduce0), Tcr, Tcr, Tcr, //
      T(ob, reduce4), T(reduce5), T(reduce6), T(reduce7), o),
    t, s);
}

void parse4(obrt, char *s) {
  LOG;
  C(b, b, 0, s);
}
void parse5(obrt, char *s) { LOG; }
void parse6(obrt, char *s) { LOG; }
void parse7(obrt, char *s) {
  LOG;
  C(b, b, 0, s);
}
void parse(obrt, char *s) {
  D(B(Tcr, Tcr, Tcr, Tcr, //
      T(parse4), T(parse5), T(parse6), T(parse7), o),
    t, s);
}
void sink(obrt, void *p1, void *p2, void *p3, void *p4) {
  void *ray = *--t;
  D(B(T(000, ray), T(001, ray), T(002, ray), T(003, ray), T(004, ray),
      T(005, ray), T(006, ray), T(007, ray), o),
    t, p1, p2, p3, p4);
}
void end(obrt, char *s) { printf("%.3lo %s\n", (long)t[-1], s); }
int main() {
  long o, b, r = o = b = 0;
  void (**t)() = T(ob, S, parse, end, sink);
  D(o, t, "baaa");
}
