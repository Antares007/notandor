#include "oars.h"
#include <stdio.h>
#define L           printf("%lu %lu "                                   \
                    "%.2lu₀%.2lu₁%.2lu₂%.2lu₃ %.3lu %s\n",              \
                    ι, Μ[ι],                                            \
                    α[0], α[1], α[2], α[3],                             \
                    ρ[ι], __FUNCTION__)
G(2, 00,c1+c0)
G(1, c2,00+c0)
G(0, c2+c1,00)
#undef G
#include <assert.h>
Q_t M0[]  ={0,0,0,0,0,0,0,0};
Q_t M333[]={0,3,3,3,0,0,0,0};
N(end2      ) {L; A(2); }
N(end1      ) {L; A(1); }
N(end0      ) {L; A(0); }
N(nxt2      ) {L; ι=(ι+7)%8, C(2); }
N(nxt1      ) {L; ι=(ι+7)%8, C(1); }
N(nxt0      ) {L; ι=(ι+7)%8, C(0); }
N(და        ) {L; for (Q_t i = 0; i < 8; i++)
                    P(i, 0111, nxt2, nxt1, nxt0);
                  O; }
N(ან        ) {L; {
                    Q_t ρn[]= { ρ[0],ρ[1],ρ[2],ρ[3],ρ[4],ρ[5],ρ[6],ρ[7], };
                    Q_t*ρ   = ρn;
                    Q_t Μ[] = {0,0,0,0,0,0,0,0};
                    for (Q_t i = 0; i < 8; i++)
                      P(i, 0111, i?nxt2:end2, i?nxt1:end1, i?nxt0:end0);
                    O;
                  }
                  Q_t ψ = R(0).Q;
                  printf("%lu\n", ψ);L;
                  if(ψ == 0) ι=(ι+7)%8,C(1);
                  else A(ψ); }
N(Co        ) {L; A(Co)          C(1); }
N(mama_     ) {L; C(1); }
N(mamam     ) {L; P(2, 030, "მამა", Co, mama_)  O;    }
N(shvil_    ) {L; C(1); }
N(shvils    ) {L; P(3, 030, "შვილ", Co, shvil_) O;    }
N(sakhl_    ) {L; C(1); }
N(sakhli    ) {L; P(1, 030, "სახლ", Co, sakhl_) O;    }
N(_shen_    ) {L; const char* Oi = (assert(R(3).v==Co), R(3).Q);
                  const char* Ss = (assert(R(3).v==Co), R(3).Q);
                  const char* Op = (assert(R(3).v==Co), R(3).Q);
                  printf("%s  %s  %s.\n", Ss, Op, Oi);
                  C(1); }
N(aushena   ) {L; P(0, 010, _shen_);
                  Μ[(ι+1)%8] = 3;
                  Μ[(ι+2)%8] = 3;
                  Μ[(ι+3)%8] = 3;
                  O; }
N(deda_     ) {L; C(1); }
N(dedam     ) {L; P(2, 030, "დედა", Co, deda_) O; }            
N(ma_       ) {L; C(1); }
N(mat       ) {L; P(3, 030, "მათ", Co, ma_) O; }            
N(namckhvar_) {L; C(1); }
N(namckhvari) {L; P(1, 030, "ნამცხვარ", Co, namckhvar_) O; }
N(_ckho_    ) {L;                       _shen_(ο,α,ρ,σ,ι,Μ); }
N(gamouckho ) {L; P(0, 010, _ckho_)
                  Μ = M333;
                  O; }
N(xti_      ) {L; printf("xti_\n");     C(1);}
N(xtis      ) {L; P(2, 010, xti_)       O; }
N(nar_      ) {L; A(mamam, shvils, sakhli, aushena,
                   და, gamouckho, mat, namckhvari, dedam,
                   //ან, xtis,
                  ) O; }
N(text_     ) {L; O; }
N(texti     ) {L; P(1, 030, R(0).v, Co, text_) O; }
N(anda      ) {L; }
N(aris      ) {L; O;}
N(da        ) {L;
  P(0, 0111, nxt2, nxt1, nxt0); P(1, 0111, nxt2, nxt1, nxt0);
  P(2, 0111, nxt2, nxt1, nxt0); P(3, 0111, nxt2, nxt1, nxt0);
  P(4, 0111, nxt2, nxt1, nxt0); P(5, 0111, nxt2, nxt1, nxt0);
  P(6, 0111, nxt2, nxt1, nxt0); P(7, 0111, nxt2, nxt1, nxt0);
  O;}
N(_arch_    ) {L; C(1); }
N(gaarchie  ) {L; Μ = M333; O; }
N(S_);
N(S_i       ) {L; P(1, 010, S_) O; }
N(S_it      ) {L; P(5, 010, S_) O; }
N(S_        ) {L; A(S_i, aris, "b", texti,
                         anda,        S_i, da,   "a", texti) O; }
N(show_     ) {L; A("baaa", texti, gaarchie, S_it) O; }
N(b         ) {L; }
N(o         ) {L; 
  P(0, 0111, end2, end1, end0); P(1, 0111, nxt2, nxt1, nxt0);
  P(2, 0111, nxt2, nxt1, nxt0); P(3, 0111, nxt2, nxt1, nxt0);
  P(4, 0111, nxt2, nxt1, nxt0); P(5, 0111, nxt2, nxt1, nxt0);
  P(6, 0111, nxt2, nxt1, nxt0); P(7, 0111, nxt2, nxt1, nxt0);
  O;
} 
N(nar       ) {L;
  P(0, 030, nxt1, nar_, o); O;
}
// ერთი და ორი და ოთხი შეკრიბე.
// "არჩილს " ტექსტი და "უყვარს " ტექსტი და "სოფო" ტექსტი შეკრიბე.
// გაარჩიე ის Sით.
// გადაიყვანე ის c სტრინგად.
N(_bechd_   ) {L; C(1); }
N(dabechde  ) {L; P(0, 010, _bechd_) O;}
int main() {
  Q_t Σ;
  s_t b[12][Σ = 256];
  s_t*ο[]     = {b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]};
  Q_t α[]     = {0,0,0,0};
  Q_t ρ[]     = {Σ,Σ,Σ,Σ,Σ,Σ,Σ,Σ};
  s_t*σ[]     = {b[8],b[9],b[10],b[11]};
  Q_t ι       = 0;
  Q_t*Μ       = M0;
  A(nxt1, dabechde, da, dabechde, o) O;
}
