// clang-format off
#define Nargs(...)      (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...)          ((const void *[]){__VA_ARGS__})
#define T(...)          ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...)       ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
#define D(o, s, op, os) LOG, a[-1](o, a - 1, r, s, op, os)
#define oars            void (***o)(), void (**a)(), long r, void (***s)(), void **op, void **os
#define LOG             printf("%ld %s\n", r, __FUNCTION__), usleep(220000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
void ps(oars) { puts((void *)*--a), D(o, s, op, os); }
void cr(oars) { LOG, o[r][-1](o[-3], o[r] - 1, r, s, op, os); }
void bo(oars) { LOG, o[r][-1](o[-3], o[r] - 1, r, s, B(op, o), B(os, s)); }
void c0(oars) { cr(o, a, 0, s, op, os); }
void c1(oars) { cr(o, a, 1, s, op, os); }
void soos(oars) { D(os[0], op[0], os, op); }
void osop(oars) { D(o, s, op, os); }
void o(oars) {
  D(B("producer", T("hi o", ps, soos), T("send next", ps, soos), T(soos), T(soos)), s, op, os);
}
void s(oars) {
  D(o, B("consumer", T(c1, "hello s", ps, soos), T("take it", ps, soos), T(soos), T(soos)), op, os);
}
void m(oars) {
  D(B(o, T("map p0", ps, osop), T("map p1", ps, osop), T("map p2", ps, osop), T("map p3", ps, osop)),
    B(s, T("map c0", ps, osop), T("map c1", ps, osop), T("map c2", ps, osop), T("map c3", ps, osop)), op, os);
}
int main() {
  void (**a)() = T(bo, m, o, s);
  long r = 0;
  D(1, 1, 0, 0);
}
void mama(oars) { D(B(0, T(0), T(0), T(0)), s, op, os); }
// რა არის დინება?
// რას არ ვაკეთებ? რაღაცას ვაკლებ! მინდა ვთქვა არ გამომდის,
// მაგრამ ვიცი არ არის ეს სწორი. აბა არ გამოგვდის ვერ ვიტყვი!
// იმიტომ რომ ჩვენ ყოველთვის გვიმართლებს ჩევენ ყველაფერი გამოგვდის.
