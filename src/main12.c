#include "oars_logn.h"
// clang-format off
void Cε(OARS); void Cβ(OARS); void Cα(OARS); void ψ(OARS);
Q_t i = 0;
N(next) { if (i++ < 10) A(Cβ) C O; }
N(αο) {}
N(βο) { ρ[σ] -= 4, next(ο, α, ρ, σ); }
N(ωο) {}
N(p_) { Q_t v = ο[σ][--α[σ]].Q; printf("%lu\n", v); A(Cβ) O; }
N(p) { A(p_, 020, ψ) O; }
N(p1) { A(p_, 010, ψ) O; }

N(one_) { A(1, Cβ) O; }
N(one) { A(one_, 010, ψ) O; }

N(two_) { A(2, Cβ) O; }
N(two) { A(two_, 010, ψ) O; }

N(add_) { Q_t r = ο[σ][--α[σ]].Q; Q_t l = ο[σ][--α[σ]].Q; A(l + r, Cβ) O; }
N(add) { A(add_, 010, ψ) O; }

N(mamaφ) { A("mama", Cβ) O; }
N(mamam_3) { C C C A(mamaφ, 010, ψ) C O; }

N(shvilφ) { A("shvil", Cβ) O; }
N(shvils_3) { C C C A(shvilφ, 010, ψ) C O; }

N(sakhlφ) { A("sakhl", Cβ) O; }
N(sakhli_1) { C A(sakhlφ, 010, ψ) C C C O; }

N(shenφ) {
  Q_t oi = ο[σ][--α[σ]].Q;
  Q_t op = ο[σ][--α[σ]].Q;
  Q_t si = ο[σ][--α[σ]].Q;
  const char *Oi = ο[oi][--α[oi]].cs;
  const char *Op = ο[op][--α[op]].cs;
  const char *S = ο[si][--α[si]].cs;
  printf("%s %s %s shena\n", S, Op, Oi);
  A(Cβ) O;
}
N(ψ10) { A(010, ψ) O; }
N(ψ40) { A(040, ψ) O; }
N(ψ60) { A(060, ψ) O; }
N(au_shen_a_331) { A(next, 3, 3, 1, shenφ, ψ40, ψ60) O; } // man mas is
// N(ami_shen_a_311  ) { } // man me is
// N(avu_shen_e_131  ) { } // me mas is
// N(agi_shen_e_121  ) { } // me shen is
// I   მე და ჩვენ
// II  შენ და თქვენ
// III ის (იგი), ისინი, მან, მას (იმას, ამას), მათ
N(B) { A(Cβ) C A(Cβ) C A(Cβ) C A(Cβ) C O; }
N(sitkva) {
  A(B, mamam_3, shvils_3, sakhli_1, au_shen_a_331) O;
  // A(Cβ,one,one,add,one,add,one,add,one,add,one,add,one,add,p1) O;
}
#define Σ 512
N(NN) { A(Cβ) C O; }
int main() {
  s_t *ο[4] = {(s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){}};
  Q_t α[4], ρ[4], σ = 0;
  for (Q_t i = 0; i < 4; i++)
    α[i] = 0, ρ[i] = 150, ο[i][--ρ[i]].c = αο, ο[i][--ρ[i]].c = βο,
    ο[i][--ρ[i]].c = ωο, ο[i][--ρ[i]].Q = 0111;
  A(sitkva) O;
  return 0;
}
