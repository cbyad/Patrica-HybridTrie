#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "../include/hybrid_trie.h"
#include "../include/word_list.h"

/*************
 * PRIMITIVES
 *************/

HTptr newEmptyHT() {
  HTptr newTrie = (HTptr) malloc(sizeof(struct hybridTrie));
  newTrie->inf = NULL;
  newTrie->eq = NULL;
  newTrie->sup = NULL;
  return newTrie;
}

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
  if(hybridTrie == NULL) {
    hybridTrie = newHybridTrie(word);
  }

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

int countwHT(HTptr hybridTrie) {
  if(hybridTrie == NULL)
    return 0;
  int n = hybridTrie->isKey;
  return n + countwHT(hybridTrie->inf) + countwHT(hybridTrie->eq) + countwHT(hybridTrie->sup);
}

// TODO
// wlist wordListHT(HTptr hybridTrie) {
// 
// }

int nbNULLHT(HTptr hybridTrie) {
  if(hybridTrie == NULL)
    return 1;
  return nbNULLHT(hybridTrie->inf) + nbNULLHT(hybridTrie->eq) + nbNULLHT(hybridTrie->sup);
}

int sizeHT(HTptr hybridTrie) {
  if(hybridTrie == NULL)
    return -1;
  return 1 + max3(sizeHT(hybridTrie->inf), sizeHT(hybridTrie->eq), sizeHT(hybridTrie->sup));
}


// int depthAvgHT(HTptr hybridTrie) {

// }

int nbPrefixHT(HTptr hybridTrie, char* word) {
  if(*word == 0)
    return countwHT(hybridTrie);

  if(*word < hybridTrie->key)
    return nbPrefixHT(hybridTrie->inf, word);

  else if(*word > hybridTrie->key)
    return nbPrefixHT(hybridTrie->sup, word);

  else 
    return hybridTrie->isKey + nbPrefixHT(hybridTrie->eq, ++word);
}

HTptr removeHT(HTptr hybridTrie, char* word) {
  if(hybridTrie == NULL)
    return hybridTrie;

  if(*word < hybridTrie->key) {
    return removeHT(hybridTrie->inf, word);
  }

  else if(*word > hybridTrie->key) {
    return removeHT(hybridTrie->sup, word);
  }

  else {
    if(*(word+1) == 0) {
      hybridTrie->isKey = false;
      return hybridTrie;
    }
    return removeHT(hybridTrie->eq, ++word);
  }
}