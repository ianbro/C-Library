#include <stdio.h>
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

/* Find query in list and returns the index. If query does not exist,
 * -1 is returned.
 */
int searchilist(ilist *list, int query) {
  for (int i = 0; i < list->size; i ++) {
    if (list->data[i] == query) {
      return i;
    }
  }
  return -1;
}

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

/* Returns a string representation of list. The string is formatted as so:
 *      [#, #, #, #]
 */
char *ilisttos(ilist list) {
  int sprintf(char *dest, const char *src, ...);
  char *strcat(char *str, char *tocat);

  char *ret = malloc(sizeof(char));
  ret[0] = '[';
  for (int i = 0; i < list.size-1; i ++) {
    /* Add each element except the last one with a comma.
     * The last element will not have the comma. */
    char newstr[10];
    sprintf(newstr, "%d, ", list.data[i]);
    strcat(ret, newstr);
  }
  if (list.size > 0 /*TODO: make isempty*/) {
    /* Add the last element without the comma. */
    char newstr[10];
    sprintf(newstr, "%d", list.data[list.size-1]);
    strcat(ret, newstr);
  }

  /* Add the closing square bracket to the string. */
  strcat(ret, "]");
  return ret;
}
