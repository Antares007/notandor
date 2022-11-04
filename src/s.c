#include "o_logn.h"
// clang-format off
G(2, 00,ψ1+ψ0)
G(1, ψ2,00+ψ0)
G(0, ψ2+ψ1,00)
#undef G
#include<assert.h>
#define RN(ti,na)   ti na = (assert(R.v==B),(ti)R.v)
N(var);
#define VBM(...) { ; A(__VA_ARGS__) o; }
#define V(aso) N(aso##_);N(aso){ ;P(030, aso##_, aso, var) o; } N(aso##_) VBM
typedef void (*n_t)(OARS);
N(B       ) { A(B, c1) o;}
N(T_      ) { const char*m = R.v; A(c1) o; }
N(e_      ) { A(c1) o; }
N(T       ) { P(020, R.v, T_) o; }
N(e       ) { P(010, e_) o; }
N(O2      ) { *(Q_t*)ο[ρ++].v = α, *(n_t*)ο[ρ++].v = c2;}
N(O1      ) { *(Q_t*)ο[ρ++].v = α, *(n_t*)ο[ρ++].v = c1;}
N(O0      ) { *(Q_t*)ο[ρ++].v = α, *(n_t*)ο[ρ++].v = c0;}
N(O       ) { o; 
              //n_t c;
              //{
              //  s_t ο[256];
              //  Q_t ρ = sizeof(ο) / sizeof(*ο);
              //  P(0111, O2, O1, O0, &α, &c) o;
              //}
              //c(Τ); // now we have result on sigma
            }
N(var2    ) {                         }
N(var1    ) {                         }
N(var0    ) {                         }
N(var     ) {
              α--, o;
              //{
              //  s_t*οs = ο;
              //  s_t ο[256];
              //  Q_t ρ = sizeof(ο)/sizeof(*ο);
              //  P(0111, var2, var1, var0, R.v, οs)  o;
              //}
            }
V(Sa      ) ("b", T, O,
             Sa, "a", T);
V(eOs     ) (e, O, "s", T)
V(Ss      ) ("s",T,"s",T)
V(Ab      ) (  "a",T,
             O,"a",T,"b",T,
             O,"a",T,"b",T,"c",T,
             O,"a",T,"b",T,"c",T,"d",T)
V(Cd      ) (        "b",T,"c",T,"d",T,"e",T,
             O,            "c",T,"d",T,"e",T,
             O,                  "d",T,"e",T,
             O,                        "e",T)
V(AbCd    ) (Ab, Cd)
V(E       ) (E,"+",T,E,
           O,E,"-",T,E,
           O,E,"*",T,E,
           O,E,"/",T,E,
           O,"(",T,E,")",T,
           O,"1",T,O,"2",T)
N(show    ) { ; void*s[]={0,0,0};
                A(s, "s", 4, B, AbCd) o;}
                
static void nop(){}
// clang-format off
LN(nop,
B       ,L)LN(L,
Cd_     ,L)LN(L,
Cd      ,L)LN(L,
Ab_     ,L)LN(L,
Ab      ,L)LN(L,
AbCd_   ,L)LN(L,
AbCd    ,L)LN(L,
T_      ,L)LN(L,
T       ,L)LN(L,
e_      ,L)LN(L,
e       ,L)LN(L,
                
O       ,L)LN(L,
Sa_     ,L)LN(L,
Sa      ,L)LN(L,
eOs_    ,L)LN(L,
eOs     ,L)LN(L,
Ss_     ,L)LN(L,
Ss      ,L)LN(L,
show    ,L)LN(L,
var     ,L)LN(L,
c2      ,L)LN(L,
c1      ,L)LN(L,
c0      ,L)LN(L,
e2      ,L)LN(L,
e1      ,L)LN(L,
e0      ,L)void init_logn(){L();}
N(e2      ) { ; logn(Τ, __FUNCTION__); }
N(e1      ) { ; logn(Τ, __FUNCTION__); }
N(e0      ) { ; logn(Τ, __FUNCTION__); }
int main() {
  s_t ο[256], σ[256];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  P(0111, e2, e1, e0);
  init_logn();
  A(B, show) o;
}

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
if (σ[α-2].v == O) printf("O\n");
for (s_t *c = σ[1].s; c; c = c[2].v)
  if (c[1].v == cur_var) 
    return α--, printf("lr\n"), o;
σ[1].v = (void*[]){ σ[1].s[0].v, cur_var, σ[1].s };
*/
