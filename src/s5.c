#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
typedef void (*fun_t)();
#define D(o, s, op, os) LOG, a[-1](o, a - 1, r, s, op, os)
#define oars                                                                   \
  void (***o)(), void (**a)(), long r, void (***s)(), void **op, void **os
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(220000)
#include <stdio.h>
#include <unistd.h>
void cr(oars) { LOG, o[r][-1](o[-3], o[r] - 1, r, s, op, os); }
void c0(oars) { LOG, o[0][-1](o[-3], o[0] - 1, 0, s, op, os); }
void c1(oars) { LOG, o[1][-1](o[-3], o[1] - 1, 1, s, op, os); }
void pos(oars) { D(((void***)op)[0][-3] = o, ((void***)os)[0][-3] = s, op, os); }
void ob(oars) {
  D(B(o, T(c0, pos), T(c0, pos), T(c0, pos), T(c0, pos)),
    B(s, T(c0, pos), T(c0, pos), T(c0, pos), T(c0, pos)), op, os);
}
void so(oars) { D(s, o, op, os); }
void o(oars) {
  o = B(0, T(so), T(so), T(so), T(so));
  D(o, s, B(op, o), os);
}
void s(oars) {
  s = B(0, T(c1, so), T(so), T(so), T(so));
  D(o, s, op, B(os, s));
}
int main() {
  void (**a)() = T(ob, o, s);
  long r = 0;
  D(0, 0, 0, 0);
}
void mama(oars) { D(B(0, T(0), T(0), T(0)), s, op, os); }
// რა არის დინება?
// რას არ ვაკეთებ? რაღაცას ვაკლებ! მინდა ვთქვა არ გამომდის,
// მაგრამ ვიცი არ არის ეს სწორი. აბა არ გამოგვდის ვერ ვიტყვი!
// იმიტომ რომ ჩვენ ყოველთვის გვიმართლებს ჩევენ ყველაფერი გამოგვდის.
