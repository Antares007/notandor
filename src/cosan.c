#include <stdio.h>
#include <assert.h>
#define LOG printf("%ld %s\n", s, __FUNCTION__) // c(o,s) s(i,n)
typedef void (*c_t)(void**,void**);
void c3(void **on, void **n) { *on = 3; }
void c2(void **on, void **n) { *on = 2; }
void c1(void **on, void **n) {
  *on = 1; 
}
void c0(void **on, void **n) { *on = 0; }
void c(void **o, void **n) {
  unsigned long ray = *--n;
  unsigned long ψ = *o++;
  for (long i = ray + 1; i < 4; i++) o += ψ >> 3 * i & 7;
  long s = ψ >> 3 * ray & 7;
  c_t *a = (c_t*)o; o += s;
  for (long i = 0; i < ray; i++) o += ψ >> 3 * i & 7;
  for (long i = 0; i < s  ; i++) {
    void *b[128];
    void**on = b + sizeof(b) / sizeof(*b);
    assert(on-b == 128);
    *--on = 4;
    void **rez = on;
    *--on = c0;
    *--on = c1;
    *--on = c2;
    *--on = c3;
    *--on = 01111;
    a[i](on, n);
    assert(((long)*rez)==1);
    if (((long)*rez) != ray) return *n++ = *rez, c(o, n);
  } 
  if(!s) *n++ = ray, c(o, n);
}
void end2(void **o, long s, void **a, void **n) { puts(__FUNCTION__); }
void end1(void **o, long s, void **a, void **n) { puts(__FUNCTION__); while(*--n != end1) printf("%p\n", *n); }
void end0(void **o, long s, void **a, void **n) { puts(__FUNCTION__); }

void seven(void **o, void **n) {
  assert(o);
  *n++ = 7, *n++ = 1, c(o, n);
}
int main() {
  printf("%ld\n",
    sizeof((void*[]){
           (void*[]){
              (void*[]){},
              (void*[]){},
              (void*[]){},
           },
           (void*[]){},
           (void*[]){},
    })/sizeof(void*));
  void *b[2048];
  void **n = b;
  void **o = b + 2048;
  *--o = end2;
  *--o = end1;
  *--o = end0;
  *--o = 0111;
  *--o = seven;
  *--o = seven;
  *--o = seven;
  *--o = seven;
  *--o = seven;
  *--o = seven;
  *--o = seven;
  *--o = 0070;
  *n++ = end1;
  *n++ = 1, c(o, n);
}
