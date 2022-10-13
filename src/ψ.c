#include "ψ.h"
// clang-format off
N(noa) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) ν[τ++].v = ο[α++].v;
  α += ac + oc;
  nc ? ν[τ-1].c(ο, α, ν, τ-1) : noa(T);
}
N(ano) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) ν[τ++].v = ο[α++].v;
  α += oc;
  ac ? ν[τ-1].c(ο, α, ν, τ-1) : ano(T);
}
N(oan) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) ν[τ++].v = ο[α++].v;
  oc ? ν[τ-1].c(ο, α, ν, τ-1) : oan(T);
}
N(ψ) {
  Q_t g = ν[--τ].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = ν[--τ].v;
  ο[--α].Q = g;
  ν[τ-1].c(ο, α, ν, τ-1);
}
