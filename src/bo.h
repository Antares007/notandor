#pragma once
/*                   Notandor / არადანი

                    β☆ ο₀  α₀   ν₀   σ    β☆ ο₀  α₀    ν₀  σ
                       ┗━━━━━━┳━━━━━━┛       ┗━━━━━━┳━━━━━━┛ 
     ┏━┳━┳━┳━┳━┳━┓            ┃ρ            ┓       ┃       ┏ο₁   
     ┃ ┃ ┃ ┃ ┃ ┃ ┃            ┃             ┃       ┃       ┃      
     ┣━╋━╋━╋━╋━╋━┫            ┃           ν₃┃       ┻       ┃α₁     
     ┣━╋━╋━╋━╋━╋━┫            ┃             ┣━━━━━━┫ρ┣━━━━━━┫
     ┃ ┃ ┃ ┃ ┃ ┃ ┃            ┃           α₃┃       ┳       ┃ν₁     
     ┣━╋━╋━╋━╋━╋━┫            ┃             ┃       ┃       ┃      
     ┗━┻━┻━┻━┻━┻━┛            ┻           ο₃┛       ┃       ┗      
                                             ┏━━━━━━┻━━━━━━┓
                                                 ν₂    α₂  ο₂ */
typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    void (*go)();
  };
} s_t;

#define OARS s_t *ω, Q_t α, Q_t ρ, s_t *σ
#define N(narname) void narname(OARS)
#define Τ ω, α, ρ, σ
#define Α(val) ω[α++].v = (void *)val,
#include "evalmap.h"
#define A(...) EVAL(MAP(Α, __VA_ARGS__)) ω[α - 1].go(ω, α - 1, ρ, σ);
