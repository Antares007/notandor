#include "τ4.h"
//#include "τ_logn.h"
// clang-format off
#define DeVar(bts) Q_t n = (bts), sc = n >> 9 & 7 , nc = n >> 6 & 7, ac = n >> 3 & 7, oc = n >> 0 & 7
N(sona) {
  DeVar(τ[0][α[0]++].Q);
  for (Q_t i = 0; i < sc; i++) τ[0][ι[0]++].v = τ[0][α[0]++].v;
  α[0] += nc + ac + oc;
  nc ? Ο : sona(Τ);
}
N(noa) {
  DeVar(τ[0][α[0]++].Q);
  α[0] += sc;
  for (Q_t i = 0; i < nc; i++) τ[0][ι[0]++].v = τ[0][α[0]++].v;
  α[0] += ac + oc;
  nc ? Ο : noa(Τ);
}
N(ano) {
  DeVar(τ[0][α[0]++].Q);
  α[0] += sc + nc;
  for (Q_t i = 0; i < ac; i++) τ[0][ι[0]++].v = τ[0][α[0]++].v;
  α[0] += oc;
  ac ? Ο : ano(Τ);
}
N(oan) {
  DeVar(τ[0][α[0]++].Q);
  α[0] += sc + nc + ac;
  for (Q_t i = 0; i < oc; i++) τ[0][ι[0]++].v = τ[0][α[0]++].v;
  oc ? Ο : oan(Τ);
}

N(ψ) {
  Q_t n = τ[0][--ι[0]].Q,
     sc = n >> 9 & 7, nc = n >> 6 & 7,
     ac = n >> 3 & 7, oc = n >> 0 & 7;
  if (sc) {
    //Q_t (*τ)₁ = 0;
  } else {
    Q_t tc = sc + nc + ac + oc;
    while (tc) tc--, τ[0][--α[0]].v = τ[0][--ι[0]].v;
    τ[0][--α[0]].Q = n;
    Ο;
  }
}
