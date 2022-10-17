#include "τ.h"
#include "τ_logn.h"
#include <stdio.h>
#include <uv.h>
void ano(TINAS);
void noa(TINAS);
void oan(TINAS);
void ψ(TINAS);
N(p1) { A(ano, 020, ψ); }
N(p2) { A(ano, 030, ψ); }
N(p3) { A(ano, 040, ψ); }
N(p4) { A(ano, 050, ψ); }
N(oneβ) { A(1, ano); }
void one(TINAS) { A(oneβ, 010, ψ); }
N(addβ) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano);
}
N(add) { A(addβ, 010, ψ); }

N(o_ray) { }
N(a_ray) { printf("done: %lu\n", τ[--ι].Q); }
N(n_ray) { }

N(pano) { printf("1\n"), ano(Τ); }
N(poan) { printf("0\n"), oan(Τ); }
N(pnoa) { printf("2\n"), noa(Τ); }
void and(TINAS) {
  // t_t nο[0x1000];
  // code, code, code, code, ..., code.
  
}
void ATree(TINAS) {
  A(
                   ano,
    one, one, add, and,
    one, one, add
  );
}
N(termβ ) {
  R(const char*,  match);
  R(Q_t,  pos);
  printf("%c\n", match[0]);
  if (pos < τ[1].Q && τ[0].cs[pos] == match[0]) A(pos+1, ano);
  else A(oan); }
N(V     ) { ano(Τ); }
void T(TINAS) { A(termβ, 020, ψ); }
N(Oβ    ) { A(ano); }
N(O     ) { A(τ[2].Q, Oβ,
              τ[2].Q, Oβ, 022, ψ); }
N(oT    ) { A("o", T); }
N(aT    ) { A("a", T); }
N(nT    ) { A("n", T); }
N(bT    ) { A("b", T); }
N(S     ) { A(V, bT, O, S, aT); }
N(OAN   ) { A(V, "o", T, "a", T, "n", T,
              O, "a", T, "n", T, "o", T,
              O, "n", T, "o", T, "a", T); }
N(prnβ  ) { while(ι) printf("> %lu\n", τ[--ι].Q); }
N(prn   ) { A(prnβ, prnβ, prnβ, 0111, ψ); }
N(SP    ) {

  A("ano",   3, 0, OAN, prn);
}
N(SP_   ) { A("baaaa", 5, 0, S,   prn); }
N(ST) { A(ano, one, 2, p1, add, one, add, one, add); }
int main() {
  t_t b1[Σ], b2[Σ], *τ = b1, *ν = &b2[Σ];
  Q_t α = Σ;
  Q_t σ = Σ;
  Q_t ι = 0;
  τ[--α].c = o_ray;
  τ[--α].c = a_ray;
  τ[--α].c = n_ray;
  τ[--α].Q = 0111;
  A(SP);
  return 5;
}
