#include "ψ.h"
// clang-format off
N(noa) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) ο[ν++].v = ο[α++].v;
  α += ac + oc;
  nc ? O : noa(X);
}
N(ano) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) ο[ν++].v = ο[α++].v;
  α += oc;
  ac ? O : ano(X);
}
N(oan) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) ο[ν++].v = ο[α++].v;
  oc ? O : oan(X);
}
N(ψ) {
  Q_t g = ο[--ν].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = ο[--ν].v;
  ο[--α].Q = g;
  O;
}

N(and)  { A(010, ψ) O; }
N(and2) { A(020, ψ) O; }
N(and3) { A(030, ψ) O; }
N(or)   { A(001, ψ) O; }
N(or3)  { A(003, ψ) O; }
N(or4)  { A(004, ψ) O; }
