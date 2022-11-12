typedef unsigned long Q_t;
typedef struct s_t {
  union {
    Q_t Q;
    void*v;
    void(*c)(
      struct s_t*,                    Q_t,
      struct s_t*,struct s_t*,struct s_t*,
      struct s_t*,struct s_t*,struct s_t*,
      struct s_t*,struct s_t*,struct s_t*,
      struct s_t*,struct s_t*,struct s_t*);
  };
} s_t;
#define OANTS          \
  s_t*s,        Q_t d, \
  s_t*ob,s_t*o,s_t*oe, \
  s_t*ab,s_t*a,s_t*ae, \
  s_t*nb,s_t*n,s_t*ne, \
  s_t*tb,s_t*t,s_t*te 
#define C(m)                  \
  (m-4)->c(s,  0, \
           o-3,    o-2,   oe, \
           a-3,    a-2,   ae, \
           n-3,    n-2,   ne, \
           m-3,    m-2, m##e)
void fun(OANTS) { }
void eo(OANTS);
void ea(OANTS);
void en(OANTS);
void co(OANTS) { C(o); }
void ca(OANTS) { C(a); }
void cn(OANTS) { C(n); }
void one_ (OANTS) { (*s++).Q = 1, C(a); }
void one  (OANTS) { 
  o++->v = co;
  a++->v = one_;
  n++->v = cn;
  o->v = o,o++, o++->v = ob, o++->v = ca;
  a->v = a,a++, a++->v = ab, a++->v = ca;
  n->v = n,n++, n++->v = nb, n++->v = ca;
  t[d-1].c(s,     d-1,
           o,  o,  oe,
           a,  a,  ae,
           n,  n,  ne,
           t,  t,  te);
}
//void add_ (OARS) { Q_t r=σ[--τ].Q; Q_t l=σ[--τ].Q; σ[τ++].Q = l+r,C(α); }
//void add  (OARS) { Ψ()(add_)(), D; }
int main() {
  s_t b[5][2048];
  s_t*s =b[0];                Q_t d=0;
  s_t*ob=b[1]+1;s_t*o=ob;s_t*oe=ob+2048;
  s_t*ab=b[2]+1;s_t*a=ab;s_t*ae=ab+2048;
  s_t*nb=b[3]+1;s_t*n=nb;s_t*ne=nb+2048;
  s_t*tb=b[4]+1;s_t*t=tb;s_t*te=tb+2048;

  (o-1)->v = eo;
  (a-1)->v = ea;
  (n-1)->v = en;
  (t-1)->v = ca;

  (*t++).v = fun;

  (*o++).v = ob;(*o++).v = ca;
  (*a++).v = ab;(*a++).v = ca;
  (*n++).v = nb;(*n++).v = ca;
  (*t++).v = tb;(*t++).v = ca;

  fun(s,     d,
      o, o, oe,
      a, a, ae,
      n, n, ne,
      t, t, te);
}
