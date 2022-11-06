typedef unsigned long Q_t;
#include <assert.h>
#define OARS struct s_t*ο, Q_t*α, Q_t ρ, struct s_t**σ, Q_t ι
#define oars            ο,     α,     ρ,             σ,     ι
typedef struct s_t {union{Q_t Q;void*v;void(*c)(OARS);};} s_t;
#define Ν(argo) void argo(OARS)
#define N(... ) { const void *va_args[] = {__VA_ARGS__};                  \
                  Q_t size = sizeof(va_args)/sizeof(*va_args);            \
                  while (size) ο[--ρ].v = (void*)va_args[--size]; }
#define S(... ) { const void *va_args[] = {__VA_ARGS__};                  \
                  Q_t size = sizeof(va_args)/sizeof(*va_args);            \
                  for (Q_t i=0; i<size; i++)                              \
                    σ[ι][α[ι]++].v = (void*)va_args[i]; }
#define D       σ[ι][--α[ι]].c(oars)
Ν(cont) {
  ι = σ[ι][--α[ι]].Q; assert(ι < 8);
  while(1) {
    Q_t ψ = ο[ρ++].Q; assert(ψ <= 07777777);
    Q_t ray_no_count = ψ >> 3 * ι & 7;
    for(Q_t i = ι + 1; i < 8           ; i++) ρ += ψ >> 3 * i & 7;
    for(Q_t i = 0    ; i < ray_no_count; i++) σ[ι][α[ι]++].v = ο[ρ++].v;
    for(Q_t i = 0    ; i < ι           ; i++) ρ += ψ >> 3 * i & 7;
    if (ray_no_count) return σ[ι][--α[ι]].c(oars);
  }
}
#include<stdio.h>
#define LOGN printf("%lu. %s\n", ι, __FUNCTION__)

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
  Q_t α[8] = {0,0,0,0,0,0,0,0};
  s_t*σ[8] = {b[1],b[2],b[3],b[4],b[5],b[6],b[7],};
  Q_t ρ    = 256;
  Q_t ι    = 0;
  N(0x49, e2, e1, e0) S(sWord0) D;
}
