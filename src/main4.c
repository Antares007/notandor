#include "bo.h"
#include <stdio.h>
void ano(TINAS);
void noa(TINAS);
void oan(TINAS);
void ψ(TINAS);
N(p1) { A(ano, 020, ψ); }
N(p2) { A(ano, 030, ψ); }
N(p3) { A(ano, 040, ψ); }
N(p4) { A(ano, 050, ψ); }
N(oneβ) { A(1, ano); }
void one(TINAS) { A(oneβ, 010, ψ); }
N(addβ) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano);
}
N(add) { A(addβ, 010, ψ); }

N(o_ray) {}
N(a_ray) { printf("done: %lu\n", τ[0][--ι[0]].Q); }
N(n_ray) {}

N(two  ) { A(one, one, add); }
N(seven) { A(ano, one, two, add, two, add, two, add); }
int main() {
  t_t b[Σ], *τ = b, *ν = 0;
  Q_t α = Σ;
  Q_t σ = Σ;
  Q_t ι = 0;
  τ[--α].c = o_ray;
  τ[--α].c = a_ray;
  τ[--α].c = n_ray;
  τ[--α].Q = 0111;
  seven(&τ, &ι, &ν, &α, &σ);
  return 0;
}
