#include "oars.h"
// clang-format off
#include<stdio.h>
char* names[0x10000]={};
#define Σ 100
static char buf[Σ];
static char* sword="NNSD";
static char* get_name(void*a) {
  char*n = names[(Q_t)a & (Q_t)0xFFFF];
  if (n) return n;
  if((Q_t)a < 151) return (snprintf(buf, Σ, "%lu", (Q_t)a), buf);
  if((Q_t)a >> 12 == (Q_t)buf >> 12 ||   //bss
     (Q_t)a >> 12 == (Q_t)sword >> 12)   //data
        return (snprintf(buf, Σ, "\"%s\"", (char*)a), buf);
  return ".";
}
void logn(OARS, const char*name) {
  {
    //static Q_t counter = 0;
    //if(counter++>31) exit(1);
  }
  {
    Q_t i = α, c = 0, m = 50;
    while(i && c < m+1) {
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
    Q_t i = ρ, c = 0, m = 100;
    while(i < 256 && c < m) {
      Q_t ψ   = ο[i++].Q;
      Q_t len = 0; for(Q_t i=0;i<7;i++) len+=ψ>>3*i&7;
      printf("₀%lo ", ψ);
      c += 4;
      while(len && c < m) {
        char *n = get_name(ο[i++].v);
        while(*n && c < m) printf("%c", *n), n++, c++;
        len--;
        if(c < m && len) printf(" "), c++;
      }
      if(c < m) printf(" "), c++;
    }
  }
  printf("\n");
}
