#define NumOfArgs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...) ((void *)&(void *[]){NumOfArgs(__VA_ARGS__), __VA_ARGS__}[1])
#define Λ(a) ((long)(a)[-1])

#define LOG printf("%s\n", __FUNCTION__)
#include <assert.h>
#include <stdio.h>
void c(void **o, void **t, long i, void **n, long a);
//void t(void **o, void **t, long i, void **n, long a) {}
//void tina(void **o, void **t, long i, void **n, long a);
//void tina_(void **o, void **t, long i, void **n, long a) {
//  r(T(0, T("tina", t), 0, o), t, i, n, a);
//  r(T(0, T(tina, "a", t), 0, o), t, i, n, a);
//}
//void tina(void **o, void **t, long i, void **n, long a) {
//  run(T(0, T(tina_), 0, o), t, i, n, a);
//}
void e2(void **o, void **t, long i, void **n, long a) { LOG; n[2]--; }
void e1(void **o, void **t, long i, void **n, long a) { LOG; n[1]--; }
void e0(void **o, void **t, long i, void **n, long a) { LOG; n[0]--; }
void t1() {
  void**s;
  c(T(T(e0), T(e1), T(e2), 0), 0, 1, s=T(7,7,7), 0);
  assert((long)s[1] == 6);
}
void t2() {
  void**s;
  c(T(T(e0), T(e1), T(e2), 0), T(1, c), 0, s=T(7,7,7), 2);
  assert((long)s[1] == 6);
}
int main() {
  c(T(T(1, c),
      T(2, c),
      T(0, c),
      T(T(2,c),
        T(0,c),
        T(1,c),
        T(T(e0),
          T(e1),
          T(e2),
          0))), 0, 2, T(7,7,7), 0);
}
