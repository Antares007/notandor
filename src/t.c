#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...) ((void *)&VA(Nargs(__VA_ARGS__), __VA_ARGS__)[1])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#include <assert.h>
#include <stdio.h>
#define LOG printf("%.2ld %s\n", r, __FUNCTION__);

void c(void (***o)(), void (**a)(), long r, void **s) {
  LOG;
  o[r][(long)o[r][-1] - 1](o[-2], &o[r][(long)o[r][-1] - 1], r, s);
}
void one_(void (***o)(), void (**a)(), long r, void **s) {
  LOG;
  c(o, a, r, s);
}
void one(void (***o)(), void (**a)(), long r, void **s) {
  LOG;
  a[-1](O(o, T(c), T(c), T(c)), a - 1, r, s);
}

void thankyouGod(void (***a)()) {}

void e0(void **o, long n, long m, void **s) { printf("%s\n", __FUNCTION__); }
void e1(void **o, long n, long m, void **s) { printf("%s\n", __FUNCTION__); }
void e2(void **o, long n, long m, void **s) { printf("%s\n", __FUNCTION__); }
int main() {
  void (***o)() = O(0, T(e0), T(e1), T(e2));
  c(o, 0, 2, 0);
}
