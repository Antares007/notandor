#pragma once
#include "o.h"
#include<stdio.h>

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(name_fun,__LINE__)

extern char*names[];
#define LN(t,n,h) N(n); static void h() { names[(Q_t)n & (Q_t)0xFFFF] = #n; t(); }

#undef o
#define o           (logn(Τ,__FUNCTION__),--α, σ[α].c(Τ))
void logn(OARS, const char*name);
