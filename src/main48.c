// clang-format off
typedef unsigned long Q_t;
typedef   signed long q_t;
typedef struct s_t {
  union {
    Q_t Q;
    struct s_t*s;
    void*v;
    void(*c)(struct s_t*ο, Q_t α, Q_t ρ, struct s_t*σ);
  };
} s_t;
#define A(...) {                                                    \
    void*s[] = {__VA_ARGS__};                                       \
    for(Q_t ξ = 0; ξ < sizeof(s)/sizeof(*s); ξ++) σ[α++].v = s[ξ]; }
#define R(...) {                                                    \
  void*s[]={__VA_ARGS__};                                           \
  Q_t ξ = sizeof(s)/sizeof(*s); while (ξ) ο[--ρ].v = s[--ξ]; }

#define N(name) void name(s_t*ο, Q_t α, Q_t ρ, s_t*σ)
#define G       printf("%lu %02lu %03lu %s\n", ο[3].Q, α, ρ, __FUNCTION__);
#define O       σ[α-1].c(ο, α-1, ρ, σ)
#include <stdio.h>

N(Nain) {G; O;}
#define Σ 4*128
N(God     ) { // G;
  Q_t ψ = ο[ρ++].Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
  ρ += notc;
  for (Q_t i = 0; i < andc; i++) σ[α++].v = ο[ρ++].v;
  ρ += oorc;
  andc ? O : God(ο, α, ρ, σ);
}
#include <unistd.h>
N(ray_oor ) {G; }
N(ray_and ) {G;
  s_t*curr_σ = ο[1].s;
  Q_t*curr_α = &curr_σ[0].Q;
  Q_t*curr_ρ = &ο[2].Q;
  *curr_α    = α;
  *curr_ρ    = ρ;
  while (α > 1)
    --α, printf("%lu .", σ[--α].Q);
  printf("\n");
  if(ο[3].Q ==0) return;
  sleep(1);
  s_t*next_ο =  ο[0].s;
  Q_t next_ρ = next_ο[2].Q;
  s_t*next_σ = next_ο[1].s;
  Q_t next_α = next_σ[0].Q;
  God(next_ο, next_α, next_ρ, next_σ); }
N(ray_not ) {G; }
N(B       ) {// G;
        α++, God(ο, α, ρ, σ); }
N(C       ) {//G;
        α++, God(ο, α, ρ, σ); }

N(one   ) { G;  R(020, 1, C) O; }
N(add   ) { G;  Q_t r = (--α, σ[--α].Q);
                Q_t l = (--α, σ[--α].Q);
                R(020, (l + r), C) O; }
N(two   ) { G;  R(010, one,   010, one,   010, add) O; }
N(three ) { G;  R(010, one,   010, two,   010, add) O; }
N(four  ) { G;  R(010, one,   010, three, 010, add) O; }
N(seven ) { G;  R(010, three, 010, four,  010, add) O; }
int main( ) {
  s_t σ[4][Σ];
  s_t ο[8][Σ];
  ο[0][0].v = ο[1]; ο[0][1].v = σ[0]; // ტექსტი
  ο[1][0].v = ο[2]; ο[1][1].v = σ[1]; // სახ.
  ο[2][0].v = ο[3]; ο[2][1].v = σ[2]; // მოთ.
  ο[3][0].v = ο[4]; ο[3][1].v = σ[2]; // მიც.
  ο[4][0].v = ο[5]; ο[4][1].v = σ[3]; // ნათ.
  ο[5][0].v = ο[6]; ο[5][1].v = σ[3]; // მოქ.
  ο[6][0].v = ο[7]; ο[6][1].v = σ[3]; // ვით.
  ο[7][0].v = ο[0]; ο[7][1].v = σ[1]; // წოდ.
  for (Q_t i = 0; i < 8; i++)
    ο[i][2].Q   = Σ-4,
    ο[i][3].Q   = i,
    ο[i][Σ-1].v = ray_oor,
    ο[i][Σ-2].v = ray_and,
    ο[i][Σ-3].v = ray_not,
    ο[i][Σ-4].v = 0111;

  σ[0][0].Q = 2; σ[0][1].v = B;
  σ[1][0].Q = 2; σ[1][1].v = B;
  σ[2][0].Q = 2; σ[2][1].v = B;
  σ[3][0].Q = 2; σ[3][1].v = B;
  seven(ο[0], σ[0][0].Q, ο[0][2].Q, σ[0]);
}
