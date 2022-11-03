#define OARS struct s_t *ο, Q_t α, Q_t ρ, struct s_t *σ
#define T                ο,     α,     ρ,             σ

typedef unsigned long Q_t;
typedef struct s_t {union{ void*v; Q_t Q; void(*c)(OARS); };} s_t;

#define N(argo)     void argo(OARS)
#define A(...)      { const void*s[] = {__VA_ARGS__};                         \
                    for (Q_t i = 0; i < sizeof(s) / sizeof(*s); i++)          \
                      σ[α++].v = (void*)s[i]; }
#define R           σ[--α]
#define G(_n,_b,_a) void c##_n(OARS) {                                        \
                    Q_t ψ = ο[ρ++].Q, ψ2 = ψ>>6&7, ψ1 = ψ>>3&7, ψ0 = ψ>>0&7;  \
                    ρ += _b;                                                  \
                    for (Q_t i = 0; i < ψ##_n; i++) σ[α++].v = ο[ρ++].v;      \
                    ρ += _a;                                                  \
                    ψ##_n ? O : c##_n(T); }
#define O           (--α, σ[α].c(T))
#define P(...)      { const void*s[] = {__VA_ARGS__};                         \
                    Q_t i = sizeof(s) / sizeof(*s);                           \
                    while(i) ο[--ρ].v = (void*)s[--i]; }


#include<stdio.h>
#define L printf("%.2lu %lu %s\n", α, ρ, __FUNCTION__)
G(2, 00,ψ1+ψ0)
G(1, ψ2,00+ψ0)
G(0, ψ2+ψ1,00)
#undef G
#include<assert.h>
#define RN(ti,na)   ti na = (assert(R.v==B),(ti)R.v)
N(term    ) {
}
N(orelse  ) {
}
N(var     ) {
}
N(Sa      ) { A(                 "b", term,
                orelse, Sa, var, "a", term) O; }
N(CSa     ) { A(Sa, var) O; }
//N(show_   ) { A("baaa", B, CSa, var) O;}

N(B       ) { ; A(B) c1(T);}

N(one     ) {L; P(020, 1, B) O; }
N(add_    ) { ; RN(Q_t, r);
                RN(Q_t, l);
                A(l + r, B) O; }
N(add     ) {L; P(010, add_) O; }
N(two     ) {L; A(one, one, add) O; }
N(four    ) {L; A(two, two, add) O; }
N(show    ) {L; A(one, two, add, four, add) O;}

N(end2    ) {L; }
N(end1    ) {L; RN(Q_t, r);printf("%lu\n", r);}
N(end0    ) {L; }
int main() {
  s_t ο[256], σ[256];
  Q_t α = 0, ρ = sizeof(ο) / sizeof(*ο);
  P(0111, end2, end1, end0);
  A(B, show) O;
}
