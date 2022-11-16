#define NumOfArgs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...)                                                                 \
  ((void *)&(const void *[]){NumOfArgs(__VA_ARGS__), __VA_ARGS__}[1])
#define Λ(a) ((long)(a)[-1])

#define LOG printf("%s\n", __FUNCTION__)
#include <assert.h>
#include <stdio.h>
void c(void **t, long i, void **n, long a, void **o);

#include <string.h>
void term_(void **t, long i, void **n, long a, void **o) {
  const char *match_str = t[--a];
  const char *in = n[1];
  long len = n[2];
  long pos = n[3];
  if (pos < len && strcmp(match_str, &in[pos]) <= 0 &&
      (in[pos] == match_str[0]))
    assert(a == 0), c(t, i, T(n, in, len, pos + strlen(match_str)), a, o);
  else
    assert(a == 0), c(0, 0, n, 0, o);
}
void term(void **t, long i, void **n, long a, void **o) {
  const char *match_str = t[--a];
  c(t, i, n, a, T(0, T(match_str, term_), 0, o));
}
void ain_(void **t, long i, void **n, long a, void **o) {
  c(t, i, n, a, T(0, T("a", term), 0, o));
  c(t, i, n, a, T(0, T("i", term), 0, o));
  c(t, i, n, a, T(0, T("n", term), 0, o));
}
void ain(void **t, long i, void **n, long a, void **o) {
  c(t, i, n, a, T(0, T(ain_), 0, o));
}
void tina(void **t, long i, void **n, long a, void **o);
void tina_(void **t, long i, void **n, long a, void **o) {
  c(t, i, n, a, T(0, T("t", term), 0, o));
  c(t, i, n, a, T(0, T(tina, ain), 0, o));
}
void tina(void **t, long i, void **n, long a, void **o) {
  c(t, i, n, a, T(0, T(tina_), 0, o));
}
void e2(void **t, long i, void **n, long a, void **o) { LOG; }
void e1(void **t, long i, void **n, long a, void **o) { LOG; printf("%p\n", n[3]); }
void e0(void **t, long i, void **n, long a, void **o) { }
int main() {
  c(T(tina), 1, T(0, "tina", 4, 0), 1,
    T(T(e0),
      T(e1),
      T(e2),
      0));
}
