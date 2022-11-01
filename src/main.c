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
N(B         ) {L; A(B); ι=(ι+7)%8, C(1); }
N(end2      ) { ; A(2); }
N(end1      ) { ; A(1); }
N(end0      ) { ; A(0); }
N(nxt2      ) { ; ι=(ι+7)%8, C(2); }
N(nxt1      ) { ; ι=(ι+7)%8, C(1); }
N(nxt0      ) { ; ι=(ι+7)%8, C(0); }
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
N(mama_     ) {L; A("მამა", Co)  C(1); }
N(mamam     ) {L; P(2, 010, mama_)  O;    }
N(shvil_    ) {L; A("შვილ", Co)  C(1); }
N(shvils    ) {L; P(3, 010, shvil_) O;    }
N(sakhl_    ) {L; A("სახლ", Co)  C(1); }
N(sakhli    ) {L; P(1, 010, sakhl_) O;    }
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
N(deda_     ) {L; A("დედა", Co)      C(1); }
N(dedam     ) {L; P(2, 010, deda_)      O; }            
N(ma_       ) {L; A("მათ", Co)       C(1); }
N(mat       ) {L; P(3, 010, ma_)        O; }            
N(namckhvar_) {L; A("ნამცხვარ", Co)  C(1); }
N(namckhvari) {L; P(1, 010, namckhvar_) O; }
N(_ckho_    ) {L;                       _shen_(ο,α,ρ,σ,ι,Μ); }
N(gamouckho ) {L; P(0, 010, _ckho_)
                  Μ[(ι+1)%8] = 3;
                  Μ[(ι+2)%8] = 3;
                  Μ[(ι+3)%8] = 3;
                  O; }
N(xti_      ) {L; printf("xti_\n");     C(1);}
N(xtis      ) {L; P(2, 010, xti_)       O; }
N(nar       ) {L; A(mamam, shvils, sakhli, aushena,
                   და, gamouckho, mat, namckhvari, dedam,
                   ან, xtis,
                  ) O; }
N(text_     ) {L; O; }
N(texti     ) {L; P(1, 030, R(0).v, Co, text_) O; }
N(anda      ) {L; }
N(aris      ) {L; O;}
N(da        ) {L; O;}
N(gaarchie  ) {L; Μ[(ι+1)%8] = 3; Μ[(ι+2)%8] = 3; Μ[(ι+3)%8] = 3; O; }
N(S_);
N(S_i       ) {L; P(1, 010, S_) O; }
N(S_it      ) {L; P(5, 010, S_) O; }
N(S_        ) {L; A(S_i, aris, "b", texti,
                            anda,        S_i, da,   "a", texti) O; }
N(nar_       ) {L; A("baaa", texti, S_it, gaarchie) O; }
 
int main() {
  Q_t Σ;
  s_t b[12][Σ = 256];
  s_t*ο[]     = {b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]};
  Q_t α[]     = {0,0,0,0};
  Q_t ρ[]     = {Σ,Σ,Σ,Σ,Σ,Σ,Σ,Σ};
  s_t*σ[]     = {b[8],b[9],b[10],b[11]};
  Q_t ι       = 0;
  Q_t Μ[]     = {0,0,0,0,0,0,0,0};
  for (Q_t i = 0; i < 8; i++)
    P(i, 0111, i?nxt2:end2, i?nxt1:end1, i?nxt0:end0);
  A(B, nar) O;
}
