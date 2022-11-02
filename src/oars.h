#pragma once
// clang-format off
#define OARS        struct s_t**ο,Q_t*α,Q_t*ρ,struct s_t**σ,Q_t ι,Q_t*Μ,Q_t Σ 
#define T           ο, α, ρ, σ, ι, Μ, Σ
typedef unsigned long Q_t;
typedef struct s_t  {union{ void*v; Q_t Q; void(*c)(OARS); };} s_t;
#define N(a)        void a(OARS)
#define A(...)      { void*ζs[] = {__VA_ARGS__};                        \
                    for (Q_t ζi = 0;ζi < sizeof(ζs) / sizeof(*ζs);ζi++) \
                      σ[0][α[0]++].Q = ζs[ζi]; }
#define R(ι)        σ[ι][--α[ι]]
#define G(O, B, A)  void goto##O(OARS) {                                \
                    Q_t ψ = ο[ι][ρ[ι]++].Q,                             \
                    c2 = ψ>>6&7, c1 = ψ>>3&7, c0 = ψ>>0&7;              \
                    ρ[ι] += B;                                          \
                    for (Q_t i = 0; i < c##O; i++)                      \
                      σ[Μ[ι]][α[Μ[ι]]++].v = ο[ι][ρ[ι]++].v;            \
                    ρ[ι] += A;                                          \
                    c##O ? σ[Μ[ι]][--α[Μ[ι]]].c(T)                      \
                         :              goto##O(T); }
#define P(ι, ...)   { void*ζs[] = {__VA_ARGS__};                        \
                    Q_t ζi = sizeof(ζs) / sizeof(*ζs);                  \
                    while(ζi) ο[ι][--ρ[ι]].Q = ζs[--ζi]; }
