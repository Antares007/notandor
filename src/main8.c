#include <stdio.h>
// clang-format off
typedef unsigned long Q_t;
typedef struct s_t { union {
  Q_t Q;
  void *v;
  void (*c)(struct s_t *ο, Q_t α, struct s_t **ρ, Q_t σ);
  const char *cs;
}; } s_t;
#define OARS      s_t *ο, Q_t α, s_t **ρ, Q_t σ
#define Τ         ο, α, ρ, σ
#define N(name)   void name(OARS)
#define Ǎ(b)      ο[α++].v = (void *)b,
#define A(...)    EVAL(MAP(Ǎ, __VA_ARGS__))
#define Ř_(b)     (void *)b,
#define Ř(r)      (*--ρ[r]).v = Ř_
#define R(r, ...) EVAL(MAP(Ř(r), __VA_ARGS__))
#define G         //printf("%02lu ρ%lu %s\n", α, σ, __FUNCTION__)
#define O         ο[α - 1].c(ο, α - 1, ρ, σ)
#include "evalmap.h"
N(Got         ) {     Q_t ψ = (*ρ[σ]++).Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
                      for (Q_t i = 0; i < notc; i++)
                        ο[α++].v = (*ρ[σ]++).v;
                      ρ[σ] += andc + oorc;
                      (notc) ? O : Got(Τ); }
N(God         ) {     Q_t ψ = (*ρ[σ]++).Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
                      ρ[σ] += notc;
                      for (Q_t i = 0; i < andc; i++)
                        ο[α++].v = (*ρ[σ]++).v;
                      ρ[σ] += oorc;
                      (andc) ? O : God(Τ); }
N(Gor         ) {     Q_t ψ = (*ρ[σ]++).Q, notc = ψ >> 6 & 7, andc = ψ >> 3 & 7, oorc = ψ & 7;
                      ρ[σ] += notc + andc;
                      for (Q_t i = 0; i < oorc; i++)
                        ο[α++].v = (*ρ[σ]++).v;
                      (oorc) ? O : Gor(Τ); }
N(mamamφ      ) { G;  A("მამა", God) O; }
N(mamam       ) { G;  R(2, mamamφ, 010) O; }
N(shvilφ      ) { G;  A("შვილ", God) O; }
N(shvils      ) { G;  R(3, shvilφ, 010) O; }
N(sakhlφ      ) { G;  A("სახლ", God) O; }
N(sakhli      ) { G;  R(1, sakhlφ, 010) O; }
N(shenφ       ) { G;  const char *p3 = ο[--α].cs;
                      const char *p2 = ο[--α].cs;
                      const char *p1 = ο[--α].cs;
                      printf("%s %s %s\n", p1, p2, p3);
                      A(God) O; }
N(aushena     ) { G;  R(0, shenφ, 010) O; }
void da(OARS);
N(dedaφ       ) { G;  A("დედა", God) O; }
N(dedam       ) { G;  R(2, dedaφ, 010) O; }
N(gemrielφ    ) { G;  A("გემრიელ", God) O; }
N(gemrieli    ) { G;  R(1, gemrielφ, 010) O; }
N(namckhvarφ  ) { G;  A("ნამცხვარ", God) O; }
N(namckhvari  ) { G;  R(1, namckhvarφ, 010) O; }
N(ackhφ       ) { G;  const char *p3 = ο[--α].cs;
                      const char *p2 = ο[--α].cs;
                      const char *p1 = ο[--α].cs;
                      printf("%s %s %s\n", p1, p2, p3);
                      A(God) O; }
N(gamoackho   ) { G;  R(0, ackhφ, 010) O; }
N(show        ) { G;  A(aushena, sakhli, mamam, shvils,
                        da,
                        gamoackho, dedam, gemrieli, namckhvari) O; }

N(B           ) { G;  α++, God(ο, α, ρ, 7); }
N(ray_next_Gor) { G;  Gor(ο, α, ρ, σ = (σ + 6) % 7); }
N(ray_next_God) { G;  God(ο, α, ρ, σ = (σ + 6) % 7); }
N(ray_next_Got) { G;  Got(ο, α, ρ, σ = (σ + 6) % 7); }
N(ray_end_Gor ) { G;  }
N(ray_end_God ) { G;  }
N(ray_end_Got ) { G;  }
#include <assert.h>
int main(     ) {     s_t ο[9 * 150], *ρ[8];
                      Q_t α = 0, σ = 0;
                      for (Q_t i = 1; i < 8; i++) 
                        ρ[i] = ο + (i + 1) * 150 + 150,
                        (*--ρ[i]).v = ray_next_Gor,
                        (*--ρ[i]).v = ray_next_God,
                        (*--ρ[i]).v = ray_next_Got,
                        (*--ρ[i]).Q = 0111;
                      assert(ρ[7] == ο + sizeof(ο) / sizeof(*ο) - 4);
                      ρ[0] = ο + 150 + 150,
                      (*--ρ[0]).v = ray_end_Gor,
                      (*--ρ[0]).v = ray_end_God,
                      (*--ρ[0]).v = ray_end_Got,
                      (*--ρ[0]).Q = 0111;
                      A(B, show) O;
                      return 0; }
N(ray_con_Gor ) { G;  Gor(ο, α, ρ, 7); }
N(ray_con_God ) { G;  God(ο, α, ρ, 7); }
N(ray_con_Got ) { G;  Got(ο, α, ρ, 7); }
N(da          ) { G;  for (Q_t i = 1; i < 8; i++) 
                        (*--ρ[i]).v = ray_next_Gor,
                        (*--ρ[i]).v = ray_next_God,
                        (*--ρ[i]).v = ray_next_Got,
                        (*--ρ[i]).Q = 0111;
                      (*--ρ[0]).v = ray_con_Gor,
                      (*--ρ[0]).v = ray_con_God,
                      (*--ρ[0]).v = ray_con_Got,
                      (*--ρ[0]).Q = 0111;
                      O; }
