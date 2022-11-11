typedef unsigned long Q_t;
#define OARS struct s_t *ο, struct s_t *α, struct s_t *ν, struct s_t *ρ, Q_t ι, struct s_t *σ, Q_t τ
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    struct s_t *s;
    void (*c)(OARS);
  };
} s_t;
#include <stdio.h>
#define LOG printf("%s\n", __FUNCTION__)
#define NUMARGS(...) (sizeof((const void*[]){__VA_ARGS__}) / sizeof(void*))
#define ΨX(X, ...) X = (s_t *)(const void *[]){X, 0, __VA_ARGS__},             \
                  (X += 2)[-1].Q = NUMARGS(__VA_ARGS__) 
#define Ψ__(...) ΨX(ν, cn, __VA_ARGS__)
#define Ψ_(...) ΨX(α, ca, __VA_ARGS__), Ψ__
#define Ψ(...) ΨX(ο, co, __VA_ARGS__), Ψ_
#define S(...) ΨX(ρ, ca, __VA_ARGS__), ι = ρ[-1].Q
#define O ρ[ι - 1].c(ο, α, ν, ρ, ι - 1, σ, τ)
#define D LOG, O 
#define C(x)                                                                   \
  ρ = x,                                                                       \
  ο = ο[-2].v,                                                                 \
  α = α[-2].v,                                                                 \
  ν = ν[-2].v,                                                                 \
  ι = ρ[-1].Q, D
void co  (OARS) { C(ο); }
void ca  (OARS) { C(α); }
void cn  (OARS) { C(ν); }
void e2   (OARS) { LOG; }
void e1   (OARS) { LOG; while(τ) printf("%lu ", σ[--τ].Q);printf("\n"); }
void e0   (OARS) { LOG; }
void one_ (OARS) { σ[τ++].Q = 1, C(α); }
void one  (OARS) { Ψ()(one_)(), D; }
void add_ (OARS) { Q_t r=σ[--τ].Q; Q_t l=σ[--τ].Q; σ[τ++].Q = l+r,C(α); }
void add  (OARS) { Ψ()(add_)(), D; }
void e    (OARS) { Ψ()()(), D; }
void t_   (OARS) { (void)ρ[--ι].v, C(α); }
void t    (OARS) { Ψ()(ρ[--ι].v, t_)(), D; }
void eOs_ (OARS) { S(e), D;
                   S("s", t), D; }
void eOs  (OARS) { Ψ()(eOs_)(), D;}
int main() {
  Q_t ι;
  s_t *ο, *α, *ν, *ρ = ο = α = ν = ι = 0;
  s_t σ[128];
  Q_t τ = 0;
  Ψ(e0)(e1)(e2);
  S(eOs), D;
  S(one, one, add, one, add), D;
  S(one, one, add, one, add, one, add, one, add, one, add, one, add), D;
}
