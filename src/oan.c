#include <stdio.h>
#define LOG printf("%s\n", __FUNCTION__);
void c(void **o, void **a, void **n) { LOG; 
  unsigned long ray = *--n;
  while (1) {
    unsigned long ψ = *o++;
    for (long i = ray + 1; i < 4  ; i++)    o += ψ >> 3 * i & 7;
    unsigned long words = ψ >> 3 * ray & 7; a  = o += words;
    for (long i = 0      ; i < ray; i++)    o += ψ >> 3 * i & 7;
    if (words) return ((void (*)()) * (a - 1))(o, a - 1, n);
  }
}
void c1(void **o, void **a, void **n) { *n++ = 1, c(o,a,n); }
void c2(void **o, void **a, void **n) { *n++ = 2, c(o,a,n); }

void end2(void **o, void **a, void **n) {puts(__FUNCTION__);}
void end1(void **o, void **a, void **n) {puts(__FUNCTION__);}
void end0(void **o, void **a, void **n) {puts(__FUNCTION__);}
void seven(void **o, void **a, void **n) {LOG; *n++ = 7, ((void (*)()) * (a - 1))(o, a - 1, n); }
int main() {LOG;
  void *n[2048];
  void **o = n + 2048;
  *--o = end2;
  *--o = end1;
  *--o = end0;
  *--o = 0111;
  *--o = seven;
  *--o = c1;
  *--o = 0020;
  c1(o, 0, n);
}
