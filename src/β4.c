typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    void (*go)();
  };
} s_t;

#define N(narname) void narname(s_t *ω, Q_t α, Q_t ρ, s_t *σ)
#define Τ ω, α, ρ, σ
#include <stdio.h>
#define LOG printf("%p %lu %lu %p %s \n", ω, α, ρ, σ, __FUNCTION__)
#define Α(val) ω[α++].v = (void*)val,
#include "evalmap.h"
#define A(...) EVAL(MAP(Α, __VA_ARGS__)) ω[α-1].go(ω, α-1, ρ, σ);
#define DestructVars(BTS) Q_t j = BTS, nc = j >> 6 & 7, ac = j >> 3 & 7, oc = j & 7
#define Unroll(NC) for (Q_t i = 0; i < NC; i++) ω[α++].v = ω[ρ++].v
N(nao) { LOG;
  DestructVars(ω[ρ++].Q);
  Unroll(nc); ρ += ac + oc;
  if (nc) α--, ω[α].go(Τ); else nao(Τ);
}
N(aon) { LOG;
  DestructVars(ω[ρ++].Q);
  ρ += nc; Unroll(ac); ρ += oc;
  if (ac) α--, ω[α].go(Τ); else aon(Τ);
}
N(ona) { LOG;
  DestructVars(ω[ρ++].Q);
  ρ += nc + ac; Unroll(oc);
  if (ac) α--, ω[α].go(Τ); else ona(Τ);
}
N(term    ) { LOG; ω[α-1].go(ω, α-1, ρ, σ); }
N(ψ       ) {}
N(β       ) { LOG; aon(Τ); }
N(end_2 ) { LOG; ω[α++].Q = 2; }
N(end_1 ) { LOG; ω[α++].Q = 1; }
N(end_0 ) { LOG; ω[α++].Q = 0; }
N(ο     ) { LOG;
  s_t nω[512];
  Q_t nα = 0;
  nω[nα++].v = β;
  while(ω[α-1].v != β && ω[α-1].v != ο) nω[nα++].v = ω[--α].v;
  ω[--ρ].v = end_0;
  ω[--ρ].v = end_1;
  ω[--ρ].v = end_2;
  ω[--ρ].Q = 0111;
  ω[α-1].go(ω, α-1, ρ, σ);
  Q_t rez = ω[0].Q;
  if (rez == 2) return;
  Q_t nρ = sizeof(nω) / sizeof(*nω);
  nω[--nρ].v = end_0;
  nω[--nρ].v = end_1;
  nω[--nρ].v = end_2;
  nω[--nρ].Q = 0111;
  nω[nα-1].go(nω, nα-1, nρ, σ);
}
N(S       ) {
  A(           "b", term, 020, ψ, ο,
    S, 010, ψ, "a", term, 020, ψ, ο
  ); }
N(a) { LOG; aon(Τ); }
N(b) { LOG; aon(Τ); }
N(c) { LOG; aon(Τ); }

int main( ) {
  s_t ω[512];
  Q_t α = 0;
  Q_t ρ = sizeof(ω)/sizeof(*ω);
  s_t σ[4];
  ω[α++].v = β;
  A(a, ο, b, ο, c, ο);
  return 0;
}
