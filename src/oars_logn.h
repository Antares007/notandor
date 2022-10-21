#pragma once
#include "oars.h"
#include <stdio.h>

#define LOG printf("%lx %02lu %lu %lu %s\n",  \
    ((Q_t)ο[σ] >> (Q_t)12) & 0xfff,           \
    α[σ],                                     \
    ρ[σ],                                     \
    σ,                                        \
    __FUNCTION__)

#undef N
#define N(Name)                               \
  void Name##Nar(OARS);                       \
  void Name(OARS) {                           \
    LOG;                                      \
    Name##Nar(ο,α,ρ,σ);                       \
  }                                           \
  void Name##Nar(OARS)
