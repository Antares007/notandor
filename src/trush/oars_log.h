#pragma once
#include"oars.h"
#include<stdio.h>
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define L CAT(name_fun,__LINE__)
extern char*names[];
#define G(t,n,h) Ν(n); static void h() { names[(Q_t)n & (Q_t)0xFFFF] = #n; void(*f)() = (void*)t; if(f) f(); }
void logn(OARS, const char*name);
#define LOGN printf("%.2lu %.3lu %s\n", ρ, α, __FUNCTION__)
#undef  D
#define D (logn(ο,ρ,α,σ,__FUNCTION__), --ρ, σ[ρ].c(oars))
