#include "oars.h"
#include <stdio.h>
N(got) {
  Q_t gate = ο[ρ++].Q;
  Q_t not_count = (gate >> 6) & 07;
  Q_t and_count = (gate >> 3) & 07;
  Q_t oor_count = (gate >> 0) & 07;
  while (not_count)
    σ[α++].v = ο[ρ++].v, not_count--;
  ρ += and_count;
  ρ += oor_count;
  O;
}
N(god) {
  Q_t gate = ο[ρ++].Q;
  Q_t not_count = (gate >> 6) & 07;
  Q_t and_count = (gate >> 3) & 07;
  Q_t oor_count = (gate >> 0) & 07;
  ρ += not_count;
  while (and_count)
    σ[α++].v = ο[ρ++].v, and_count--;
  ρ += oor_count;
  O;
}
N(gor) {
  Q_t gate = ο[ρ++].Q;
  Q_t not_count = (gate >> 6) & 07;
  Q_t and_count = (gate >> 3) & 07;
  Q_t oor_count = (gate >> 0) & 07;
  ρ += not_count;
  ρ += and_count;
  while (oor_count)
    σ[α++].v = ο[ρ++].v, oor_count--;
  O;
}
N(goan) {
  Q_t gate = σ[--α].Q;
  Q_t not_count = gate >> 6 & 07;
  Q_t and_count = gate >> 3 & 07;
  Q_t oor_count = gate >> 0 & 07;
  Q_t tot_count = not_count + and_count + oor_count;
  while (tot_count)
    ο[--ρ].v = σ[--α].v, tot_count--;
  ο[--ρ].Q = gate;
  O;
}

N(one    ) { A(1, god) O; }
N(add    ) { R(Q_t, r); R(Q_t, l); A(l + r, god) O; }
N(and    ) { A(010, goan) O; }

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
  A(one, one, and, add, and, one, and, add, and, one, and, add, and,
         one, and, add, and, one, and, add, and, one, and, add, and) O;
  return 5;
}
