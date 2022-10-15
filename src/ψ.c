#include "ψ.h"
#include "ψ_logn.h"
// clang-format off
N(noa) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) ο[ν++].v = ο[α++].v;
  α += ac + oc;
  nc ? Ο : noa(Τ);
}
N(ano) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) ο[ν++].v = ο[α++].v;
  α += oc;
  ac ? Ο : ano(Τ);
}
N(oan) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) ο[ν++].v = ο[α++].v;
  oc ? Ο : oan(Τ);
}
/*
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
N(ψ) {
  Q_t g = ο[--ν].Q,
          nc = g >> 6 & 7,
          ac = g >> 3 & 7,
          oc = g >> 0 & 7,
          tc = nc + ac + oc;
  n_t nar = ο[ν - tc - 1].c;
  (void)nar;
  for (Q_t i = 0; i < tc; i++) ο[--α].v = ο[--ν].v;
  ο[--α].Q = g;
  Ο;
}
