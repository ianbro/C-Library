#include <stdlib.h>

#include "collections.h"

/* Adds toadd to the list */
void list_addi(ilist *list, int toadd) {
  int *tmpdata = list->data;
  list->data = malloc((list->size + 1) * sizeof(int));
  list->size ++;

  for (int i = 0; i < list->size-1; i++) {
    list->data[i] = tmpdata[i];
  }

  list->data[list->size-1] = toadd;
  free(tmpdata);
}

/* Adds each element in toadd to list in the order given in toadd. */
void list_addi_mult(ilist *list, ilist toadd) {
  int *tmpdata = list->data;

  list->data = malloc((list->size + toadd.size) * sizeof(int));
  list->size += toadd.size;

  for (int i = 0; i < list->size-toadd.size; i++) {
    list->data[i] = tmpdata[i];
  }

  for (int i = 0; i < toadd.size; i++) {
    list->data[i+(list->size - toadd.size)] = toadd.data[i];
  }
}

/* Returns the int at index in list. */
int list_geti_index(ilist *list, int index);

/* Find query in list and returns the index. If query does not exist,
 * -1 is returned.
 */
int searchilist(ilist *list, int query);

/* Creates a list of integers and returns that list. The elements in toadd will
 * be added to the list upon creation.
 */
ilist buildilist(int toadd[]);
