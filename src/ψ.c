#include "ψ.h"
// clang-format off
N(noa) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  nc ? σ[α-1].c(ο, α-1, ρ, σ) : noa(C);
}
N(ano) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc;
  for (Q_t i = 0; i < ac; i++) σ[α++].v = ο[ρ++].v;
  ρ += oc;
  ac ? σ[α-1].c(ο, α-1, ρ, σ) : ano(C);
}
N(oan) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc + ac;
  for (Q_t i = 0; i < oc; i++) σ[α++].v = ο[ρ++].v;
  oc ? σ[α-1].c(ο, α-1, ρ, σ) : oan(C);
}
N(ψ) {
  Q_t g = σ[--α].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = g;
  σ[α-1].c(ο, α-1, ρ, σ);
}
