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
 * be added to the list upon creation. The parameter size will be the number of
 * elements that should be added from toadd.
 *
 * NOTE: This function assumes that size is accurate. If it is larger than the
 * actual size of toadd, then an index error will be thrown. If it is smaller,
 * no error will be thrown but only size number of elements from toadd will be
 * set to the ilists data.
 */
ilist *buildilist(int toadd[], int size) {
  ilist *list = buildilist_empty();

  ilist temp;
  temp.data = toadd;
  temp.size = size;
  list_addi_mult(list, temp);

  return list;
}

/* Creates an empty list of integers and returns that list. */
ilist *buildilist_empty() {
  ilist *list = malloc(1);
  list->data = NULL;
  list->size = 0;

  return list;
}
