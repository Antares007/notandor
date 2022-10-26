// clang_format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t**ο,Q_t*α,Q_t*ρ,struct s_t**σ,Q_t*Μ,Q_t Ι,Q_t Σ);
}; } s_t;
#define OARS       s_t**ο,Q_t*α,Q_t*ρ,       s_t**σ,Q_t*Μ,Q_t Ι,Q_t Σ
#define οαρσΜΙΣ         ο,    α,    ρ,            σ,    Μ,    Ι,    Σ
#define οαρσΜ           ο,    α,    ρ,            σ,    Μ
#define L printf("%lu %02lu %03lu %s\n", Ι, α[Μ[Ι]], ρ[Ι], __FUNCTION__);

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
void go2      (OARS) { ;Q_t ψ = T(Ι).Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                        ρ[Ι] += ac + oc;
                        nc ? R(Ι).c(οαρσΜΙΣ) : go2(οαρσΜΙΣ); }
void go1      (OARS) { ;Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        ρ[Ι] += nc;
                        for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                        ρ[Ι] += oc;
                        ac ? R(Ι).c(οαρσΜΙΣ) : go1(οαρσΜΙΣ); }
void go0      (OARS) { ;Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        ρ[Ι] += nc + ac;
                        for (Q_t i = 0; i < ac; i++) A(Ι, T(Ι).v);
                        oc ? R(Ι).c(οαρσΜΙΣ) : go0(οαρσΜΙΣ); }
void B        (OARS) { ;A(Ι, B) go1(οαρσΜ,7,Σ); }
void C        (OARS) { ;A(Ι, C) go1(οαρσΜΙΣ); }
void end      (OARS) { ; }
void next1    (OARS) {L;go1(οαρσΜ,(Ι+7)%8,Σ); }

void mama_    (OARS) {L;A(Ι, "მამა", C)   go1(οαρσΜΙΣ); }
void mamam    (OARS) {L;P(2, 010, mama_)  R(Ι).c(οαρσΜΙΣ); }
void shvil_   (OARS) {L;A(Ι, "შვილ", C)   go1(οαρσΜΙΣ); }
void shvils   (OARS) {L;P(3, 010, shvil_) R(Ι).c(οαρσΜΙΣ); }
void sakhl_   (OARS) {L;A(Ι, "სახლ", C)   go1(οαρσΜΙΣ); }
void sakhli   (OARS) {L;P(1, 010, sakhl_) R(Ι).c(οαρσΜΙΣ); }
void _shen_   (OARS) {L;Q_t pi3 = R(Ι).Q;
                        Q_t pi2 = R(Ι).Q;
                        Q_t pi1 = R(Ι).Q;
                        printf("%lu %lu %lu\n", pi1, pi2, pi3);
                        const char* ps3 = (assert(R(pi3).v==C), R(pi3).Q);
                        const char* ps2 = (assert(R(pi2).v==C), R(pi2).Q);
                        const char* ps1 = (assert(R(pi1).v==C), R(pi1).Q);
                        printf("%s  %s  %s შენ.\n", ps1, ps2, ps3);
                        go1(οαρσΜΙΣ); }
void aushena  (OARS) {L;P(Ι, 040, 2, 2, 1, _shen_) R(Ι).c(οαρσΜΙΣ); }
void ntext    (OARS) {L;A(Ι, shvils, mamam, aushena, sakhli) R(Ι).c(οαρσΜΙΣ); }
int main() {
  Q_t Σ;
  s_t b[12][Σ = 512];
  s_t*ο[8]    = {b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]};
  Q_t α[4]    = {0, 0, 0, 0};
  Q_t ρ[8]    = {Σ, Σ, Σ, Σ, Σ, Σ, Σ, Σ};
  s_t*σ[4]    = {b[8], b[9], b[10], b[11]};
  Q_t Μ[8]    = {0, 1, 2, 2, 3, 3, 3, 1};
  Q_t Ι       = 0;
  for (Q_t i  = 0; i < 8; i++)
    P(i, 0111, end, (i ? next1 : end), end)
  A(0, B);
  ntext(οαρσΜΙΣ);
}
