#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&VA(__VA_ARGS__, Nargs(__VA_ARGS__))[Nargs(__VA_ARGS__)])
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define LOG (void)0 //, printf("%.2ld %s\n", r, __FUNCTION__) //, sleep(1)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define OARS void (***o)(), void (**a)(), long r, void **s
#define N(argo) void argo(OARS)
N(l) {
  LOG;
  if (o[-2]) {
    o[-2] = o[9];
    o[r][-1](o[-2], o[r] - 1, o[10], s, o[11]);
  } else {
    void (***on)() = s[0];
    o[-2] = (void *)on;
    on[4][-1](on[-2], on[4] - 1, 4, s[-2]);
  }
}
N(m) {
  LOG;
  char *ms = (char *)*--a;
  char *in = s[0];
  long pos = s[1];
  long i = 0;
  while (ms[i]) {
    if (ms[i] < in[pos + i])
      return r++, o[r][-1](o[-2], o[r] - 1, r, s);
    else if (in[pos + i] < ms[i])
      return r--, o[r][-1](o[-2], o[r] - 1, r, s);
    i++;
  }
  o[r][-1](o[-2], o[r] - 1, r, O(s, in, pos + i));
}
N(c) { LOG, o[r][-1](o[-2], o[r] - 1, r, s); }
N(g) { LOG, o[11] = (long)o[11] + 1, c(o, a, r, s); }
N(ε) { LOG; }
void lt(OARS, long eq) { LOG, c(o, a, eq ? r : r - 1, s); }
void gt(OARS, long eq) { LOG, c(o, a, eq ? r : r + 1, s); }
N(k) { LOG, c(o, a, 4, s); }
// clang-format off
#define S7(o,r,SRD1,RED1,SRD2,RED2,SRD3,RED3,SRD4,RED4,SRD5,RED5,SRD6,RED6,SRD7,RED7) \
  O(O(O(O(O(O(0,                                                      \
  T(lt),RED1,RED2,RED3,RED4,RED5,RED6,RED7,T(gt), o, r, 0),           \
  T(l ),T(g),T(g),T(g),T(g),T(g),T(g),T(g),T(l )),                    \
  T(c ),SRD1,T(c),T(c),T(c),T(c),T(c),SRD7,T(ε )),                    \
  T(c ),T(ε),SRD2,T(c),T(c),T(c),SRD6,T(ε),T(ε )),                    \
  T(c ),T(ε),T(ε),SRD3,T(c),SRD5,T(ε),T(ε),T(ε )),                    \
  T(c ),T(ε),T(ε),T(ε),SRD4,T(ε),T(ε),T(ε),T(ε ))   
N(dec17) {
  o = S7(o, r,
      T("1", m),T(k),
      T("2", m),T(k),
      T("3", m),T(k),
      T("4", m),T(k),
      T("5", m),T(k),
      T("6", m),T(k),
      T("7", m),T(k));
  a[-1](o, a-1, 0, O(s, o));
}
N(r0) {printf("%s %s %ld\n", __FUNCTION__, (char*)s[0], (long)s[1]);}
N(r1) {printf("%s %s %ld\n", __FUNCTION__, (char*)s[0], (long)s[1]);}
N(r2) {printf("%s %s %ld\n", __FUNCTION__, (char*)s[0], (long)s[1]);}
int main() {
  void(***o)()   = O(0, T(r0), T(r1), T(r2));
  void(**a)()    = T(c,   dec17);
  a[-1](o, a-1, 1, O(0, "41231234", 0));
}
