#include <stdio.h>
#include <stdlib.h>

#include "../collections.h"

int main(int argc, char *argv[])
{
  printf("Hello World!\n");

  ilist *a = malloc(sizeof(ilist));
  a->data = malloc(1*sizeof(int));
  a->size = 1;

  a->data[0] = 4;

  printf("%d\n", a->data[0]);

  list_addi(a, 7);

  printf("%d\n", a->data[1]);

  exit(0);
}
