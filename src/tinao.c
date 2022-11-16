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
void e2(void **t, long i, void **n, long a, void **o) { LOG; n[2]--; }
void e1(void **t, long i, void **n, long a, void **o) { LOG; n[1]--; }
void e0(void **t, long i, void **n, long a, void **o) { LOG; n[0]--; }
int main() {
  void**s;
  c(0, 1, s=T(7,7,7), 0,
    T(T(1, c),
      T(2, c, 1, c, 0, c, 2, c, 1, c, 0, c),
      T(0, c),
      T(T(2,c),
        T(0,c),
        T(1,c),
        T(T(e0),
          T(e1),
          T(e2),
          0))));
}
