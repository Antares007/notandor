#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(__VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define obart                                                                  \
  void (****o)(), void (****b)(), long a, long r, void (**t)(), char *data
#define B(...) ((void *)(void *[]){__VA_ARGS__})
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define LOG                                                                    \
  printf("%ld %ld %s\t%ld\n", a, r, __FUNCTION__, (long)data), usleep(100000)

void end(obart) { printf("%.3lo %p %ld\n", (long)t[-1], o, (long)data); }
void cr(obart) { o[a][r][-1](o[2], b, a, r, o[a][r] - 1, data); }

void ps(obart) { puts((char *)*--t), t[-1](o, b, a, r, t - 1, data); }

void term0(obart) { LOG; }
void term1(obart) {
  LOG;
  o[0][3][-1](o[2], o, 0, 3, o[0][1] - 1, data);
}
void term2(obart) { LOG; }
void term3(obart) {
  LOG, b[0][1][-1](b[2], b, 0, 1, b[0][1] - 1, (char *)*--t);
}
void term(obart) {
  char *ms = (void *)*--t;
  LOG, t[-1](B(B(T(cr), T(cr), T(cr), T(cr)),
               B(T(term0), T(term1), T(term2), T(ms, term3)), o),
             b, a, r, t - 1, data);
}

#define D(o, t) ((void (**)())t)[-1](o, b, a, r, ((void **)t) - 1);
#define C(o, a, r, d) o[a][r][-1](o[2], o, a, r, o[a][r] - 1, (void *)d)
void ob(obart) { LOG, C(o, 1, 0, data); }

// "b" term "a" term parse
void S(obart);
void S0(obart) { LOG; }
void S1(obart) { LOG; }
void S2(obart) { LOG; }

void S3(obart) {
  LOG;
  void (**t0)() = T(ob, "b", term);
  t0[-1](o, 0, a, r, t0 - 1, data);
  // void (**t1)() = T(ob, S, "a", term);
  // t1[-1](o, 0, a, r, t1 - 1, data);
}
void S(obart) {
  LOG, t[-1](B(B(T(cr), T(cr), T(cr), T(cr)), B(T(S0), T(S1), T(S2), T(S3)), o),
             b, a, r, t - 1, data);
}
void parse0(obart) { LOG; }
void parse1(obart) {
  LOG;
  long *pos = (long *)*--t;
  char *in = (void *)*--t;
  if (data[0] == in[*pos])
    *pos = *pos + 1, b[1][1][-1](b[2], b, 1, 1, b[1][1] - 1, data);
  else
    b[1][0][-1](b[2], b, 1, 0, b[1][0] - 1, data);
}
void parse2(obart) { LOG; }
void parse3(obart) { LOG, b[1][3][-1](b[2], b, 1, 3, b[1][3] - 1, data); }
void parse(obart) {
  char *in = (void *)*--t;
  long pos = 0;
  LOG, t[-1](B(B(T(parse0), T(in, &pos, parse1), T(parse2), T(parse3)),
               B(T(cr), T(cr), T(cr), T(cr)), o),
             b, a, r, t - 1, data);
}
// დაიწყე ერთით და ყოველ ერთ წუთში დაუმატე ერთი და დაბეჭდე.
// მამამ შვილს სახლი აუშენა.
// აუშენა მამამ შვილს სახლი.
// აუშენა სახლი შვილს მამამ.
void one00(obart) { LOG, C(o, 1, 1, 1), C(o, 1, 3, 0); }
void one(obart) {
  LOG, D(B(B(T(one00),  T(cr), T(cr), T(cr)),
           B(T(cr),     T(cr), T(cr), T(cr)), o), t);
}
void add00(obart) {
  LOG;
  long *sum = (long *)*--t;
  C(o, 1, 1, *sum), C(o, 1, 3, 0);
}
void add11(obart) {
  LOG;
  long *sum = (long *)*--t;
  *sum = *sum + (long)data;
}
void add10(obart) { LOG, C(b, 0, 0, 0); }
void add13(obart) { LOG, C(b, 0, 0, 0); }
void add(obart) {
  LOG;
  long sum = 0;
  D(B(B(T(&sum, add00), T(cr),          T(cr), T(cr)),
      B(T(add10),       T(&sum, add11), T(cr), T(add13)), o),
    t);
}
void seven(obart) {
  D(B(B(T(ob, one, one, one, one, one, one, one, add),  T(cr), T(cr), T(cr)),
      B(T(cr),                                          T(cr), T(cr), T(cr)), o),
    t);
}

int main() {
  //  void (**t)() = T(ob, S, "baaa", parse);
  void (**t)() = T(ob, seven, one, seven, add);
  t[-1](B(B(T(000, end), T(001, end), T(002, end), T(003, end)),
          B(T(010, end), T(011, end), T(012, end), T(013, end)), 9),
        0, 0, 1, t - 1, 0);
}
