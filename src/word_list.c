#include <stdio.h>
#include <stdlib.h>

#include "../include/word_list.h"

list newList(char* word) {
  list newList = (list) malloc(sizeof(struct word_list));
  newList->word = word;
  newList->next = NULL;
  return newList;
}

list addList(list l, char* word) {
  if(l == NULL) {
    l = newList(word);
    return l;
  }
  return addList(l->next, word);
}

void printList(list l) {
  if(l == NULL)
    return;
  printf("%s\n", l->word);
  printList(l->next);
}

void freeList(list l) {
  if(l == NULL)
    return;
  freeList(l->next);
  free(l->word);
  free(l);
}

