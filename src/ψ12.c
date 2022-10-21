#include "oars.h"
#undef LOG
#define LOG
N(Cε) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  for (Q_t i = 0; i < εc; i++) ο[α++].v = ο[ρ++].v;
  ρ += βc + αc;
  if(εc) O;
  else   Cε(Τ);
}
N(Cβ) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  ρ += εc;
  for (Q_t i = 0; i < βc; i++) ο[α++].v = ο[ρ++].v;
  ρ += αc;
  if(βc) O;
  else   Cβ(Τ);
}
N(Cα) {LOG;
  Q_t ψd = ο[ρ++].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  ρ += εc + βc;
  for (Q_t i = 0; i < αc; i++) ο[α++].v = ο[ρ++].v;
  if(αc) O;
  else   Cα(Τ);
}
N(ψ) {LOG;
  Q_t ψd = ο[--α].Q, εc = ψd >> 6 & 7, βc = ψd >> 3 & 7, αc = ψd & 7;
  for (Q_t i = 0; i < εc+βc+αc; i++) ο[--ρ].v = ο[--α].v;
  ο[--ρ].Q = ψd;
  O;
}
