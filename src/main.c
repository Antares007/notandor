#include <stdio.h>
#include <stdlib.h>
int main(int argv, char **argc) {
  if (argv < 2)
    printf("Provide the path of the file as an argument."), exit(0);
  printf("Running pith:%s\n", argc[1]);
  return 0;
}
