#include "ψ.h"
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
N(ψ) {
  Q_t g = ο[--ν].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = ο[--ν].v;
  ο[--α].Q = g;
  Ο;
}
