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
#include <stdio.h>
#define LOG printf("%s\n", __FUNCTION__)
#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))
#define ΨX(X, ...) X = (s_t *)(const void *[]){X, 0, __VA_ARGS__},  \
                  (X += 2)[-1].Q = NUMARGS(__VA_ARGS__)
#define Ψ__(...) ΨX(ρ, __VA_ARGS__)
#define Ψ_(...) ΨX(α, __VA_ARGS__), Ψ__
#define Ψ(...) ΨX(ο, __VA_ARGS__), Ψ_
#define S(...) ΨX(σ, __VA_ARGS__), ι = σ[-1].Q
#define O σ[ι - 1].c(ο, α, ρ, σ, ι - 1)
#define D O //LOG, 
#define C(α)                                                                   \
  σ = α,                                                                       \
  ο = ο[-2].v,                                                             \
  α = α[-2].v,                                                             \
  ρ = ρ[-2].v,                                                             \
  ι = σ[-1].Q, D
void nar  (OARS) { C(α); }
void e2   (OARS) { LOG; }
void e1   (OARS) { LOG; printf("\n"); }
void e0   (OARS) { LOG; }
void ob   (OARS) { C(α); }
void os   (OARS) { σ = σ[ι - 1].v, D; }
void one_ (OARS) { C(α); }
void one  (OARS) { Ψ(os)(one_)(os), D; }
void add_ (OARS) { C(α); }
void add  (OARS) { Ψ(os)(add_)(os), D; }
int main() {
  Q_t ι;
  s_t *ο, *α, *ρ, *σ = ο = α = ρ = ι = 0;
  Ψ(e0)(e1)(e2);
  S(ob, one, one, add), D;
  S(ob, one, one, add), D;
}
