#include <stdio.h>
#include <assert.h>
typedef void (*n_t)(void **ο, long α, long ρ, void **σ);
#define S(...)                                                                 \
  {                                                                            \
    const void *va_args[] = {__VA_ARGS__};                                     \
    long size = sizeof(va_args) / sizeof(*va_args);                            \
    for (long i = 0; i < size; i++)                                            \
      σ[ρ++] = (void *)va_args[i];                                             \
  }
#define N(...)                                                                 \
  {                                                                            \
    const void *ϋ[] = {__VA_ARGS__};                                           \
    long size = sizeof(ϋ) / sizeof(*ϋ);                                        \
    while (size)                                                               \
      ο[--α] = (void *)ϋ[--size];                                              \
  }
#define Ν(argo) void argo(void **ο, long α, long ρ, void **σ)

void logn(void **ο, long α, long ρ, void **σ, const char*name);
#define Dot (logn(ο, ρ, α, σ, __FUNCTION__),((n_t)σ[ρ - 1])(ο, α, ρ - 1, σ))

void c(void **ο, long α, long ρ, void **σ) {
  unsigned long nth_ray = σ[--ρ];
  while (1) {
    unsigned long ψ = ο[α++];
    unsigned long words = ψ >> 3 * nth_ray & 7;
    for (unsigned long i = nth_ray + 1; i < 8; i++) α += ψ >> 3 * i & 7;
    for (unsigned long i = 0; i < words; i++) σ[ρ++] = ο[α++];
    for (unsigned long i = 0; i < nth_ray; i++) α += ψ >> 3 * i & 7;
    if (words) return Dot;
  }
}
Ν(bo   ) { S(bo, 1, c) Dot; }

Ν(one_) { S(1, 1, c) Dot; }
Ν(one) { N(010, one_) Dot; }
Ν(add_) {
  long r = σ[--ρ];
  long l = σ[--ρ];
  S(l + r, 1, c) Dot;
}
Ν(add) { N(010, add_) Dot; }
Ν(e₂) { puts(""); }
Ν(e₁) { puts(""); }
Ν(e₀) { puts(""); }

Ν(e) { S(1, c) Dot; }
Ν(t_) {
  char   *m = σ[--ρ];
  assert(bo== σ[--ρ]);
  long  pos = σ[--ρ];
  long  len = σ[--ρ];
  char *inp = σ[--ρ];
  if (pos < len && inp[pos] == m[0]) {
    S(inp, len, pos+1, bo, 1, c) Dot;
  } else {
    S(inp, len, pos,   bo, 0, c) Dot;
  }
}
Ν(t     ) { N(020, σ[--ρ], t_) Dot; }
Ν(join2 ) { long oα = σ[--ρ]; void**oο = σ[--ρ]; S(2) c(oο, oα, ρ, σ); }
Ν(join1 ) { long oα = σ[--ρ]; void**oο = σ[--ρ]; S(1) c(oο, oα, ρ, σ); }
Ν(join0 ) { long oα = σ[--ρ]; void**oο = σ[--ρ]; S(0) c(oο, oα, ρ, σ); }
Ν(eOs_  ) {{
  void**oο = ο, **oσ=σ; long oα = α, oρ = ρ;
  ο = (void*[256]){}; α = 256;
  N(0333, oο, oα, join0,
          oο, oα, join1,
          oο, oα, join2)
  for (long i = 0; i < ρ; i++) σ[i] = oσ[i];
  S(e) Dot;
  ο = oο, α = oα, ρ = oρ; σ = oσ;
}{ 
  void**oο = ο, **oσ=σ; long oα = α, oρ = ρ;
  ο = (void*[256]){}; α = 256;
  N(0333, oο, oα, join0,
          oο, oα, join1,
          oο, oα, join2)
  for (long i = 0; i < ρ; i++) σ[i] = oσ[i];
  S("s", t) Dot;
  ο = oο, α = oα, ρ = oρ; σ = oσ;
}}
Ν(eOs) { N(010, eOs_) Dot; }
Ν(parse) { S("sssss", 5, 0, bo, eOs, eOs) Dot; }
Ν(two_ ) { S(one, one, add) Dot;}
Ν(two  ) { N(030, 1, c, two_) Dot;}
Ν(fru_ ) { S(two, two, add) Dot;}
Ν(fru  ) { N(030, 1, c, fru_) Dot;}
Ν(oct_ ) { S(fru, fru, add) Dot;}
Ν(oct  ) { N(030, 1, c, oct_) Dot;}
Ν(seven) { S(1, c, one, two, add, fru, add, oct, add) Dot; }
void init_names();
int main() {
  init_names();
  void *ο[256];
  long α = 256;
  long ρ = 0;
  void *σ[128];
  N(0111, e₂, e₁, e₀)
  S(seven)
  Dot;
}
extern char* names[];
#define NAME(ame) names[(long)ame&0xFFFF] = #ame
void init_names() {
  NAME(e);
  NAME(t_);
  NAME(t);
  NAME(eOs_);
  NAME(eOs);

  NAME(one_);
  NAME(one);
  NAME(two_);
  NAME(two);
  NAME(fru_);
  NAME(fru);
  NAME(oct_);
  NAME(oct);
  NAME(add_);
  NAME(add);

  NAME(c);
  NAME(bo);
  NAME(e₂);
  NAME(e₁);
  NAME(e₀);
}
