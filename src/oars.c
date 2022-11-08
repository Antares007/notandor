// clang-format off
#include "oars_log.h"
#include <assert.h>
Ν(c) {
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
Ν(bo        ) { S(bo, 1, c) D; }
Ν(bi        ) { S(bi, 1, c) D; }
Ν(v_        ) { ρ--; assert(σ[ρ].v == bi); S(1, c) D; }
Ν(v         ) { ρ--; N(010, v_) D; }
Ν(o         ) { D; }
Ν(t_        ) { --ρ;S(1,c) D;}
Ν(t         ) { N(020, σ[--ρ].v, t_) D; }
Ν(e         ) { N(020, 1, c) D; }
Ν(Sa        );
Ν(Sa_       ) { S("b", t, o, "a", t) D; }
Ν(Sa        ) { N(010, Sa_) S(Sa, v) D; }
Ν(st_       ) { S("s", t) D; }
Ν(st        ) { N(010, st_) S(bi, st, v) D; }
Ν(ast_      ) { S(st) D; }
Ν(ast       ) { N(010, ast_) S(bi, ast, v) D; }
Ν(eOs_      ) { S(e, o, st) D; }
Ν(eOs       ) { N(010, eOs_) S(bi, eOs, v) D; }
Ν(eOseOs_   ) { S(eOs, eOs) D; }
Ν(eOseOs    ) { N(010, eOseOs_) S(bi, eOseOs, v) D; }
Ν(parse     ) { S("ssss", 4, 0, bo, ast) D; }
/*
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
  V o
  V T
  o V
  O T
  T V
  T O
  T T
  V   V   V   V   V   V
  O V O     O     O T O
  T   T   T   T   T   T
*/
Ν(end3      ) {}
Ν(end2      ) {}
Ν(end1      ) {}
Ν(end0      ) {}
void init();
int main() {
  init();
  s_t ο[256];
  Q_t α = 256;
  Q_t ρ = 0;
  s_t σ[256];
  N(01111, end3, end2, end1, end0)
  S(parse) D;
}
// clang-format off
               G(0,
c           ,L)G(L,
bo          ,L)G(L,
bi          ,L)G(L,
v_          ,L)G(L,
v           ,L)G(L,
o           ,L)G(L,
t_          ,L)G(L,
t           ,L)G(L,
st_         ,L)G(L,      
st          ,L)G(L, 
ast_        ,L)G(L,      
ast         ,L)G(L, 
eOs_        ,L)G(L,      
eOs         ,L)G(L, 
eOseOs_     ,L)G(L,
eOseOs      ,L)G(L,
parse       ,L)G(L,
e           ,L)void init(){L();}
