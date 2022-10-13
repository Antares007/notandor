#include "ψ.h"
#include "ψ_logn.h"
#include <stdio.h>
#include <uv.h>
void ano(OANT);
void noa(OANT);
void oan(OANT);
void ψ(OANT);
N(p1) { A(ano, 020, ψ); }
N(p2) { A(ano, 030, ψ); }
N(p3) { A(ano, 040, ψ); }
N(p4) { A(ano, 050, ψ); }
N(oneβ) { A(1, ano); }
N(one) { A(oneβ, 010, ψ); }
N(addβ) {
  R(Q_t, r);
  R(Q_t, l);
  A(l + r, ano);
}
N(add) { A(addβ, 010, ψ); }

N(o_ray) { }
N(a_ray) { printf("done: %lu\n", ν[--τ].Q); }
N(n_ray) { }

N(pano) { printf("1\n"), ano(T); }
N(poan) { printf("0\n"), oan(T); }
N(pnoa) { printf("2\n"), noa(T); }
void and(OANT) {
  // p_t nο[0x1000];
  // code, code, code, code, ..., code.
  
}
void ATree(OANT) {
  A(
                   ano,
    one, one, add, and,
    one, one, add
  );
}
N(cont_sigma) { ν[τ-1].c(ο, α, ν, τ-1); }
N(ex_pith_o ) { ο[α+0].v = oan; ο[α+1].Q = τ; }
N(ex_pith_a ) { ο[α+0].v = ano; ο[α+1].Q = τ; }
N(ex_pith_n ) { ο[α+0].v = noa; ο[α+1].Q = τ; }
N(ex_pith   ) { 
  p_t nο[512]; Q_t nα = 512;
  nα -= 2;
  nο[--nα].v = ex_pith_o;
  nο[--nα].v = ex_pith_a;
  nο[--nα].v = ex_pith_n;
  nο[--nα].Q = 0111;
  cont_sigma(nο, nα, ν, τ);
  nο[510].c(ο, α, ν, nο[511].Q);
}
N(termβ) {
  R(const char*,  match);
  if (ν[2].Q < ν[1].Q && ν[0].cs[ν[2].Q] == match[0])
    ν[2].Q++, A(ano);
  else
    A(oan);
}
N(term    ) { A(termβ, 020, ψ); }
N(orelse  ) {
  p_t nο[512]; Q_t nα = 512;
  nα -= 2;
  nο[--nα].c = ex_pith_o;
  nο[--nα].c = ex_pith_a;
  nο[--nα].c = ex_pith_n;
  nο[--nα].Q = 0111;

  p_t nν[512];
  nν[0].v = ν[0].v;
  nν[1].v = ν[1].v;
  nν[2].v = ν[2].v;

  ν[τ-1].c(nο, nα, ν, τ-1);
  τ = nο[510].Q;

  if(nο[511].Q) {
    
  } else {
    ano(ο, α, ν, τ);
  }
  //ο = nο;
  //p_t *rο = ο;
  //(void)rο;
}
N(S) {
  A(
            "b", term,
    orelse, "a", term,
    orelse, "c", term
    );
}
N(printrezβ   ) { printf("%lu", ν[2].Q); }
N(printrez    ) { A(printrezβ, 010, ψ); }
N(show_parser ) { A("aaaa", 5, 0, ano, S, ex_pith, printrez); }
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსისთვის,
// ის ვრცელდება p-ზე j-თი, შემდეგ გამოიყენება q-ზე j-თი და შემდგომში
// აერთიანებს მიღებულ სიმრავლეს.:
//    (p ‘orelse‘ q) j = unite (p j) (q j)
//    e.g, assuming that the input is "ssss", then
//    (empty ‘orelse‘ term_s) 2 => {2, 3}
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსზე, ის ჯერ მიმართავს
// p-ს j ინდექსისთვის, შემდეგ ის მიმართავს q თითოეული p-თი დაბრუნებული ინდექსისათვის
// შედეგების სიმრავლეში. ის q-სთვის აბრუნებს ამ აპლიკაციების გაერთიანებას.
//    (p ‘thenS‘ q) j = union (map q (p j))
//    e.g., assuming that the input is "ssss", then
//    (term_s ‘thenS‘ term_s) 1 => {3}
N(ST) { A(ano, one, 2, p1, add, one, add, one, add); }
int main() {
  p_t ο[512];
  Q_t α = sizeof(ο) / sizeof(*ο);
  p_t ν[512];
  Q_t τ = 0;
  ο[--α].c = o_ray;
  ο[--α].c = a_ray;
  ο[--α].c = n_ray;
  ο[--α].Q = 0111;
  A(show_parser);
  return 5;
}
