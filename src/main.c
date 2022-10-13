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
N(a_ray) { printf("done: %lu\n", σ[--α].Q); }
N(n_ray) { }

N(pano) { printf("1\n"), ano(C); }
N(poan) { printf("0\n"), oan(C); }
N(pnoa) { printf("2\n"), noa(C); }
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
N(cont_sigma) { σ[α-1].c(ο, α-1, ρ, σ); }
N(ex_pith_o ) { ο[ρ+0].v = oan; ο[ρ+1].Q = α; }
N(ex_pith_a ) { ο[ρ+0].v = ano; ο[ρ+1].Q = α; }
N(ex_pith_n ) { ο[ρ+0].v = noa; ο[ρ+1].Q = α; }
N(ex_pith   ) { 
  p_t nο[512]; Q_t nρ = 512;
  nρ -= 2;
  nο[--nρ].v = ex_pith_o;
  nο[--nρ].v = ex_pith_a;
  nο[--nρ].v = ex_pith_n;
  nο[--nρ].Q = 0111;
  cont_sigma(nο, α, nρ, σ);
  nο[510].c(ο, nο[511].Q, ρ, σ);
}
N(termβ) {
  R(const char*,  match);
  if (σ[2].Q < σ[1].Q && σ[0].cs[σ[2].Q] == match[0])
    σ[2].Q++, A(ano);
  else
    A(oan);
}
N(term    ) { A(termβ, 020, ψ); }
N(orelse  ) {
  p_t nο[512]; Q_t nρ = 512;
  nρ -= 2;
  nο[--nρ].c = ex_pith_o;
  nο[--nρ].c = ex_pith_a;
  nο[--nρ].c = ex_pith_n;
  nο[--nρ].Q = 0111;

  p_t nσ[512];
  nσ[0].v = σ[0].v;
  nσ[1].v = σ[1].v;
  nσ[2].v = σ[2].v;

  σ[α-1].c(nο, α-1, nρ, σ);
  α = nο[510].Q;

  if(nο[511].Q) {
    
  } else {
    ano(ο, α, ρ, σ);
  }
  //ο = nο;
  //p_t *rο = ο;
  //(void)rο;
}
N(S) {
  A(        "b", term,
    orelse, "a", term);
}
N(printrezβ   ) { printf("%lu", σ[2].Q); }
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
  Q_t ρ = sizeof(ο) / sizeof(*ο);
  p_t σ[512];
  Q_t α = 0;
  ο[--ρ].c = o_ray;
  ο[--ρ].c = a_ray;
  ο[--ρ].c = n_ray;
  ο[--ρ].Q = 0111;
  A(show_parser);
  return 5;
}
