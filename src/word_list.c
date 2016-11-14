#include <stdio.h>
#include <stdlib.h>

#include "../include/word_list.h"
#include <string.h>

wlist newList() {
  wlist newList = (wlist) malloc(sizeof(struct word_list));
  newList->word = NULL;
  newList->next = NULL;
  return newList;
}

wlist addList(wlist l, char* word) {
  while(l->next != NULL)
    l = l->next;
    wlist tmp = newList();
   
    // allocate the char necessary before  copy the content
    tmp->word = (char*) malloc(sizeof(char)*strlen(word));
    strcpy(tmp->word, word);
    
  l->next = tmp;
  return l->next;
}

void printList(wlist l) {
  l = l->next;
  while(l != NULL) {
    printf("%s\n", l->word);
    l = l->next;
  }
}

void freeList(wlist l) {
  if(l == NULL)
    return;
  freeList(l->next);
  free(l->word);
  free(l);
}

bool wlistIsEmpty(wlist l) {
  return l->next == NULL;
}

