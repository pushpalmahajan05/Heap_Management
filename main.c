#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  void *a = malloc(-1);
  printf("%p\n", a);
  return EXIT_SUCCESS;
}
