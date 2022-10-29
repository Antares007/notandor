// clang_format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t**ω,Q_t*α,Q_t*ρ,struct s_t**σ,Q_t*Μ,Q_t Σ,Q_t Ι);
}; } s_t;                                                      
#define OARS              s_t**ω,Q_t*α,Q_t*ρ,       s_t**σ,Q_t*Μ,Q_t Σ,Q_t Ι
#define οαρσΜΣΙ                ω,    α,    ρ,            σ,    Μ,    Σ,    Ι
#define οαρσ                   ω,    α,    ρ,            σ,          
#define οαρσΜΣ                 ω,    α,    ρ,            σ,    Μ,    Σ
#define ΣΙ                                                      ,    Σ,    Ι
#define L                 printf("%lu %lu %02lu₀%02lu₁%02lu₂%02lu₃%.3lu %s\n", Ι, Μ[Ι], α[0], α[1], α[2], α[3], ρ[Ι], __FUNCTION__);
#define N(a)              void a(OARS)
#define A(Ι, ...)         { void*s[]={__VA_ARGS__};                       \
                            for(Q_t ξ=0; ξ<sizeof(s)/sizeof(*s);ξ++)      \
                              σ[Μ[Ι]][α[Μ[Ι]]++].v = s[ξ]; }
#define R(Ι)              σ[Μ[Ι]][--α[Μ[Ι]]]
#define GOTO(On, Be, Af)  N(goto##On) {                                   \
                            Q_t ψ = T(Ι).Q, c3 = ψ>>9&7,                  \
                            c2 = ψ>>6&7, c1 = ψ>>3&7, c0 = ψ>>0&7;        \
                            ρ[Ι] += Be;                                   \
                            for (Q_t i = 0; i < c##On; i++) A(Ι, T(Ι).v); \
                            ρ[Ι] += Af;                                   \
                            c##On ? R(Ι).c(οαρσΜΣΙ) : goto##On(οαρσΜΣΙ); }
#define O                 R(Ι).c(οαρσΜΣΙ)
#define T(Ι)              ω[Ι][ρ[Ι]++]
#define P(Ι, ...)         { void*s[]={__VA_ARGS__};                       \
                            Q_t ξ=sizeof(s)/sizeof(*s);                   \
                            while(ξ)                                      \
                              ω[Ι][--ρ[Ι]].v = s[--ξ]; }
#include<stdio.h>
#include<assert.h>

GOTO(3, 00,c2+c1+c0)
GOTO(2, c3,00+c1+c0)
GOTO(1, c3+c2,00+c0)
GOTO(0, c3+c2+c1,00)
N(B         ) {L; A(Ι, B) goto1(οαρσΜΣ,7); }
N(C         ) {L; A(Ι, C) goto1(οαρσΜΣΙ); }
N(end       ) { ;  }
N(next1     ) { ; goto1(οαρσΜΣ,(Ι+7)%8); }

N(mama_     ) {L; A(Ι, "მამა", C)   goto1(οαρσΜΣΙ); }
N(mamam     ) {L; P(2, 010, mama_)  R(Ι).c(οαρσΜΣΙ); }
N(shvil_    ) {L; A(Ι, "შვილ", C)   goto1(οαρσΜΣΙ); }
N(shvils    ) {L; P(3, 010, shvil_) R(Ι).c(οαρσΜΣΙ); }
N(sakhl_    ) {L; A(Ι, "სახლ", C)   goto1(οαρσΜΣΙ); }
N(sakhli    ) {L; P(1, 010, sakhl_) R(Ι).c(οαρσΜΣΙ); }
N(_shen_    ) {L; const char* Oi = (assert(R(3).v==C), R(3).Q);
                  const char* S  = (assert(R(3).v==C), R(3).Q);
                  const char* Op = (assert(R(3).v==C), R(3).Q);
                  printf("%s  %s  %s.\n", S, Op, Oi);
                  goto1(οαρσΜΣΙ); }
Q_t Map[][8] = { [0333]={0,3,3,3,0,0,0,0} };
N(aushena   ) {L; P(Ι, 010, _shen_)
                  R(Ι).c(οαρσ Map[0333] ΣΙ); }
N(da        ) {L; for(Q_t i=0;i<8;i++) {
                    P(i, 0111, end, next1, end);
                  }
                  R(Ι).c(οαρσΜΣΙ); }
N(an        ) {L; for(Q_t i=0;i<8;i++) {
                    P(i, 0111, end, end, next1);
                    ω[i][0].v = ρ[i]; }
                  R(Ι).c(οαρσΜΣΙ); }
N(ο         ) {L; R(Ι).c(οαρσΜΣΙ);}
N(deda_     ) {L; A(Ι, "დედა", C)       goto1(οαρσΜΣΙ); }
N(dedam     ) {L; P(2, 010, deda_)      R(Ι).c(οαρσΜΣΙ); }
N(ma_       ) {L; A(Ι, "მათ", C)        goto1(οαρσΜΣΙ); }
N(mat       ) {L; P(3, 010, ma_)        R(Ι).c(οαρσΜΣΙ); }
N(namckhvar_) {L; A(Ι, "ნამცხვარ", C)   goto1(οαρσΜΣΙ); }
N(namckhvari) {L; P(2, 010, namckhvar_) R(Ι).c(οαρσΜΣΙ); }
N(_ckho_    ) {L;                       _shen_(οαρσΜΣΙ); }
N(gamouckho ) {L; P(Ι, 010, _ckho_)
                  R(Ι).c(οαρσ Map[0333] ΣΙ); }

N(ntext     ) {L; A(Ι, mamam, sakhli, shvils,     aushena,
                   da, dedam, mat,    namckhvari, gamouckho
                  ) R(Ι).c(οαρσΜΣΙ); }

N(show      ) {L; ntext(οαρσΜΣΙ); }

int main() {
  Q_t Σ;
  s_t b[12][Σ = 512];
  s_t*ω[8]    = {b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]};
  Q_t α[4]    = {0, 0, 0, 0};
  Q_t ρ[8]    = {Σ, Σ, Σ, Σ, Σ, Σ, Σ, Σ};
  s_t*σ[4]    = {b[8], b[9], b[10], b[11]};
  Q_t Μ[8]    = {0, 1, 2, 2, 3, 3, 3, 1};
  Q_t Ι       = 0;
  for (Q_t i  = 0; i < 8; i++) {
    P(i, 0111, end, (i ? next1 : end), end);
    ω[i][0].v = ρ[i];
    ω[i][1].v = ρ[i];
    ω[i][2].v = ρ[i];
  }
  A(0, B);
  show(οαρσΜΣΙ);
}
