#include "oars.h"
// clang-format off
N(got) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  nc ? O : got(X);
}
N(god) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc;
  for (Q_t i = 0; i < ac; i++) σ[α++].v = ο[ρ++].v;
  ρ += oc;
  ac ? O : god(X);
}
N(gor) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc + ac;
  for (Q_t i = 0; i < oc; i++) σ[α++].v = ο[ρ++].v;
  oc ? O : gor(X);
}
N(goan) {
  Q_t g = σ[--α].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = g;
  O;
}

N(and)  { A(010, goan) O; }
N(and2) { A(020, goan) O; }
N(and3) { A(030, goan) O; }
N(or)   { A(001, goan) O; }
N(or3)  { A(003, goan) O; }
N(or4)  { A(004, goan) O; }


