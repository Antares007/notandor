#pragma once
// clang-format off
typedef unsigned long Q_t;
#include <assert.h>
#define OARS struct s_t*ο, Q_t α, Q_t ρ, struct s_t*σ
#define oars            ο,     α,     ρ,            σ
typedef struct s_t {union{Q_t Q;void*v;void(*c)(OARS);};} s_t;
#define Ν(argo  ) void argo(OARS)
#define N(...   ) { const void *ϋ[] = {__VA_ARGS__};                          \
                    Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                    while (size) ο[--α].v = (void*)ϋ[--size]; }
#define S(...   ) { const void *ϋ[] = {__VA_ARGS__};                          \
                    Q_t size = sizeof(ϋ) / sizeof(*ϋ);                        \
                    for (Q_t i=0; i<size; i++) σ[ρ++].v = (void*)ϋ[i]; }
#define D         (--ρ, σ[ρ].c(oars))
