#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define D(o, t)                                                                \
  LOG(r, data), (((void (**)())t)[-1](o, b, r, ((void **)t) - 1, data))
#define B(...) ((void *)(void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&((const void *[]){0, __VA_ARGS__,                                  \
                              Nargs(__VA_ARGS__)})[Nargs(0, __VA_ARGS__)])
#define C(o, r, data)                                                          \
  assert(!t[-1]), LOG(r, data), o[r][-1](o[8], o, r, o[r] - 1, (void *)data)
#define obrt void (***o)(), void (***b)(), long r, void (**t)(), char *data
#define LOG(r, data)                                                           \
  printf("%ld %s\t%s\n", (long)r, __FUNCTION__, (char *)data), usleep(100000)

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

void end(obrt) { printf("%.3lo %p %ld\n", (long)t[-1], o, (long)data); }
void cr(obrt) { o[r][-1](o[8], b, r, o[r] - 1, data); }

void ps(obrt) { puts((char *)*--t), t[-1](o, b, r, t - 1, data); }
void ob(obrt) { C(o, 4, data); }
void term00(obrt) {
  char *ms = (char *)*--t;
  puts(ms);
  if (data[0] == ms[0])
    C(o, 5, data + 1), C(o, 7, data + 1);
  else
    C(o, 6, data);
}
void term(obrt) {
  char *ms = (void *)*--t;
  D(B(T(ms, term00), T(cr, "term01", ps), T(cr, "term02", ps),
      T(cr, "term03", ps), //
      T(cr, "term10", ps), T(cr, "term11", ps), T(cr, "term12", ps),
      T(cr, "term13", ps), o),
    t);
}
// "b" term "a" term parse
void S(obrt);
void S00(obrt) {
  D(o, T(ob, "b", term));
  D(o, T(ob, S, "a", term));
}
void S(obrt) {
  D(B(T(S00), T(cr, "S01", ps), T(cr, "S02", ps), T(cr, "S03", ps), //
      T(cr, "S10", ps), T(cr, "S11", ps), T(cr, "S12", ps), T(cr, "S13", ps),
      o),
    t);
}
void parse10(obrt) { C(b, 0, data); }
void parse11(obrt) {}
void parse12(obrt) {}
void parse13(obrt) { C(b, 0, data); }
void parse(obrt) {
  data = (void *)*--t;
  D(B(T(cr), T(cr), T(cr), T(cr), //
      T(parse10), T(parse11), T(parse12), T(parse13), o),
    t);
}
void one00(obrt) { C(o, 5, 1), C(o, 7, 0); }
void one(obrt) {
  D(B(T(one00), T(cr), T(cr), T(cr), //
      T(cr), T(cr), T(cr), T(cr), o),
    t);
}
void add00(obrt) {
  long *sum = (long *)*--t;
  C(o, 5, *sum), C(o, 7, 0);
}
void add11(obrt) {
  long *sum = (long *)*--t;
  *sum = *sum + (long)data;
}
void add10(obrt) { C(b, 0, 0); }
void add13(obrt) { C(b, 0, 0); }
void add(obrt) {
  long sum = 0;
  D(B(T(&sum, add00), T(cr), T(cr), T(cr), //
      T(add10), T(&sum, add11), T(cr), T(add13), o),
    t);
}
void seven(obrt) {
  D(B(T(ob, one, one, one, one, one, one, one, add), T(cr), T(cr), T(cr), //
      T(cr), T(cr), T(cr), T(cr), o),
    t);
}
int main() {
  void (**t)() = T(ob, S, "baaa", parse);
  long b = 0, r = 0, data = 0;
  // void (**t)() = T(ob, seven, one, seven, add);
  D(B(T(000, end), T(001, end), T(002, end), T(003, end), //
      T(010, end), T(011, end), T(012, end), T(013, end), 0),
    t);
}
