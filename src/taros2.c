#define Nargs(...)                                                             \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define B(...) T(__VA_ARGS__)
#define LOGT (void)0
#define T(...)                                                                 \
  (LOGT, (s_t *)&(void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define BOtars                                                                 \
  struct s_t *b, struct s_t *o, struct s_t *t, long a, long r, long s
#define N(argos) void argos(BOtars)
#define LOGD (void)0
#define D(_o_) LOGD, t[a - 1].c(b, o, t, a - 1, r, s)
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
#define LOGD printf("%ld %ld %ld %s\n", a, r, s, __FUNCTION__), usleep(100000)
#undef LOGT
#define LOGT printf("T")
#endif

N(cr) {
  assert(a == 0);
  t = o[r].o;
  a = t[-1].q;
  t[a - 1].c(b, o[4].o, t, a - 1, r, s);
}
// mamam shvils sakhli aushena
// aushena mamam shvils sakhli
// sakhli aushena mamam shvils
// shvils aushena mamam sakhli
// erts daumate erti da gaamravle orze.
// τ α ρ ο σ δ ι
N(mamam) {}
N(shvils) {}
N(sakhli) {}
N(aushena) {}

N(o0) { LOGD, cr(b[5].o, b, t, a, r + 0, !s); }
N(o1) { LOGD, cr(b[5].o, b, t, a, r + 0, !s); }
N(o2) { LOGD, cr(b[5].o, b, t, a, r + 0, !s); }
N(o3) { LOGD, cr(b[5].o, b, t, a, r + 0, !s); }

N(b0) { LOGD, cr(b[5].o, b, t, a, r + 1, !s); }
N(b1) { LOGD, cr(b[5].o, b, t, a, r + 1, !s); }
N(b2) { LOGD, cr(b[5].o, b, t, a, r + 1, !s); }
N(b3) { LOGD; }

N(cro0) {  D(o); }
N(cro1) {  D(o); }
N(cro2) {  D(o); }
N(cro3) {  D(o); }

N(crb0) {  D(o); }
N(crb1) {  D(o); }
N(crb2) {  D(o); }
N(crb3) {  D(o); }

N(sword) {
  b = B(T(cr, crb0), T(cr, crb1), T(cr, crb2), T(cr, crb3), b, 0);
  o = B(T(cr, cro0), T(cr, cro1), T(cr, cro2), T(cr, cro3), o, 0);
  b[5].o = o;
  o[5].o = b;
  D(o);
}
int main() {
  s_t *b = B(T(b0), T(b1), T(b2), T(b3), 0, 0);
  s_t *o = B(T(o0), T(o1), T(o2), T(o3), 0, 0);
  b[5].o = o;
  o[5].o = b;
  s_t *t = T(cr, sword);
  long a = t[-1].q;
  long r = 0;
  long s = 0;
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
