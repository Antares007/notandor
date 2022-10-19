#include "bo.h"
#include <stdio.h>
void nao(OARS);
void aon(OARS);
void ona(OARS);
void ψ(OARS);
#define LOG printf("%p %lu %lu %p %s \n", ω, α, ρ, σ, __FUNCTION__)
N(β     ) { LOG, aon(Τ); }
N(end_2 ) { LOG, ω[α++].Q = 2; }
N(end_1 ) { LOG, ω[α++].Q = 1; }
N(end_0 ) { LOG, ω[α++].Q = 0; }
N(ο     ) {
  LOG;
  s_t nω[512];
  Q_t nα = 0;
  nω[nα++].v = β;
  while (ω[α - 1].v != β && ω[α - 1].v != ο)
    printf("."), nω[nα++].v = ω[--α].v;
  printf("\n");
  ω[--ρ].v = end_0;
  ω[--ρ].v = end_1;
  ω[--ρ].v = end_2;
  ω[--ρ].Q = 0111;
  ω[α - 1].go(ω, α - 1, ρ, σ);
  Q_t rez = ω[0].Q;
  if (rez == 2)
    return;
  Q_t nρ = sizeof(nω) / sizeof(*nω);
  nω[--nρ].v = end_0;
  nω[--nρ].v = end_1;
  nω[--nρ].v = end_2;
  nω[--nρ].Q = 0111;
  nω[nα - 1].go(nω, nα - 1, nρ, σ);
}
N(term) {
  LOG;
  ω[α - 1].go(ω, α - 1, ρ, σ);
}
N(S) { A("b", term, 020, ψ, ο, S, 010, ψ, "a", term, 020, ψ, ο); }
N(a) { LOG, A(aon, 010, ψ); }
N(b) { LOG, A(aon, 010, ψ); }
N(c) { LOG, A(aon, 010, ψ); }

int main() {
  s_t ω[512];
  Q_t α = 0;
  Q_t ρ = sizeof(ω) / sizeof(*ω);
  s_t σ[4];
  ω[α++].v = β;
  A(a, a, a, ο, b, b, ο, c, ο);
  return 0;
}
