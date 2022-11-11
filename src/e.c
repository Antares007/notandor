typedef unsigned long Q_t;
#define OARS struct s_t *ο, struct s_t *α, struct s_t *ρ, struct s_t *σ, Q_t ι
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    struct s_t *s;
    void (*c)(OARS);
  };
} s_t;
//Ν(one       ) { N(040, 1, bo, 1, c)  D; }
//Ν(add_      ) { Q_t r = (--ρ, σ[--ρ].Q);
//                Q_t l = (--ρ, σ[--ρ].Q);
//                S(r+l, bo) D; }
//Ν(add       ) { N(010, add_)  D; }
//Ν(seven     ) { S(bo, one,
//                      one, add,
//                      one, add,
//                      one, add,
//                      one, add,
//                      one, add,
//                      one, add) D; }
#include <stdio.h>
#define LOG printf("%s\n", __FUNCTION__)
#define O σ[ι - 1].c(ο, α, ρ, σ, ι - 1)
#define D LOG, O
#define C(α)                                                                   \
  {                                                                            \
    s_t *o##α  = α;                                                            \
    ο          = o##α[o##α[0].Q - 3].v;                                        \
    α          = o##α[o##α[0].Q - 2].v;                                        \
    ρ          = o##α[o##α[0].Q - 1].v;                                        \
    o##α[0].Q -= 3;                                                            \
    o##α[1].v  = σ;                                                            \
    σ          = o##α;                                                         \
    ι          = σ[0].Q;                                                       \
  }                                                                            \
  D
void nar(OARS) { C(α); }
void e2(OARS) { LOG; }
void e1(OARS) { printf("%lu\n", σ[1].s[2].Q); }
void e0(OARS) { LOG; }
void ob(OARS) { C(α); }
void os(OARS) { σ = σ[ι-1].v; D; }
void one(OARS) {
  ο = (s_t[]){{{6}}, {{σ}}, {{os}},         {{ο}},{{α}},{{ρ}}};
  α = (s_t[]){{{7}}, {{σ}}, {{1 }}, {{ob}}, {{ο}},{{α}},{{ρ}}};
  ρ = (s_t[]){{{6}}, {{σ}}, {{os}},         {{ο}},{{α}},{{ρ}}};
  D;
}
void add_(OARS) { 
  ο = (s_t[]){{{6}}, {{σ}}, {{os}},         {{ο}},{{α}},{{ρ}}};
  α = (s_t[]){{{7}}, {{σ}}, {{σ[1].s[2].Q + σ[1].s[1].s[2].Q }}, {{ob}}, {{ο}},{{α}},{{ρ}}};
  ρ = (s_t[]){{{6}}, {{σ}}, {{os}},         {{ο}},{{α}},{{ρ}}};
  C(α);
}
void add(OARS) {
  ο = (s_t[]){{{6}}, {{σ}}, {{os  }}, {{ο}},{{α}},{{ρ}}};
  α = (s_t[]){{{6}}, {{σ}}, {{add_}}, {{ο}},{{α}},{{ρ}}};
  ρ = (s_t[]){{{6}}, {{σ}}, {{os  }}, {{ο}},{{α}},{{ρ}}};
  D;
}
int main() {
  s_t ο[] = {{{6}}, {{0}}, {{e0}}, {{0}}, {{0}}, {{0}}};
  s_t α[] = {{{6}}, {{0}}, {{e1}}, {{0}}, {{0}}, {{0}}};
  s_t ρ[] = {{{6}}, {{0}}, {{e2}}, {{0}}, {{0}}, {{0}}};
  s_t σ[] = {{{16}}, {{0}}, {{ob}}, {{one}}, {{one}}, {{add}},
                                             {{one}}, {{add}},
                                             {{one}}, {{add}},
                                             {{one}}, {{add}},
                                             {{one}}, {{add}},
                                             {{one}}, {{add}},
                                            };
  Q_t ι   = σ[0].Q;
  D;
}
