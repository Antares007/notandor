// clang-format off
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    struct s_t*s;
    void*v;
    void(*c)(struct s_t*ο, Q_t α, Q_t ρ, struct s_t*σ);
  };
} s_t;
#define Ai(i, ...)                                \
  {                                               \
    void*s[]={__VA_ARGS__};                       \
    for(Q_t ξ=0; ξ < sizeof(s)/sizeof(*s); ξ++)   \
      ; \
  }}
#define N(name) void name(s_t*ο, Q_t α, Q_t ρ, s_t*σ)
#define G       printf("%lu %02lu %03lu %s\n", ο[4].Q, α, ρ, __FUNCTION__);
#define O       σ[α-1].c(ο, α-1, ρ, σ)
#include <stdio.h>

N(Nain) {G; O;}
#define Σ 4*128
N(God     ) {G;
  Q_t ψ = ο[ρ++].Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
  ρ += notc;
  for (Q_t i = 0; i < andc; i++) σ[α++].v = ο[ρ++].v;
  ρ += oorc;
  andc ? O : God(ο, α, ρ, σ);
}
N(ray_oor ) {G; }
N(ray_and ) {G; ο[1].Q = α, God(ο[0].s, ο[0].s[1].Q, ο[0].s[2].Q, ο[0].s[3].s); }
N(ray_not ) {G; }
N(B       ) {G; God(ο, α+1, ρ, σ); }
int main( ) {
  s_t ο[8][Σ];
  s_t σ[4][Σ];
  ο[0][0].v = ο[1]; ο[0][3].v = σ[0]; // ტექსტი
  ο[1][0].v = ο[2]; ο[1][3].v = σ[1]; // სახ.
  ο[2][0].v = ο[3]; ο[2][3].v = σ[2]; // მოთ.
  ο[3][0].v = ο[4]; ο[3][3].v = σ[2]; // მიც.
  ο[4][0].v = ο[5]; ο[4][3].v = σ[3]; // ნათ.
  ο[5][0].v = ο[6]; ο[5][3].v = σ[3]; // მოქ.
  ο[6][0].v = ο[7]; ο[6][3].v = σ[3]; // ვით.
  ο[7][0].v = ο[0]; ο[7][3].v = σ[1]; // წოდ.
  for (Q_t i = 0; i < 4; i++)
    σ[i][0].Q   = B;
  for (Q_t i = 0; i < 8; i++)
    ο[i][1].Q   = 1,
    ο[i][2].Q   = Σ-4,
    ο[i][4].Q   = i,
    ο[i][Σ-1].v = ray_oor,
    ο[i][Σ-2].v = ray_and,
    ο[i][Σ-3].v = ray_not,
    ο[i][Σ-4].v = 0111;
  Nain(ο[0], 1, Σ-4, σ[0]);
}
