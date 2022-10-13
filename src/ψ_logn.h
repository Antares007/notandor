#pragma once
#include <stdio.h>
#define LOG printf("%s(%lu)\n", __FUNCTION__, α)
/*
*/
#undef N
#define N(Name)                                                                \
  void Name##Nar(OANT);                                                        \
  void Name(OANT) {                                                            \
    LOG;                                                                       \
    Name##Nar(C);                                                              \
  }                                                                            \
  void Name##Nar(OANT)
