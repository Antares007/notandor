typedef unsigned long Q_t;
#include <assert.h>
#define OARS struct s_t*ο, Q_t α, Q_t ρ, struct s_t*σ
#define oars            ο,     α,     ρ,            σ
typedef struct s_t {union{Q_t Q;void*v;void(*c)(OARS);};} s_t;
#define Ν(argo  ) void argo(OARS)
#define N(...   ) { const void *ϋ[] = {__VA_ARGS__};                          \
                    Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                    while (size) ο[--α].v = (void*)ϋ[--size]; }
#define S(...   ) { const void *ϋ[] = {__VA_ARGS__};                          \
                    Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                    for (Q_t i=0; i<size; i++) σ[ρ++].v = (void*)ϋ[i]; }
#define D         (--ρ, σ[ρ].c(oars))
Ν(C) {
  Q_t n = σ[--ρ].Q;
  while(1) {
    Q_t ψ = ο[α++].Q;
    Q_t swords = ψ >> 3 * n & 7;
    for(Q_t i = n + 1; i < 8     ; i++) α += ψ >> 3 * i & 7;
    for(Q_t i = 0    ; i < swords; i++) σ[ρ++].v = ο[α++].v;
    for(Q_t i = 0    ; i < n     ; i++) α += ψ >> 3 * i & 7;
    if (swords) return D;
  }
}
#include<stdio.h>
#define LOGN printf("%.2lu %.3lu %s\n", ρ, α, __FUNCTION__)
#undef  D
#define D LOGN, (--ρ, σ[ρ].c(oars))
Ν(B         ) { S(B, 1, C) D; }
Ν(V         ) { ρ--, D; }
Ν(O         ) { D; }
Ν(T_        ) { }
Ν(T         ) { N(020, σ[--ρ].v, T_) D; }
Ν(ε         ) { D; }
Ν(Sa        );
Ν(Sa_       ) { S("b", T, O, "a", T) D; }
Ν(Sa        ) { N(010, Sa_) S(Sa, V) D; }
Ν(eOs_      ) { S(ε, O, "s", T) D; }
Ν(eOs       ) { N(010, eOs_) S(eOs, V) D; }
Ν(eOseOs_   ) { S(eOs, eOs) D; }
Ν(eOseOs    ) { N(010, eOseOs_) S(eOseOs, V) D; }
Ν(parse     ) { S("ssss", 4, 2, B, eOseOs) D; }
/*
  V V
  V O
  V T
  O V
  O T
  T V
  T O
  T T
  V   V   V   V   V   V
  O V O     O     O T O
  T   T   T   T   T   T
*/
Ν(e3        ) {LOGN;}
Ν(e2        ) {LOGN;}
Ν(e1        ) {LOGN;}
Ν(e0        ) {LOGN;}
int main() {
  s_t ο[256];
  Q_t α = 256;
  Q_t ρ = 0;
  s_t σ[256];
  N(01111, e3, e2, e1, e0)
  S(parse) D;
}
