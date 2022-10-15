#include "ψ.h"
#include "ψ_logn.h"
// clang-format off
#define DeVar(bts) Q_t n = (bts), sc = n >> 9 & 7 , nc = n >> 6 & 7, ac = n >> 3 & 7, oc = n >> 0 & 7
N(sona) {
  DeVar(ο[α++].Q);
  for (Q_t i = 0; i < sc; i++) ο[ν++].v = ο[α++].v;
  α += nc + ac + oc;
  nc ? Ο : sona(Τ);
}
N(noa) {
  DeVar(ο[α++].Q);
  α += sc;
  for (Q_t i = 0; i < nc; i++) ο[ν++].v = ο[α++].v;
  α += ac + oc;
  nc ? Ο : noa(Τ);
}
N(ano) {
  DeVar(ο[α++].Q);
  α += sc + nc;
  for (Q_t i = 0; i < ac; i++) ο[ν++].v = ο[α++].v;
  α += oc;
  ac ? Ο : ano(Τ);
}
N(oan) {
  DeVar(ο[α++].Q);
  α += sc + nc + ac;
  for (Q_t i = 0; i < oc; i++) ο[ν++].v = ο[α++].v;
  oc ? Ο : oan(Τ);
}
N(ψ) {
  DeVar(ο[--ν].Q);
  Q_t tc = sc + nc + ac + oc;
  while (tc) tc--, ο[--α].v = ο[--ν].v;
  ο[--α].Q = n;
  Ο;
}
/*
s_t = stick type

←     →
ψ    oan 
     ano
     nao
     sona
β 07777 ψ

term j     = j test_input_for_index_j xx yy andor

or(n)      = 0000n ψ
and(n)     = 000n0 ψ
orelse(n)  = 0n000 ψ


S = β S and                 ok
S = α
    S orelse β and              ?

N(S) { A(S);            } - error noa;
N(S) { A(S, X, 010, ψ); } - loop X, Y, Z while ano);
N(S) { A(X, S, 010, ψ); } - loop X, Y, Z while ano);

N(S) { A(S, β,       0001, ψ); } - loop β if S continues with "oan".
N(S) { A(S, β,       0010, ψ); } - loop β if S continues with "ano".
N(S) { A(S, β,       0100, ψ); } - loop β if S continues with "noa".
N(S) { A(β,    S, S, 0011, ψ); } - loop β if S continues with "ano" or "oan".
N(S) { A(β, X, S, S, 0111, ψ); } - loop β if S continues with "ano" or "oan".

N(S) { A(...β,       S, 0001, ψ); }
N(S) { A(...β,       S, 0010, ψ); }
N(S) { A(...β,       S, 0100, ψ); }
N(S) { A(...β,    S, S, 0011, ψ); }
N(S) { A(...β, X, S, S, 0111, ψ); }
*/
