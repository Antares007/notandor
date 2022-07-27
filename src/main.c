#include "oars.h"
#include <uv.h>
#include <stdio.h>

N(and); N(and2); N(and3); N(god);

N(one)    { A(1, god) O; }
N(add)    { R(Q_t, r); R(Q_t, l); A(l + r, god) O; }
N(addww)  { A(add, and, and3) O; }
N(addws)  { A(add, and2) O; }
N(addsw)  { A(add, and) O; }

N(n_ray)  { printf("NOT\n"); }
N(a_ray)  { printf("AND %lu\n", σ[--α].Q); }
N(o_ray)  { printf("OOR\n"); }

#define S(...) __VA_ARGS__
N(test)   { A(one, S(1, 2, 3), addws) O; }

int main() {
  p_t ο[512];
  Q_t ρ = sizeof(ο) / sizeof(*ο);
  p_t σ[512];
  Q_t α = 0;
  ο[--ρ].c = n_ray;
  ο[--ρ].c = a_ray;
  ο[--ρ].c = o_ray;
  ο[--ρ].Q = 0111;
  A(2, 7, add, one, addww, 3, addws, one, addww) O;
  return 5;
}
