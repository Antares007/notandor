#define Nargs(...)                                                             \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define B(...) T(__VA_ARGS__)
#define LOGT (void)0
#define T(...)                                                                 \
  (LOGT, (s_t *)&(void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define BOtars                                                                 \
  struct s_t *b, struct s_t *o, struct s_t *t, long a, long r //, long s
#define N(argos) void argos(BOtars)
#define LOGD (void)0
#define D(_o_) LOGD, t[a - 1].c(b, o, t, a - 1, r)
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

N(cr) {
  assert(a == 0);
  t = o[r].o;
  a = t[-1].q;
  t[a - 1].c(b, o[4].o, t, a - 1, r);
}
N(ps) {
  printf("%s\n", (char *)t[--a].v), usleep(100000);
  t[a - 1].c(b, o, t, a - 1, r);
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

N(swap_ob) { LOGD, t[a - 1].c(b[5].o, b, t, a - 1, r); }
N(next_ray) { t[a - 1].c(b, o, t, a - 1, (r + 1) % 4); }
N(dot) {
  void *Tcr_next_ray_swap_ob = T(cr, next_ray, swap_ob);
  void *Tcr_swap_ob = T(cr, swap_ob);
  b = B(Tcr_next_ray_swap_ob, Tcr_next_ray_swap_ob, Tcr_next_ray_swap_ob,
        Tcr_next_ray_swap_ob, b, 0);
  o = B(Tcr_swap_ob, Tcr_swap_ob, Tcr_swap_ob, Tcr_swap_ob, o, 0);
  b[5].o = o;
  o[5].o = b;
  D(o);
}
N(sw) {
  b = B(T(cr, "s_b0", ps), T(cr, "s_b1", ps), T(cr, "s_b2", ps),
        T(cr, "s_b3", ps), b, 0);
  o = B(T(cr, "s_o0", ps), T(cr, "s_o1", ps), T(cr, "s_o2", ps),
        T(cr, "s_o3", ps), o, 0);
  b[5].o = o, o[5].o = b, D(o);
}
N(tw) {
  b = B(T(cr, "t_b0", ps), T(cr, "t_b1", ps), T(cr, "t_b2", ps),
        T(cr, "t_b3", ps), b, 0);
  o = B(T(cr, "t_o0", ps), T(cr, "t_o1", ps), T(cr, "t_o2", ps),
        T(cr, "t_o3", ps), o, 0);
  b[5].o = o;
  o[5].o = b;
  D(o);
}
N(land) { LOGD; }
int main() {
  s_t *b = 0;
  s_t *o = 0;
  s_t *t = T(cr, tw, dot, sw, dot);
  long a = t[-1].q;
  long r = 0;
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
