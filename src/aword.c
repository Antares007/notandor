#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define ToString(a) #a,
#define T(...)                                                                 \
  ((s_t *)&(const void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define B(...) ((s_t *)(const void *[]){__VA_ARGS__})

#define D_(o) t[a - 1].c(o, b, a - 1, r, t, s)
#define D(o) logn(o, b, a, r, t, s, __FUNCTION__), D_(o)

#define obarts                                                                 \
  struct s_t *o, struct s_t *b, long a, long r, struct s_t *t, struct s_t *s
typedef struct s_t {
  union {
    struct s_t *o;
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
//  for (s_t *p = o; p; p = p[4].o)
//    printf("  ");
  printf("%s\n", name), usleep(1000000);
}
N(bo) {
  assert(a == 0);
  s_t *text = o[r].o;
  long len = text[-1].q;
  long advance = len - 1;
  s_t *father = o[4].o;
  w_t last_word = text[advance].c;
  last_word(father, b, advance, r, text, s);
}
N(cr0) { r = 0, D(o); }
N(cr1) { r = 1, D(o); }
N(cr2) { r = 2, D(o); }
N(cr3) { r = 3, D(o); }
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
N(ε       ) {   }

N(term0   ) { D(o); }
N(term1   ) { D(o); }
N(term2   ) { D(o); }
N(term3   ) { D(o); }
N(term    ) { D(B(T(term0), T(term1), T(term2), T(term3), o)); }
N(prop    ) {}
N(sS      ) { D(B(T(prop),              T(),    T(),  T(),
                B(T("s", term, sS, sS), T(bo),  T(ε), T(ε),
                B(T(),                  T(),    T(),  T(), o))));
}
N(yin) {D(o);}
N(yan) {D(o);}
int main( ) {
  s_t *t = T(bo);
  long a = t[-1].q;
  s_t *b =  B(T(bo, yin), T(bo, yin), T(bo, yin), T(bo, yin),
            B(T(bo, yan), T(bo, yan), T(bo, yan), T(bo, yan), 0));
  b[4].o[4].o = b;
  s_t *o = b;
  long r = 0;
  s_t *s = 0;
  D(o);
}
