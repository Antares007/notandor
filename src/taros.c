#include "taros.h"
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#undef LOG
#define LOG printf("%ld/%ld %s\n", s, r, __FUNCTION__), usleep(100000)
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
