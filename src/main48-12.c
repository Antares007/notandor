// clang_format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t**ω,Q_t α,Q_t ρ,struct s_t**σ,Q_t Σ,Q_t Ι);
}; } s_t;                                                      
#define OARS              s_t**ω,Q_t α,Q_t ρ,       s_t**σ,Q_t Σ,Q_t Ι
#define οαρσΜΣΙ                ω,    α,    ρ,            σ,    Σ,    Ι
#define οαρσ                   ω,    α,    ρ,            σ,    
#define οαρσΜΣ                 ω,    α,    ρ,            σ,    Σ
#define ΣΙ                                                     Σ,    Ι
#define L                 printf("%lu %lu%lu%lu%lu%lu%lu%lu%lu %02lu₀%02lu₁%02lu₂%02lu₃%.3lu %s\n", \
                                 Ι,           \
                                 ω[0][ρ+1].Q, \
                                 ω[1][ρ+1].Q, \
                                 ω[2][ρ+1].Q, \
                                 ω[3][ρ+1].Q, \
                                 ω[4][ρ+1].Q, \
                                 ω[5][ρ+1].Q, \
                                 ω[6][ρ+1].Q, \
                                 ω[7][ρ+1].Q, \
                                 σ[0][α].Q, \
                                 σ[1][α].Q, \
                                 σ[2][α].Q, \
                                 σ[3][α].Q, \
                                 ω[Ι][ρ+0].Q, \
                                 __FUNCTION__);
#define N(a)              void a(OARS)
#define A(Ι, ...)         { void*s[]={__VA_ARGS__};                       \
                            for(Q_t ξ=0; ξ<sizeof(s)/sizeof(*s);ξ++)      \
                              σ[ω[Ι][ρ+1].Q][(σ[ω[Ι][ρ+1].Q][α]).Q++].v = s[ξ]; }
#define R(Ι)              σ[ω[Ι][ρ+1].Q][--(σ[ω[Ι][ρ+1].Q][α]).Q]
#define GOTO(On, Be, Af)  N(goto##On) {                                   \
                            Q_t ψ = T(Ι).Q, c3 = ψ>>9&7,                  \
                            c2 = ψ>>6&7, c1 = ψ>>3&7, c0 = ψ>>0&7;        \
                            ω[Ι][ρ+0].Q += Be;                                   \
                            for (Q_t i = 0; i < c##On; i++) A(Ι, T(Ι).v); \
                            ω[Ι][ρ+0].Q += Af;                                   \
                            c##On ? O : goto##On(οαρσΜΣΙ); }
#define O                 R(Ι).c(οαρσΜΣΙ)
#define T(Ι)              ω[Ι][ω[Ι][ρ+0].Q++]
#define P(Ι, ...)         { void*s[]={__VA_ARGS__};                       \
                            Q_t ξ=sizeof(s)/sizeof(*s);                   \
                            while(ξ)                                      \
                              ω[Ι][--ω[Ι][ρ+0].Q].v = s[--ξ]; }
#define M(v)  ω[0][ρ+1].Q = v>>3*(7-0)&7, \
              ω[1][ρ+1].Q = v>>3*(7-1)&7, \
              ω[2][ρ+1].Q = v>>3*(7-2)&7, \
              ω[3][ρ+1].Q = v>>3*(7-3)&7, \
              ω[4][ρ+1].Q = v>>3*(7-4)&7, \
              ω[5][ρ+1].Q = v>>3*(7-5)&7, \
              ω[6][ρ+1].Q = v>>3*(7-6)&7, \
              ω[7][ρ+1].Q = v>>3*(7-7)&7

#include<stdio.h>
#include<assert.h>

GOTO(3, 00,c2+c1+c0)
GOTO(2, c3,00+c1+c0)
GOTO(1, c3+c2,00+c0)
GOTO(0, c3+c2+c1,00)
N(B         ) {L; A(Ι, B) goto1(οαρσΜΣ,7); }
N(C         ) {L; A(Ι, C) goto1(οαρσΜΣΙ); }
N(end       ) { ;  }

N(mama_     ) {L; A(Ι+0, "მამა", C)   goto1(οαρσΜΣΙ); }
N(mamam     ) {L; P(Ι+2, 010, mama_)  O; }
N(shvil_    ) {L; A(Ι+0, "შვილ", C)   goto1(οαρσΜΣΙ); }
N(shvils    ) {L; P(Ι+3, 010, shvil_) O; }
N(sakhl_    ) {L; A(Ι+0, "სახლ", C)   goto1(οαρσΜΣΙ); }
N(sakhli    ) {L; P(Ι+1, 010, sakhl_) O; }
N(_shen_    ) {L; const char* Oi = (assert(R(3).v==C), R(3).Q);
                  const char* S  = (assert(R(3).v==C), R(3).Q);
                  const char* Op = (assert(R(3).v==C), R(3).Q);
                  printf("%s  %s  %s.\n", S, Op, Oi);
                  goto1(οαρσΜΣΙ); }
N(aushena   ) {L; P(Ι, 010, _shen_);
                  M(003330000);
                  R(Ι).c(οαρσΜΣΙ); }
N(next2     ) { ; goto2(οαρσΜΣ,(Ι+7)%8); }
N(next1     ) { ; goto1(οαρσΜΣ,(Ι+7)%8); }
N(next0     ) { ; goto0(οαρσΜΣ,(Ι+7)%8); }
N(rest2     ) {L; ρ -= 2; A(Ι, 2); }
N(rest1     ) {L; ρ -= 2; A(Ι, 1); }
N(rest0     ) {L; ρ -= 2; A(Ι, 0); }
N(da        ) {L; for (Q_t i = 0; i < 8; i++) ω[i][ρ+2].Q = ω[i][ρ+0].Q,
                                              ω[i][ρ+3].Q = ω[i][ρ+1].Q;
                  ρ += 2;
                  P(0, 0111, rest2, rest1, rest0);
                  for (Q_t i = 1; i < 8; i++) P(i, 0111, next2, next1, next0);
                  O;
                  ρ -= 2;
                  Q_t ψ = R(Ι).Q;
                  printf("%lu\n", ψ);L;
                  if(ψ == 1) goto1(οαρσΜΣ,(Ι+7)%8);
                  else A(Ι, ψ);
              }
N(an        ) {L; for (Q_t i = 0; i < 8; i++) ω[i][ρ+2].Q = ω[i][ρ+0].Q,
                                              ω[i][ρ+3].Q = ω[i][ρ+1].Q;
                  ρ += 2;
                  P(0, 0111, rest2, rest1, rest0);
                  for (Q_t i = 1; i < 8; i++) P(i, 0111, next2, next1, next0);
                  O;
                  ρ -= 2;
                  Q_t ψ = R(Ι).Q;
                  printf("%lu\n", ψ);L;
                  if(ψ == 0) goto1(οαρσΜΣ,(Ι+7)%8);
                  else A(Ι, ψ);
              }
N(ο         ) {L; O;}
N(deda_     ) {L; A(Ι, "დედა", C)       goto1(οαρσΜΣΙ); }
N(dedam     ) {L; P(2, 010, deda_)      O; }
N(ma_       ) {L; A(Ι, "მათ", C)        goto1(οαρσΜΣΙ); }
N(mat       ) {L; P(3, 010, ma_)        O; }
N(namckhvar_) {L; A(Ι, "ნამცხვარ", C)   goto1(οαρσΜΣΙ); }
N(namckhvari) {L; P(2, 010, namckhvar_) O; }
N(_ckho_    ) {L;                       _shen_(οαρσΜΣΙ); }
N(gamouckho ) {L; P(Ι, 010, _ckho_)
                  M(003330201);
                  R(Ι).c(οαρσΜΣΙ); }
N(xti_      ) {L; printf("xti_\n");     goto1(οαρσΜΣΙ);}
N(xtis      ) {L; P(2, 010, xti_) O; }
N(ntext     ) {L; A(Ι, mamam, sakhli, shvils,     aushena,
                   da, dedam, mat,    namckhvari, gamouckho,
                   an, xtis,
                  ) O; }

N(show      ) {L; ntext(οαρσΜΣΙ); }

int main() {
  Q_t Σ;
  s_t b[12][Σ = 512];
  s_t*ω[8]    = {b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]};
  Q_t α       = Σ - 1;
  Q_t ρ       = 0;
  s_t*σ[4]    = {b[8], b[9], b[10], b[11]};
  Q_t Ι       = 0;
  for (Q_t i  = 0; i < 8; i++) {
    ω[i][ρ+0].Q = Σ;
    ω[i][ρ+1].Q = 0;
    P(i, 0111, end, (i ? next1 : end), end);
  }
  for (Q_t i  = 0; i < 4; i++) {
    σ[i][α].Q = 0;
  }
  A(0, B);
  show(οαρσΜΣΙ);
}
