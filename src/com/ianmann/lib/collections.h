struct ilist
{
  int *data;
  int size;
};
typedef struct ilist ilist;

/* Adds toadd to the list */
void list_addi(ilist *list, int toadd);

/* Adds each element in toadd to list in the order given in toadd. */
void list_addi_mult(ilist *list, int toadd[]);

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
