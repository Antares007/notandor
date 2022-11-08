// clang-format off
#include "os_log.h"
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
Ν(B         ) { S(α, 1, C) D; }
Ν(V         ) { ρ--, D; }
Ν(O         ) { D; }
Ν(T_        ) { }
Ν(T         ) { N(020, σ[--ρ].v, T_) D; }
Ν(e         ) { S(1, C) D; }
Ν(Sa        );
Ν(Sa_       ) { S("b", T, O, "a", T) D; }
Ν(Sa        ) { N(010, Sa_) S(Sa, V) D; }
Ν(eOs_      ) { S(e, O, "s", T) D; }
Ν(eOs       ) { N(010, eOs_) S(B, eOs, V) D; }
Ν(eOseOs_   ) { S(eOs, eOs) D; }
Ν(eOseOs    ) { N(010, eOseOs_) S(eOseOs, V) D; }
Ν(parse     ) { S("ssss", 4, 2, eOs) D; }
// clang-format off
               G(0,
B           ,L)G(L,
V           ,L)G(L,
O           ,L)G(L,
T_          ,L)G(L,
T           ,L)G(L,
eOs_        ,L)G(L,      
eOs         ,L)G(L, 
eOseOs_     ,L)G(L,
eOseOs      ,L)G(L,
parse       ,L)G(L,
e           ,L)void init(){L();}
/*
parse                           main   01 251   1111....
. . . eOs                       parse  04 251   1111....
. . . B eOs V                   eOs    06 249   010eOs_ 1111....
. . . B                         V      04 249   010eOs_ 1111....
. . . . . .                     B      06 249   010eOs_ 1111....
. . . . eOs_                    C      05 251   1111....
. . . . e O s T                 eOs_   08 251   1111....
. . . . e O                     T      06 248   020sT_ 1111....
. . . . e                       O      05 248   020sT_ 1111....
. . . . . .                     e      06 248   020sT_ 1111....
. . . . s T_                    C      06 251   1111....
Grammar rules are expanded from right to left.

Tokens are consumed from left to right.

Backtracking is used to expand all alternative right-hand-sides of grammar
rules in order to identify all possible parses.

Top-down recognizers can be implemented as a set of mutually recursive
processes which search for parses using a top-down expansion of the grammar
rules defining non-terminals while looking for matches of terminals with
tokens on the input.

Recognizers are functions which take an index j as argument and which return
a set of indices as result. Each index in the result set corresponds to the
position at which the recognizer successfully finished recognizing a sequence
of tokens that began at position j.

An empty result set indicates that the recognizer failed to recognize any
sequence beginning at j. Multiple results are returned for ambiguous input.

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
  init();
  s_t ο[256];
  Q_t α = 256;
  Q_t ρ = 0;
  s_t σ[256];
  N(01111, e3, e2, e1, e0)
  S(parse) D;
}
