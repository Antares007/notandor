#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, 0, Nargs(__VA_ARGS__), __VA_ARGS__)[3])
typedef void (*fun_t)();
#define D(o, s, op, os) LOG, a[-1](o, a - 1, r, s, op, os)
#define oars                                                                   \
  void (***o)(), void (**a)(), long r, void (***s)(), void **op, void **os
#define LOG printf("%ld %s\n",r , __FUNCTION__), usleep(220000)
#include <stdio.h>
#include <unistd.h>
void cr(oars) { LOG, o[r][-1](o[-3], o[r]-1, r, s, op, os); }
void stop(oars) { LOG; }
void show(oars) { D(B(o, T(stop)), s, op, os); }
int main() {
  void (**a)() = T(show);
  long r = 0;
  D(0, 0, 0, 0);
}
void mama(oars) { D(B(0, T(0), T(0), T(0)), s, op, os); }
// რა არის დინება?
// რას არ ვაკეთებ? რაღაცას ვაკლებ! მინდა ვთქვა არ გამომდის,
// მაგრამ ვიცი არ არის ეს სწორი. აბა არ გამოგვდის ვერ ვიტყვი!
// იმიტომ რომ ჩვენ ყოველთვის გვიმართლებს ჩევენ ყველაფერი გამოგვდის.
