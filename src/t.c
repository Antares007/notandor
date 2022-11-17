#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...) ((void *)&VA(__VA_ARGS__,Nargs(__VA_ARGS__))[Nargs(__VA_ARGS__)])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#include <assert.h>
#include <stdio.h>
#define LOG //printf("%.2ld %s\n", r, __FUNCTION__);

void c(void (***o)(), void (**a)(), long r, void **s) { LOG;
  o[r][-1](o[-2], o[r]-1, r, s);
}
void d(void (***o)(), void (**a)(), long r, void **s) { LOG;
  a[-1](o, a - 1, r, s);
}
void one_(void (***o)(), void (**a)(), long r, void **s) { LOG;
  c(o, a, r, O(s, 1));
}
void one(void (***o)(), void (**a)(), long r, void **s) { LOG;
  d(O(o, T(c), T(one_), T(c)), a, r, s);
}
void add_(void (***o)(), void (**a)(), long r, void **s) { LOG;
  void**sp = s[-2];
  c(o, a, r, O(sp[-2], (long)sp[0] + (long)s[0]));
}
void add(void (***o)(), void (**a)(), long r, void **s) { LOG;
  d(O(o, T(c), T(add_), T(c)), a, r, s);
}

void thankyouGod(void (***a)()) {}
void printo(void(***o)(), void(**a)(), long r, void **s) {
  while(o) {
    printf("%p %p %p\n", o[0][-1], o[1][-1], o[2][-1]);
    o = (void*)o[-2];
  }
  d(o, a, r, s);
}
void e0(void(***o)(), void(**a)(), long r, void **s) { /*printf("%s\n", __FUNCTION__);*/ }
void e1(void(***o)(), void(**a)(), long r, void **s) { printf("%s %ld %ld %s\n", (char*)s[0], (long)s[1], (long)s[2], __FUNCTION__); }
void e2(void(***o)(), void(**a)(), long r, void **s) { printf("%s\n", __FUNCTION__); }

void term_(void(***o)(), void(**a)(), long r, void **s) { LOG;
  const char *m   = (void*)*--a;
  const char *in  = s[0];
  long len        = s[1];
  long pos        = s[2];
  if (pos < len && in[pos] == m[0])
    c(o,a,r,O(s, in, len, pos + 1));
  else
    c(o,a,0,s);
}
void term(void(***o)(), void(**a)(), long r, void **s) { LOG;
  const char *m = (void*)*--a;
  (void)m;
  a[-1](O(o,
          T(c),
          T(m, term_),
          T(c)), a - 1, r, s);
}
void tina(void(***o)(), void(**a)(), long r, void **s);
void tina_(void(***o)(), void(**a)(), long r, void **s) { LOG;
  d(O(o,
      T(c),
      T(c, "t", term),
      T(c)), a, r, s);
  d(O(o,
      T(c),
      T(c, tina, "a", term),
      T(c)), a, r, s);
}
void tina(void(***o)(), void(**a)(), long r, void **s) { LOG;
  d(O(o,
      T(c),
      T(c, tina_),
      T(c)), a, r, s);
}

int main() {
  void (***o)() = O(O(0,
                      T(e0),
                      T(e1),
                      T(e2)),
                        T(c),
                        T(c, tina), //T(c,one,one,add,one,add,one,add,one,add,one,add,one,add),
                        T(c));
  c(o, 0, 1, O(0, "taaa", 4, 0));
}
