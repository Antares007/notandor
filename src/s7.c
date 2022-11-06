typedef unsigned long Q_t;
#include <assert.h>
#define OARS struct s_t*ο, Q_t*ρ, Q_t α, struct s_t**σ, Q_t ξ
#define oars            ο,     ρ,     α,             σ,     ξ
typedef struct s_t {union{Q_t Q;void*v;void(*c)(OARS);};} s_t;
#define Ν(argo) void argo(OARS)
#define N(... ) { const void *ϋ[] = {__VA_ARGS__};                          \
                  Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                  while (size) ο[--α].v = (void*)ϋ[--size]; }
#define S(... ) { const void *ϋ[] = {__VA_ARGS__};                          \
                  Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                  for (Q_t i=0; i<size; i++) σ[ξ][ρ[ξ]++].v = (void*)ϋ[i]; }
#define D       σ[ξ][--ρ[ξ]].c(oars)

Ν(cont) {
  ξ = σ[ξ][--ρ[ξ]].Q; assert(ξ < 8);
  while(1) {
    Q_t ψ = ο[α++].Q; assert(ψ-1 < 07777777);
    Q_t sword_count = ψ >> 3 * ξ & 7;
    for(Q_t i = ξ + 1; i < 8          ; i++) α += ψ >> 3 * i & 7;
    for(Q_t i = 0    ; i < sword_count; i++) σ[ξ][ρ[ξ]++].v = ο[α++].v;
    for(Q_t i = 0    ; i < ξ          ; i++) α += ψ >> 3 * i & 7;
    if (sword_count) return σ[ξ][--ρ[ξ]].c(oars);
  }
}
#include<stdio.h>
#define LOGN printf("%lu. %.2lu %.3lu %s\n", ξ, ρ[ξ], α, __FUNCTION__)

Ν(sWord0); Ν(sWord1); Ν(sWord2);
Ν(sWord0) { N(0111, sWord2, sWord1, sWord0) S(1, cont) LOGN, D; }
Ν(sWord1) { N(0111, sWord2, sWord1, sWord0) S(2, cont) LOGN, D; }
Ν(sWord2) { N(0111, sWord2, sWord1, sWord0) S(0, cont) LOGN, D; }
Ν(e2) {LOGN;}
Ν(e1) {LOGN;}
Ν(e0) {LOGN;}
int main() {
  s_t b[8][256];
  s_t*ο    = b[0];
  Q_t α    = 256;
  Q_t ρ[8] = {0,0,0,0,0,0,0,0};
  s_t*σ[8] = {b[1],b[2],b[3],b[4],b[5],b[6],b[7],};
  Q_t ξ    = 0;
  N(0x49, e2, e1, e0) S(sWord0) D;
}
