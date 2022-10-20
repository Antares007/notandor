// clang-format off
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    void (*c)();
  };
} s_t;
#define N(name) void name(s_t *ο, Q_t α, Q_t ρ,  \
                          s_t *ο₂, Q_t α₂, Q_t ρ₂,  \
                          s_t *ο₃, Q_t α₃, Q_t ρ₃,  \
                          s_t *ο₄, Q_t α₄, Q_t ρ₄)
#define A1(b) ο[α++].v = (void*)b,
#include "evalmap.h"
#define A(...) EVAL(MAP(A1, __VA_ARGS__)) 
#define O α--, ο[α].c(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄)
// ψ α β ε
#include <stdio.h>
#define LOG //printf("%lx %02lu %lu %s\n", (Q_t)ο >> 12, α, ρ, __FUNCTION__)
N(Cε) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  for (Q_t i = 0; i < εc; i++) ο[α++].v = ο[ρ++].v;
  ρ += βc + αc;
  if(εc) O;
  else   Cε(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
}
N(Cβ) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  ρ += εc;
  for (Q_t i = 0; i < βc; i++) ο[α++].v = ο[ρ++].v;
  ρ += αc;
  if(βc) O;
  else   Cβ(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
}
N(Cα) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  ρ += εc + βc;
  for (Q_t i = 0; i < αc; i++) ο[α++].v = ο[ρ++].v;
  if(αc) O;
  else   Cα(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
}
N(ψ) {LOG;
  Q_t ψd = ο[--α].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  for (Q_t i = 0; i < εc+βc+αc; i++) ο[--ρ].v = ο[--α].v;
  ο[--ρ].Q = ψd;
  O;
}
#define BT ο₄[α₄++].Q = ρ,        ο₄[α₄++].Q = α,        ο₄[α₄++].v = ο,       \
           ο          = ο₄,       α          = α₄,       ρ          = ρ₄,      \
           ο₄         = ο₃,       α₄         = α₃,       ρ₄         = ρ₃,      \
           ο₃         = ο₂,       α₃         = α₂,       ρ₃         = ρ₂,      \
           ο₂         = ο[--α].v, α₂         = ο[--α].Q, ρ₂         = ο[--α].Q
N(αο  ) { LOG; }
#include<unistd.h>
N(βο  ) { LOG; ρ -= 4; BT; if(α) O; }
N(εο  ) { LOG; }
N(p_  ) { LOG; Q_t v = ο[--α].Q; printf("%lu\n", v); A(Cβ) O; }
N(p   ) { LOG; A(p_, 020, ψ) O; }
N(testW) { LOG;
  A(1, p, 2, p, 3, p) BT,
  A(4, p, 5, p, 6, p) BT,
  A(7, p, 8, p, 9, p) BT,
  A(10, p, 11, p, 12, p) BT,
  O;
}
N(test);
#define Σ 512
int main() {
  s_t *ο  = (s_t[Σ]){}; Q_t α  = 0, ρ  = Σ;
  s_t *ο₂ = (s_t[Σ]){}; Q_t α₂ = 0, ρ₂ = Σ;
  s_t *ο₃ = (s_t[Σ]){}; Q_t α₃ = 0, ρ₃ = Σ;
  s_t *ο₄ = (s_t[Σ]){}; Q_t α₄ = 0, ρ₄ = Σ;
  for(Q_t i = 0; i < 4; i++) {
    ο[α++].c = Cβ, ο[--ρ].c = αο, ο[--ρ].c = βο, ο[--ρ].c = εο, ο[--ρ].Q = 0111;
    BT; LOG;
  }
  A(testW) O;
  //α--,ο[α].c(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
  //test(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄);
  return 7;
}
N(test) { LOG;
  printf("%d\n", ο[α-1].v == Cβ);
  printf("%d\n", ο[ρ+0].Q == 0111);
  printf("%d\n", ο[ρ+1].v == εο);
  printf("%d\n", ο[ρ+2].v == βο);
  printf("%d\n", ο[ρ+3].v == αο);

  printf("%d\n", ο₂[α₂-1].v == Cβ);
  printf("%d\n", ο₂[ρ₂+0].Q == 0111);
  printf("%d\n", ο₂[ρ₂+1].v == εο);
  printf("%d\n", ο₂[ρ₂+2].v == βο);
  printf("%d\n", ο₂[ρ₂+3].v == αο);

  printf("%d\n", ο₃[α₃-1].v == Cβ);
  printf("%d\n", ο₃[ρ₃+0].Q == 0111);
  printf("%d\n", ο₃[ρ₃+1].v == εο);
  printf("%d\n", ο₃[ρ₃+2].v == βο);
  printf("%d\n", ο₃[ρ₃+3].v == αο);

  printf("%d\n", ο₄[α₄-1].v == Cβ);
  printf("%d\n", ο₄[ρ₄+0].Q == 0111);
  printf("%d\n", ο₄[ρ₄+1].v == εο);
  printf("%d\n", ο₄[ρ₄+2].v == βο);
  printf("%d\n", ο₄[ρ₄+3].v == αο);
  printf("%p %p %p %p\n", ο, ο₂, ο₃, ο₄);
  printf("%lu %lu %lu %lu\n", α, α₂, α₃, α₄);
  printf("%lu %lu %lu %lu\n", ρ, ρ₂, ρ₃, ρ₄);
}
