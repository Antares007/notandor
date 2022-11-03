#pragma once
#define OARS struct s_t *ο, Q_t α, Q_t ρ, struct s_t *σ
#define T                ο,     α,     ρ,             σ

typedef unsigned long Q_t;
typedef struct s_t {union{ void*v; Q_t Q; void(*c)(OARS); struct s_t*s; };} s_t;

#define N(argo)     void argo(OARS)
#define A(...)      { const void*ζs[] = {__VA_ARGS__};                         \
                    for (Q_t i = 0; i < sizeof(ζs) / sizeof(*ζs); i++)         \
                      σ[α++].v = (void*)ζs[i]; }
#define R           σ[--α]
#define G(_n,_b,_a) void c##_n(OARS) {                                        \
                    Q_t ψ = ο[ρ++].Q, ψ2 = ψ>>6&7, ψ1 = ψ>>3&7, ψ0 = ψ>>0&7;  \
                    ρ += _b;                                                  \
                    for (Q_t i = 0; i < ψ##_n; i++) σ[α++].v = ο[ρ++].v;      \
                    ρ += _a;                                                  \
                    ψ##_n ? O : c##_n(T); }
#define O           (--α, σ[α].c(T))
#define P(...)      { const void*ζs[] = {__VA_ARGS__};                        \
                    Q_t i = sizeof(ζs) / sizeof(*ζs);                         \
                    while(i) ο[--ρ].v = (void*)ζs[--i]; }
