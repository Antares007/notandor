#pragma once
// clang-format off
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    void (*c)();
  };
} s_t;
#define N(name) void name(s_t *ο, Q_t α, Q_t ρ,  \
                          s_t *ο₂, Q_t α₂, Q_t ρ₂,  \
                          s_t *ο₃, Q_t α₃, Q_t ρ₃,  \
                          s_t *ο₄, Q_t α₄, Q_t ρ₄)
#define A1(b) ο[α++].v = (void*)b,
#include "evalmap.h"
#define A(...) EVAL(MAP(A1, __VA_ARGS__)) 
#define O α--, ο[α].c(ο, α, ρ, ο₂, α₂, ρ₂, ο₃, α₃, ρ₃, ο₄, α₄, ρ₄)
// ψ α β ε
#include <stdio.h>

#define LOG printf("%lx %02lu %lu %s\n", (Q_t)ο >> 12, α, ρ, __FUNCTION__)
