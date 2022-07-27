#include "oars.h"
// clang-format off
N(got) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) σ[ρ++].v = ο[α++].v;
  α += ac + oc;
  nc ? O : got(X);
}
N(god) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) σ[ρ++].v = ο[α++].v;
  α += oc;
  ac ? O : god(X);
}
N(gor) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) σ[ρ++].v = ο[α++].v;
  oc ? O : gor(X);
}
N(goan) {
  Q_t g = σ[--ρ].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = σ[--ρ].v;
  ο[--α].Q = g;
  O;
}

N(and)  { A(010, goan) O; }
N(and2) { A(020, goan) O; }
N(and3) { A(030, goan) O; }
N(or)   { A(001, goan) O; }
N(or3)  { A(003, goan) O; }
N(or4)  { A(004, goan) O; }


