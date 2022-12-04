#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define O(r0, r1, r2, r3, o) ((void *)(const void *[]){r0, r1, r2, r3, o})
#define T(...)                                                                 \
  ((void *)&A(propeller, 0, revise_brain, __VA_ARGS__, use_brain,              \
              Nargs(__VA_ARGS__) + 4)[Nargs(__VA_ARGS__) + 4])
#define A(...) ((void *[]){__VA_ARGS__})

typedef void (*w_t)(void *, void *, void *, void *);
#define btos w_t **b, w_t *t, w_t **o, void **s
#include <assert.h>
void revise_brain(btos) {
  assert(t[-1] == 0);
  t[-1] = (void *)o;
  t[-2](b, t - 2, o, s);
}
void use_brain(btos) {
  assert((void *)t[0] == use_brain);
  long l = (long)t[1]-1;
  assert((void *)t[-l] == propeller);
  w_t on = t[1 - l];
  if (on) t[-l](b, t - l, on, s);
  else    t[-1](b, t - 1, o,  s);
}
#include <stdio.h>
void cr(btos) {
    o[i][-1](b, o[i] - 1, o[4], s);
}
void propeller(btos) {
  for (long i = 0; i < 4; i++)
    printf("%p %ld\n", t, i),o[i][-1](b, o[i] - 1, o[4], s);
}
void ε() {}
void *Tε = T(ε);

void dim(btos) {
  char c = ((char *)*--t)[0];
  char *in = s[0];
  long len = s[1];
  long pos = s[2];
  if (pos < len && c == in[pos])
    t[-1](b, t - 1, o, A(in, len, pos + 1));
}
void term(btos) {
  void *str = *--t;
  t[-1](b, t - 1, O(T(str, dim), Tε, Tε, Tε, o), s);
}
void S(btos) {
  t[-1](b, t - 1, O(T("b", term), T(S, "a", term), T(ε), T(ε), o), s);
}
void print(btos){
  printf("aa\n");
  t[-1](b, t-1, o, s);
}
void test(btos) {
  t[-1](b, t-1, O(T(print), Tε, Tε, Tε, o), s);
}
void end(btos) { printf("end %ld\n", (long)s[2]); }
int main() {
  w_t*t = T("b", term);
  t[-1](0, t-1, O(T(end), T(end), T(end), T(end), 0), A("baaa", 4, 0));
}

//    XXXXX
//     XXX
//      #
//     XXX
//    XXXXX
//
//      X
//     XXX
//    XXXXX
//     ###
//      #
