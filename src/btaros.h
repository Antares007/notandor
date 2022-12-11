#pragma once
#define NofArgs(...)                                                           \
  (sizeof((const void *[]){__VA_ARGS__}) / sizeof(const void *))
#define LOG (void)0
#define D(o) LOG, t[a - 1].c(b, t, a - 1, r, o, s)
#define B(r0, r1, r2, r3, oa, ob, oc, od)                                      \
  T(r0, r1, r2, r3, (void *)oa, (void *)ob, (void *)oc, (void *)od)
#define T(...)                                                                 \
  ((taros *)&(void *[]){(void *)NofArgs(__VA_ARGS__), __VA_ARGS__}[1])
#define N(argos)                                                               \
  void argos(struct taros *b, struct taros *t, long a, long r, struct taros *o, long s)
typedef struct taros {
  union {
    struct taros *o;
    signed long q;
    void *v;
    const char *cs;
    N((*c));
  };
} taros;
