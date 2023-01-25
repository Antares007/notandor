#define D struct s_t *t, struct s_t *a, struct s_t *r, struct s_t *o, long s
#define T t, a, r, o, s
typedef struct s_t {
  union {
    long q;
    struct s_t *s;
    void (*c)(D);
  };
} s_t;
#define B(...)                                                                 \
  (s_t *)(void *[]) { __VA_ARGS__ }
void ct2(D) { t[2].c(t[4].s, a, r, o, s); }
void one(D) { t[1].c(t[4].s, a, r, o, 1); }
// void two(D) { one(B(ct0, one, ct1, ct3, t), a, r, o, s); }
void add(D) {}
void and (struct s_t * t, struct s_t *a, struct s_t *r, struct s_t *o, long s) {
  //
}
void seven(D) { t[1].c(t[4].s, a, r, o, s); }
#define LOGN printf("%s\n", __FUNCTION__);
#include <stdio.h>
// clang-format off
void t0(D) { LOGN; } void t1(D) { LOGN; } void t2(D) { LOGN; }
void a0(D) { LOGN; } void a1(D) { LOGN; } void a2(D) { LOGN; }
void r0(D) { LOGN; } void r1(D) { LOGN; } void r2(D) { LOGN; }
void o0(D) { LOGN; } void o1(D) { LOGN; } void o2(D) { LOGN; }
// when to brunch?
// clang-format on
int main() {
  (void)
  B(t0, one, t2,
    B(t0, one, t2,
      B(t0, one, t2,
        B(t0, add, t2, 0))));
  
  seven(B(t0, t1, t2, 0), B(a0, a1, a2, 0), B(r0, r1, r2, 0), B(o0, o1, o2, 0),
        0);
  return 0;
}
void nar() {
}
// mamam shvils sakhli aushena.
//  rotation/loop
//  branching
//  stacking
//  memory managment
//  streaming 
/*
distributed parts of definitions:
  * big idea is that we need to have one huge tree (like blockchains) and his roots will
    be in all kind of devices as operating systems.
  * tree grows in any directions.
      b     t    b
       \    |   /
         b  t  b
          \ | /
    b - b - p - t - t
          / | \
         t  b  t
we need to dream in colors. execution 4waves           
how to thread execution in tree brances?
what is a lifetime of a tree branch?
rotation? what we are rotating?
            +-----TTT-----+
            | +---TTT---+ |
            | |         | |
            | | +-TTT-+ | |
            T T T     T T T
            T T T  +  T T T
            T T T     T T T
            | | +-TTT-+ | |
            | |         | |
            | +---TTT---+ |
            +-----TTT-----+

void bark(*text, advance, ray_number, **pith, side) {
  text[advance-1].c(text,
                    advance-1,
                    ray_number, 
                    B(T(red0, red1, red2, pith[0].o),
                      T(grn0, grn1, grn2, pith[1].o),
                      T(blu0, blu1, blu2, pith[2].o),
                      T(whi0, whi1, whi2, pith[3].o)),
                    side);
}

bark (*text, advance, ray_number, *pith, state)
  bark is the tuple of variables represented as parameters of
  the C function.
rings
  rings are arrays allocated on stack during growing process.
  thay are holding rays and pointer to previous ring or pith
rays
  rays are arrays allocated on stack which are holding
  addresses of words and values accordins syntax of langauage.
pith
  pith is pointer to previous ring

What the code was doing
What he was thinking about
What else he had tried that didn't work
How you should feel about the code

I don't have a real example anymore but here is how I remember it:

Now we take the length of array and add it to our counter.
This is our offset, how we use it will be a surprise for later.
I was thinking about calling the variable myOffet but I didn't
want to seem so possessive about it. Actually we should probably
break out this block into its own function for debugging but
I'm still a little tired from lunch to do that right now.
*/
