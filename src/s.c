#define OARS struct s_t *ο, Q_t α, Q_t ρ, struct s_t *σ
#define T                ο,     α,     ρ,             σ

typedef unsigned long Q_t;
typedef struct s_t {union{ void*v; Q_t Q; void(*c)(OARS); struct s_t*s; };} s_t;

#define N(argo)     void argo(OARS)
#define A(...)      { const void*ζs[] = {__VA_ARGS__};                         \
                    for (Q_t i = 0; i < sizeof(ζs) / sizeof(*ζs); i++)         \
                      σ[α++].v = (void*)ζs[i]; }
#define R           σ[--α]
#define G(_n,_b,_a) void c##_n(OARS) {                                        \
                    Q_t ψ = ο[ρ++].Q, ψ2 = ψ>>6&7, ψ1 = ψ>>3&7, ψ0 = ψ>>0&7;  \
                    ρ += _b;                                                  \
                    for (Q_t i = 0; i < ψ##_n; i++) σ[α++].v = ο[ρ++].v;      \
                    ρ += _a;                                                  \
                    ψ##_n ? O : c##_n(T); }
#define O           (logn(T,__FUNCTION__),--α, σ[α].c(T))
#define P(...)      { const void*ζs[] = {__VA_ARGS__};                        \
                    Q_t i = sizeof(ζs) / sizeof(*ζs);                         \
                    while(i) ο[--ρ].v = (void*)ζs[--i]; }
#include<stdio.h>
#define L logn(T, __FUNCTION__)
void logn(OARS, const char*name);
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
N(term_   ) { ; α--; A(c1) O; }
N(term    ) { ; P(020, R.v, term_) sleep(1), O; }
N(orelse  ) { ; O; }
N(Sa);
V(Bb      ) ("b", term, "b", term)
V(Abba    ) (Sa, "a", term, Bb, "a", term)
V(Sa      ) ("b", term, orelse,
             "b", term, Sa, "a", term);
N(show    ) { ; void*s[]={0,0,0};
                A(s, "baaa", 4, B, Sa) O;}

N(var     ) { ; //void (*cur_var)(OARS) = R.v;
                if (σ[α-2].v == orelse) printf("orelse\n");
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
N(end2    ) { ; }
N(end1    ) { ; RN(Q_t, r);printf("%lu\n", r);}
N(end0    ) { ; }
void init_names();
int main() {
  s_t ο[256], σ[256];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  P(0111, end2, end1, end0);
  init_names();
  A(B, show) O;
}
#define NAME(me) names[(Q_t)me & (Q_t)0xFFFF] = #me 
char* names[0x10000]={};
void init_names() {
  NAME(B       );
  NAME(term_   );
  NAME(term    );
  NAME(orelse  );
  NAME(Bb      );
  NAME(Abba    );
  NAME(Sa_     );
  NAME(Sa      );
  NAME(show    );
  NAME(var     );
  NAME(c2      );
  NAME(c1      );
  NAME(c0      );
  NAME(end2    );
  NAME(end1    );
  NAME(end0    );
}
#undef NAME
char* get_name(void*addr) { char*n = names[(Q_t)addr & (Q_t)0xFFFF]; return n ? n : "."; }
void logn(OARS, const char*name) {
  Q_t m = 44;
  {
    Q_t i = α, c = 0;
    while(i && c < m) {
      char*n = get_name(σ[--i].v);
      while(*n) n++, c++;
      c++;
    }
    c = 0;
    while(i < α && c < m) {
      char*n = get_name(σ[i++].v);
      while(*n && c < m) printf("%c", *n), n++, c++;
      if (c < m) printf(" "), c++;
    }
    while(c < m) printf(" "), c++;
  }
  printf("  ");
  {
    Q_t i = 0;
    while(name[i] &&
          i < 7) printf("%c", name[i++]);
    while(i < 7) printf(" "), i++;
    printf("%.2lu %.3lu", α, ρ);
  }
  printf("  ");
  {
    Q_t i = ρ, c = 0;
    while(i < 255 && c < m) {
      Q_t ψ   = ο[i++].Q;
      Q_t len = (ψ>>6&7)+(ψ>>3&7)+(ψ&7);
      printf("ψ%.3lo ", ψ);
      c += 5;
      while(len && c < m) {
        char *n = get_name(ο[i++].v);
        while(*n && c < m) printf("%c", *n), n++, c++;
        if(c < m) printf(" "), c++;
        len--;
      }
    }
  }
  printf("\n");
}
