#pragma once
#include <stdio.h>
#define LOG printf("%s(%02lu)\n", __FUNCTION__, ι)
#define LOG_                            \
  printf("%s(%02lu %02lu %lu%lu%lu)\n", \
      __FUNCTION__,                     \
      ι,                                \
      α,                                \
      (τ[α].Q >> 6) & 7,                \
      (τ[α].Q >> 3) & 7,                \
      (τ[α].Q >> 0) & 7)
/*
 */
#undef N
#define N(Name)                                                                \
  void Name##Nar(TINAS);                                                        \
  void Name(TINAS) {                                                            \
    LOG;                                                                       \
    Name##Nar(Τ);                                                              \
  }                                                                            \
  void Name##Nar(TINAS)
