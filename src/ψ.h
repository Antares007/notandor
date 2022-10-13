#pragma once
/*                   Notandor / არადანი

                              .
               init           .           next
        .............................................
          ν      ○ ← ο        .            ○ ← ο
          ↓     \○/           .     ν      ○
          nnn○○○○○○○○○○○○     .     ↓     \○/
             ↑  /○\           .     nnn○○○○○○○○○○○○
           ν[τ]  ψ ← ο[α]     .        ↑  /ψ\ ← ο[α]
                 o            .      ν[τ]  o         
                 a            .            a         
                 n            .            n
                              .

            ο[α] = 0x010101           ο[α] = 0x000100

  The protocol of "Notandor/არადანი" gives us the power to specify
  everything in the M-words. We need to do so because the M-words
  are the only language we have from the beginning within the CPU.
  We need to start to specify things using language and not data
  structures. */
// clang-format off
typedef   signed char b_t; typedef   signed short w_t;
typedef unsigned char B_t; typedef unsigned short W_t;
typedef   signed int  d_t; typedef   signed long  q_t;
typedef unsigned int  D_t; typedef unsigned long  Q_t;
typedef struct p_t {
  union {
    struct p_t *p;
    void (*c)(struct p_t *ο, Q_t α, Q_t ν);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OANT p_t *ο, Q_t α, Q_t ν 
#define Τ         ο,     α,     ν 
typedef void (*n_t)(OANT);

#define N(n)    void n(OANT)
#define A_(vs)  ο[ν++].v = (void *)(vs),
#define R(T, n) T n = (T)ο[--ν].v
#define Ο       ο[ν - 1].c(ο, α, ν - 1)
#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "evalmap.h"
#define A(...) EVAL(MAP(A_, __VA_ARGS__)) Ο
#define Σ 512
