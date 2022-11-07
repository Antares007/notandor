typedef unsigned long Q_t;
#include <assert.h>
#define OARS struct s_t**ο, Q_t*α, Q_t*ρ, struct s_t**σ, Q_t ξ
#define oars             ο,     α,     ρ,             σ,     ξ
typedef struct s_t {union{Q_t Q;void*v;void(*c)(OARS);};} s_t;
#define Ν(argo  ) void argo(OARS)
#define N(ξ, ...) { const void *ϋ[] = {__VA_ARGS__};                          \
                    Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                    while (size) ο[ξ][--α[ξ]].v = (void*)ϋ[--size]; }
#define S(... ) { const void *ϋ[] = {__VA_ARGS__};                          \
                  Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                  for (Q_t i=0; i<size; i++) σ[ξ][ρ[ξ]++].v = (void*)ϋ[i]; }
#define D       σ[ξ][--ρ[ξ]].c(oars)

Ν(cont) {
  Q_t nextξ = σ[ξ][--ρ[ξ]].Q; assert(ξ < 8);
  while(1) {
    Q_t ψ = ο[ξ][α[ξ]++].Q; assert(0 < ψ && ψ < 0100000000);
    Q_t nextξcount = ψ >> 3 * nextξ & 7;
    for(Q_t i = nextξ + 1; i < 8         ; i++) α[ξ] += ψ >> 3 * i & 7;
    for(Q_t i = 0        ; i < nextξcount; i++) σ[ξ][ρ[ξ]++].v = ο[ξ][α[ξ]++].v;
    for(Q_t i = 0        ; i < nextξ     ; i++) α[ξ] += ψ >> 3 * i & 7;
    if (nextξcount) return D;
  }
}
#include<stdio.h>
#define LOGN printf("%lu. %.2lu %.3lu %s\n", ξ, ρ[ξ], α[ξ], __FUNCTION__)
#undef  D
#define D LOGN, σ[ξ][--ρ[ξ]].c(oars)
Ν(B     ) { S(ξ, cont) D; }
Ν(V     ) { ρ[ξ]--, D; }
Ν(O     ) { D; }
Ν(T_    ) { }
Ν(T     ) { N(ξ, 020, σ[ξ][--ρ[ξ]].v, T_) D; }
Ν(ε     ) { D; }
Ν(Sa    );
Ν(Sa_   ) { S("b", T, O, "a", T) D; }
Ν(Sa    ) { N(ξ, 010, Sa_) S(Sa, V) D; }
Ν(eOt_  ) { S(ε, O, "s", T) D; }
Ν(eOt   ) { N(ξ, 010, eOt_) S(eOt, V) D; }
Ν(sOa_  ) { S("s", T, O, "a", T) D; }
Ν(sOa   ) { N(ξ, 010, sOa_) S(sOa, V) D; }
Ν(eOtsOa_){ S(eOt, sOa) D; }
Ν(eOtsOa) { N(ξ, 010, eOtsOa_) S(eOtsOa, V) D; }
Ν(parse ) { S("ssss", 4, 2, B, eOtsOa) D; }
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
Ν(how   ) { S(parse) D; }
Ν(e7    ) {LOGN;}
Ν(e6    ) {LOGN;}
Ν(e5    ) {LOGN;}
Ν(e4    ) {LOGN;}
Ν(e3    ) {LOGN;}
Ν(e2    ) {LOGN;}
Ν(e1    ) {LOGN;}
Ν(e0    ) {LOGN;}
Ν(fmap  ) { D; }
Ν(m2    ) { D; }
Ν(one   ) { N(ξ, 030, 1, 1, cont) D; }
Ν(sum   ) { D; }
Ν(dot   ) { D; }
int main() {
  s_t b[4+4][256];
  s_t*ο[4] = {b[0], b[1], b[2], b[3], };
  Q_t α[4] = {256,  256,  256,  256,  };
  Q_t ρ[4] = {0,    0,    0,    0,    };
  s_t*σ[4] = {b[4], b[5], b[6], b[7], };
  Q_t ξ    = 0;
  N(0, 01111, e3, e2, e1, e0)
  //S(B, one, one, one, sum) D;
  S(parse) D;
}
// (p ‘orelse‘ q) j = unite (p j) (q j)   e.g., assuming that the input is "ssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3}

// (p ‘thenS‘ q) j = union (map q (p j))  e.g., assuming that the input is "ssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
