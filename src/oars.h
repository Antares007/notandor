#pragma once
// clang-format off
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    const char *cs;
    void (*c)();
  };
} s_t;
#define N(name) void name(s_t **ο, Q_t *α, Q_t *ρ, Q_t σ)
#define A1(b) ο[σ][α[σ]++].v = (void*)b,
#include "evalmap.h"
#define A(...) EVAL(MAP(A1, __VA_ARGS__)) 
#define O α[σ]--, ο[σ][α[σ]].c(ο, α, ρ, σ)
#define C  (σ=(σ+1)%4),
#define CC (σ=(σ+3)%4),
// ψ α β ε
#include <stdio.h>

#define LOG printf("%lx %02lu %lu %lu %s\n",  \
    ((Q_t)ο[σ] >> (Q_t)12) & 0xfff,           \
    α[σ],                                     \
    ρ[σ],                                     \
    σ,                                        \
    __FUNCTION__)
