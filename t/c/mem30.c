// Noncompliant Code Example
// This example from Brian Kernighan and Dennis Ritchie [Kernighan 1988]
// shows both the incorrect and correct techniques for freeing the memory
// associated with a linked list. In their (intentionally) incorrect example,
// p is freed before p->next is executed, so that p->next reads memory
// that has already been freed.
#include <stdlib.h>
 
struct node {
  int value;
  struct node *next;
};

void free_list_XXX(struct node *head) {
  for (struct node *p = head; p != NULL; p = p->next) {
    free(p);
  }
}
// Compliant Solution
// Kernighan and Ritchie correct this error by storing a reference to p->next
// in q before freeing p:
void free_list(struct node *head) {
  struct node *q;
  for (struct node *p = head; p != NULL; p = q) {
    q = p->next;
    free(p);
  }
}
// https://www.securecoding.cert.org/confluence/display/c/MEM30-C.+Do+not+access+freed+memory

