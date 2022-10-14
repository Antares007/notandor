#pragma once
#include <stdio.h>
#define LOG printf("%s(%02lu)\n", __FUNCTION__, ν)
#define LOG_                            \
  printf("%s(%02lu %02lu %lu%lu%lu)\n", \
      __FUNCTION__,                     \
      ν,                                \
      α,                                \
      (ο[α].Q >> 6) & 7,                \
      (ο[α].Q >> 3) & 7,                \
      (ο[α].Q >> 0) & 7)
/*
 */
#undef N
#define N(Name)                                                                \
  void Name##Nar(OANT);                                                        \
  void Name(OANT) {                                                            \
    LOG;                                                                       \
    Name##Nar(Τ);                                                              \
  }                                                                            \
  void Name##Nar(OANT)
