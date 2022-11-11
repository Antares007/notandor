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
#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
#define ΨX(X, ...) X = (s_t*)(const void*[]){0,0,__VA_ARGS__,ο,α,ρ}, X[0].Q=NUMARGS(__VA_ARGS__)+5
#define Ψ__(...) ΨX(ρ, __VA_ARGS__)
#define Ψ_(...)  ΨX(α, __VA_ARGS__),Ψ__
#define Ψ(...)   ΨX(ο, __VA_ARGS__),Ψ_
#define S(...) ΨX(σ, __VA_ARGS__), ι = NUMARGS(__VA_ARGS__) + 2
#define O σ[ι - 1].c(ο, α, ρ, σ, ι - 1)
#define D LOG, O
#define C(α)                                                                   \
  {                                                                            \
    s_t *o##α  = α;                                                            \
    ο          = o##α[o##α[0].Q - 3].v;                                        \
    α          = o##α[o##α[0].Q - 2].v;                                        \
    ρ          = o##α[o##α[0].Q - 1].v;                                        \
    o##α[1].v  = σ;                                                            \
    σ          = o##α;                                                         \
    ι          = σ[0].Q-3;                                                     \
  }                                                                            \
  D
void nar  (OARS) { C(α); }
void e2   (OARS) { LOG; }
void e1   (OARS) { printf("%lu\n", σ[1].s[2].Q); }
void e0   (OARS) { LOG; }
void ob   (OARS) { C(α); }
void os   (OARS) { σ = σ[ι-1].v; D; }
void one  (OARS) { Ψ(os)(1, ob)(os), D; }
void add_ (OARS) { Ψ(os)(σ[1].s[2].Q + σ[1].s[1].s[2].Q, ob)(os); C(α); }
void add  (OARS) { Ψ(os)(add_)(os), D; }
int main  () {
  Q_t ι;
  s_t *ο, *α, *ρ, *σ = ο = α = ρ = ι = 0;
  Ψ(e0)(e1)(e2);
  S(ob, one, one, add, one, add, one, add, one, add, one, add, one, add), D;
}
