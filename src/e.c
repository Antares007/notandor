typedef unsigned long Q_t;
#define OARS struct s_t *ο, struct s_t *α, struct s_t *ν, struct s_t *ρ, Q_t ι, struct s_t *σ, Q_t τ
typedef struct s_t {
  union {
    Q_t Q;
    void *v;
    struct s_t *s;
    void (*c)(OARS);
  };
} s_t;
#include <stdio.h>
#include <assert.h>
#define LOG printf("%s ", __FUNCTION__), logt(ο, α, ν, ρ, ι, σ, τ)
#define NUMARGS(...) (sizeof((const void*[]){__VA_ARGS__}) / sizeof(void*))
#define ΨX(X, ...) X = (s_t *)(const void *[]){X, 0, __VA_ARGS__},             \
                  (X += 2)[-1].Q = NUMARGS(__VA_ARGS__) 
#define Ψ__(...)  ΨX(ν, cn, __VA_ARGS__)
#define Ψ_(...)   ΨX(α, ca, __VA_ARGS__), Ψ__
#define Ψ(...)    ΨX(ο, co, __VA_ARGS__), Ψ_
#define S(...)    ΨX(ρ, ca, __VA_ARGS__), ι = ρ[-1].Q
#define O         ρ[ι - 1].c(ο, α, ν, ρ, ι - 1, σ, τ)
#define D         LOG,O    
#define C(x)                                                                   \
  ρ = x,                                                                       \
  ο = ο[-2].v,                                                                 \
  α = α[-2].v,                                                                 \
  ν = ν[-2].v,                                                                 \
  ι = ρ[-1].Q, D
static char* get_name(void*a);
void logt(OARS) {
  printf("\t");
  while(ο && α && ν) {
    //printf("\t%lu", α[-1].Q-1);
    //printf("\t%lu.%lu.%lu", ν[-1].Q, α[-1].Q, ο[-1].Q);
    //for(Q_t i = 0; i < ν[-1].Q; i++) printf(" %s", get_name(ν[i].v));
    //printf(" ");
    for(Q_t i = 1; i < α[-1].Q; i++) printf("%s", get_name(α[i].v));
    //printf(" ");
    //for(Q_t i = 0; i < ο[-1].Q; i++) printf(" %s", get_name(ο[i].v));
    ν = ν[-2].v; α = α[-2].v; ο = ο[-2].v;
    printf(" ");
  }
  printf("\n");
}
void co  (OARS) { C(ο); }
void ca  (OARS) { C(α); }
void cn  (OARS) { C(ν); }
void e2   (OARS) { LOG; }
void e1   (OARS) { LOG; while(τ) printf("%lu ", σ[--τ].Q);printf("\n"); }
static Q_t lr = 0;
void e0   (OARS) { lr++; LOG; }
void one_ (OARS) { σ[τ++].Q = 1, C(α); }
void one  (OARS) { Ψ()(one_)(), D; }
void add_ (OARS) { Q_t r=σ[--τ].Q; Q_t l=σ[--τ].Q; σ[τ++].Q = l+r,C(α); }
void add  (OARS) { Ψ()(add_)(), D; }
void e    (OARS) { Ψ()()(), D; }
void t_   (OARS) {  char *m = ρ[--ι].v;
                    printf("%s ", m);
                    Q_t pos = σ[--τ].Q;
                    Q_t len = σ[--τ].Q;
                    char *inp = σ[--τ].v;
                    if (pos < len && inp[pos] == m[0])
                      σ[τ++].v = inp, σ[τ++].Q = len, σ[τ++].Q = pos + 1, C(α);
                    else 
                      σ[τ++].v = inp, σ[τ++].Q = len, σ[τ++].Q = pos, C(ο);
                 }
void t    (OARS) { Ψ()(ρ[--ι].v, t_)(), D; }
void eOs  (OARS);
void eOs_ (OARS) {  s_t nσ[128]; for(Q_t i=0;i<τ;i++) nσ[i].v = σ[i].v;
                    S(e), D;
                    σ = nσ;
                    S("s", t, eOs, eOs), D; }
void eOs  (OARS) {  Ψ()(eOs_)(), D;}
void Sa   (OARS);
void Sa_  (OARS) {   
                    //if(lr) { lr = 0; printf("aaa\n"); return C(α); }
                    static Q_t i = 0; if (i++>14) return;
                    s_t nσ[128]; for(Q_t i=0;i<τ;i++) nσ[i].v = σ[i].v;
                    S(    "b", t), D; σ = nσ;
                    printf("\n>>>\n");
                    S(Sa, "a", t), D; 
                 }
void Sa   (OARS) {
  //assert(Sa == (void*)ρ[ρ[-1].Q-1].v);
  Ψ()(Sa_)(), D; }
void initNames();
int main() {
  initNames();
  Q_t ι;
  s_t *ο, *α, *ν, *ρ = ο = α = ν = ι = 0;
  s_t σ[128];
  Q_t τ = 0;
  Ψ(e0)(e1)(e2);
  σ[τ++].v = "baaaaaaaa";
  σ[τ++].Q = 9;
  σ[τ++].Q = 0;
  S(Sa), D;
  //S(one, one, add, one, add), D;
  //S(one, one, add, one, add, one, add, one, add, one, add, one, add), D;
}
static char*names[0x10000] = {};
#define Σ 100
static char buf[Σ];
static char* sword = "NNSD";
static char* get_name(void*a) {
  char*n = names[(Q_t)a & (Q_t)0xFFFF];
  if (n) return n;
  if((Q_t)a < 151) return (snprintf(buf, Σ, "%lu", (Q_t)a), buf);
  if((Q_t)a >> 12 == (Q_t)buf >> 12 ||   //bss
     (Q_t)a >> 12 == (Q_t)sword >> 12)   //data
        return (snprintf(buf, Σ, "\"%s\"", (char*)a), buf);
  return ".";
}
#define NAME(name) names[(Q_t)name & 0xffff] = #name
void initNames() {
  NAME(Sa);
  NAME(co);
  NAME(ca);
  NAME(cn);
  NAME(e2);
  NAME(e1);
  NAME(e0);
  NAME(one_);
  NAME(one);
  NAME(add_);
  NAME(add);
  NAME(e);
  NAME(t_);
  NAME(t);
  NAME(eOs);
  NAME(eOs_);
  NAME(eOs);
  NAME(Sa);
  NAME(Sa_);
  NAME(Sa);
  NAME(main);
}
