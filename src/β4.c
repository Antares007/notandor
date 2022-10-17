#include "τ4.h"
//#include "τ_logn.h"
// clang-format off
#define DeVar(bts) Q_t n = (bts), sc = n >> 9 & 7 , nc = n >> 6 & 7, ac = n >> 3 & 7, oc = n >> 0 & 7
N(sona) {
  DeVar((*τ)[(*α)++].Q);
  for (Q_t i = 0; i < sc; i++) (*τ)[(*ι)++].v = (*τ)[(*α)++].v;
  (*α) += nc + ac + oc;
  nc ? Ο : sona(Τ);
}
N(noa) {
  DeVar((*τ)[(*α)++].Q);
  (*α) += sc;
  for (Q_t i = 0; i < nc; i++) (*τ)[(*ι)++].v = (*τ)[(*α)++].v;
  (*α) += ac + oc;
  nc ? Ο : noa(Τ);
}
N(ano) {
  DeVar((*τ)[(*α)++].Q);
  (*α) += sc + nc;
  for (Q_t i = 0; i < ac; i++) (*τ)[(*ι)++].v = (*τ)[(*α)++].v;
  (*α) += oc;
  ac ? Ο : ano(Τ);
}
N(oan) {
  DeVar((*τ)[(*α)++].Q);
  (*α) += sc + nc + ac;
  for (Q_t i = 0; i < oc; i++) (*τ)[(*ι)++].v = (*τ)[(*α)++].v;
  oc ? Ο : oan(Τ);
}

N(ψ) {
  Q_t n = (*τ)[--(*ι)].Q,
     sc = n >> 9 & 7, nc = n >> 6 & 7,
     ac = n >> 3 & 7, oc = n >> 0 & 7;
  if (sc) {
    //Q_t (*τ)₁ = 0;
  } else {
    Q_t tc = sc + nc + ac + oc;
    while (tc) tc--, (*τ)[--(*α)].v = (*τ)[--(*ι)].v;
    (*τ)[--(*α)].Q = n;
    Ο;
  }
}
