#include "ψ.h"
#include <stdio.h>
#include <uv.h>

N(ano);
N(noa);
N(oan);
N(ψ);

N(one) { A(1) ano(C); }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r) ano(C);
}
N(addww) { A(add, 010, ψ, 030) ψ(C); }
N(addws) { A(add, 020) ψ(C); }
N(addsw) { A(add, 010) ψ(C); }

N(o_ray) { printf("OOR\n"); }
N(a_ray) { printf("AND %lu\n", ο[--ν].Q); }
N(n_ray) { printf("NOT\n"); }

#define S(...) __VA_ARGS__
N(test) { A(one, S(1, 2, 3)) addws(C); }
N(pano) { printf("1\n"); ano(C); }
N(poan) { printf("0\n"); oan(C); }
N(pnoa) { printf("2\n"); noa(C); }
N(and) { 
}
N(ATree) {
  A(
    ano,
      poan, ano, 0001, ψ,
    040, ψ,
      pano, ano, 0010, ψ,
    040, ψ,
      pnoa, ano, 0100, ψ,
    040
    ) ψ(C);
}

int main() {
  p_t ο[512];
  Q_t α = sizeof(ο) / sizeof(*ο);
  Q_t ν = 0;
  ο[--α].c = n_ray;
  ο[--α].c = a_ray;
  ο[--α].c = o_ray;
  ο[--α].Q = 0111;
  ATree(C);
  //  A(2, 7, add, one, addww, 3, addws, one) addww(C);
  return 5;
}
