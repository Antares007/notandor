#include "btaros.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#ifndef NDEBUG
#undef LOGD
#define LOGD printf("%ld/%ld %s\n", s, r, __FUNCTION__), usleep(100000)
#undef LOGT
#define LOGT printf("T")
#endif
N(bo) {
  assert(a == 0);
  t = o[r].o;
  a = t[-1].q;
  // D(o[s + 4].o); // ===
  t[a - 1].c(b, t, a - 1, r, o[s + 4].o, s);
}
// clang-format off
N(cr      ) { r = t[--a].q, D(o); }
N(cs      ) { s = t[--a].q, D(o); }
N(ps      ) { printf("%ld/%ld %s\n", s, r, t[--a].cs), usleep(10000), t[a - 1].c(b, t, a - 1, r, o, s); }
N(mb      ) { b = o, D(o); }
N(one0    ) { D(o); }
N(one1    ) { D(o); }
N(one2    ) { D(o); }
N(one3    ) { D(o); }
N(one     ) { 
  D(B(T(bo, one0),T(bo, one1),T(bo, one2),T(bo, one3),o,o,o,o)); }
N(sumo    ) { D(o); }
N(dot0    ) { s=(s+1)%4,D(b); }
N(dot1    ) { D(b); }
N(dot2    ) { D(b); }
N(dot3    ) { D(b); }
N(dot     ) {
  D(B(T(bo, dot0), T(bo, dot1), T(bo, dot2), T(bo, dot3), o, o, o, o));
}
void show() {
  taros *t = T(bo, mb, one);
  dot(0, t, t[-1].q, 0, 0, 0);
}
// clang-format on
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
