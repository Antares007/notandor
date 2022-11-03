#include "o.h"
// clang-format off
static char* names[0x10000]={};
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(name_fun,__LINE__)
#define E(t,n,h) N(n); static void h() { names[(Q_t)n & (Q_t)0xFFFF] = #n; t(); }
static void nop(){}
E(nop,
B       ,L)E(L,
t_      ,L)E(L,
t       ,L)E(L,
oe      ,L)E(L,
Bb      ,L)E(L,
Abba    ,L)E(L,
Sa_     ,L)E(L,
Sa      ,L)E(L,
show    ,L)E(L,
var     ,L)E(L,
c2      ,L)E(L,
c1      ,L)E(L,
c0      ,L)E(L,
e2      ,L)E(L,
e1      ,L)E(L,
e0      ,L)void init_logn(){L();}
#undef E
#undef L
char* get_name(void*addr) { char*n = names[(Q_t)addr & (Q_t)0xFFFF]; return n ? n : "."; }
#include<stdio.h>
void logn(OARS, const char*name) {
  {
    Q_t i = α, c = 0, m = 44;
    while(i && c < m) {
      char*n = get_name(σ[--i].v);
      while(*n) n++, c++;
      c++;
    }
    c = 0;
    while(i < α && c < m) {
      char*n = get_name(σ[i++].v);
      while(*n && c < m) printf("%c", *n), n++, c++;
      if (c < m) printf(" "), c++;
    }
    while(c < m) printf(" "), c++;
  }
  printf("  ");
  {
    Q_t i = 0;
    while(name[i] &&
          i < 7) printf("%c", name[i++]);
    while(i < 7) printf(" "), i++;
    printf("%.2lu %.3lu", α, ρ);
  }
  printf("  ");
  {
    Q_t i = ρ, c = 0, m = 80;
    while(i < 255 && c < m) {
      Q_t ψ   = ο[i++].Q;
      Q_t len = (ψ>>6&7)+(ψ>>3&7)+(ψ&7);
      printf("%.3lo ", ψ);
      c += 4;
      while(len && c < m) {
        char *n = get_name(ο[i++].v);
        while(*n && c < m) printf("%c", *n), n++, c++;
        if(c < m) printf(" "), c++;
        len--;
      }
    }
  }
  printf("\n");
}
