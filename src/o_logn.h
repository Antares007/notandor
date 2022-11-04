#pragma once
#include "o.h"
#include<stdio.h>

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(name_fun,__LINE__)

extern char*names[];
#define LN(t,n,h) N(n); static void h() { names[(Q_t)n & (Q_t)0xFFFF] = #n; t(); }

#undef O
#define O           (logn(T,__FUNCTION__),--α, σ[α].c(T))
void logn(OARS, const char*name);
