#include "ψ.h"
#include <stdio.h>
#include <uv.h>
N(ano);
N(noa);
N(oan);
N(ψ);
N(p1) { A(ano, 020, ψ); }
N(p2) { A(ano, 030, ψ); }
N(p3) { A(ano, 040, ψ); }
N(p4) { A(ano, 050, ψ); }
N(one) { A(1, ano, 020, ψ); }
N(add_) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano);
}
N(add) { A(add_, 010, ψ); }

N(o_ray) { printf("OOR\n"); }
N(a_ray) { printf("AND %lu\n", ο[--ν].Q); }
N(n_ray) { printf("NOT\n"); }

N(pano) { printf("1\n"), ano(C); }
N(poan) { printf("0\n"), oan(C); }
N(pnoa) { printf("2\n"), noa(C); }
N(and) {}
N(ATree) {
  A(ano, poan, ano, 0001, ψ, 040, ψ, pano, ano, 0010, ψ, 040, ψ, pnoa, ano,
    0100, ψ, 040, ψ);
}
N(ST) { A(ano, one, 2, p1, add, one, add, one, add); }
int main() {
  p_t ο[512];
  Q_t α = sizeof(ο) / sizeof(*ο);
  Q_t ν = 0;
  ο[--α].c = n_ray;
  ο[--α].c = a_ray;
  ο[--α].c = o_ray;
  ο[--α].Q = 0111;
  ST(C);
  return 5;
}
