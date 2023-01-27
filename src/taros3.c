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
  (void)B(t0, one, t2, B(t0, one, t2, B(t0, one, t2, B(t0, add, t2, 0))));

  seven(B(t0, t1, t2, 0), B(a0, a1, a2, 0), B(r0, r1, r2, 0), B(o0, o1, o2, 0),
        0);
  return 0;
}
void nar() {}
/*
1. Develop a new compositional unit, specifically the word, as the fundamental building block for new interfaces.

distributed parts of definitions:
  * big idea is that we need to have one huge tree (like blockchains) and his
roots will be in all kind of devices as operating systems.
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
            +-----TTT-----+ <- prefix
            | +---TTT---+ <--- root
            | |         | |
            | | +-TTT-+ <----- sifix
            T T T     T T T
            T T T  +  T T T
            T T T     T T T
            | | +-TTT-+ | |
            | |         | |
            | +---TTT---+ |
            +-----TTT-----+
Morphemes, The smallest unit of meaning in a word, which can be a root word or a
prefix/suffix.
Root word, the base or core part of a word that carries the main
meaning.
Prefixes and suffixes that are added to the root word to change its
meaning or grammatical function.

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

Now we take the length of array and add it to our counter.
This is our offset, how we use it will be a surprise for later.
I was thinking about calling the variable myOffet but I didn't
want to seem so possessive about it.We can create a new compositional unit called "aradani" in a similar way to how
the C function is defined, which is a definition of mathematical function in
computing. We will use the C function protocol and define "aradani" on top of
it.

Specifically, we can begin by defining a tuple of variables. We will capture
these variables as C function parameters, with the body of the function being an
obvious variable. Additionally, we will establish a set of rules for how to work
with these variables. Now, we need to determine what type of data to capture in
our variables. The first and obvious one is a set of instructions or simply
machine text. The rest can be scalar variables such as pointers, integers or
floats. For other structures, we need memory to store them. We will use memory
from the stack, which is part of the C function protocol.


Is it a good idea to change the name of the word to a completely new word
"nargo"? This will help us to avoid confusion when referring to "nargos" as
mnemonics. Think of it as executable narratives, thus "NarGo"?


An IP packet consists of a header and a payload. The header contains information
about the packet, such as the source and destination IP addresses, the packet's
length, and the protocol used for the payload. The payload is the data being
transmitted, such as TCP or UDP data. The header is typically 20-60 bytes in
length, while the payload can be any length, up to a maximum of 65,535 bytes.
The header contains several fields that are used for routing and error checking,
such as the version, header length, time to live, protocol and header checksum.


  IPa                                                                    IPb
  can we have conversation? >
  < shure. u can send me 3 packets in a row.

I don't have a real example anymore but here is how I remember it:

Actually we should probably break out this block into its own function for debugging but
I'm still a little tired from lunch to do that right now.
*/
