#include <stdio.h>
#define LOG printf("%s\n", __FUNCTION__)
void c(void **o, long s, void **a, void **n) {
  unsigned long ray = *--n;
  unsigned long ψ = *o++;
  for (long i = ray + 1; i < 4; i++) o += ψ >> 3 * i & 7;
  a = o, o += s = ψ >> 3 * ray & 7;
  for (long i = 0; i < ray; i++) o += ψ >> 3 * i & 7;
  if (s) LOG, ((void (*)()) * (a + s - 1))(o, s - 1, a, n);
  else *n++ = ray, c(o, s, a, n);
}
void end2(void **o, long s, void **a, void **n) { puts(__FUNCTION__); }
void end1(void **o, long s, void **a, void **n) { puts(__FUNCTION__); while(*--n != end1) printf("%p\n", *n); }
void end0(void **o, long s, void **a, void **n) { puts(__FUNCTION__); }

void seven(void **o, long s, void **a, void **n) { *n++ = 7, *n++ = 1, c(o, s, a, n); }
int main() {
  void *b[2048];
  void **n = b;
  void **o = b + 2048;
  *--o = end2;
  *--o = end1;
  *--o = end0;
  *--o = 0111;
  *--o = seven;
  *--o = 0010;
  *n++ = end1;
  *n++ = 1, c(o, 0, 0, n);
}
