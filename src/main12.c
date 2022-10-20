// clang-format off
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    void (*c)();
  };
} s_t;
#include <stdio.h>
#define N(name) void name(s_t *ο₁, Q_t α₁, Q_t ρ₁,  \
                          s_t *ο₂, Q_t α₂, Q_t ρ₂,  \
                          s_t *ο₃, Q_t α₃, Q_t ρ₃,  \
                          s_t *ο₄, Q_t α₄, Q_t ρ₄)
// ψ α β ε
N(β) {
  Q_t ψ = ο₁[ρ₁++].Q, εc = ψ >> 6 & 7, βc = ψ >> 3 & 7, αc = ψ & 7;
  for (Q_t i = 0; i < εc; i++) ο₁[α₁++].v = ο₁[ρ₁++].v;
  ρ₁ += βc + αc;
  if(εc) α₁--, ο₁[α₁].c(ο₁, α₁, ρ₁, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
  else                β(ο₁, α₁, ρ₁, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
}
int main() {
  s_t ο₁[512], ο₂[512], ο₃[512], ο₄[512];
  Q_t α₁ = 0, ρ₁ = 512;
  Q_t α₂ = 0, ρ₂ = 512;
  Q_t α₃ = 0, ρ₃ = 512;
  Q_t α₄ = 0, ρ₄ = 512;
  ο₁[α₁++].c = β;
  ο₂[α₂++].c = β;
  ο₃[α₃++].c = β;
  ο₄[α₄++].c = β;
  return 7;
}
