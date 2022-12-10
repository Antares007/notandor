#define NofArgs(...)                                                           \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define LOG (void)0
#define D(o) LOG, t[a - 1].c(t, a - 1, r, o, s)
#define B(r0, r1, r2, r3, oa, ob, oc, od)                                      \
  T(r0, r1, r2, r3, (void *)oa, (void *)ob, (void *)oc, (void *)od)
#define T(...)                                                                 \
  ((taros *)&(void *[]){(void *)NofArgs(__VA_ARGS__), __VA_ARGS__}[1])
#define N(argos)                                                               \
  void argos(struct taros *t, long a, long r, struct taros *o, long s)
typedef struct taros {
  union {
    struct taros *o;
    signed long q;
    void *v;
    const char *cs;
    N((*c));
  };
} taros;
#include <stdio.h>
#include <unistd.h>
#undef LOG
#define LOG printf("%ld/%ld %s\n", s, r, __FUNCTION__), usleep(100000)

#include <assert.h>
N(cr) {
  assert(a == 0);
  t = o[r].o;
  a = t[-1].q;
  D(o[s + 4].o); // === t[a - 1].c(o[s + 4].o, t, a - 1, r, s);
}
N(propeller) { LOG; }
N(one) {
  D(B(T(propeller), T(propeller), T(propeller), T(propeller), o, o, o, o));
}
N(sumo) { LOG; }
N(land) { LOG; }
N(dot) {
  assert(a == 0);
  a = t[-1].q;
  D(o);
}
void show() {
  dot(T(cr, one, one, sumo, one, sumo), 0, 0,
      B(T(cr, land), T(cr, land), T(cr, land), T(cr, land), 3, 2, 1, 0), 0);
}
int main() { show(); }
/*
   one one
     \/
    sumo one
       \/
      sumo
        |
      land
*/
