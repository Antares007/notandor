#include <stdio.h>
void c(void **ο, long α, long ρ, void **σ) { //printf("%s\n", __FUNCTION__);
  unsigned long nth_ray = σ[--ρ];
  while (1) {
    unsigned long ψ = ο[α++];
    unsigned long words = ψ >> 3 * nth_ray & 7;
    for (unsigned long i = nth_ray + 1; i < 8      ; i++) α += ψ >> 3 * i & 7;
    for (unsigned long i = 0          ; i < words  ; i++) σ[ρ++] = ο[α++];
    for (unsigned long i = 0          ; i < nth_ray; i++) α += ψ >> 3 * i & 7;
    if (words) {
        void (*nar)() = σ[--ρ];
        return nar(ο, α, ρ, σ);
    }
  }
}
void ერთ(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
  σ[ρ++] = 1, σ[ρ++] = 1, c(ο, α, ρ, σ);
}
void ერთი(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
  ο[--α] = ერთ, ο[--α] = 010;
  void (*n)() = σ[--ρ];
  n(ο, α, ρ, σ);
}
void კრიბ(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
  long r = σ[--ρ];
  long l = σ[--ρ];
  σ[ρ++] = l + r, σ[ρ++] = 1, c(ο, α, ρ, σ);
}
void შეკრიბე(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
  ο[--α] = კრიბ, ο[--α] = 010;
  void (*n)() = σ[--ρ];
  n(ο, α, ρ, σ);
}
void end2(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
            }
void end1(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
      while(ρ) printf("%ld ",(long)σ[--ρ]);}
void end0(void **ο, long α, long ρ, void **σ) {//printf("%s\n", __FUNCTION__);
            }
int main() {
  void*ο[256];
  long α=256;
  long ρ=0;
  void*σ[128];
  ο[--α]=end2;
  ο[--α]=end1;
  ο[--α]=end0;
  ο[--α]=0111;
  σ[ρ++]=1, σ[ρ++]=c,
    σ[ρ++]=ერთი, σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე, σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე, σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე,
                 σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე; σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე, σ[ρ++]=ერთი, σ[ρ++]=შეკრიბე;
  void (*n)() = σ[--ρ];
  n(ο, α, ρ, σ);
}
