#define Nargs(...) (sizeof((const void *[]){__VA_ARGS__}) / sizeof(void *))
#define V(...) ((const void *[]){__VA_ARGS__})
#define T(...)                                                                 \
  ((void *)&V(cr, __VA_ARGS__, Nargs(__VA_ARGS__) + 1)[Nargs(__VA_ARGS__) + 1])
#define B(o, ...) ((void *)&V(o, Nargs(__VA_ARGS__), __VA_ARGS__)[2])
#define Ν(...)                                                                 \
  { __VA_ARGS__; }                                                             \
  }
#define N(argo)                                                                \
  void argo(OARS) {                                                            \
    Ν
#define OARS void (***o)(), void (**a)(), long r, void **s, void **op, void **os
#define C(o, Ray, s, op, os)                                                   \
  (LOG,                                                                        \
   ((void (***)())o)[Ray][-1](((void (***)())o)[-2],                           \
                              &((void (***)())o)[Ray][-1], Ray, s, op, os))
#define D(o, s, op, os) (LOG, a[-1](o, &a[-1], r, s, op, os))
#define Short(v) (long)(v) & (long)0xffff
#define LOG printf("%ld %s\n", r, __FUNCTION__), usleep(100000) // (void)0 //
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// clang-format off
N(cr      )(C(o, r, s, op, os))
N(cn      )(r = *--a, C(o, r, s, op, os))
N(err     )(LOG)


struct term_st { void*inner_s; const char*match; long len, pos; void*s,*parser; };
N(term_s0     )(LOG)
N(term_s1     )(struct term_st*st = (void*)o;
                const char    *in = os[0];
                long          len = os[1];
                long i = 0;
                while(i < len)
                  if(in[i] != st->match[st->pos + i])
                    return D(s, st->s, op,os);
                )
N(term_s2     )(LOG)
N(term0       )(struct term_st*st = (void*)o;
                st->parser = s,
                D(s, st->s, op, B(os, st->len)))
N(term        )(long len = (void*)*--a;
                const char*match = (void*)*--a;
                struct term_st on = {
                         .inner_s = s,
                         .match   = match, .len = len, .pos = 0,
                         .s = B(&on,
                                T(term_s0),
                                T(term_s1),
                                T(term_s2)) };
                D(o, B(&on,
                       T(term0)), op, os))


void Saaa0();
N(Saaa0       )(D(s, B(o, 0), op, os))
N(Saaa        )(D(o, B(0, T(Saaa0)), op, os))

struct parser_st { void*inner_o,*s; const char*in; long len; };
N(parser_s0   )(LOG)
N(parser_s1   )(LOG)
N(parser_s2   )(LOG)
N(parser0     )(struct parser_st*st = (void*)o;
                D(s, st->s, op, os))
N(parser      )(struct parser_st on = { .inner_o = o, .s = B(&on,
                                                             T(parser_s0),
                                                             T(parser_s1),
                                                             T(parser_s2)) };
                D(B(&on,
                    T(parser0)), s, op, os))
struct main_t {void *o,*s;};
N(main_ps0    )(LOG)
N(main_ps1    )(const void**on = (void*)o;
                D(s, on[0], op, os))
N(main_ps2    )(LOG)
N(main_p0     )(const void**on = (void*)o;
                on[1] = s;
                D(s, on[0], op, os))
N(main_c0     )(const void**on = (void*)o;
                on[1] = s;
                D(s, on[0], op, os))
N(main_cs0    )(LOG)
N(main_cs1    )(const void**on = (void*)o;
                D(s, on[0], op, os))
N(main_cs2    )(LOG)

N(map_ps0     )(LOG)
N(map_ps1     )(const void **on = (void*)o;
                D(on[0],on[2],op,os))
N(map_ps2     )(LOG)
N(map_cs0     )(const void **on = (void*)o;
                D(on[3],on[1],op,os))
N(map_cs1     )(LOG)
N(map_cs2     )(LOG)
N(map_p0      )(const void **on = (void*)o;
                on[3] = s;
                D(on[0], on[2], op, os))
N(map         )(const void *on[] = {
                o, B(on,
                     T(map_ps0), T(map_ps1), T(map_ps2)), 
                   B(on,
                     T(map_cs0), T(map_cs1), T(map_cs2)), 0};
                D(B(on,
                    T(map_p0)), s, op, os))
int main(     ) {
  const void*on[] = {
                    B(on,
                      T(main_ps0), T(main_ps1), T(main_ps2)), 0 };
  void(***o)()    = B(on,
                      T(main_p0));
  void (**a)()    = T(cr);
  long    r       = 0;
  const void*sn[] = {
                    B(sn,
                      T(main_cs0), T(main_cs1), T(main_cs2)), 0 };
  void **s        = B(sn,
                      T(1, cn, main_c0));
  D(o, s, 0, 0);
}
