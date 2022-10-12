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
N(oneβ) { A(1, ano); }
N(one) { A(oneβ, 010, ψ); }
N(addβ) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano);
}
N(add) { A(addβ, 010, ψ); }

N(o_ray) { printf("OOR\n"); }
N(a_ray) { printf("AND %lu\n", ν[--τ].Q); }
N(n_ray) { printf("NOT\n"); }

N(pano) { printf("1\n"), ano(C); }
N(poan) { printf("0\n"), oan(C); }
N(pnoa) { printf("2\n"), noa(C); }
void and(OANT) {
  // p_t nο[0x1000];
  // code, code, code, code, ..., code.
  
}
void ATree(OANT) {
  A(
                   ano,
    one, one, add, and,
    one, one, add
  );
}
N(ST) { A(ano, one, 2, p1, add, one, add, one, add); }
int main() {
  p_t ο[512];
  Q_t α = sizeof(ο) / sizeof(*ο);
  p_t ν[512];
  Q_t τ = 0;
  ο[--α].c = n_ray;
  ο[--α].c = a_ray;
  ο[--α].c = o_ray;
  ο[--α].Q = 0111;
  A(ST);
  return 5;
}
