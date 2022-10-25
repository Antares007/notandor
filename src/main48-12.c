// clang_format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t**ο,Q_t*α,Q_t*ρ,struct s_t**σ,Q_t*Μ,Q_t Ι,Q_t Σ);
}; } s_t;
#define OARS       s_t**ο,Q_t*α,Q_t*ρ,       s_t**σ,Q_t*Μ,Q_t Ι,Q_t Σ
#define οαρσΜΙΣ         ο,    α,    ρ,            σ,    Μ,    Ι,    Σ
#define L printf("%lu %02lu %03lu %s\n", Ι, α[Μ[Ι]], ρ[Ι], __FUNCTION__);
#include<stdio.h>
void God(OARS) {L;
  Q_t ψ = ο[Ι][ρ[Ι]++].Q, nc = ψ >> 6 & 7, ac = ψ >> 3 & 7, oc = ψ & 7;
  ρ[Ι] += nc;
  for (Q_t i = 0; i < ac; i++) σ[Μ[Ι]][α[Μ[Ι]]++].v = ο[Ι][ρ[Ι]++].v;
  ρ[Ι] += oc;
  ac ? σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ) : God(οαρσΜΙΣ);
}
void B        (OARS) {L;α[Μ[Ι]]++, God(ο,α,ρ,σ,Μ,7,Σ); }
void ray_God  (OARS) {L;if (Ι) God(ο,α,ρ,σ,Μ,(Ι+7)%8,Σ); }
void dot      (OARS) {L;σ[Μ[Ι]][--α[Μ[Ι]]].c(οαρσΜΙΣ); }
void mamam    (OARS) {L;dot(οαρσΜΙΣ); }
void shvils   (OARS) {L;dot(οαρσΜΙΣ); }
void sakhli   (OARS) {L;dot(οαρσΜΙΣ); }
void aushena  (OARS) {L;dot(οαρσΜΙΣ); }
void ntext    (OARS) {L;σ[Μ[Ι]][α[Μ[Ι]]++].v = mamam;
                        σ[Μ[Ι]][α[Μ[Ι]]++].v = shvils;
                        σ[Μ[Ι]][α[Μ[Ι]]++].v = sakhli;
                        σ[Μ[Ι]][α[Μ[Ι]]++].v = aushena;
                        dot(οαρσΜΙΣ); }
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
