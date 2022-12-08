#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define ToString(a) #a,
#define T(...)                                                                 \
  ((s_t *)&(const void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define O(...) ((s_t *)(const void *[]){__VA_ARGS__})

#define D_(o) t[a - 1].c(o, b, a - 1, r, t, s)
#define D(o) logn(o, b, a, r, t, s, __FUNCTION__), D_(o)

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
  printf("%s\n", name), usleep(1000000);
}
// memoize what and when?
// we need to remove cycle from propeller and find perfect cycle!
// mamam shvils sakhli aushena
// how perfect cycle can be defined? c: void y(long x) { y((x + 1) % 8); }
N(bo) {
  assert(a == 0);
  s_t *text = o[r].s;
  long len = text[-1].q;
  long advance = len - 1;
  s_t *father = o[4].s;
  w_t last_word = text[advance].c;
  last_word(father, b, advance, r, text, s);
}
N(cr0) { r = 0, D(o); }
N(cr1) { r = 1, D(o); }
N(cr2) { r = 2, D(o); }
N(cr3) { r = 3, D(o); }
N(dot) { D(o); }
N(propeller) {
  for (r = 0; r < 4; r++)
    D(o);
}
N(wrap_1x1) {
  s_t *Tb = t[--a].s;
  s_t *Ta = t[--a].s;
  D(O(Ta, Ta, Ta, Ta, O(Tb, Tb, Tb, Tb, o)));
}
N(match) {
  const char *in = s[1].cs;
  long len = s[2].q;
  long pos = s[3].q;
  const char *str = t[--a].cs;
  if (pos < len && str[0] == in[pos])
    s = O(s, in, (void *)len, (void *)(pos + 1)), D(o);
  else
    D(o);
}
#define W(a, b) T(bo, a, b, wrap_1x1)
N(dign_o) {
  D(O(T(bo, "0", match), T(bo, "1", match), T(bo, "2", match),
      T(bo, "3", match), o));
}

N(rec) { D(b); }
N(the_word) {
  if (o[5].c == the_word)
    D_(o);
  else
    D_(O(T(bo), T(bo), T(bo), T(bo), o, the_word));
}
void perfect_loop() {
  s_t *o = O(
      T(bo, the_word), T(bo, the_word), T(bo, the_word), T(bo, the_word),
      O(T(bo, rec, cr1), T(bo, rec, cr2), T(bo, rec, cr3), T(bo, rec, cr0), 0));
  bo(o, o, 0, 0, 0, 0);
}

N(end_o) { printf("end_o %ld %s %ld %ld\n", r, s[1].cs, s[2].q, s[3].q); }
N(end_b) { printf("end_b\n"); }
int main() {
  perfect_loop();
  return 9;
  s_t *t = T(bo);
  char *str = "012";
  t[t[-1].q - 1].c(
      O(T(bo, end_o), T(bo, end_o), T(bo, end_o), T(bo, end_o), 0), //
      O(T(bo, end_b), T(bo, end_b), T(bo, end_b), T(bo, end_b), 0), //
      t[-1].q - 1, 1, t, O(0, str, (void *)strlen(str), (void *)0));
}
