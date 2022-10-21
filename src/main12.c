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
N(βο  ) { LOG; ρ -= 4; BT (void)0; if (ο[α-1].v == Cβ || ο[α-1].v == ψ) O; }
N(εο  ) { LOG; }
N(p_  ) {      Q_t v = ο[--α].Q; printf("%lu\n", v); A(Cβ) O; }
N(p   ) {      A(p_, 020, ψ) O; }
N(p1  ) { LOG; A(p_, 010, ψ) O; }

N(_bechd_ ) { printf("%s\n", ο[--α].cs), A(Cβ) O; }
N(dabechde) { A(_bechd_, 010, ψ) O; }

N(one_    ) { LOG; A(1, Cβ) O; }
N(one     ) { LOG; A(one_, 010, ψ) O; }
N(add_    ) { LOG; Q_t r = ο[--α].Q; Q_t l = ο[--α].Q; A(l+r, Cβ) O; }
N(add     ) { LOG; A(add_, 010, ψ) O;}

N(mamaφ   ) { LOG; A("mama", Cβ) O; }
N(mamam_3 ) { LOG; BT BT BT A(mamaφ, 010, ψ) BT O; }

N(shvilφ  ) { LOG; A("shvil", Cβ) O; }
N(shvils_3) { LOG; BT BT BT A(shvilφ, 010, ψ) BT O; }

N(sakhlφ  ) { LOG; A("sakhl", Cβ) O; }
N(sakhli_1) { LOG; BT A(sakhlφ, 010, ψ) BT BT BT O;}

N(shenφ   ) { LOG;
  const char *S  = ο[--α].cs;
  const char *Op = ο₁[--α₁].cs;
  const char *Oi = ο₂[--α₂].cs;
  printf("%s %s %s shena\n", S, Op, Oi);
  A(Cβ) O;
}
N(au_shen_a_331   ) {LOG; } // man mas is
N(ami_shen_a_311  ) {LOG; } // man me is
N(avu_shen_e_131  ) {LOG; } // me mas is
N(agi_shen_e_121  ) {LOG; } // me shen is
// I   მე და ჩვენ
// II  შენ და თქვენ
// III ის (იგი), ისინი, მან, მას (იმას, ამას), მათ
N(sitkva ) { LOG;
  //A(Cβ, mamam_3, shvils_3, sakhli_1, au_shen_a_331) O;
  A(Cβ, one, one, add, one, add, one, add, one, add, one, add, one, add, p1) O;
}
N(test);
#define Σ 512
int main() {
  s_t *ο  = (s_t[Σ]){}; Q_t α  = 0, ρ  = Σ;
  s_t *ο₁ = (s_t[Σ]){}; Q_t α₁ = 0, ρ₁ = Σ;
  s_t *ο₂ = (s_t[Σ]){}; Q_t α₂ = 0, ρ₂ = Σ;
  s_t *ο₃ = (s_t[Σ]){}; Q_t α₃ = 0, ρ₃ = Σ;
  for(Q_t i = 0; i < 4; i++) {
    LOG, ο[--ρ].c = αο, ο[--ρ].c = βο, ο[--ρ].c = εο, ο[--ρ].Q = 0111;
    BT (void)0;
  }
  A(sitkva) O;
  //  α--,ο[α].c(Τ);
  //  A(Cβ, test, 010, ψ) O;
  return 7;
}
#include <assert.h>
N(test) { LOG; 
  A(0) BT A(3) BT A(2) BT A(1) BT (void)0;
  assert(ο [--α].Q == 0);
  assert(ο₁[--α₁].Q == 1);
  assert(ο₂[--α₂].Q == 2);
  assert(ο₃[--α₃].Q == 3);
  A(Cβ) O;
}
