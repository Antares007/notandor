// clang-format off
typedef unsigned long Q_t;
#define OARS struct s_t**ο,                                         \
                    Q_t *α,                                         \
                    Q_t *ρ,                                         \
             struct s_t**σ,                                         \
                    Q_t  ι,                                         \
                    Q_t *Μ
typedef struct s_t {union{
  void*v;
  Q_t Q;
  void(*c)(OARS);
};} s_t;
#define L printf("%lu %lu %.2lu₀%.2lu₁%.2lu₂%.2lu₃ %.3lu %s\n", ι, Μ[ι], α[0], α[1], α[2], α[3], ρ[ι], __FUNCTION__);
#define N(a) void a(OARS)
#define A(ι, ...) {                                                 \
  void*s[]            = {__VA_ARGS__};                              \
  Q_t  αΜι            = α[Μ[ι]];                                    \
  for (Q_t i = 0;i < sizeof(s)/sizeof(*s);i++)                      \
    σ[Μ[ι]][αΜι++].Q  = s[i];                                       \
  α[Μ[ι]]             = αΜι;                                        \
}
#define R(ι) σ[Μ[ι]][--α[Μ[ι]]]
#define G(On, Be, Af)                                               \
  void goto##On(OARS) {                                             \
    Q_t ψ = ο[ι][ρ[ι]++].Q, c2 = ψ>>6&7, c1 = ψ>>3&7, c0 = ψ>>0&7;  \
    ρ[ι] += Be;                                                     \
    for (Q_t i = 0; i < c##On; i++)                                 \
      σ[Μ[ι]][α[Μ[ι]]++].v = ο[ι][ρ[ι]++].v;                        \
    ρ[ι] += Af;                                                     \
    c##On ? σ[Μ[ι]][--α[Μ[ι]]].c(ο, α, ρ, σ, ι, Μ)                  \
          :             goto##On(ο, α, ρ, σ, ι, Μ); }
#define O   σ[Μ[ι]][--α[Μ[ι]]].c(ο, α, ρ, σ, ι, Μ)
#define P(ι, ...) {                                                 \
  void*s[]   = {__VA_ARGS__};                                       \
  Q_t  size  = sizeof(s)/sizeof(*s);                                \
  Q_t  ρι    = ρ[ι];                                                \
  while(size)  ο[ι][--ρι].Q = s[--size];                            \
  ρ[ι]       = ρι;                                                  \
}
#define T(ι) ο[ι][ρ[ι]++]
#include <assert.h>
#include <stdio.h>
G(2,00,c1+c0);
G(1,c2,00+c0);
G(0,c2+c1,00);
#undef G
void B(OARS) { L;
  A(ι, B); goto1(ο,α,ρ,σ,(ι+7)%8,Μ);
}
N(end ) { L; }
N(end2) { L; σ[Μ[ι]][α[Μ[ι]]++].Q = 2; }
N(end1) { L; σ[Μ[ι]][α[Μ[ι]]++].Q = 1; }
N(end0) { L; σ[Μ[ι]][α[Μ[ι]]++].Q = 0; }
N(nxt2) { L; goto2(ο,α,ρ,σ,(ι+7)%8,Μ); }
N(nxt1) { L; goto1(ο,α,ρ,σ,(ι+7)%8,Μ); }
N(nxt0) { L; goto0(ο,α,ρ,σ,(ι+7)%8,Μ); }
N(და  ) { L; 
  for (Q_t i = 0; i < 8; i++)
    P((ι+i)%8, 0111, i?nxt2:end2, i?nxt1:end1, i?nxt0:end0);
  σ[Μ[ι]][--α[Μ[ι]]].c(ο,α,ρ,σ,ι, (Q_t[]){0,0,0,0,0,0,0,0});
  Q_t ψ = R(ι).Q;
  printf("%lu\n", ψ);
  if(ψ == 1) goto1(ο,α,ρ,σ,(ι+7)%8,Μ);
  else A(ι, ψ);
}
N(C         ) {L; A(ι, C) goto1(ο,α,ρ,σ,ι,Μ); }
N(mama_     ) {L; A(ι+0, "მამა", C)   goto1(ο,α,ρ,σ,ι,Μ); }
N(mamam     ) {L; P(ι+2, 010, mama_)  O; }
N(shvil_    ) {L; A(ι+0, "შვილ", C)   goto1(ο,α,ρ,σ,ι,Μ); }
N(shvils    ) {L; P(ι+3, 010, shvil_) O; }
N(sakhl_    ) {L; A(ι+0, "სახლ", C)   goto1(ο,α,ρ,σ,ι,Μ); }
N(sakhli    ) {L; P(ι+1, 010, sakhl_) O; }
N(_shen_    ) {L; const char* Oi = (assert(R(3).v==C), R(3).Q);
                  const char* S  = (assert(R(3).v==C), R(3).Q);
                  const char* Op = (assert(R(3).v==C), R(3).Q);
                  printf("%s  %s  %s.\n", S, Op, Oi);
                  goto1(ο,α,ρ,σ,ι,Μ); }
N(aushena   ) {L; P(ι, 010, _shen_);
                  R(ι).c(ο,α,ρ,σ,ι,(Q_t[]){
                    0,3,3,3,0,0,0,0
                  }); }
void nar(OARS) { L;
  A(ι, mamam, shvils, sakhli, aushena, 
   და, mamam, sakhli, aushena, shvils, 
  ) O;
}
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
    P((ι+i)%8, 0111, i?nxt2:end2, i?nxt1:end1, i?nxt0:end0);
  A(ι, B);
  nar(ο, α, ρ, σ, ι, Μ);
}
