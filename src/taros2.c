#define Nargs(...)                                                             \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define LOGD (void)0
#define LOGT (void)0
#define D(_o_) o = (_o_), a--, LOGD, t[a].c(t, a, r, o, s, d)
#define B(...) T(__VA_ARGS__)
#define T(...)                                                                 \
  (LOGT, (s_t *)&(void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])

#define N(argos)                                                               \
  void argos(struct s_t *t, long a, long r, struct s_t *o, long s,             \
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
  // B(T(), T(), T(), T(), o[4 + (s + 1) % 2].o);
  t[a - 1].c(t, a - 1, r, o[4 + s].o, s, d);
}
N(ε) {}
N(propeller0) {
  for (r = 0; r < 4; r++)
    cr(t, a, r, o, s, d);
}
N(match) {
  const char *m = t[--a].v;
  if (*d == *m)
    cr(t, a, r, o, s, d + 1);
}
void term(struct s_t *t, long a, long r, struct s_t *o, long s, const char *d) {
  char *str = t[--a].v;
  s_t *Tpro = T(propeller0), *Tε = T(ε);
  D(B(Tpro, Tpro, Tpro, Tpro, B(T(str, match), Tε, Tε, Tε, o)));
}
void term4(struct s_t *t, long a, long r, struct s_t *o, long s,
           const char *d) {
  char *str0 = t[--a].v;
  char *str1 = t[--a].v;
  char *str2 = t[--a].v;
  char *str3 = t[--a].v;
  s_t *Tpro = T(propeller0);
  D(B(Tpro, Tpro, Tpro, Tpro,
      B(T(str0, match), T(str1, match), T(str2, match), T(str3, match), o)));
}
N(Sa) {
  D(B(T(propeller0), T(propeller0), T(propeller0), T(propeller0),
      B(T(cr, "b", term), T(cr, Sa, "a", term), T(ε), T(ε), o)));
}
N(land) { LOGD; }
int main() {
  s_t *t = T(cr, Sa);
  long a = t[-1].q;
  long r = 1;
  s_t *o = B(T(land), T(land), T(land), T(land), 0);
  s_t *s = 0;
  char *d = "baaa";
  D(o);
}
/*
lets start defining protocall.
* can perform previously impossible tasks
we have awesome protocall how to define executable sentences
and the words. now we shall implement its distributed version
and we will:
* achieve unprecedented levels of performance
* implementing, and improving a massive-scale distributed,
  machine learning, system,
* writing bug-free machine learning code,
* building the science behind the algorithms employed
write  read
read   write2


*/
