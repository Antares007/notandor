#include "oars.h"
#include <stdio.h>
// clang-format off
N(got) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  if (nc) O; else got(X);
}
N(god) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc;
  for (Q_t i = 0; i < ac; i++) σ[α++].v = ο[ρ++].v;
  ρ += oc;
  if (ac) O; else god(X);
}
N(gor) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc + ac;
  for (Q_t i = 0; i < oc; i++) σ[α++].v = ο[ρ++].v;
  if (oc) O; else gor(X);
}
N(goan) {
  Q_t g = σ[--α].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = g; O;
}
N(and ) { A(010) goan(X); }
N(and2) { A(020) goan(X); }
N(or4 ) { A(004) goan(X); }
N(term) { god(X); }
N(S) {
  A("b", term,
    S, "a", term, and2, or4) god(X);
}

N(one) { A(1, god) O; }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, god) O;
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
  A(one, one, and, add, and, one, and, add, and, one, and, add, and, one, and,
    add, and, one, and, add, and, one, and, add, and)
  O;
  return 5;
}
