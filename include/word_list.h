#ifndef _WORD_LIST_
#define _WORD_LIST_

// Linked list structure
typedef struct word_list {
  char* word;
  struct linked_list *next;
} *list;

list newList(char* word);

list addList(list l, char* word);

void printList(list l);

void freeList(list l);

#endif