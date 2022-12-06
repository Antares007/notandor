#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define ToString(a) #a,
#define T(...)                                                                 \
  ((s_t *)&(const void *[]){(void *)Nargs(bo, __VA_ARGS__), bo, __VA_ARGS__}[1])
#define O(...) ((s_t *)(const void *[]){__VA_ARGS__})
#define obarts                                                                 \
  struct s_t *o, struct s_t *b, long a, long r, struct s_t *t, struct s_t *s
typedef struct s_t {
  union {
    struct s_t *s;
    signed long q;
    void *v;
    const char *cs;
    void (*c)(obarts);
  };
} s_t;
typedef void (*w_t)(obarts);
#define N(argo) void argo(obarts)
#include <assert.h>
// logging
// memoization
// we need to remove cycle from propeller and find perfect cycle!
N(bo) {
  assert(a == 0);
  s_t *text = o[r].s;
  long len = text[-1].q;
  long advance = len - 1;
  s_t *father = o[4].s;
  w_t last_word = text[advance].c;
  last_word(father, b, advance, r, text, s);
}
N(cr0) { t[a - 1].c(o, b, a - 1, 0, t, s); }
N(cr1) { t[a - 1].c(o, b, a - 1, 1, t, s); }
N(cr2) { t[a - 1].c(o, b, a - 1, 2, t, s); }
N(cr3) { t[a - 1].c(o, b, a - 1, 3, t, s); }

N(dot) { t[a - 1].c(o, b, a - 1, r, t, s); }
N(propeller) {
  for (r = 0; r < 4; r++)
    t[a - 1].c(o, b, a - 1, r, t, s);
}
N(match) {
  const char *in = s[1].cs;
  long len = s[2].q;
  long pos = s[3].q;
  const char *str = t[--a].cs;
  if (pos < len && str[0] == in[pos])
    t[a - 1].c(o, b, a - 1, r, t, O(s, in, (void *)len, (void *)(pos + 1)));
}
N(operator_o) {
  t[a - 1].c(O(T("+", match), T("-", match), T("*", match), T("/", match), o),
             b, a - 1, r, t, s);
}
N(wrap) {
  s_t *To = t[--a].s;
  s_t *Tb = t[--a].s;
  t[a - 1].c(O(Tb, Tb, Tb, Tb, O(To, To, To, To, o)), b, a - 1, r, t, s);
}
N(operator) {
  s_t *Tp = T(propeller, operator_o);
  t[a - 1].c(O(T(Tp, T(cr0), wrap), T(Tp, T(cr1), wrap), T(Tp, T(cr2), wrap),
               T(Tp, T(cr3), wrap), o),
             b, a - 1, r, t, s);
}

#include <stdio.h>
N(end_o) { printf("end_o %ld %s %ld %ld\n", r, s[1].cs, s[2].q, s[3].q); }
N(end_b) { printf("end_b\n"); }
int main() {
  s_t *t = T(operator, operator, operator, operator);
  t[t[-1].q - 1].c(O(T(end_o), T(end_o), T(end_o), T(end_o), 0), //
                   O(T(end_b), T(end_b), T(end_b), T(end_b), 0), //
                   t[-1].q - 1, 1, t, O(0, "*+/-", (void *)4, (void *)0));
}
