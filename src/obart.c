#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(__VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define obart void (****o)(), void (****b)(), long a, long r, void (**t)()
#define V(...) ((void *)(void *[]){__VA_ARGS__})
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define LOG printf("%ld %ld %s\n", a, r, __FUNCTION__), usleep(100000)
// დაიწყე ერთით და ყოველ ერთ წუთში დაუმატე ერთი და დაბეჭდე.
void end(obart) { printf("%.3lo %p\n", (long)t[-1], o); }
void cr(obart) { o[a][r][-1](o[2], b, a, r, o[a][r] - 1); }
void ob(obart) { assert(!b), LOG, o[0][3][-1](o[2], o, 0, 3, o[0][3] - 1); }

void ps(obart) {
  puts((char *)*--t);
  t[-1](o, b, a, r, t - 1);
}
void term1(obart) {
  LOG;
  b[0][1][-1](b[2], b, 0, 1, b[0][1] - 1);
};
void term3(obart) {
  LOG;
  b[0][1][-1](b[2], b, 0, 1, b[0][1] - 1);
};
void term(obart) {
  --t;
  LOG, t[-1](V(V(T(cr), T(cr), T(cr), T(cr)), V(T(0), T(term1), T(0), T(term3)),
               o),
             b, a, r, t - 1);
}
// "b" term "a" term parse
void S(obart) {
  //  T("b", term);
  //  T(S, "a", term);
}
void parse1(obart) { LOG, b[1][1][-1](b[2], b, 1, 1, b[1][1] - 1); }
void parse3(obart) { LOG, b[1][3][-1](b[2], b, 1, 3, b[1][3] - 1); }
void parse(obart) {
  LOG, t[-1](V(V(T(cr), T(parse1), T(cr), T(parse3)),
               V(T(cr), T(cr), T(cr), T(cr)), o),
             b, a, r, t - 1);
}

int main() {
  void *o = V(V(T(000, end), T(001, end), T(002, end), T(003, end)),
              V(T(010, end), T(011, end), T(012, end), T(013, end)), 9);
  void (**t)() = T(ob, "b", term, "a", term, parse);
  t[-1](o, 0, 0, 1, t - 1);
}
