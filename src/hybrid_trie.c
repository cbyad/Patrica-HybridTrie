#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../include/hybrid_trie.h"

HTptr newHybridTrie(char* word) {
  HTptr newTrie = (HTptr) malloc(sizeof(struct hybridTrie));
  newTrie->key = *word;
  newTrie->isKey = false;
  newTrie->inf = NULL;
  newTrie->eq = NULL;
  newTrie->sup = NULL;
  return newTrie;
}

HTptr insertHT(HTptr hybridTrie, char* word) {
  if(hybridTrie == NULL)
    hybridTrie = newHybridTrie(word);

  if(*word < hybridTrie->key) {
    hybridTrie->inf = insertHT(hybridTrie->inf, word);
  }

  else if(*word > hybridTrie->key) {
    hybridTrie->sup = insertHT(hybridTrie->sup, word);
  }

  else {
    if(*(word+1) == 0)
      hybridTrie->isKey = true;
    else
      hybridTrie->eq = insertHT(hybridTrie->eq, ++word);
  }

  return hybridTrie;
}

void freeHT(HTptr hybridTrie) {
  if(hybridTrie == NULL)
    return;
  freeHT(hybridTrie->inf);
  freeHT(hybridTrie->eq);
  freeHT(hybridTrie->sup);
  free(hybridTrie);
}

/*********************
 * ADVANCED FUNCTIONS
 *********************/

bool searchHT(HTptr hybridTrie, char* word) {
  if(hybridTrie == NULL)
    return false;

  if(*word < hybridTrie->key) {
    return searchHT(hybridTrie->inf, word);
  }

  else if(*word > hybridTrie->key) {
    return searchHT(hybridTrie->sup, word);
  }

  else {
    if(*(word+1) == 0 && hybridTrie->isKey)
      return true;
    else if(*(word+1) == 0 && !hybridTrie->isKey)
      return false;
    else
      return searchHT(hybridTrie->eq, ++word);
  }
}