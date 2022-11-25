#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
#define D(o, s, op, os) LOG, a[-1](o, a - 1, r, s, op, os)
#define oars                                                                   \
  void (***o)(), void (**a)(), long r, void (***s)(), void **op, void **os
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(220000)
#include <stdio.h>
#include <unistd.h>
void ps(oars) { puts((void *)*--a), D(o, s, op, os); }
void cr(oars) { LOG, o[r][-1](o[-3], o[r] - 1, r, s, B(op, o), B(os, s)); }
void c0(oars) { cr(o, a, 0, s, op, os); }
void c1(oars) { cr(o, a, 1, s, op, os); }
void so(oars) { D(os[0], op[0], os, op); }
void o(oars) {
  o = B(0, T("hi o", ps, so), T("send next", ps, so), T(so), T(so));
  D(o, s, op, os);
}
void s(oars) {
  s = B(0, T(c1, "hello s", ps, so), T("take it", ps, so), T(so), T(so));
  D(o, s, op, os);
}
int main() {
  void (**a)() = T(cr, o, s);
  long r = 0;
  D(0, 0, 0, 0);
}
void mama(oars) { D(B(0, T(0), T(0), T(0)), s, op, os); }
// რა არის დინება?
// რას არ ვაკეთებ? რაღაცას ვაკლებ! მინდა ვთქვა არ გამომდის,
// მაგრამ ვიცი არ არის ეს სწორი. აბა არ გამოგვდის ვერ ვიტყვი!
// იმიტომ რომ ჩვენ ყოველთვის გვიმართლებს ჩევენ ყველაფერი გამოგვდის.
