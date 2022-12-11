#include "taros.h"
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
  t[a - 1].c(t, a - 1, r, o[s + 4].o, s);
}
N(dot) {
  assert(a == 0);
  a = t[-1].q;
  D(o);
}
N(propeller) {
  for (s = 0; s < 4; s++)
    t[a - 1].c(t, a - 1, r, o, s); // D(o);
}
N(cr) { r = t[--a].q, D(o); }
N(cs) { s = t[--a].q, D(o); }
N(ps) {
  printf("%ld/%ld %s\n", s, r, t[--a].cs), usleep(10000),
      t[a - 1].c(t, a - 1, r, o, s);
}
// clang-format off
N(one) {
  D(B(T(bo, propeller), T(bo), T(bo), T(bo),
      B(  T(bo,"A0",ps),  T(bo,"A1",ps),  T(bo,"A2",ps),  T(bo,"A3",ps), 
        B(T(bo,"Aa0",ps), T(bo,"Aa1",ps), T(bo,"Aa2",ps), T(bo,"Aa3",ps), o, o, o, o), 
        B(T(bo,"Ab0",ps), T(bo,"Ab1",ps), T(bo,"Ab2",ps), T(bo,"Ab3",ps), o, o, o, o), 
        B(T(bo,"Ac0",ps), T(bo,"Ac1",ps), T(bo,"Ac2",ps), T(bo,"Ac3",ps), o, o, o, o), 
        B(T(bo,"Ad0",ps), T(bo,"Ad1",ps), T(bo,"Ad2",ps), T(bo,"Ad3",ps), o, o, o, o)),
      B(  T(bo,"B0",ps),  T(bo,"B1",ps),  T(bo,"B2",ps),  T(bo,"B3",ps),
        B(T(bo,"Ba0",ps), T(bo,"Ba1",ps), T(bo,"Ba2",ps), T(bo,"Ba3",ps), o, o, o, o), 
        B(T(bo,"Bb0",ps), T(bo,"Bb1",ps), T(bo,"Bb2",ps), T(bo,"Bb3",ps), o, o, o, o), 
        B(T(bo,"Bc0",ps), T(bo,"Bc1",ps), T(bo,"Bc2",ps), T(bo,"Bc3",ps), o, o, o, o), 
        B(T(bo,"Bd0",ps), T(bo,"Bd1",ps), T(bo,"Bd2",ps), T(bo,"Bd3",ps), o, o, o, o)),
      B(  T(bo,"C0",ps),  T(bo,"C1",ps),  T(bo,"C2",ps),  T(bo,"C3",ps),
        B(T(bo,"Ca0",ps), T(bo,"Ca1",ps), T(bo,"Ca2",ps), T(bo,"Ca3",ps), o, o, o, o), 
        B(T(bo,"Cb0",ps), T(bo,"Cb1",ps), T(bo,"Cb2",ps), T(bo,"Cb3",ps), o, o, o, o), 
        B(T(bo,"Cc0",ps), T(bo,"Cc1",ps), T(bo,"Cc2",ps), T(bo,"Cc3",ps), o, o, o, o), 
        B(T(bo,"Cd0",ps), T(bo,"Cd1",ps), T(bo,"Cd2",ps), T(bo,"Cd3",ps), o, o, o, o)),
      B(  T(bo,"D0",ps),  T(bo,"D1",ps),  T(bo,"D2",ps),  T(bo,"D3",ps),
        B(T(bo,"Da0",ps), T(bo,"Da1",ps), T(bo,"Da2",ps), T(bo,"Da3",ps), o, o, o, o), 
        B(T(bo,"Db0",ps), T(bo,"Db1",ps), T(bo,"Db2",ps), T(bo,"Db3",ps), o, o, o, o), 
        B(T(bo,"Dc0",ps), T(bo,"Dc1",ps), T(bo,"Dc2",ps), T(bo,"Dc3",ps), o, o, o, o), 
        B(T(bo,"Dd0",ps), T(bo,"Dd1",ps), T(bo,"Dd2",ps), T(bo,"Dd3",ps), o, o, o, o))
      ));
}
// clang-format on
N(sumo) { D(B(T(bo), T(bo), T(bo), T(bo), o, o, o, o)); }
N(land) {}
N(growland) {
  taros *Tland = T(bo, land);
  D(B(Tland, Tland, Tland, Tland, o, o, o, o));
}
void show() { dot(T(bo, one, one, growland), 0, 0, 0, 0); }
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
  struct word_t *rs[4];
  struct pith_t *os[4];
} pith_t;
N(bo_) {
  t = o->rs[r];
  a = t[-1].q;
  t[a - 1].c(t, a - 1, r, o->os[s], s);
}
N(tt) {
  t[a - 1].c(t, a - 1, r,
             &(pith_t){.rs =
                           {
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                               (word_t[]){{.c = bo_}},
                           },
                       .os = {0, 0, 0, 0}},
             s);
}
/*
  one one sumo one sumo land
  lets start defining the word in programming.
  the word is C function with five fixed parameters.

  void the_word(taros *t, int a, int r, taros *o, int s) {...}
  as we can see there a, r and s are just scalar int values.
  o is the pith of the word.

  in georgian language, sentence can be divided in four parts.
  subject, primary object, secondary object and listener.
*/
int main() { show(); }
