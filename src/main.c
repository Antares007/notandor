#include "ψ.h"
#include <stdio.h>
#include <uv.h>

N(and);
N(and2);
N(and3);
N(ano);
N(noa);
N(oan);
N(ψ);

N(one) { A(1, ano) O; }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano) O;
}
N(addww) { A(add, and, and3) O; }
N(addws) { A(add, and2) O; }
N(addsw) { A(add, and) O; }

N(o_ray) { printf("OOR\n"); }
N(a_ray) { printf("AND %lu\n", ο[--ν].Q); }
N(n_ray) { printf("NOT\n"); }

#define S(...) __VA_ARGS__
N(test) { A(one, S(1, 2, 3), addws) O; }
N(pano) { printf("1\n"); ano(X); }
N(poan) { printf("0\n"); oan(X); }
N(pnoa) { printf("2\n"); noa(X); }
N(ATree) {
  A(
    ano,
      poan, ano, 0001, ψ,
    040, ψ,
      pano, ano, 0010, ψ,
    040, ψ,
      pnoa, ano, 0100, ψ,
    040, ψ
    ) O;
}

int main() {
  p_t ο[512];
  Q_t α = sizeof(ο) / sizeof(*ο);
  Q_t ν = 0;
  ο[--α].c = n_ray;
  ο[--α].c = a_ray;
  ο[--α].c = o_ray;
  ο[--α].Q = 0111;
  ATree(X);
  //  A(2, 7, add, one, addww, 3, addws, one, addww) O;
  return 5;
}
