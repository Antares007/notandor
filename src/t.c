#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...) ((void *)&VA(Nargs(__VA_ARGS__), __VA_ARGS__)[1])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#include <assert.h>
#include <stdio.h>
#define LOG printf("%.2ld %s\n", r, __FUNCTION__);

void c(void (***o)(), void (**a)(), long r, void **s) { LOG;
  o[r][(long)o[r][-1] - 1](o[-2], &o[r][(long)o[r][-1] - 1], r, s);
}
void one_(void (***o)(), void (**a)(), long r, void **s) { LOG;
  c(o, a, r, O(s, 1));
}
void one(void (***o)(), void (**a)(), long r, void **s) { LOG;
  a[-1](O(o, T(c), T(c, one_), T(c)), a - 1, r, s);
}
void add_(void (***o)(), void (**a)(), long r, void **s) { LOG;
  void**sp = s[-2];
  c(o, a, r, O(sp[-2], (long)sp[0] + (long)s[0]));
}
void add(void (***o)(), void (**a)(), long r, void **s) { LOG;
  a[-1](O(o, T(c), T(add_), T(c)), a - 1, r, s);
}

void thankyouGod(void (***a)()) {}

void e0(void(***o)(), void(**a)(), long r, void **s) { printf("%s\n", __FUNCTION__); }
void e1(void(***o)(), void(**a)(), long r, void **s) { printf("%p %s\n", s[0], __FUNCTION__); }
void e2(void(***o)(), void(**a)(), long r, void **s) { printf("%s\n", __FUNCTION__); }
int main() {
  void (***o)() = O(O(0,
                      T(e0),
                      T(e1),
                      T(e2)),
                        T(c),
                        T(c,one,one,add,one,add,one,add,one,add,one,add,one,add),
                        T(c));
  c(o, 0, 1, 0);
}
