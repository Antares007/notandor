#include <stdio.h>
#define Σ 256
#define PLOG printf("%s\n", __FUNCTION__)
typedef struct pith {
  void *b[Σ*4];
  long  a;
} pith;

void mf() {}
void map_pith() {}

void end2(pith*o) {PLOG;}
void end1(pith*o) {PLOG;}
void end0(pith*o) {PLOG;}
void dot (pith*o);
void cont(pith*o) {

}
int main() {
  pith o;
  o.b[Σ*0+0] = end0; o.b[Σ*0+1] =  dot;
  o.b[Σ*1+0] = end1; o.b[Σ*1+1] =  dot;
  o.b[Σ*2+0] = end2; o.b[Σ*2+1] =  dot;
  o.b[Σ*3+0] =    1; o.b[Σ*3+1] = cont, o.a = 2;

  o.b;
}
