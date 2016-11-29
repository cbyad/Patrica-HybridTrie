#include <stdio.h>
#include <stdlib.h>

#include "../include/word_list.h"
#include <string.h> 

wlist newList() {
  wlist newList = (wlist) malloc(sizeof(struct word_list));
  newList->word = NULL;
  newList->prev = newList;
  newList->next = newList;
  return newList;
}

bool wlistIsEmpty(wlist l) {
  return l->next == l;
}

wlist addList(wlist l, char* word) {
  wlist tmp = newList();
  tmp->word = (char*) malloc(sizeof(char)*strlen(word)+1);
  strcpy(tmp->word, word);
  tmp->next = l;
  tmp->prev = l->prev;
  l->prev->next = tmp;
  l->prev = tmp;
  return tmp;
}

void printList(wlist l) {
  wlist tmp = l->next;
  while (tmp != l) {
    printf("%s\n", tmp->word);
    tmp = tmp->next;
  }
}

void freeList(wlist l) {
  for (wlist tmp = l->next; tmp != l; tmp = tmp->next){
    free(tmp->word);
    if(tmp->prev != l ){
      free(tmp->prev);
    }
  }
  if(!wlistIsEmpty(l)){
    free(l->prev);
  }
  free(l);
}

wlist wlistcat(wlist dest, wlist src) {
  if (dest == NULL || wlistIsEmpty(dest))
    return src;
  if (src == NULL || wlistIsEmpty(src))
    return dest;
  dest->prev->next = src->next;
  src->prev->next = dest;
  free(src);
  return dest;
}