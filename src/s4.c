#define OARS struct s_t *ο, struct s_t *α, struct s_t *ρ, struct s_t *σ
#define oars             ο,             α,             ρ,             σ
typedef unsigned long Q_t;
typedef struct s_t { union { Q_t Q; void *v; void (*c)(OARS); }; } s_t;
#define N(argo) void argo(OARS)
#define A(...) {  const void *va_args[] = {__VA_ARGS__};                       \
                  Q_t size = sizeof(va_args) / sizeof(*va_args);               \
                  for (Q_t i=0; i<size; i++) (*α++).v=(void*)va_args[i]; }
#define o (α--,(*α).c(oars))
#include<assert.h>
N(cont) {                                                            
  Q_t ray_no = (*--α).Q; assert(ray_no < 8);
  while(1) {
    Q_t ψ = (*ρ++).Q; assert(ψ <= 07777777);
    Q_t ray_no_count = ψ >> ray_no * 3 & 7;
    for(Q_t i = ray_no + 1; i < 8                  ; i++) ρ += ψ >> 3 * i & 7;
    for(Q_t i = 0         ; i < ray_no_count       ; i++) (*α++).v = (*ρ++).v;
    for(Q_t i = 0         ; i < ray_no             ; i++) ρ += ψ >> 3 * i & 7;
    if (ray_no_count) return (--α, (*α).c(oars));
  }
}
#include<stdio.h>
N(B) { A(B, 1, cont) o; }
N(add_) { Q_t r = (--α, (*--α).Q); Q_t l = (--α, (*--α).Q); A(l + r, B) o; }
N(add ) { (*--ρ).v = add_, (*--ρ).Q = 010, o; }
N(one ) { (*--ρ).v = B,    (*--ρ).Q = 1, (*--ρ).Q = 020, o; }

N(e4) { printf("e4 %p\n", ρ);}
N(e3) { printf("e3 %lu, %p\n", (*--α).Q, ρ);}
N(e2) { printf("e2 %p\n", ρ);}
N(e1) { printf("e1 %p\n", ρ);}
N(e0) { printf("e0 %p\n", ρ);}
N(b2) { printf("b2 %p\n", ρ);}
N(b1) { --α, printf("b1 %p %lu\n", ρ, (*--α).Q);}
N(b0) { printf("b0 %p\n", ρ);}
int main() {
    /* ←ο
    σ→     ←ρ
        α→ */    
    s_t b[256 + 256], *σ = b, *ο = σ + 256, *α = ο, *ρ = ο + 256;
    printf("%p\n", ρ);
    (*--ρ).v=e0;(*--ρ).v=e1;(*--ρ).v=e2;(*--ρ).v=e3;(*--ρ).Q=9;(*--ρ).v=e4;(*--ρ).Q=012111;
    (*--ρ).v=b0;(*--ρ).v=b1;(*--ρ).v=b2;(*--ρ).Q=0111;
    A(B,  one,
          one, add,
          one, add,
          one, add,
          one, add,
          one, add,
          one, add) o;
}
