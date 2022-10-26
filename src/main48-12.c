// clang_format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t**ο,Q_t*α,Q_t*ρ,struct s_t**σ,Q_t*Μ,Q_t Σ,Q_t Ι);
}; } s_t;                                                      
#define OARS       s_t**ο,Q_t*α,Q_t*ρ,       s_t**σ,Q_t*Μ,Q_t Σ,Q_t Ι
#define οαρσΜΣΙ         ο,    α,    ρ,            σ,    Μ,    Σ,    Ι
#define οαρσΜΣ          ο,    α,    ρ,            σ,    Μ,    Σ
#define L printf("%lu %02lu %03lu %s\n", Ι, α[Μ[Ι]], ρ[Ι], __FUNCTION__);
#define N(a)      void a(OARS)
#define A(Ι, ...) { void*s[]={__VA_ARGS__};                   \
                    for(Q_t ξ=0; ξ<sizeof(s)/sizeof(*s);ξ++)  \
                      σ[Μ[Ι]][α[Μ[Ι]]++].v = s[ξ]; }
#define R(Ι)      σ[Μ[Ι]][--α[Μ[Ι]]]
#define P(Ι, ...) { void*s[]={__VA_ARGS__};                   \
                    Q_t ξ=sizeof(s)/sizeof(*s);               \
                    while(ξ)                                  \
                      ο[Ι][--ρ[Ι]].v = s[--ξ]; }
#define T(Ι)      ο[Ι][ρ[Ι]++]
#include<stdio.h>
#include<assert.h>
N(go2       ) { ; Q_t ψ = T(Ι).Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                  for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                  ρ[Ι] += ac + oc;
                  nc ? R(Ι).c(οαρσΜΣΙ) : go2(οαρσΜΣΙ); }
N(go1       ) { ; Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                  ρ[Ι] += nc;
                  for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                  ρ[Ι] += oc;
                  ac ? R(Ι).c(οαρσΜΣΙ) : go1(οαρσΜΣΙ); }
N(go0       ) { ; Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                  ρ[Ι] += nc + ac;
                  for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                  oc ? R(Ι).c(οαρσΜΣΙ) : go0(οαρσΜΣΙ); }
N(B         ) {L; A(Ι, B) go1(οαρσΜΣ,7); }
N(C         ) {L; A(Ι, C) go1(οαρσΜΣΙ); }
N(end       ) { ;  }
N(next1     ) { ; go1(οαρσΜΣ,(Ι+7)%8); }

N(mama_     ) {L; A(Ι, "მამა", C)   go1(οαρσΜΣΙ); }
N(mamam     ) {L; P(2, 010, mama_)  R(Ι).c(οαρσΜΣΙ); }
N(shvil_    ) {L; A(Ι, "შვილ", C)   go1(οαρσΜΣΙ); }
N(shvils    ) {L; P(3, 010, shvil_) R(Ι).c(οαρσΜΣΙ); }
N(sakhl_    ) {L; A(Ι, "სახლ", C)   go1(οαρσΜΣΙ); }
N(sakhli    ) {L; P(1, 010, sakhl_) R(Ι).c(οαρσΜΣΙ); }
N(_shen_    ) {L; Q_t pi3 = R(Ι).Q;
                  Q_t pi2 = R(Ι).Q;
                  Q_t pi1 = R(Ι).Q;
                  printf("%lu %lu %lu\n", pi1, pi2, pi3);
                  const char* ps3 = (assert(R(pi3).v==C), R(pi3).Q);
                  const char* ps2 = (assert(R(pi2).v==C), R(pi2).Q);
                  const char* ps1 = (assert(R(pi1).v==C), R(pi1).Q);
                  printf("%s  %s  %s.\n", ps1, ps2, ps3);
                  go1(οαρσΜΣΙ); }
N(aushena   ) {L; P(Ι, 040, 2, 2, 1, _shen_)  R(Ι).c(οαρσΜΣΙ); }
N(da        ) {L; for(Q_t i=0;i<8;i++) {
                    P(i, 0111, end, next1, end);
                    ο[i][1].v = ρ[i]; }
                  R(Ι).c(οαρσΜΣΙ); }
N(an        ) {L; for(Q_t i=0;i<8;i++) {
                    P(i, 0111, end, end, next1);
                    ο[i][0].v = ρ[i]; }
                  R(Ι).c(οαρσΜΣΙ); }
N(deda_     ) {L; A(Ι, "დედა", C)           go1(οαρσΜΣΙ); }
N(dedam     ) {L; P(2, 010, deda_)          R(Ι).c(οαρσΜΣΙ); }
N(ma_       ) {L; A(Ι, "მათ", C)            go1(οαρσΜΣΙ); }
N(mat       ) {L; P(2, 010, ma_)            R(Ι).c(οαρσΜΣΙ); }
N(namckhvar_) {L; A(Ι, "ნამცხვარ", C)       go1(οαρσΜΣΙ); }
N(namckhvari) {L; P(2, 010, namckhvar_)     R(Ι).c(οαρσΜΣΙ); }
N(_ckho_    ) {L;                           _shen_(οαρσΜΣΙ); }
N(gamouckho ) {L; P(Ι, 040, 2,2,2, _ckho_)  R(Ι).c(οαρσΜΣΙ); }


N(ntext     ) {L; A(Ι,  mamam, sakhli, shvils, aushena,
                  da, dedam, mat, namckhvari, gamouckho)
                  R(Ι).c(οαρσΜΣΙ); }
N(show      ) {L; ntext(οαρσΜΣΙ); }

int main() {
  Q_t Σ;
  s_t b[12][Σ = 512];
  s_t*ο[8]    = {b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]};
  Q_t α[4]    = {0, 0, 0, 0};
  Q_t ρ[8]    = {Σ, Σ, Σ, Σ, Σ, Σ, Σ, Σ};
  s_t*σ[4]    = {b[8], b[9], b[10], b[11]};
  Q_t Μ[8]    = {0, 1, 2, 2, 3, 3, 3, 1};
  Q_t Ι       = 0;
  for (Q_t i  = 0; i < 8; i++) {
    P(i, 0111, end, (i ? next1 : end), end);
    ο[i][0].v = ρ[i];
    ο[i][1].v = ρ[i];
    ο[i][2].v = ρ[i];
  }
  A(0, B);
  show(οαρσΜΣΙ);
}
