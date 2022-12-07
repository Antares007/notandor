#include <stdio.h>
#include <unistd.h>
long prn(long y);

void y(long x) { y(prn((x + 1) % 8)); }

int main() { y(0); }

long prn(long y) {
  for (long i = 0; i < y; i++)
    printf(" ");
  printf("%ld\n", y), usleep(100000);
  return y;
}
