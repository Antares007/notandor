#include "ψ.h"
#include "ψ_logn.h"
// clang-format off
n_t lr[1024]; Q_t lr_len = 0;
N(noa) { lr_len = 0;
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) ο[ν++].v = ο[α++].v;
  α += ac + oc;
  nc ? Ο : noa(Τ);
}
N(ano) { lr_len = 0;
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc;
  for (Q_t i = 0; i < ac; i++) ο[ν++].v = ο[α++].v;
  α += oc;
  ac ? Ο : ano(Τ);
}
N(oan) { lr_len = 0;
  Q_t g = ο[α++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  α += nc + ac;
  for (Q_t i = 0; i < oc; i++) ο[ν++].v = ο[α++].v;
  oc ? Ο : oan(Τ);
}
N(ψ) {
  Q_t g = ο[--ν].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) ο[--α].v = ο[--ν].v;
  ο[--α].Q = g;
  R(n_t, nar);
  for(Q_t i = 0; i < lr_len; i++)
    if (lr[i] == nar) return (printf("LREC!\n"), (void) 0);
  lr[lr_len++] = nar;
  nar(Τ);
}
