#include "bo.h"
#include <stdio.h>
#define LOG printf("%p %lu %lu %p %s \n", ω, α, ρ, σ, __FUNCTION__)
// clang-format off
#define DestructVars(BTS) Q_t j = BTS, naoc = j >> 6 & 7, aonc = j >> 3 & 7, onac = j & 7
#define Unroll(NC) for (Q_t i = 0; i < NC##c; i++) ω[α++].v = ω[ρ++].v
#define Continue(name) if (name##c) α--, ω[α].go(Τ); else name(Τ)
N(nao   ) { LOG; DestructVars(ω[ρ++].Q); Unroll(nao); ρ += aonc + onac; Continue(nao); }
N(aon   ) { LOG; DestructVars(ω[ρ++].Q); ρ += naoc; Unroll(aon); ρ += onac; Continue(aon); }
N(ona   ) { LOG; DestructVars(ω[ρ++].Q); ρ += naoc + aonc; Unroll(ona); Continue(ona); }
N(ψ     ) { LOG;
  DestructVars(ω[--α].Q);
  for (Q_t i = 0; i < naoc + aonc + onac; i++) ω[--ρ].v = ω[--α].v;
  ω[--ρ].Q = j; ω[α - 1].go(ω, α - 1, ρ, σ);
}
// clang-format on
