#include "oars.h"
#include <stdio.h>
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
  O; // σ[α - 1].c(ο, α - 1, ρ, σ)
}

N(and ) { A(010, goan) O; }
N(and2) { A(020, goan) O; }
N(and3) { A(030, goan) O; }
N(or  ) { A(001, goan) O; }
N(or3 ) { A(003, goan) O; }
N(or4 ) { A(004, goan) O; }

N(term) { god(X); }

N(bT  ) { A("b", term) O; }
N(aT  ) { A("a", term) O; }
N(xT  ) { A("x", term) O; }

N(cT  ) { A("c", term) O; }
N(empty) {}
N(bε  ) { 
  A(bT, empty, or) O;
}

N(M) {
  A(aT,
    aT, bT, and, or3,
    aT, cT, and, or3, god) O;
}
N(Ba) {
  A("b", term,
Ba, "a", term, and2, or4) O;
}
N(Bax) {
  A(Ba, xT, and2) O;
}

N(one) { A(1, god) O; }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, god) O;
}
N(addww) {
  A(add, and, and3) O;
}
N(addws) {
  A(add, and2) O;
}
N(addsw) {
  A(add, and) O;
}

N(not_ray) { printf("NOT\n"); }
N(and_ray) { printf("AND %lu\n", σ[--α].Q); }
N(oor_ray) { printf("OOR\n"); }
int main() {
  p_t ο[512];
  Q_t ρ = sizeof(ο) / sizeof(*ο);
  p_t σ[512];
  Q_t α = 0;
  ο[--ρ].c = not_ray;
  ο[--ρ].c = and_ray;
  ο[--ρ].c = oor_ray;
  ο[--ρ].Q = 0111;
  A(2, one, addsw, one, addww, one, addww,
         one, addww, 7, addws, one, addww) O;
  return 5;
}
