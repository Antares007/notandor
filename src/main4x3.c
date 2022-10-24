typedef unsigned long Q_t;
typedef struct s_t {
  union {
    void *v;
    Q_t Q;
    void (*c)();
  };
} s_t;
#define OARS s_t **ο, Q_t *α, Q_t *ρ, Q_t σ

#define N(n) void n(OARS)
#define Ai(i, ...)                                                             \
  {                                                                            \
    void *s[] = {__VA_ARGS__};                                                 \
    Q_t ξ = sizeof(s) / sizeof(*s);                                            \
    while (ξ)                                                                  \
      ξ--, ο[i][--ρ[i]].v = s[ξ];                                              \
  }
#define As(...) Ai(σ, __VA_ARGS__)
#define G printf("%02lu %02lu %lu %s\n", σ, α[σ], ρ[σ], __FUNCTION__)
#define O α[σ]--, ο[σ][α[σ]].c(ο, α, ρ, σ)
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
  // G;
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
N(nar) { G; }
N(B) { G, α[σ]++, God(ο, α, ρ, σ); }
N(ray_nxt_not) { G, Got(ο, α, ρ, (σ + 3) % 4); }
N(ray_nxt_and) { G, God(ο, α, ρ, (σ + 3) % 4); }
N(ray_nxt_oor) { G, Gor(ο, α, ρ, (σ + 3) % 4); }
N(ray_end_not) { G, σ -= 4, Got(ο, α, ρ, (σ + 3) % 4); }
N(ray_end_and) {
  G;
  while (α[σ] > 1)
    --α[σ], printf("%lu ", ο[σ][--α[σ]].Q);
  printf("\n");
  σ -= 4, God(ο, α, ρ, (σ + 3) % 4);
}
N(ray_end_oor) { G, σ -= 4, Gor(ο, α, ρ, (σ + 3) % 4); }
N(one) {
  G;
  As(σ, 030, 1, B, God) O;
}
N(add) {
  G;
  Q_t r = (--α[σ], ο[σ][--α[σ]].Q);
  Q_t l = (--α[σ], ο[σ][--α[σ]].Q);
  As(σ, 030, (l + r), B, God) O;
}
N(two) {
  G;
  As(010, one, 010, one, 010, add) O;
}
N(three) {
  G;
  As(010, one, 010, two, 010, add) O;
}
N(four) {
  G;
  As(010, one, 010, three, 010, add) O;
}
N(seven) {
  G;
  As(010, three, 010, four, 010, add) O;
}
N(go) { G, O; }
int main() {
  s_t *ο[4] = {(s_t[4 * 128]){}, (s_t[4 * 128]){}, (s_t[4 * 128]){},
               (s_t[4 * 128]){}};
  Q_t α[4] = {0, 0, 0, 0}, ρ[4] = {4 * 128, 4 * 128, 4 * 128, 4 * 128}, σ = 0;
  for (Q_t i = 1; i < 4; i++) {
    ο[i][α[i]++].v = B;
    Ai(i, 0111, ray_end_not, ray_end_and, ray_end_oor)(void) 0;
  }
  ο[0][α[0]++].v = B;
  Ai(0, 0111, ray_end_not, ray_end_and, ray_end_oor)
  Ai(0, 010, seven) God(ο, α, ρ, σ);
}
