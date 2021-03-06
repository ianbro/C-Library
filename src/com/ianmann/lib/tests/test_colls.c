#include <stdio.h>
#include <stdlib.h>

#include "../collections.h"

int main(int argc, char *argv[])
{
  printf("Hello World!\n");

  ilist *a = malloc(sizeof(ilist));
  a->data = malloc(1*sizeof(int));
  a->size = 1;

  ilist *b = malloc(sizeof(ilist));
  b->data = malloc(2*sizeof(int));
  b->size = 2;

  a->data[0] = 4;
  b->data[0] = 1;
  b->data[1] = 6;

  printf("%d %d\n", a->data[0], a->size);

  list_addi_mult(a, *b);

  printf("%d, %d\n", a->data[2], a->size);

  int newlist[] = {1, 4, 6, 2, 3};
  ilist *c = buildilist(newlist, 5);
  char *cstr = ilisttos(*c);
  printf("%s\n", cstr);

  printf("%d\n", searchilist(c, 6));

  exit(0);
}
