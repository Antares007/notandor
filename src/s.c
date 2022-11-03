#include "o_logn.h"
G(2, 00,ψ1+ψ0)
G(1, ψ2,00+ψ0)
G(0, ψ2+ψ1,00)
#undef G
#include<assert.h>
#define RN(ti,na)   ti na = (assert(R.v==B),(ti)R.v)
N(var);
#define VBM(...) { ; A(__VA_ARGS__) O; }
#define V(aso) N(aso##_);N(aso){ ;P(030, aso##_, aso, var) O; } N(aso##_) VBM
#include<unistd.h>
N(B       ) { ; A(B, c1) O;}
N(t_      ) { ; α--; A(c1) O; }
N(t       ) { ; P(020, R.v, t_) sleep(1), O; }
N(oe      ) { ; O; }
N(Sa);
V(Bb      ) ("b", t, "b", t)
V(Abba    ) (Sa, "a", t, Bb, "a", t)
V(Sa      ) ("b", t, oe,
             "b", t, Sa, "a", t);
N(show    ) { ; void*s[]={0,0,0};
                A(s, "baaa", 4, B, Sa) O;}

N(var     ) { ; //void (*cur_var)(OARS) = R.v;
                if (σ[α-2].v == oe) printf("oe\n");
                //for (s_t *c = σ[1].s; c; c = c[2].v)
                //  if (c[1].v == cur_var) 
                //    return α--, printf("lr\n"), O;
                //σ[1].v = (void*[]){ σ[1].s[0].v, cur_var, σ[1].s };
                O; }
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
*/
N(e2      ) { ; }
N(e1      ) { ; RN(Q_t, r);printf("%lu\n", r);}
N(e0      ) { ; }
int main() {
  s_t ο[256], σ[256];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  P(0111, e2, e1, e0);
  init_logn();
  A(B, show) O;
}
