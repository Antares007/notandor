#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...) ((void *)&VA(__VA_ARGS__,Nargs(__VA_ARGS__))[Nargs(__VA_ARGS__)])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define A(...) a[-1](O(o, T(c), T(__VA_ARGS__), T(c)), a-1, r, s)
#define C(r, s) o[r][-1](o[-2], o[r]-1, r, s)
#define N(argo) void argo(void (***o)(), void (**a)(), long r, void **s)
#include <assert.h>
#include <stdio.h>
#define LOG // printf("%.2ld %s\n", r, __FUNCTION__);

N(c     ) { LOG; o[r][-1](o[-2], o[r]-1, r, s); }
N(one_  ) { LOG; C(r, O(s, 1)); }
N(one   ) { LOG; A(one_); }
N(add_  ) { LOG; void**sp = s[-2];
                 c(o, a, r, O(sp[-2], (long)sp[0] + (long)s[0])); }
N(add   ) { LOG; A(add_); }
long e0c = 0;
N(e0    ) { e0c++;/*printf("%s\n", __FUNCTION__);*/ }
N(e1    ) { printf("%p %s\n", s[2], __FUNCTION__); }
N(e2    ) { printf("%p %s\n", s[0], __FUNCTION__); }
N(term_ ) { LOG;  const char *m   = (void*)*--a;
                  const char *in  = s[0];
                  long len        = s[1];
                  long pos        = s[2];
                  if (pos < len && in[pos] == m[0])
                    c(o,a,r,O(s, in, len, pos + 1));
                  else
                    c(o,a,0,s); }
N(term  ) { LOG;  const char *m = (void*)*--a;
                  A(c, m, term_); }
N(tina  );
N(tina_ ) { LOG;  A(c, "t", term);
                  A(c, tina, "a", term); }
N(tina  ) { LOG;  A(c, tina_); }
int main() {
  void (***o)() = O(O(0,
                      T(e0),
                      T(e1),
                      T(e2)),
                        T(c),
                        T(c, tina),
                        T(c));
  c(o, 0, 1, O(0, "taaa", 4, 0));

}
