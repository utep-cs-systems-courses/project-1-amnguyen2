#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history() {
  List *history = (List*) malloc(sizeof(List*) * 100); // allocate space for list
  return history;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  Item *item = (Item*) malloc(sizeof(Item*) * 100); // allocate space for item
  item->str = str; // set item's str value

  if(list->root == NULL) { // if the list doesn't have an item (*root)
    item->id = 1; // set first item id
    list->root = item; // add first item to list
    return;
  }

  // if the list has at least one item
  Item *temp = list->root; // temporary iterator to move through list
  int id = 1; // current item id in list
  
  while(temp->next != NULL) { // loop to end of list
    id++;
    temp = temp->next; // next item in list
  } // reached last item in list

  temp->next = item; // append item to list
  item->id++; // next id number
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *temp = list->root; // temporary iterator to move through list
  
  while (temp != NULL) { // iterate to end of list
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  
  return temp->str;
}


/* Print the entire contents of the list. */
void print_history(List *list) {

}


/* Free the history list and the strings it references. */
void free_history(List *list) {

}
