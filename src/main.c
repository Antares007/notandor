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
Q_t M312[]={0,3,1,2,0,0,0,0};
N(end2      ) {L; A(goto2); }
N(end1      ) {L; A(goto1); }
N(end0      ) {L; A(goto0); }
N(nxt2      ) { ; ι=(ι+7)%8, goto2(T); }
N(nxt1      ) { ; ι=(ι+7)%8, goto1(T); }
N(nxt0      ) { ; ι=(ι+7)%8, goto0(T); }
N(b         ) {L; ι = 7, goto1(T); }
N(o         ) {L; { s_t β[8][Σ];
                    s_t*ο[]     = {β[0],β[1],β[2],β[3],β[4],β[5],β[6],β[7]};
                    Q_t ρ[]     = {Σ,Σ,Σ,Σ,Σ,Σ,Σ,Σ};
                    O(0, 0111, end2, end1, end0); O(1, 0111, nxt2, nxt1, nxt0); O(2, 0111, nxt2, nxt1, nxt0); O(3, 0111, nxt2, nxt1, nxt0); O(4, 0111, nxt2, nxt1, nxt0); O(5, 0111, nxt2, nxt1, nxt0); O(6, 0111, nxt2, nxt1, nxt0); O(7, 0111, nxt2, nxt1, nxt0);
                    R(0).c(T); }
                  assert(R(0).v == goto1);
                  b(T); } 
N(da        ) {L; O(0, 0111, nxt2, nxt1, nxt0); O(1, 0111, nxt2, nxt1, nxt0); O(2, 0111, nxt2, nxt1, nxt0); O(3, 0111, nxt2, nxt1, nxt0); O(4, 0111, nxt2, nxt1, nxt0); O(5, 0111, nxt2, nxt1, nxt0); O(6, 0111, nxt2, nxt1, nxt0); O(7, 0111, nxt2, nxt1, nxt0);
                  R(0).c(T); }
N(და        ) { ; da(T); }
N(ან        ) {L; {
                    Q_t ρn[]= { ρ[0],ρ[1],ρ[2],ρ[3],ρ[4],ρ[5],ρ[6],ρ[7], };
                    Q_t*ρ   = ρn;
                    Q_t Μ[] = {0,0,0,0,0,0,0,0};
                    for (Q_t i = 0; i < 8; i++)
                      O(i, 0111, i?nxt2:end2, i?nxt1:end1, i?nxt0:end0);
                    R(0).c(T);
                  }
                  Q_t ψ = R(0).Q;
                  printf("%lu\n", ψ);L;
                  if(ψ == 0) ι=(ι+7)%8,goto1(T);
                  else A(ψ); }
N(Co        ) {L; A(Co)          goto1(T); }
N(mamam     ) {L; O(2, 020, "მამა", goto1) R(0).c(T); }
N(shvils    ) {L; O(3, 020, "შვილ", goto1) R(0).c(T); }
N(sakhli    ) {L; O(1, 020, "სახლ", goto1) R(0).c(T); }
N(_shen_    ) {L; const char* Ss = R(1).v;
                  const char* Op = R(2).v;
                  const char* Oi = R(3).v;
                  printf("%s  %s  %s.\n", Ss, Op, Oi);
                  goto1(T); }
N(aushena   ) {L; O(0, 010, _shen_) Μ = M312, R(0).c(T); }

N(dedam     ) {L; O(2, 020, "დედა",    goto1) R(0).c(T); }            
N(mat       ) {L; O(3, 020, "მათ ",    goto1) R(0).c(T); }            
N(namckhvari) {L; O(1, 020, "ნამცხვარ",goto1) R(0).c(T); }
N(gamouckho ) {L; O(0, 010, _shen_) Μ = M312, R(0).c(T); }
N(xti_      ) {L; printf("xti_\n");     goto1(T);}
N(xtis      ) {L; O(2, 010, xti_)       R(0).c(T); }
N(nar_      ) {L; A(mamam, shvils, sakhli, aushena,
                   და, gamouckho, mat, namckhvari, dedam,
                   //ან, xtis,
                  ) R(0).c(T); }

N(text_     ) {L; R(0).c(T); }
N(texti     ) {L; O(1, 030, R(0).v, Co, text_) R(0).c(T); }
N(anda      ) {L; }
N(aris      ) {L; R(0).c(T);}
N(_arch_    ) {L; goto1(T); }
N(gaarchie  ) {L; Μ = M333; R(0).c(T); }
N(S_);
N(S_i       ) {L; O(1, 010, S_) R(0).c(T); }
N(S_it      ) {L; O(5, 010, S_) R(0).c(T); }
N(S_        ) {L; A(S_i, aris, "β", texti,
                         anda,        S_i, da,   "a", texti) R(0).c(T); }
N(show_     ) {L; A("baaa", texti, gaarchie, S_it) R(0).c(T); }

N(_bechd_   ) {L; goto1(T); }
N(dabechde  ) {L; O(0, 010, _bechd_) R(0).c(T);}
int main() {
  Q_t Σ;
  s_t β[12][Σ = 256];
  s_t*ο[]     = {β[0],β[1],β[2],β[3],β[4],β[5],β[6],β[7]};
  Q_t α[]     = {0,0,0,0};
  Q_t ρ[]     = {Σ,Σ,Σ,Σ,Σ,Σ,Σ,Σ};
  s_t*σ[]     = {β[8],β[9],β[10],β[11]};
  Q_t ι       = 0;
  Q_t*Μ       = M0;
  O(0, 0111, end2, end1, end0); O(1, 0111, nxt2, nxt1, nxt0); O(2, 0111, nxt2, nxt1, nxt0); O(3, 0111, nxt2, nxt1, nxt0); O(4, 0111, nxt2, nxt1, nxt0); O(5, 0111, nxt2, nxt1, nxt0); O(6, 0111, nxt2, nxt1, nxt0); O(7, 0111, nxt2, nxt1, nxt0);

  A(b, nar_, o) R(0).c(T);
}
