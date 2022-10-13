#include "ψ.h"
#include "ψ_logn.h"
#include <stdio.h>
#include <uv.h>
#define Σ 512
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
N(a_ray) { printf("done: %lu\n", ο[--ν].Q); }
N(n_ray) { }

N(pano) { printf("1\n"), ano(Τ); }
N(poan) { printf("0\n"), oan(Τ); }
N(pnoa) { printf("2\n"), noa(Τ); }
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
N(termβ) {
  R(const char*,  match);
  if (ο[2].Q < ο[1].Q && ο[0].cs[ο[2].Q] == match[0]) ο[2].Q++, A(ano);
  else A(oan); }
N(T) { A(termβ, 020, ψ); }
N(V) { ano(Τ); }
N(O) { Ο; }
N(S) { A(V, "o", T, "a", T, "n", T,
         O, "a", T, "n", T, "o", T,
         O, "n", T, "o", T, "a", T); }
N(printrezβ   ) { printf("%lu", ο[2].Q); }
N(printrez    ) { A(printrezβ, 010, ψ); }
N(show_parser ) { A("aaaa", 5, 0, S, printrez); }
/*  S(3)
      T(23) T(21) T(19) O(17)
      T(16) T(14) T(12) O(10)
      T( 9) T( 7) T( 5) V( 3)
    termβ(4)
    o_ray(3) */
//     Z0) inp len pos ano bterm O aterm  | .
//
// O) inp len pos ano bterm               | 010 aterm .
//       > inp len pos ano bterm               |           .
//       > inp len pos ano                     | 010 aterm .
//
//  bterm) inp len pos ano                     | .
// 

// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსისთვის,
// ის ვრცელდება p-ზე j-თი, შემდეგ გამოიყენება q-ზე j-თი და შემდგომში
// აერთიანებს მიღებულ სიმრავლეს.:
//    (p ‘O‘ q) j = unite (p j) (q j)
//    e.g, assuming that the input is "ssss", then
//    (empty ‘O‘ term_s) 2 => {2, 3}
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსზე, ის ჯერ მიმართავს
// p-ს j ინდექსისთვის, შემდეგ ის მიმართავს q თითოეული p-თი დაბრუნებული ინდექსისათვის
// შედეგების სიმრავლეში. ის q-სთვის აბრუნებს ამ აპლიკაციების გაერთიანებას.
//    (p ‘thenS‘ q) j = union (map q (p j))
//    e.g., assuming that the input is "ssss", then
//    (term_s ‘thenS‘ term_s) 1 => {3}
N(ST) { A(ano, one, 2, p1, add, one, add, one, add); }
int main() {
  p_t ο[Σ];
  Q_t α = Σ;
  Q_t ν = 0;
  ο[--α].c = o_ray;
  ο[--α].c = a_ray;
  ο[--α].c = n_ray;
  ο[--α].Q = 0111;
  A(show_parser);
  return 5;
}
