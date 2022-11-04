#include "o_logn.h"
// clang-format off
G(2, 00,ψ1+ψ0)
G(1, ψ2,00+ψ0)
G(0, ψ2+ψ1,00)
#undef G
#include<assert.h>
#define RN(ti,na)   ti na = (assert(R.v==B),(ti)R.v)
N(var);
#define VBM(...) { ; A(__VA_ARGS__) O; }
#define V(aso) N(aso##_);N(aso){ ;P(030, aso##_, aso, var) O; } N(aso##_) VBM
N(B       ) { ; A(B, c1) O;}
N(t_      ) { ; const char*m = R.v; A(c1) O; }
N(e_      ) { ;                     A(c1) O; }
N(t       ) { ; P(020, R.v, t_) O; }
N(e       ) { ; P(010, e_) O; }
N(OE      ) { ; O; }
V(Sa      ) ("b", t, OE,
             "b", t, Sa, "a", t);
V(sOe     ) ("s", t, OE, e)
N(show    ) { ; void*s[]={0,0,0};
                A(s, "s", 4, B, sOe) O;}
N(var_    ) { ; α--; A(c1) O; }
N(var     ) { ; P(020, R.v, var_)  O; }
/*
      A → A α |β

      A → βA′
      A → αA′|ϵ

      E → E + T | T
      T → T * F | F
      F → ( E )
      F → id
      
      E → TE′ E′→ +TE′|∈
      T → FT′ T′→ *FT′|∈
      F → ( E ) | id

void (*cur_var)(OARS) = R.v;
if (σ[α-2].v == OE) printf("OE\n");
for (s_t *c = σ[1].s; c; c = c[2].v)
  if (c[1].v == cur_var) 
    return α--, printf("lr\n"), O;
σ[1].v = (void*[]){ σ[1].s[0].v, cur_var, σ[1].s };
*/
                
N(e2      ) { ; }
N(e1      ) { ; RN(Q_t, r);printf("%lu\n", r);}
N(e0      ) { ; }
static void nop(){}
// clang-format off
LN(nop,
B       ,L)LN(L,
t_      ,L)LN(L,
t       ,L)LN(L,
e_      ,L)LN(L,
e       ,L)LN(L,
OE      ,L)LN(L,
Sa_     ,L)LN(L,
Sa      ,L)LN(L,
sOe_    ,L)LN(L,
sOe     ,L)LN(L,
show    ,L)LN(L,
var_    ,L)LN(L,
var     ,L)LN(L,
c2      ,L)LN(L,
c1      ,L)LN(L,
c0      ,L)LN(L,
e2      ,L)LN(L,
e1      ,L)LN(L,
e0      ,L)void init_logn(){L();}
int main() {
  s_t ο[256], σ[256];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  P(0111, e2, e1, e0);
  init_logn();
  A(B, show) O;
}
