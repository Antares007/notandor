#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define ToString(a) #a,
#define T(...)                                                                 \
  ((s_t *)&(const void *[]){(void *)Nargs(bo, __VA_ARGS__), bo, __VA_ARGS__}[1])
#define O(...) ((s_t *)(const void *[]){__VA_ARGS__})

#define D(o)                                                                   \
  logn(o, b, a, r, t, s, __FUNCTION__), t[a - 1].c(o, b, a - 1, r, t, s)

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
// logging
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void logn(obarts, const char *name) {
  printf("%ld ", r);
  for (s_t *p = o; p; p = p[4].s)
    printf("  ");
  printf("%s %ld\n", name, s[3].q), usleep(10000);
}
// memoization what and when
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
N(cr0) { r=0,D(o); }
N(cr1) { r=1,D(o); }
N(cr2) { r=2,D(o); }
N(cr3) { r=3,D(o); }

N(dot) { D(o); }
N(propeller) {
  for (r = 0; r < 4; r++)
    D(o);
}
N(wrap) {
  s_t *Tcrn = t[--a].s;
  s_t *Tpropeller_wordcore = t[--a].s;
  D(O(Tpropeller_wordcore, Tpropeller_wordcore, Tpropeller_wordcore,
      Tpropeller_wordcore, O(Tcrn, Tcrn, Tcrn, Tcrn, o)));
}
// mamam shvils sakhli aushena
void word(obarts, void *wordcore) {
  s_t *Tpropeller_wordcore = T(propeller, wordcore);
  D(O(T(Tpropeller_wordcore, T(cr0), wrap), //
      T(Tpropeller_wordcore, T(cr1), wrap), //
      T(Tpropeller_wordcore, T(cr2), wrap), //
      T(Tpropeller_wordcore, T(cr3), wrap), o));
}
N(match) {
  const char *in = s[1].cs;
  long len = s[2].q;
  long pos = s[3].q;
  const char *str = t[--a].cs;
  if (pos < len && str[0] == in[pos])
    s = O(s, in, (void *)len, (void *)(pos + 1)), D(o);
}
N(dig03_o) {
  D(O(T("0", match), T("1", match), T("2", match), T("3", match), o));
}
N(dig) {
  s_t*Tpropellerdig03_o = T(propeller, dig03_o);
  D(O(T(Tpropellerdig03_o, T(cr0), wrap),
      T(Tpropellerdig03_o, T(cr1), wrap),
      T(Tpropellerdig03_o, T(cr2), wrap),
      T(Tpropellerdig03_o, T(cr3), wrap), o)); }

N(dig47_o) {
  D(O(T("4", match), T("5", match), T("6", match), T("7", match), o));
}
N(dig47) { word(o, b, a, r, t, s, dig47_o); }
N(dig03) { word(o, b, a, r, t, s, dig03_o); }
N(Nat_o) { D(O(T(dig03), T(dig47), T("8", match), T("9", match), o)); }
N(Nat) { word(o, b, a, r, t, s, Nat_o); }
N(ε) {}
N(Nats);
N(Nats_o) { D(O(T(Nat), T(Nats, Nat), T(ε), T(ε), o)); }
N(Nats) { word(o, b, a, r, t, s, Nats_o); }

N(operator_o) {
  D(O(T("+", match), T("-", match), T("*", match), T("/", match), o));
}
N(operator) { word(o, b, a, r, t, s, operator_o); }
N(E);
N(E_o) { D(O(T(E, operator, E), T(Nats), T(ε), T(ε), o)); }
N(E) { word(o, b, a, r, t, s, E_o); }

N(end_o) { printf("end_o %ld %s %ld %ld\n", r, s[1].cs, s[2].q, s[3].q); }
N(end_b) { printf("end_b\n"); }
N(ps) {
  t = t[--a].s;
  a = t[-1].q;
  D(o);
}
int main() {
  s_t *t = T(T(dig), ps);
  char *str = "2987654321";
  t[t[-1].q - 1].c(O(T(end_o), T(end_o), T(end_o), T(end_o), 0), //
                   O(T(end_b), T(end_b), T(end_b), T(end_b), 0), //
                   t[-1].q - 1, 2, t,
                   O(0, str, (void *)strlen(str), (void *)0));
}
