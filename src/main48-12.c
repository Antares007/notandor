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
#define R(i, ...) { void*s[]={__VA_ARGS__};                   \
                    Q_t ξ=sizeof(s)/sizeof(*s);               \
                    while(ξ)                                  \
                      ο[i][--ρ[i]].v = s[--ξ]; }
#define A(i, ...) { void*s[]={__VA_ARGS__};                   \
                    for(Q_t ξ=0; ξ<sizeof(s)/sizeof(*s);ξ++)  \
                      σ[Μ[i]][α[Μ[i]]++].v = s[ξ]; }
#include<stdio.h>
void Got      (OARS) { ;Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        for (Q_t i = 0; i < nc; i++) σ[Μ[Ι]][α[Μ[Ι]]++].v = ο[Ι][ρ[Ι]++].v;
                        ρ[Ι] += ac + oc;
                        nc ? σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ) : Got(οαρσΜΙΣ); }
void God      (OARS) { ;Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        ρ[Ι] += nc;
                        for (Q_t i = 0; i < ac; i++) σ[Μ[Ι]][α[Μ[Ι]]++].v = ο[Ι][ρ[Ι]++].v;
                        ρ[Ι] += oc;
                        ac ? σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ) : God(οαρσΜΙΣ); }
void Gor      (OARS) { ;Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
                        ρ[Ι] += nc + ac;
                        for (Q_t i = 0; i < oc; i++) σ[Μ[Ι]][α[Μ[Ι]]++].v = ο[Ι][ρ[Ι]++].v;
                        oc ? σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ) : Gor(οαρσΜΙΣ); }
void B        (OARS) { ;α[Μ[Ι]]++, God(οαρσΜ,7,Σ); }
void C        (OARS) { ;α[Μ[Ι]]++, God(οαρσΜΙΣ); }
void ray_God  (OARS) { ;if (Ι) God(οαρσΜ,(Ι+7)%8,Σ); }
void dot      (OARS) { ;σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ); }
void mama_    (OARS) {L;A(Ι, "მამა", C)   God(οαρσΜΙΣ); }
void mamam    (OARS) {L;R(2, 010, mama_)  dot(οαρσΜΙΣ); }
void shvil_   (OARS) {L;A(Ι, "შვილ", C)   God(οαρσΜΙΣ); }
void shvils   (OARS) {L;R(3, 010, shvil_) dot(οαρσΜΙΣ); }
void sakhl_   (OARS) {L;A(Ι, "სახლ", C)   God(οαρσΜΙΣ); }
void sakhli   (OARS) {L;R(1, 010, sakhl_) dot(οαρσΜΙΣ); }
void _shen_   (OARS) {L;Q_t pi3 = σ[Μ[Ι]][--α[Μ[Ι]]].Q;
                        Q_t pi2 = σ[Μ[Ι]][--α[Μ[Ι]]].Q;
                        Q_t pi1 = σ[Μ[Ι]][--α[Μ[Ι]]].Q;
                        printf("%lu %lu %lu\n", pi1, pi2, pi3);
                        const char* ps3 = (--α[Μ[pi3]], σ[Μ[pi3]][--α[Μ[pi3]]].Q);
                        const char* ps2 = (--α[Μ[pi2]], σ[Μ[pi2]][--α[Μ[pi2]]].Q);
                        const char* ps1 = (--α[Μ[pi1]], σ[Μ[pi1]][--α[Μ[pi1]]].Q);
                        printf("%s  %s  %s შენ.\n", ps1, ps2, ps3);
                        God(οαρσΜΙΣ); }
void aushena  (OARS) {L;R(Ι, 040, 2, 2, 1, _shen_) dot(οαρσΜΙΣ); }
void ntext    (OARS) {L;A(Ι, shvils, mamam, aushena, sakhli) dot(οαρσΜΙΣ); }
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
    ο[i][--ρ[i]].c  = ray_God;
    ο[i][--ρ[i]].Q  = 010;
  }
  σ[0][α[Μ[0]]++].c = B;
  ntext(οαρσΜΙΣ);
}
