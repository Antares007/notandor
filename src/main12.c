#include "oars.h"
// clang-format off
N(Cε); N(Cβ); N(Cα); N(ψ);
#define BT ο₃[α₃++].Q = ρ,        ο₃[α₃++].Q = α,        ο₃[α₃++].v = ο,       \
           ο          = ο₃,       α          = α₃,       ρ          = ρ₃,      \
           ο₃         = ο₂,       α₃         = α₂,       ρ₃         = ρ₂,      \
           ο₂         = ο₁,       α₂         = α₁,       ρ₂         = ρ₁,      \
           ο₁         = ο[--α].v, α₁         = ο[--α].Q, ρ₁         = ο[--α].Q,
N(αο  ) { LOG; }
#include<unistd.h>
N(βο  ) { LOG; ρ -= 4; BT (void)0; if(α) O; }
N(εο  ) { LOG; }
N(p_  ) {      Q_t v = ο[--α].Q; printf("%lu\n", v); A(Cβ) O; }
N(p   ) {      A(p_, 020, ψ) O; }
N(p1  ) { LOG; A(p_, 010, ψ) O; }

N(_bechd_ ) { printf("%s\n", ο[--α].cs), A(Cβ) O; }
N(dabechde) { A(_bechd_, 010, ψ) O; }

N(fill) { LOG;
  A(Cβ, 1,  p,  2,  p,  3,  p) BT 
  A(Cβ, 4,  p,  5,  p,  6,  p) BT 
  A(Cβ, 7,  p,  8,  p,  9,  p) BT 
  A(Cβ, 10, p,  11, p,  12, p) BT O;
}
N(one_    ) { LOG; A(1, Cβ) O; }
N(one     ) { LOG; A(one_, 010, ψ) O; }
N(add_    ) { LOG; Q_t r = ο[--α].Q; Q_t l = ο[--α].Q; A(l+r, Cβ) O; }
N(add     ) { LOG; A(add_, 010, ψ) O;}

N(mamaφ   ) { A("mama", Cβ) O; }
N(mamam_3 ) { LOG; A(mamaφ, 010, ψ) O; }

N(shvils_3) {LOG;}
N(sakhli_1) {LOG;}
N(φshena  ) {LOG;
  const char *S  = ο[--α].cs;
  const char *Op = ο₁[--α₁].cs;
  const char *Oi = ο₂[--α₂].cs;
  printf("%s %s %s shena\n", S, Op, Oi);
  A(Cβ) O;
}
N(aushena_331 ) {LOG;
}
// me     ami shena
// chven agvi shena
// shen   agi shena
// mas     au shena
// is      au shena
N(testW ) { LOG;
  A(Cβ, mamam_3, shvils_3, sakhli_1, aushena_331) O;
  //A(one, one, add, one, add, one, add, one, add, one, add, one, add, p1) O;
  //A(fill, fill, 010, ψ) O;
  //A(fill) O;
}
N(test);
N(test2);
#define Σ 512
int main() {
  s_t *ο  = (s_t[Σ]){}; Q_t α  = 0, ρ  = Σ;
  s_t *ο₁ = (s_t[Σ]){}; Q_t α₁ = 0, ρ₁ = Σ;
  s_t *ο₂ = (s_t[Σ]){}; Q_t α₂ = 0, ρ₂ = Σ;
  s_t *ο₃ = (s_t[Σ]){}; Q_t α₃ = 0, ρ₃ = Σ;
  for(Q_t i = 0; i < 4; i++) {
    ο[α++].c = Cβ, ο[--ρ].c = αο, ο[--ρ].c = βο, ο[--ρ].c = εο, ο[--ρ].Q = 0111;
    BT LOG;
  }
  //A(testW) O;
  //α--,ο[α].c(Τ);
  A(test2, test, 010, ψ) O;
  return 7;
}
#include <assert.h>
N(test2) { LOG; 
  A(0)  (void) 0;
  BT A(3) BT BT BT (void) 0;
  BT BT A(2) BT BT (void) 0;
  BT BT BT A(1) BT (void) 0;
  assert(ο[--α].Q == 0);
  assert(ο₁[--α₁].Q == 1);
  assert(ο₂[--α₂].Q == 2);
  assert(ο₃[--α₃].Q == 3);
  A(Cβ) O;
}
N(test) { LOG;
  assert(ο[α-1].v == Cβ);
  assert(ο[ρ+0].Q == 0111);
  assert(ο[ρ+1].v == εο);
  assert(ο[ρ+2].v == βο);
  assert(ο[ρ+3].v == αο);

  assert(ο₁[α₁-1].v == Cβ);
  assert(ο₁[ρ₁+0].Q == 0111);
  assert(ο₁[ρ₁+1].v == εο);
  assert(ο₁[ρ₁+2].v == βο);
  assert(ο₁[ρ₁+3].v == αο);

  assert(ο₂[α₂-1].v == Cβ);
  assert(ο₂[ρ₂+0].Q == 0111);
  assert(ο₂[ρ₂+1].v == εο);
  assert(ο₂[ρ₂+2].v == βο);
  assert(ο₂[ρ₂+3].v == αο);

  assert(ο₃[α₃-1].v == Cβ);
  assert(ο₃[ρ₃+0].Q == 0111);
  assert(ο₃[ρ₃+1].v == εο);
  assert(ο₃[ρ₃+2].v == βο);
  assert(ο₃[ρ₃+3].v == αο);
  A(Cβ) O;
}
