#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(__VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define obart                                                                  \
  void (****o)(), void (****b)(), long a, long r, void (**t)(), char *data
#define V(...) ((void *)(void *[]){__VA_ARGS__})
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define LOG printf("%ld %ld %s\t%s\n", a, r, __FUNCTION__, data), usleep(100000)

void end(obart) { printf("%.3lo %p\n", (long)t[-1], o); }
void cr(obart) { o[a][r][-1](o[2], b, a, r, o[a][r] - 1, data); }

void ps(obart) { puts((char *)*--t), t[-1](o, b, a, r, t - 1, data); }

void term0(obart) { LOG; }
void term1(obart) { LOG; o[0][3][-1](o[2], o, 0, 3, o[0][1] - 1, data); }
void term2(obart) { LOG; }
void term3(obart) { LOG, b[0][1][-1](b[2], b, 0, 1, b[0][1] - 1, (char*)*--t); }
void term(obart) {
  char *ms = (void *)*--t;
  LOG, t[-1](V(V(T(cr), T(cr), T(cr), T(cr)),
               V(T(term0), T(term1), T(term2), T(ms, term3)), o),
             b, a, r, t - 1, data);
}
// "b" term "a" term parse
void S(obart);
void S0(obart) { LOG; }
void S1(obart) { LOG; }
void S2(obart) { LOG; }
void ob(obart) { LOG, o[0][3][-1](o[2], b?b:o, 0, 3, o[0][3] - 1, data); }
void S3(obart) {
  LOG;
// 0 1 parse       (null)
// 0 1 S   (null)
// 0 1 ob  (null)
// 0 3 parse3      (null)
// 1 3 S3  (null)
  void (**t0)() = T(ob, "b", term);
  t0[-1](o, 0, a, r, t0 - 1, data);
  void (**t1)() = T(ob, S, "a", term);
  t1[-1](o, 0, a, r, t1 - 1, data);
}
void S(obart) {
  LOG, t[-1](V(V(T(cr), T(cr), T(cr), T(cr)),
               V(T(S0), T(S1), T(S2), T(S3)), o), b, a, r, t - 1, data);
}
void parse0(obart) { LOG; }
void parse1(obart) { LOG;
  long*pos= (long*)*--t;
  char*in = (void*)*--t;
  if(data[0] == in[*pos])
    *pos = *pos + 1, b[1][1][-1](b[2], b, 1, 1, b[1][1] - 1, data);
  else
    b[1][0][-1](b[2], b, 1, 0, b[1][0] - 1, data);

}
void parse2(obart) { LOG; }
void parse3(obart) { LOG, b[1][3][-1](b[2], b, 1, 3, b[1][3] - 1, data); }
void parse(obart) {
  char*in=(void*)*--t;
  long pos = 0;
  LOG, t[-1](V(V(T(parse0), T(in, &pos, parse1), T(parse2), T(parse3)),
               V(T(cr), T(cr), T(cr), T(cr)), o),
             b, a, r, t - 1, data);
}
// დაიწყე ერთით და ყოველ ერთ წუთში დაუმატე ერთი და დაბეჭდე.
void one(obart) {
  t[-1](V(V(T(0),T(0),T(0)),
          V(T(0),T(0),T(0)),
          V(T(0),T(0),T(0)),
          V(T(0),T(0),T(0)), o), b, a, r, t-1);
}
void add(obart) {
  t[-1](V(V(T(0),T(0),T(0),T(0)),
          V(T(cr),T(cr),T(cr),T(cr)), o), b, a, r, t-1);
}

int main() {
  void (**t)() = T(ob, S, "baaa", parse);
  t[-1](V(V(T(000, end), T(001, end), T(002, end), T(003, end)),
          V(T(010, end), T(011, end), T(012, end), T(013, end)), 9),
        0, 0, 1, t - 1, 0);
}
