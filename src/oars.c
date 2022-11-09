// clang-format off
#include "oars_log.h"
#include <assert.h>
#include <string.h>
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
#define Ϋ(...) { S(__VA_ARGS__) D; }
#define V(aso) Ν(aso##_); Ν(aso) {              \
  names[(Q_t)aso & (Q_t)0xFFFF] = #aso;         \
  names[(Q_t)aso##_ & (Q_t)0xFFFF] = #aso "_";     \
  N(010, aso##_, 020, aso, v_)  D; } Ν(aso##_) Ϋ
Ν(bo        ) { S(bo, 1, c) D; }
Ν(v_        ) { ρ--; S(1, c) D; }
Ν(v         ) { ρ--; N(010, v_) D; }
Ν(o_        ) { S(1, c) D; }
Ν(o         ) { N(010, o_) D; }
Ν(t_);Ν(t   ) { N(020, σ[--ρ].v, t_) D; }
Ν(e         ) { N(020, 1, c) D; }
Ν(Sa        );
Ν(Sa_       ) { S("b", t, o, Sa, "a", t) D; }
Ν(Sa        ) { N(010, Sa_) S(Sa, v) D; }
Ν(st_       ) { S("s", t) D; }
Ν(st        ) { N(010, st_) S(st, v) D; }
Ν(ast_      ) { S(st) D; }
Ν(ast       ) { N(010, ast_) S(ast, v) D; }
Ν(eOs_      ) { S(e, o, "s", t) D; }
Ν(eOs       ) { N(010, eOs_, 010, o_)  D; }
Ν(eOseOs_   ) { S(eOs, eOs) D; }
Ν(eOseOs    ) { N(010, eOseOs_) S(eOseOs, v) D; }
V(aT        ) ("a", t)
V(aaT       ) (aT, aT)
V(aaaT      ) (aT, aT)
Ν(parse     ) { S("ssss", 4, 0, bo, aaaT) D; }

Ν(e3        ) {printf("end3\n");}
Ν(e2        ) {printf("end2\n");}
Ν(e1        ) {assert(bo==σ[ρ-1].v);printf("end1\n");}
Ν(e0        ) {printf("end0\n");}
void init();
int main() {
  init();
  s_t ο[256];
  Q_t α = 256;
  Q_t ρ = 0;
  s_t σ[256];
  N(01111, e3, e2, e1, e0)
  S(parse) D;
}
// clang-format off
               G(0,
c           ,L)G(L,
bo          ,L)G(L,
bo          ,L)G(L,
v_          ,L)G(L,
v           ,L)G(L,
o_          ,L)G(L,
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
Ν(t_        ) {
  const char *match = σ[--ρ].v;
  assert(bo        == σ[--ρ].v);
  Q_t pos           = σ[--ρ].v;
  Q_t len           = σ[--ρ].v;
  const char *in    = σ[--ρ].v;
  if (pos < len && strcmp(match, in+pos) <= 0)
    S(in, len, pos + strlen(match), bo, 1, c)
  else
    S(in, len, pos, bo, 0, c)
  D;
}
/*
AraDAni aka NotAndOr is the protocol which can
define high level langugege words, and thins to use for
write and execute human language like senteces in computer world.

thik about it. in computer world we dont have words, rather we have 
mathematical funcion implementation to divide and conuire problems.
two most useful model of computetion we have are functions and
sequences of states.

What is more powerfull then human langauage. We can
specify and define almost evrething by words.

it groups and combines low level
language instructions in function like procedures whic dont use
"return" statement aka mathematical function implementation protocol,
rather thay ony use continiue sentence execution,
from nowon lets call them narratives, execution process of the
source langugege words
in aradani we have double edged word definitions.
from now on we shell call then swords.
on one edge of thee sword we have sentences written from left to rigt
and on another edge of the sword we write execution pipeline of the word core.

Grammar rules are expanded from right to left.

Tokens are consumed from left to right.

Backtracking is used to expand all alternative right-hand-sides of grammar
rules in order to identify all possible parses.

Programmer 1: "Where's the pizza?"
Programmer 2: (Removes headphones) "What?"
Programmer 1: "Where's the pizza?"
Programmer 2: "It's in the break room"
Programmer 1: "Is there any more soda?"
Programmer 2: "I'm not sure"
(Both put their headphones back on)

Top-down recognizers can be implemented as a set of mutually recursive
processes which search for parses using a top-down expansion of the grammar
rules defining non-terminals while looking for matches of terminals with
tokens on the input.

Recognizers are functions which take an index j as argument and which return
a set of indices as result. Each index in the result set corresponds to the
position at which the recognizer successfully finished recognizing a sequence
of tokens that began at position j.

An empty result set indicates that the recognizer failed to recognize any
sequence beginning at j. Multiple results are returned for bo input.

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
