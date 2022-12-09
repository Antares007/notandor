#pragma once
#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define ToString(a) #a,
#define T(...)                                                                 \
  ((s_t *)&(const void *[]){(void *)Nargs(__VA_ARGS__), __VA_ARGS__}[1])
#define B(...) ((s_t *)(const void *[]){__VA_ARGS__})
#define D(o) t[a - 1].c(o, b, r, a - 1, n, t, s)
#define obrants                                                                \
  struct s_t *o, struct s_t *b, struct s_t *r, long a, long n, struct s_t *t,  \
      struct s_t *s
typedef struct s_t {
  union {
    struct s_t *o;
    signed long q;
    void *v;
    const char *cs;
    void (*c)(obrants);
  };
} s_t;
typedef void (*w_t)(obrants);
#define N(argo) void argo(obrants)
