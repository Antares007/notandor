// clang-format off
#define Nargs(...)      (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...)          ((const void *[]){__VA_ARGS__})
#define T(...)          ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...)       ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
#define D(o, s, op, os) a[-1](o, a - 1, r, s, op, os)
#define oars            void (***o)(), void (**a)(), long r, void *s, void **op, void **os
#define LOG             printf("%ld %s\n", r, __FUNCTION__), usleep(777777)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
void ps   (oars) { printf("%s\n", (char *)*--a), usleep(555555), D(o, s, op, os); }
void cr   (oars) { o[r][-1](o[-3], o[r] - 1, r, s, op, os); }
void bo   (oars) { LOG, o[r][-1](o[-3], o[r] - 1, r, s, B(op, o), B(os, s)); }
void c0   (oars) { cr(o, a, 0, s, op, os); }
void c1   (oars) { cr(o, a, 1, s, op, os); }
void c2   (oars) { cr(o, a, 2, s, op, os); }
void soos (oars) { D(os[0], op[0], os, op); }
void osop (oars) { D(o, s, op, os); }
void o    (oars) {
  D(B(o,
      T("o0", ps, soos), T("o1", ps, soos), T("o2", ps, soos), T("o3", ps, soos)), s, op, os); }
void s    (oars) {
  D(o,
    B(0,
      T(c1, "s0", ps, soos), T("s1", ps, soos), T("s2", ps, soos), T("s3", ps, soos)), op, B(os, s)); }
long cout=0;
void bstop(oars) {
  if(cout++>3)
    r = 0, op = op[-3], D(s, o, os, op);
  else
    D(s,o,os,op);
}
void b    (oars) {
  D(o,
    B(0,
      T(c1, "b0", ps, soos), T("b1", ps, bstop), T("b2", ps, soos), T("b3", ps, soos)), op, B(os, s)); }
void m    (oars) {
  D(B(o, T("map p0", ps, osop), T("map p1", ps, osop), T("map p2", ps, osop), T("map p3", ps, osop)),
    B(s, T("map c0", ps, osop), T("map c1", ps, osop), T("map c2", ps, osop), T("map c3", ps, osop)), op, os);
}
void term (oars) { 
  D(o,
    B(s, T(c1, soos),T(soos),T(soos)), op, os);
}
void S    (oars);
void S_   (oars) { // take it called by producer with input
  D(o,
    B(s, T(c0),T(bo,    "a", term),T(soos)), op, os);
  D(o,
    B(s, T(c0),T(bo, S, "a", term),T(soos)), op, os);
}
void S    (oars) {
  D(o,
    B(s, T(c1, soos),T(S_),T(soos)), op, os);
}
int main() {
  void (**a)() = T(bo, o, b, s);
  long r = 0;
  D(1, 0, 0, 0);
}
void mama(oars) { D(B(0, T(0), T(0), T(0)), s, op, os); }
// რა არის დინება?
// რას არ ვაკეთებ? რაღაცას ვაკლებ! მინდა ვთქვა არ გამომდის,
// მაგრამ ვიცი არ არის ეს სწორი. აბა არ გამოგვდის ვერ ვიტყვი!
// იმიტომ რომ ჩვენ ყოველთვის გვიმართლებს ჩევენ ყველაფერი გამოგვდის.
