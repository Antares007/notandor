#include "oars.h"
// clang-format off
N(Cε); N(Cβ); N(Cα); N(ψ);
N(αο  ) { LOG; }
//#include<unistd.h>
N(βο  ) { LOG,ρ[σ]-=4,SCCW ((ο[σ][α[σ]-1].v == Cβ || ο[σ][α[σ]-1].v == ψ)?O:(void)0); }
N(ωο  ) { LOG; }
N(p_  ) {      Q_t v = ο[σ][--α[σ]].Q; printf("%lu\n", v); A(Cβ) O; }
N(p   ) {      A(p_, 020, ψ) O; }
N(p1  ) { LOG; A(p_, 010, ψ) O; }

N(one_    ) { LOG; A(1, Cβ) O; }
N(one     ) { LOG; A(one_, 010, ψ) O; }

N(two_    ) { LOG; A(2, Cβ) O; }
N(two     ) { LOG; A(two_, 010, ψ) O; }

N(add_    ) { LOG; Q_t r = ο[σ][--α[σ]].Q; Q_t l = ο[σ][--α[σ]].Q; A(l+r, Cβ) O; }
N(add     ) { LOG; A(add_, 010, ψ) O;}

N(mamaφ   ) { LOG; A("mama", Cβ) O; }
N(mamam_3 ) { LOG; SCCW A(mamaφ, 010, ψ) SCW O; }

N(shvilφ  ) { LOG; A("shvil", Cβ) O; }
N(shvils_3) { LOG; SCCW A(shvilφ, 010, ψ) SCW O; }

N(sakhlφ  ) { LOG; A("sakhl", Cβ) O; }
N(sakhli_1) { LOG; SCW A(sakhlφ, 010, ψ) SCCW O;}

N(shenφ   ) { LOG;
  //const char *S  = ο[--α].cs;
  //const char *Op = ο₁[--α₁].cs;
  //const char *Oi = ο₂[--α₂].cs;
  //printf("%s %s %s shena\n", S, Op, Oi);
  //A(Cβ) O;
}
N(au_shen_a_331   ) {LOG; A(3,3,1,shenφ, 040, ψ) O;
} // man mas is
//N(ami_shen_a_311  ) {LOG; } // man me is
//N(avu_shen_e_131  ) {LOG; } // me mas is
//N(agi_shen_e_121  ) {LOG; } // me shen is
// I   მე და ჩვენ
// II  შენ და თქვენ
// III ის (იგი), ისინი, მან, მას (იმას, ამას), მათ
N(sitkva ) { LOG;
  A(Cβ, mamam_3, shvils_3, sakhli_1, au_shen_a_331) O;
  //A(Cβ,one,one,add,one,add,one,add,one,add,one,add,one,add,p1) O;
}
N(test1);
N(test2);
#define Σ 512
int main() {
  s_t *ο[SC] = {(s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){},
                (s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){}, (s_t[Σ]){}};
  Q_t  α[SC],
       ρ[SC],
       σ = 0;
  for(Q_t i = 0; i < SC; i++) 
    α[i] = 0,
    ρ[i] = 150,
    ο[i][--ρ[i]].c = αο,
    ο[i][--ρ[i]].c = βο,
    ο[i][--ρ[i]].c = ωο,
    ο[i][--ρ[i]].Q = 0111;
  A(sitkva) O;
  //test1(ο,α,ρ,σ);
  //test2(ο,α,ρ,σ);
  return 0;

}
#include <assert.h>
N(test1) { LOG; 
  A(0) SCW A(1) SCW A(2) SCW A(3) SCW (void)0;
  assert(ο[0][--α[0]].Q == 0);
  assert(ο[1][--α[1]].Q == 1);
  assert(ο[2][--α[2]].Q == 2);
  assert(ο[3][--α[3]].Q == 3);
}
N(test2) { LOG; 
  A(-1) SCCW A(3) SCCW A(2) SCCW A(1) SCCW (void)0;
  assert(ο[0][--α[0]].Q == -1);
  assert(ο[SC-3][--α[SC-3]].Q == 1);
  assert(ο[SC-2][--α[SC-2]].Q == 2);
  assert(ο[SC-1][--α[SC-1]].Q == 3);
}
