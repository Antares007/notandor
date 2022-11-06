#define OARS struct s_t *ο, struct s_t *α, struct s_t *ρ, struct s_t *σ
#define oars             ο,             α,             ρ,             σ
typedef unsigned long Q_t;
typedef struct s_t { union { Q_t Q; void *v; void (*c)(OARS); }; } s_t;

#define N(argo  ) void argo(OARS)
#define A(α,... ) { const void *va_args[] = {__VA_ARGS__};                  \
                    Q_t size = sizeof(va_args)/sizeof(*va_args);            \
                    for (Q_t i=0; i<size; i++) (*α++).v=(void*)va_args[i]; }
#define P( ...  ) { const void *va_args[] = {__VA_ARGS__};                  \
                    Q_t size = sizeof(va_args)/sizeof(*va_args);            \
                    while (size) (*--ρ).v=(void*)va_args[--size]; }
#define o(α) (α--,(*α).c(oars))
#include<assert.h>
N(cont    ) {                                                            
  Q_t ray_no = (*--α).Q; assert(ray_no < 8);
  while(1) {
    Q_t ψ = (*ρ++).Q; assert(ψ <= 07777777);
    Q_t ray_no_count = ψ >> 3 * ray_no & 7;
    for(Q_t i = ray_no + 1; i < 8           ; i++) ρ += ψ >> 3 * i & 7;
    for(Q_t i = 0         ; i < ray_no_count; i++) (*α++).v = (*ρ++).v;
    for(Q_t i = 0         ; i < ray_no      ; i++) ρ += ψ >> 3 * i & 7;
    if (ray_no_count) return (--α, (*α).c(oars));
  }
}
#include<stdio.h>
N(B       ) { A(α, B, 1, cont) o(α); }
N(add_    ) { Q_t r = (--α, (*--α).Q);
              Q_t l = (--α, (*--α).Q);
              A(α, l + r, B) o(α); }
N(add     ) { P(010, add_) o(α); }
N(one     ) { P(020, 1, B) o(α); }
N(seven   ) { A(α, one, one, add, one, add, one, add, one, add, one, add, one, add) o(α); }

N(ping    ) { A(α,  ping) o(α); }
N(show    ) { A(α, seven) o(α); }

N(e4      ) { printf("e4 %p\n", ρ);}
N(e3      ) { printf("e3 %lu, %p\n", (*--α).Q, ρ);}
N(e2      ) { printf("e2 %p\n", ρ);}
N(e1      ) { printf("e1 %p\n", ρ);}
N(e0      ) { printf("e0 %p\n", ρ);}
N(b2      ) { printf("b2 %p\n", ρ);}
N(b1      ) { --α, printf("b1 %p %lu\n", ρ, (*--α).Q);}
N(b0      ) { printf("b0 %p\n", ρ);}
int main( ) {
    /* ←ο
    σ→     ←ρ
        α→ */    
  const Q_t Σ = 512;

  s_t b[Σ], *σ = b,
            *ο = σ + Σ / 2,
            *α = ο,
            *ρ = ο + Σ / 2;
  P(012111, e4,  9, e3, e2, e1, e0) 
  P(  0x49, b2, b1, b0)
  P(012111, e4,  9, e3, e2, e1, e0) 
  P(  0x49, b2, b1, b0)
  A(α, B, show) o(α);
}
