#pragma once
/*                       Notandor / არადანი
                                  .
               init               .           next
        .................................................
            σ[α] M  ο[ρ]          .            M
              ↓  M    ↓           .            M
        σ→NNNn○○ ο→○○GOAN         .            M
                 M                .            M
                 M                .            ο
                 M                .   σ→NNN○○○ ο→GnGOAN
                 M                .        ↑   M ↑ 
                 M                .      σ[α]  M ο[ρ]
                                  .
                             ο[p] = 0777

  The protocol of "Notandor/არადანი" gives us the power to specify
  everything in the M-words. We need to do so because the M-words
  are the only language we have from the beginning within the CPU.
  We need to start to specify things using language and not data
  structures. */
// clang-format off
#include <stdint.h>
typedef  int8_t  b_t; typedef  int16_t w_t; typedef  int32_t d_t; typedef  int64_t q_t;
typedef uint8_t  B_t; typedef uint16_t W_t; typedef uint32_t D_t; typedef uint64_t Q_t;
typedef struct p_t {
  union {
    struct p_t *p;
    void (*c)(struct p_t *ο, Q_t α, Q_t ρ, struct p_t *σ);
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OARS  p_t *ο, Q_t α, Q_t ρ, p_t *σ 
typedef void (*n_t)(OARS);

#define N(n)    void n(OARS)
#define A_(vs)   σ[α++].v = (void *)(vs),
#define R(T, n) T n = (T)σ[--α].v
#define O       σ[α - 1].c(ο, α - 1, ρ, σ)

#define ALIGN(O, A) ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T) ALIGN(sizeof(T), sizeof(void*))

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#include "evalmap.h"
#define A(...) EVAL(MAP(A_, __VA_ARGS__))

