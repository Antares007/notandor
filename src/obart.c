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
  printf("%ld %ld %.2ld %.2ld %s\t\t%s\n", a, r, odepth((void*)o), odepth((void*)b), __FUNCTION__, (char*)data), usleep(100000)
long odepth(void**o) {
  long d=0;
  while(o && o[2]) o = o[2], d++;
  return d;
}
void end(obart) { printf("%.3lo %p %ld %s\n", (long)t[-1], o, (long)data, (char*)data); }
void cr(obart) { o[a][r][-1](o[2], b, a, r, o[a][r] - 1, data); }

void ps(obart) { puts((char *)*--t), t[-1](o, b, a, r, t - 1, data); }
#define D(o, t) ((void (**)())t)[-1](o, b, a, r, ((void **)t) - 1, data);
#define C(o, a, r, d) assert(!t[-1]), o[a][r][-1](o[2], o, a, r, o[a][r] - 1, (void *)d)
void ob(obart) { LOG, C(o, 1, 0, data); }

void term00(obart) { LOG; 
  char *ms = (char *)*--t;
  if (data[0] == ms[0])
    C(o, 1, 1, data + 1),
    C(o, 1, 3, data + 1);
  else
    C(o, 1, 2, data);
}
void term(obart) {
  char *ms = (void *)*--t;
  LOG, t[-1](B(B(T(ms, term00), T(cr), T(cr), T(cr)),
               B(T(cr),  T(cr), T(cr), T(cr)), o), b, a, r, t - 1, data);
}

// "b" term "a" term parse
void S(obart);
void S00(obart) { LOG;
  D(o, T(ob, "b", term));

  D(o, T(ob, S, "a", term));
}
void S(obart) {
  LOG, D(B(B(T(S00), T(cr), T(cr), T(cr)),
           B(T(cr), T(cr), T(cr), T(cr)), o), t);
}

void parse10(obart) { LOG; C(b, 0, 0, data); }
void parse11(obart) { LOG; }
void parse12(obart) { LOG; }
void parse13(obart) { LOG; C(b, 0, 0, data); }
void parse(obart) {
  char *in = (void *)*--t;
  LOG, t[-1](B(B(T(cr), T(cr), T(cr), T(cr)),
               B(T(parse10), T(parse11), T(parse12), T(parse13)), o),
             b, a, r, t - 1, in);
}
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
  void (**t)() = T(ob, S, "baaa", parse);
  // void (**t)() = T(ob, seven, one, seven, add);
  t[-1](B(B(T(000, end), T(001, end), T(002, end), T(003, end)),
          B(T(010, end), T(011, end), T(012, end), T(013, end)), 0),
        0, 0, 1, t - 1, 0);
}
