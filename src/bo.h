#pragma once
/*                   Notandor / არადანი
                                    
                         ┗━━━━╋━━━━┛
                        ┗━━━━━╋━━━━━┛
                      ┓┗━━━━━━╋━━━━━━┛┏
                     ┓┃               ┃┏
                    ┓┃┃               ┃┃┏
                    ╋╋╋               ╋╋╋
                    ┛┃┃               ┃┃┗
                     ┛┃               ┃┗
                      ┛┏━━━━━━╋━━━━━━┓┗
                        ┏━━━━━╋━━━━━┓
                         ┏━━━━╋━━━━┓

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
    void (*call)();
  };
} s_t;

#define OARS s_t *ω, Q_t α, Q_t ρ, s_t *σ
#define N(narname) void narname(OARS)
#define Τ ω, α, ρ, σ
#define Α(val) ω[α++].v = (void *)val,
#include "evalmap.h"
#define A(...) EVAL(MAP(Α, __VA_ARGS__)) ω[α - 1].call(ω, α - 1, ρ, σ);
#define LOG printf("%04lx %lu %lu %04lx %s\n", (Q_t)ω & (Q_t)0xffff, α, ρ, (Q_t)σ & (Q_t)0xffff, __FUNCTION__)
#define C2VS(v) (void*)v,
#define S(...) (s_t*)(void*[]){ EVAL(MAP(C2VS, __VA_ARGS__))}
