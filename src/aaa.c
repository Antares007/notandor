#undef N
#define N(argos)                                                               \
  void argos(struct word_t *t, long a, long r, struct pith_t *o,               \
             struct pith_t *s)
struct pith_t;
typedef struct word_t {
  union {
    signed long q;
    void *v;
    N((*c));
  };
} word_t;
typedef struct pith_t {
  struct word_t *rays[4];
  struct pith_t *o;
} pith_t;
N(bo) {
  t = o->rays[r];
  a = t[0].q;
  t[a - 1].c(t, a - 1, r, o->o,
             &(pith_t){.rays =
                           {
                               (word_t[]){},
                               (word_t[]){},
                               (word_t[]){},
                               (word_t[]){},
                           },
                       .o = s});
}
N(propeller) {
  for (r = 0; r < 4; r++)
    t[a - 1].c(t, a - 1, r, o,
               &(pith_t){.rays =
                             {
                                 (word_t[]){},
                                 (word_t[]){},
                                 (word_t[]){},
                                 (word_t[]){},
                             },
                         .o = s});
}
// S -> b term 
N(S) {
  t[a - 1].c(t, a - 1, r,
             &(pith_t){{
                           (word_t[]){{.q=0}},
                           (word_t[]){{.q=0}},
                           (word_t[]){{.q=0}},
                           (word_t[]){{.q=0}},
                       },
                       o},
             s);
}
#include <stdio.h>
N(oend) { printf("%s\n", __FUNCTION__); }
N(send) { printf("%s\n", __FUNCTION__); }
int main() {
  pith_t o = {.rays = {(word_t[]){{.q = 3}, {.c = bo}, {.c = oend}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = oend}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = oend}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = oend}}},
              .o = 0};
  pith_t s = {.rays = {(word_t[]){{.q = 3}, {.c = bo}, {.c = send}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = send}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = send}},
                       (word_t[]){{.q = 3}, {.c = bo}, {.c = send}}},
              .o = 0};
  word_t t[] = {{.q = 2}, {.c = bo}};
  long a = sizeof(t) / sizeof(*t);
  long r = 0;
  t[a - 1].c(t, a - 1, r, &o, &s);
}
/*
lets start defining protocall.
* can perform previously impossible tasks
we have awesome protocall how to define executable sentences and the words.
now we shall implement its distributed version and we will:
* achieve unprecedented levels of performance
* implementing, and improving a massive-scale distributed,
  machine learning, system,
* writing bug-free machine learning code,
* building the science behind the algorithms employed
*/
