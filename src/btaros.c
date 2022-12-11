#include "btaros.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#ifndef NDEBUG
#undef LOG
#define LOG printf("%ld/%ld %s\n", s, r, __FUNCTION__), usleep(10000)
#endif
N(bo) {
  assert(a == 0);
  t = o[r].o;
  a = t[-1].q;
  // D(o[s + 4].o); // ===
  t[a - 1].c(o, t, a - 1, r, o[s + 4].o, s);
}
N(propeller) {
  for (s = 0; s < 4; s++)
    t[a - 1].c(b, t, a - 1, r, o, s); // D(o);
}
N(cr) { r = t[--a].q, D(o); }
N(cs) { s = t[--a].q, D(o); }
N(ps) {
  printf("%ld/%ld %s\n", s, r, t[--a].cs), usleep(10000),
      t[a - 1].c(b, t, a - 1, r, o, s);
}
// clang-format off
N(one) {
  D(
    B(T(bo), T(bo), T(bo), T(bo), o, o, o, o)
  );
}
// clang-format on
N(sumo) { D(B(T(bo), T(bo), T(bo), T(bo), o, o, o, o)); }
N(land) {}
N(growland) {
  taros *Tland = T(bo, land);
  D(B(Tland, Tland, Tland, Tland, o, o, o, o));
}
void show() {
  taros *t = T(bo, one, one, sumo, one, sumo);
  growland(0, t, t[-1].q, 0, 0, 0);
}
#undef N
#define N(argos)                                                               \
  void argos(struct word_t *t, long a, long r, struct pith_t *o, long s)
struct pith_t;
typedef struct word_t {
  union {
    signed long q;
    void *v;
    N((*c));
  };
} word_t;
typedef struct pith_t {
  struct word_t *rays[4];
  struct pith_t *os[4];
} pith_t;
N(bo_) {
  t = o->rays[r];
  a = t[-1].q;
  t[a - 1].c(t, a - 1, r, o->os[s], s);
}
N(tt) {
  t[a - 1].c(t, a - 1, r,
             &(pith_t){.rays =
                           {
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                           },
                       .os = {0, 0, 0, 0}},
             s);
}
int main() { show(); }
