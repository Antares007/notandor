#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define T(...)                                                                 \
  ((o_t *)&(const void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define B(r0, r1, r2, r3, oa, ob, oc, od)                                      \
  ((o_t *)(const void *[]){r0, r1, r2, r3, oa, ob, oc, od})
#define D(o) t[a - 1].c(o, t, a - 1, r, s);
typedef struct o_t {
  union {
    struct o_t *o;
    signed long q;
    void *v;
    const char *cs;
    void (*c)(struct o_t *o, struct o_t *t, long a, long r, long s);
  };
} o_t;
void cr(o_t *o, o_t *t, long a, long r, long s) {
  t = o[r].o;
  a = t[-1].q;
  D(o[s + 4].o); // === t[a - 1].c(o[s + 4].o, t, a - 1, r, s);
}
void term(o_t *o, o_t *t, long a, long r, long s) {
  D(B(T(), T(), T(), T(),
      B(T(), T(), T(), T(), o, o, o, o),
      B(T(), T(), T(), T(), o, o, o, o),
      B(T(), T(), T(), T(), o, o, o, o),
      B(T(), T(), T(), T(), o, o, o, o)));
}
void show() {}
