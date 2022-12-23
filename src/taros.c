#define Nargs(...)                                                             \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define LOGD (void)0
#define LOGT (void)0
#define D(_o_) o = (_o_), a--, LOGD, t[a].c(t, a, r, o, s, d)
#define B(...) T(__VA_ARGS__)
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
#define LOGD                                                                   \
  printf("%ld %ld %s %s\n", a, r, __FUNCTION__, (char *)d), usleep(100000)
#undef LOGT
#define LOGT printf("T")
#endif

N(ps) {
  printf("%s\n", (char *)t[--a].v), usleep(500000);
  t[a - 1].c(t, a - 1, r, o, s, d);
}

N(cr) {
  assert(0 == a);
  t = o[r].o;
  a = t[-1].q;
  t[a - 1].c(t, a - 1, r, o[4].o, s, d);
}
N(ε) {}
long p = 0;
N(propeller2) {
  long nr = t[--a].q;
  s_t *no = t[--a].v;
  cr(t, a, nr, no, B(T(cr), T(o, (void *)(nr + 1), propeller2), T(ε), T(ε), s),
     d);
}
N(propeller0) {
  for (r = 0; r < 4; r++)
    cr(t, a, r, o, s, d);
  // cr(t, a, 0, o,
  //    B(T(cr), T(o, (void *)1, propeller2), T(ε), T(ε), s),
  //    d);
}
N(match) {
  const char *m = t[--a].v;
  if (*d == *m)
    cr(t, a, r, o, s, d + 1);
  else
    cr(t, a, r, s, o, d);
}
N(term) {
  char *str = t[--a].v;
  s_t *Tpro = T(propeller0), *Tε = T(ε);
  D(B(Tpro, Tpro, Tpro, Tpro, B(T(str, match), Tε, Tε, Tε, o)));
}
N(Sa) {
  o = B(T(propeller0), T(propeller0), T(propeller0), T(propeller0),
        B(T(cr, "b", term), T(cr, Sa, "a", term), T(ε), T(ε), o));
  s = B(T(propeller0), T(propeller0), T(propeller0), T(propeller0),
        B(T(cr, "b", term), T(cr, Sa, "a", term), T(ε), T(ε), s));
  D(o);
}
N(o_land0) { LOGD, cr(t, a, r + 0, s, o, d); }
N(s_land0) { LOGD, cr(t, a, r + 1, s, o, d); }
N(o_land1) { LOGD, cr(t, a, r + 0, s, o, d); }
N(s_land1) { LOGD, cr(t, a, r + 1, s, o, d); }
N(o_land2) { LOGD, cr(t, a, r + 0, s, o, d); }
N(s_land2) { LOGD, cr(t, a, r + 1, s, o, d); }
N(o_land3) { LOGD, cr(t, a, r + 0, s, o, d); }
N(s_land3) { LOGD; }
// growing pith is process when we consume words from ntext space
// and putting rings with rays around pith.
N(tword3) {
  o = B(T(cr), T(cr), T(cr), T(cr), o);
  D(o);
}
N(tword2) {
  D(o);
}
N(sword) {
  s = B(T(cr, tword2), T(cr), T(cr), T(cr), s);
  D(o);
} 
void tword(struct s_t *t,
                  long a,
                  long r,
           struct s_t *o,
           struct s_t *s,
           const char *d) {
  o=B(T(cr,"o00",ps),T(cr,"o01",ps),T(cr,"o02",ps),T(cr,"o03",ps),o);
  o=B(T(cr,"o10",ps),T(cr,"o11",ps),T(cr,"o12",ps),T(cr,"o13",ps),o);
  o=B(T(cr,"o20",ps),T(cr,"o21",ps),T(cr,"o22",ps),T(cr,"o23",ps),o);
  D(o);
}
N(land) { LOGD; }
int main() {
  s_t *t = T(cr, Sa);
  long a = t[-1].q;
  long r = 0;
  s_t *o = B(T(land), T(land), T(land), T(land), 0);
  //s_t *o = B(T(o_land0), T(o_land1), T(o_land2), T(o_land3), 0);
  s_t *s = B(T(s_land0), T(s_land1), T(s_land2), T(s_land3), 0);
  char *d = "baaa";
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
