#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define VA(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&VA(__VA_ARGS__, Nargs(__VA_ARGS__))[Nargs(__VA_ARGS__)]),
#define O(o, ...) ((void *)&VA(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define LOG printf("%.2ld %s\n", r, __FUNCTION__)
//, sleep(1)
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define N(argo) void argo(void (***o)(), void (**a)(), long r, void **s)
N(lp) {
  LOG, o[-2] = s[0], o = s[0], r = 4, o[r][-1](o[-2], o[r] - 1, r, s[-2]);
}
N(m) {
  LOG;
  char *ms = (char *)*--a;
  char *in = s[0];
  long pos = s[1];
  long i=0;
  while(ms[i]) {
    if (ms[i] < in[pos+i])
      return r--, o[r][-1](o[-2], o[r]-1, r, s);
    else if (in[pos+i] < ms[i])
      return r++, o[r][-1](o[-2], o[r]-1, r, s);
    i++;
  }
  o[r][-1](o[-2], o[r]-1, r, O(s, in, pos + i));
}
N(c) { LOG, o[r][-1](o[-2], o[r] - 1, r, s); }
N(ε) { LOG; }
N(lt) { LOG; }
N(gt) { LOG; }
N(k) { LOG; printf("\"%s\" %ld\n", (char*)s[0], (long)s[1]), c(o, a, 4, s); }
#define S(a) T(#a, m)
// clang-format off
#define S7(sw1,rw1,sw2,rw2,sw3,rw3,sw4,rw4,sw5,rw5,sw6,rw6,sw7,rw7) \
  O(O(O(O(O(0,                                                      \
  T(gt)rw7 rw6 rw5 rw4 rw3 rw2 rw1 T(lt)),                          \
  T(lp)sw7 T(c)T(c)T(c)T(c)T(c)sw1 T(ε )),                          \
  T(c )T(ε)sw6 T(c)T(c)T(c)sw2 T(ε)T(ε )),                          \
  T(c )T(ε)T(ε)sw5 T(c)sw3 T(ε)T(ε)T(ε )),                          \
  T(c )T(ε)T(ε)T(ε)sw4 T(ε)T(ε)T(ε)T(ε ))   
int main() {
  void(***o)()  = S7(
      T("1", m),T(k),
      T("2", m),T(k),
      T("3", m),T(k),
      T("4", m),T(k),
      T("5", m),T(k),
      T("6", m),T(k),
      T("7", m),T(k));
  o[0][-1](o[-2], o[0]-1, 0, O(O(0, "41231234", 0), o));
}
