#include <stdio.h>
#include <stdlib.h>

#include "../include/word_list.h"
#include <string.h> 

wlist newList() 
{
  wlist newList = (wlist) malloc(sizeof(struct word_list));
  newList->word = NULL;
  newList->prev = newList;
  newList->next = newList;
  return newList;
}

bool wlistIsEmpty(wlist l) 
{
  return l->next == l;
}

wlist addList(wlist l, char* word) 
{
  wlist tmp = newList();
  tmp->word = (char*) malloc(sizeof(char)*strlen(word)+1);
  strcpy(tmp->word, word);
  tmp->next = l;
  tmp->prev = l->prev;
  l->prev->next = tmp;
  l->prev = tmp;
  return tmp;
}

void printList(wlist l) 
{
  wlist tmp = l->next;
  while (tmp != l) 
  {
    printf("%s\n", tmp->word);
    tmp = tmp->next;
  }
}

void freeList(wlist l) 
{
  if (wlistIsEmpty(l)) 
    free(l);
  else {
    free(l->word);
    freeList(l->next);
    free(l);
  }
}

wlist wlistcat(wlist dest, wlist src) 
{
  if (wlistIsEmpty(dest))
    return src;
  if (wlistIsEmpty(src))
    return dest;
  dest->prev->next = src->next;
  src->prev->next = dest;
  free(src);
  return dest;
}