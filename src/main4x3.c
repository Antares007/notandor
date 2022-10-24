// clang-format off
typedef unsigned long Q_t;
typedef struct s_t { union {
    void *v;
    Q_t Q;
    void (*c)();
  }; } s_t;
#define OARS s_t **ο, Q_t *α, Q_t *ρ, Q_t σ

#define N(n) void n(OARS)
#define A(...) As(σ, __VA_ARGS__)
#define R(...) Rs(σ, __VA_ARGS__)
#define G printf("%lu %02lu %02lu %s\n", σ, α[σ], ρ[σ], __FUNCTION__)
#define O α[σ]--, ο[σ][α[σ]].c(ο, α, ρ, σ)

#define As(i, ...)                                                             \
  {                                                                            \
    void *s[] = {__VA_ARGS__};                                                 \
    for (Q_t ξ = 0; ξ < sizeof(s) / sizeof(*s); ξ++)                           \
      ο[i][α[i]++].v = s[ξ];                                                   \
  }
#define Rs(i, ...)                                                             \
  {                                                                            \
    void *s[] = {__VA_ARGS__};                                                 \
    Q_t ξ = sizeof(s) / sizeof(*s);                                            \
    while (ξ)                                                                  \
      ξ--, ο[i][--ρ[i]].v = s[ξ];                                              \
  }

#include <stdio.h>
N(Got) {
  G;
  Q_t ψ = ο[σ][ρ[σ]++].Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
  for (Q_t i = 0; i < notc; i++)
    ο[σ][α[σ]++].v = ο[σ][ρ[σ]++].v;
  ρ[σ] += andc + oorc;
  notc ? O : Got(ο, α, ρ, σ);
}
N(God) {
  G;
  Q_t ψ = ο[σ][ρ[σ]++].Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
  ρ[σ] += notc;
  for (Q_t i = 0; i < andc; i++)
    ο[σ][α[σ]++].v = ο[σ][ρ[σ]++].v;
  ρ[σ] += oorc;
  andc ? O : God(ο, α, ρ, σ);
}
N(Gor) {
  G;
  Q_t ψ = ο[σ][ρ[σ]++].Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
  ρ[σ] += notc + andc;
  for (Q_t i = 0; i < oorc; i++)
    ο[σ][α[σ]++].v = ο[σ][ρ[σ]++].v;
  oorc ? O : Gor(ο, α, ρ, σ);
}
N(B) { G, α[σ]++, God(ο, α, ρ, σ); }
N(ray_nxt_not) { G, Got(ο, α, ρ, (σ + 4) % 5); }
N(ray_nxt_and) { G, God(ο, α, ρ, (σ + 4) % 5); }
N(ray_nxt_oor) { G, Gor(ο, α, ρ, (σ + 4) % 5); }
#include <unistd.h>
N(ray_end_not) { G, sleep(1), ρ[σ] -= 4, Got(ο, α, ρ, (σ + 4) % 5); }
N(ray_end_and) {
  G; //while (α[σ] > 1) --α[σ], printf("%lu ", ο[σ][--α[σ]].Q); printf("\n");
  sleep(1), ρ[σ] -= 4, God(ο, α, ρ, (σ + 4) % 5);
}
N(ray_end_oor) { G, sleep(1), ρ[σ] -= 4, Gor(ο, α, ρ, (σ + 4) % 5); }

N(shvilφ) { G; A("შვილ", B) O; }
N(shvils) { G; Rs(2, 010, shvilφ) O; }

N(mamaφ) { G; A("მამა", B) O; }
N(mamam) { G; Rs(2, 010, mamaφ) O; }

N(sakhlφ  ) { G; A("სახლ", B) O; }
N(sakhli  ) { G; Rs(1, 010, sakhlφ) O; }

N(shenφ   ) { G; Q_t o2s = ο[σ][--α[σ]].Q;
                 Q_t o1s = ο[σ][--α[σ]].Q;
                 Q_t s_s = ο[σ][--α[σ]].Q;
                 const char* o2 = (--α[o2s], ο[o2s][--α[o2s]].v);
                 const char* o1 = (--α[o1s], ο[o1s][--α[o1s]].v);
                 const char* s_ = (--α[s_s], ο[s_s][--α[s_s]].v);
                 printf("%s %s %s\n", s_, o1, o2);
                 O; }
N(aushena ) { G; Rs(0, 040, 2, 2, 1, shenφ) O; }

N(ntext) { G; A(mamam, aushena, shvils, sakhli) O; }

N(one   ) { G;  R(σ, 030, 1, B, God) O; }
N(add   ) { G;  Q_t r = (--α[σ], ο[σ][--α[σ]].Q);
                Q_t l = (--α[σ], ο[σ][--α[σ]].Q);
                R(σ, 030, (l + r), B, God) O; }
N(two   ) { G;  R(010, one, 010, one, 010, add) O; }
N(three ) { G;  R(010, one, 010, two, 010, add) O; }
N(four  ) { G;  R(010, one, 010, three, 010, add) O; }
N(seven ) { G;  R(010, three, 010, four, 010, add) O; }
int main() {
  s_t*ο[5] = {(s_t[4*128]){}, (s_t[4*128]){}, (s_t[4*128]){},
              (s_t[4*128]){}, (s_t[4*128]){}};
  Q_t α[5] = {0, 0, 0, 0, 0},
      ρ[5] = {4*128, 4*128, 4*128, 4*128, 4*128},
      σ = 4;
  for (Q_t i = 0; i < 5; i++) {
    ο[i][α[i]++].v = B;
    Rs(i, 0111, ray_end_not, ray_end_and, ray_end_oor)(void) 0;
  }
  A(ntext) O;
}
