unsigned int h31_hash(const char *s) {
  unsigned int h = 0;
  while (*s)
    h = 31 * h + *s++;
  return h;
}
#include <stdio.h>
#include <string.h>

int main() {
  int words[] = {1, 2, 3};
  const char *str = "adadaasdd"
                    "asasd"
                    "adsad";

  printf("%d\n", h31_hash(str));
}
