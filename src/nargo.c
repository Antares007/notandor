#include "obrants.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#undef D
// taborns
#define D(o)                                                                   \
  logn(o, b, r, a, n, t, s, __FUNCTION__), t[a - 1].c(o, b, r, a - 1, n, t, s)
void logn(obrants, const char *name) {
  printf("%ld ", n);
  for (s_t *p = o; p; p = p[4].o)
    printf("  ");
  printf("%s\n", name), usleep(100000);
}
N(bo) {
  assert(a == 0);
  s_t *text = o[n].o;
  long len = text[-1].q;
  long advance = len - 1;
  s_t *father = o[4].o;
  w_t last_word = text[advance].c;
  last_word(father, b, r, advance, n, text, s);
}
N(ci0) { n = 0, D(o); }
N(ci1) { n = 1, D(o); }
N(ci2) { n = 2, D(o); }
N(ci3) { n = 3, D(o); }
N(match) {
  const char *in = s[1].cs;
  long len = s[2].q;
  long pos = s[3].q;
  const char *str = t[--a].cs;
  if (pos < len && str[0] == in[pos])
    s = B(s, in, (void *)len, (void *)(pos + 1)), D(o);
  else
    D(o);
}
N(ε) {}

N(term0) { D(o); }
N(term1) { D(o); }
N(term2) { D(o); }
N(term3) { D(o); }
N(term) { D(B(T(term0), T(term1), T(term2), T(term3), o)); }
N(prop) {}
N(sS) {
  D(B(T(prop), T(), T(), T(),
      B(T("s", term, sS, sS), T(bo), T(ε), T(ε), B(T(), T(), T(), T(), o))));
}
N(yin2) { D(r); }
N(yin ) { D(B(T(bo, yin2), T(bo, yin2), T(bo, yin2), T(bo, yin2), b)); }
N(yan ) { D(b); }
N(ob  ) { bo(o, b, r, a, n, t, s); }
int main() {
  s_t *t = T(bo);
  long a = t[-1].q;
  s_t *b = B(T(ob, yin), T(ob, yin), T(ob, yin), T(ob, yin), 0);
  s_t *r = B(T(ob, yan), T(ob, yan), T(ob, yan), T(ob, yan), 0);
  long n = 0;
  s_t *s = 0;
  D(b);
}
