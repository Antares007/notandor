#include "bo.h"
#include <stdio.h>
void nao(OARS);
void aon(OARS);
void ona(OARS);
void ψ(OARS);
N(end_2) { LOG, ω[α++].Q = 2; }
N(end_1) { LOG, ω[α++].Q = 1; }
N(end_0) { LOG, ω[α++].Q = 0; }
N(β) { LOG, aon(Τ); }
N(ο) { LOG;
  A(end_2, end_1, end_0, 0111, ψ);
}
N(term) { LOG;
  ω[α - 2].call(ω, α - 2, ρ, σ);
}
N(Sa) { LOG;
        A(β,  "b", term, ο,
  β,  "b", term, ο,
  Sa, 010, ψ, "a", term, ο, "a", term, ο); }

N(a) { LOG, A(aon, 010, ψ); }
N(b) { LOG, A(aon, 010, ψ); }
N(c) { LOG, A(aon, 010, ψ); }
int main() {
  s_t ω[512];
  Q_t α = 0;
  Q_t ρ = sizeof(ω) / sizeof(*ω);
  s_t *σ = S("baaaa", 5, 0);
  ω[α++].v = β;
  //A(ona, end_2, end_1, end_0, 0111, ψ);
  // A(Sa, ο)
  A(a, a, a, ο, b, b, ο, c, ο);
  return 0;
}
