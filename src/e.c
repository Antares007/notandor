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
#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))
#define ΨX(X, ...) X = (s_t *)(const void *[]){X, 0, __VA_ARGS__},             \
                  (X += 2)[-1].Q = NUMARGS(__VA_ARGS__)
#define Ψ__(...) ΨX(ν, __VA_ARGS__)
#define Ψ_(...) ΨX(α, __VA_ARGS__), Ψ__
#define Ψ(...) ΨX(ο, __VA_ARGS__), Ψ_
#define S(...) ΨX(ρ, __VA_ARGS__), ι = ρ[-1].Q
#define O ρ[ι - 1].c(ο, α, ν, ρ, ι - 1, σ, τ)
#define D O //LOG, 
#define C(α)                                                                   \
  ρ = α,                                                                       \
  ο = ο[-2].v,                                                                 \
  α = α[-2].v,                                                                 \
  ν = ν[-2].v,                                                                 \
  ι = ρ[-1].Q, D
void nar  (OARS) { C(α); }
void e2   (OARS) { LOG; }
void e1   (OARS) { LOG; printf("%lu %lu\n", τ, σ[τ-1].Q); }
void e0   (OARS) { LOG; }
void ob   (OARS) { C(α); }
void one_ (OARS) { σ[τ++].Q = 1, C(α); }
void one  (OARS) { Ψ()(one_)(), D; }
void add_ (OARS) { Q_t r=σ[--τ].Q; Q_t l=σ[--τ].Q; σ[τ++].Q = l+r,C(α); }
void add  (OARS) { Ψ()(add_)(), D; }
int main() {
  Q_t ι;
  s_t *ο, *α, *ν, *ρ = ο = α = ν = ι = 0;
  s_t σ[128];
  Q_t τ = 0;
  Ψ(e0)(e1)(e2);
  S(ob, one, one, add, one, add), D;
  S(ob, one, one, add, one, add, one, add, one, add, one, add, one, add), D;
}
