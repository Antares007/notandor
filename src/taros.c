#define Nargs(...)                                                             \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define LOGD (void)0
#define LOGT (void)0
#define D(_o_) o = (_o_), a--, LOGD, t[a].c(t, a, r, o, s, d)
#define B(r0, r1, r2, r3, o) T(r0, r1, r2, r3, (void *)o)
#define T(...)                                                                 \
  (LOGT, (s_t *)&(void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])

#define N(argos)                                                               \
  void argos(struct s_t *t, long a, long r, struct s_t *o, struct s_t *s,      \
             const char *d)
typedef struct s_t {
  union {
    long q;
    struct s_t *o;
    void *v;
    N((*c));
  };
} s_t;
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#ifndef NDEBUG
#undef LOGD
#define LOGD printf("%ld %ld %s\n", a, r, __FUNCTION__), usleep(100000)
#undef LOGT
#define LOGT printf("T")
#endif

N(sword) { t[a - 1].c(t, a - 1, r, o, s, d); }

N(cr) {
  assert(0 == a);
  t = o[r].o;
  a = t[-1].q;
  t[a - 1].c(t, a - 1, r, o[4].o, s, d);
}
long p = 0;
N(propeller) {
  p++;
  for (r = 0; r < 4; r++)
    printf("%ld ", p), LOGD, cr(t, a, r, o, s, d);
  p--;
}
N(match) {
  const char *m = t[--a].v;
  if (*d == *m)
    cr(t, a, r, o, s, d + 1);
}
N(land) { printf("%s\n", (char*)d);//, cr(t, a, r, s, o, d);
}
N(ε) {}
N(term) {
  char *str = t[--a].v;
  s_t *Tpro = T(propeller), *Tε = T(ε);
  D(B(Tpro, Tpro, Tpro, Tpro, B(T(str, match), Tε, Tε, Tε, o)));
}
N(Sa) {
  o = B(T(propeller), T(propeller), T(propeller), T(propeller),
      B(T(cr, "b", term),
        T(cr, Sa, "a", term),
        T(ε),
        T(ε), o));
  D(o);
}
int main() {
  s_t *t = T(cr, Sa);
  long a = t[-1].q;
  long r = 0;
  s_t *o = B(T(cr, land), T(cr, land), T(cr, land), T(cr, land), 0);
  s_t *s = 0;
  char*d = "baaa";
  D(o);
}
/*
lets start defining protocall.
* can perform previously impossible tasks
we have awesome protocall how to define executable sentences and the words.
now we shall implement its distributed version and we will:
* achieve unprecedented levels of performance
* implementing, and improving a massive-scale distributed,
  machine learning, system,
* writing bug-free machine learning code,
* building the science behind the algorithms employed
*/
