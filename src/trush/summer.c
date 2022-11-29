#include "obrt.h"
void cr(obrt, void *p1, void *p2, void *p3, void *p4) {
  o[r][-1](o[8], b, r, o[r] - 1, p1, p2, p3, p4);
}
static void *Tcr = T(cr);
void ob(obrt, void *p1, void *p2, void *p3, void *p4) {
  C(o, o, 4, p1, p2, p3, p4);
}

void one0(obrt) { C(o, o, 5, 1), C(o, o, 7, 0); }
void one(obrt) { D(B(T(one0), Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, 0); }
void add0(obrt) {
  long *sum = (long *)*--t;
  C(o, o, 5, *sum), C(o, o, 7, 0);
}
void add5(obrt, long v) {
  long *sum = (long *)*--t;
  *sum = *sum + (long)v;
}
void add4(obrt) { C(b, b, 0, 0); }
void add7(obrt) { C(b, b, 0, 0); }
void add(obrt) {
  long sum = 0;
  D(B(T(&sum, add0), Tcr, Tcr, Tcr, //
      T(add4), T(&sum, add5), Tcr, T(add7), o),
    t, 0);
}
void seven(obrt) {
  void *r0 = T(ob, one, one, one, one, one, one, one, add);
  D(B(r0, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, 0);
}
void two(obrt) {
  void *r0 = T(ob, one, one, add);
  D(B(r0, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, Tcr, o), t, 0);
}
void sink(obrt) {
  void *ray = *--t;
  t[-1]((void *[]){T(000, ray), T(001, ray), T(002, ray), T(003, ray),
                   T(004, ray), T(005, ray), T(006, ray), T(007, ray), o},
        b, r, t - 1);
}
#include <stdio.h>
void add_end(obrt, long sum) { printf("%.3lo %ld\n", (long)t[-1], sum); }
void parse_end(obrt, char *s) { printf("%.3lo %s\n", (long)t[-1], s); }
int main() {
  long o, b, r = o = b = 0;
  void (**t)() = T(ob, seven, one, seven, two, add, add_end, sink);
  D(o, t, 0);
}
