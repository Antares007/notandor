#include "oan.h"
// clang-format off
N(Got) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) ο[ν++].v = ο[α++].v;
  α += ac + oc;
  nc ? O : Got(X);
}
N(God) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) ο[ν++].v = ο[α++].v;
  α += oc;
  ac ? O : God(X);
}
N(Gor) {
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) ο[ν++].v = ο[α++].v;
  oc ? O : Gor(X);
}
N(oan) {
  Q_t g = ο[--ν].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = ο[--ν].v;
  ο[--α].Q = g;
  O;
}

N(and)  { A(010, oan) O; }
N(and2) { A(020, oan) O; }
N(and3) { A(030, oan) O; }
N(or)   { A(001, oan) O; }
N(or3)  { A(003, oan) O; }
N(or4)  { A(004, oan) O; }
