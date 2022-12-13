#include "btaros.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#ifndef NDEBUG
#undef LOGD
#define LOGD printf("%ld/%ld %s\n", s, r, __FUNCTION__), usleep(10000)
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
N(one     ) { D(B(  T(bo),        T(bo),        T(bo),        T(bo),
                  B(T(bo,"A0",ps),T(bo,"A1",ps),T(bo,"A2",ps),T(bo,"A3",ps), o, o, o, o),
                  B(T(bo,"B0",ps),T(bo,"B1",ps),T(bo,"B2",ps),T(bo,"B3",ps), o, o, o, o),
                  B(T(bo,"C0",ps),T(bo,"C1",ps),T(bo,"C2",ps),T(bo,"C3",ps), o, o, o, o),
                  B(T(bo,"D0",ps),T(bo,"D1",ps),T(bo,"D2",ps),T(bo,"D3",ps), o, o, o, o)
                  )); }
N(sumo    ) { D(o); }
N(and     ) { D(o); }
N(dot0    ) { D(o); } N(dot1    ) { D(o); } N(dot2    ) { D(o); } N(dot3    ) { D(o); }
N(dotS0   ) { s++,D(b); }
N(dotS1   ) { s++,D(b); }
N(dotS2   ) { s++,D(b); }
N(dotS3   ) { LOGD; }
N(dot     ) {
  //D(B(0, 0, 0, 0,
  //    b, b, b, b));
  D(B(  T(bo,dot0), T(bo,dot1), T(bo,dot2), T(bo,dot3),
      B(T(bo,dotS0),T(bo,dotS0),T(bo,dotS0),T(bo,dotS0), o,o,o,o),
      B(T(bo,dotS1),T(bo,dotS1),T(bo,dotS1),T(bo,dotS1), o,o,o,o),
      B(T(bo,dotS2),T(bo,dotS2),T(bo,dotS2),T(bo,dotS2), o,o,o,o),
      B(T(bo,dotS3),T(bo,dotS3),T(bo,dotS3),T(bo,dotS3), o,o,o,o)
      ));
}
// ushenebs mama shvils sakhls da mze icinis.
// epoll-s mivkvet da gavaketot taros-i
// kerki kani membrana
void show() {
  taros *t = T(bo, mb, one, dot);
  long a = t[-1].q;
  t[a-1].c(0, t, a-1, 0, 0, 0);
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
/*
* can perform previously impossible tasks
* achieve unprecedented levels of performance
* implementing, and improving a massive-scale distributed,
  machine learning, system,
* writing bug-free machine learning code,
* building the science behind the algorithms employed
*/
