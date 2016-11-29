#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/hybrid_trie.h"
#include "../include/word_list.h"

/*************
 * PRIMITIVES
 *************/

HTptr newHybridTrie(char* word, HTptr inf, HTptr eq, HTptr sup) {
  HTptr newTrie = (HTptr) malloc(sizeof(struct hybridTrie));
  newTrie->key = *word;
  newTrie->isKey = false;
  newTrie->inf = inf;
  newTrie->eq = eq;
  newTrie->sup = sup;
  return newTrie;
}

HTptr insertHT(HTptr hybridTrie, char* word) {
  if (hybridTrie == NULL) {
    hybridTrie = newHybridTrie(word, NULL, NULL, NULL);
  }

  if (*word < hybridTrie->key) {
    hybridTrie->inf = insertHT(hybridTrie->inf, word);
  }

  else if (*word > hybridTrie->key) {
    hybridTrie->sup = insertHT(hybridTrie->sup, word);
  }

  else {
    if (*(word+1) == 0)
      hybridTrie->isKey = true;
    else
      hybridTrie->eq = insertHT(hybridTrie->eq, ++word);
  }

  return hybridTrie;
}

void freeHT(HTptr hybridTrie) {
  if (hybridTrie == NULL)
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
  if (hybridTrie == NULL)
    return false;

  if (*word < hybridTrie->key) {
    return searchHT(hybridTrie->inf, word);
  }

  else if (*word > hybridTrie->key) {
    return searchHT(hybridTrie->sup, word);
  }

  else {
    if (*(word+1) == 0 && hybridTrie->isKey)
      return true;
    else if (*(word+1) == 0 && !hybridTrie->isKey)
      return false;
    else
      return searchHT(hybridTrie->eq, ++word);
  }
}

int countwHT(HTptr hybridTrie) {
  if (hybridTrie == NULL)
    return 0;
  int n = hybridTrie->isKey;
  return n + countwHT(hybridTrie->inf) + countwHT(hybridTrie->eq) + countwHT(hybridTrie->sup);
}

wlist wordListHT_aux(HTptr hybridTrie, wlist list, char* word) {
  if (hybridTrie == NULL)
    return list;
  char *tmp, *w;


  wordListHT_aux(hybridTrie->inf, list, word);

  w = malloc(sizeof(char)*strlen(word) + 2*sizeof(char));
  strcpy(w, word);
  tmp = strchr(w, 0);
  *tmp = hybridTrie->key;
  *(tmp+1) = 0;
  
  if (hybridTrie->isKey)
    addList(list, w);

  wordListHT_aux(hybridTrie->eq, list, w);
  free(w);
  wordListHT_aux(hybridTrie->sup, list, word);

  return list;
}

wlist wordListHT(HTptr hybridTrie) {
  wlist list;
  list = newList();
  wordListHT_aux(hybridTrie, list, "");
  return list;
}

int nbNULLHT(HTptr hybridTrie) {
  if (hybridTrie == NULL)
    return 1;
  return nbNULLHT(hybridTrie->inf) + nbNULLHT(hybridTrie->eq) + nbNULLHT(hybridTrie->sup);
}

int heightHT(HTptr hybridTrie) {
  if (hybridTrie == NULL)
    return -1;
  return 1 + max3(heightHT(hybridTrie->inf), heightHT(hybridTrie->eq), heightHT(hybridTrie->sup));
}

int depthAvgHT_aux(HTptr hybridTrie, int depth, int *nbLeaf) {
  if (hybridTrie == NULL)
    return 0;
  if (hybridTrie->eq == NULL && hybridTrie->inf == NULL && hybridTrie->sup == NULL) {
    *nbLeaf = *nbLeaf + 1;
    return depth;
  }
  return depthAvgHT_aux(hybridTrie->eq, depth+1, nbLeaf) + depthAvgHT_aux(hybridTrie->inf, depth+1, nbLeaf) 
          + depthAvgHT_aux(hybridTrie->sup, depth+1, nbLeaf);
}

int depthAvgHT(HTptr hybridTrie) {
  int total;
  int *nbLeaf = malloc(sizeof(int));
  *nbLeaf = 0;
  total = depthAvgHT_aux(hybridTrie, 0, nbLeaf);
  total /= *nbLeaf;
  free(nbLeaf);
  return total;
}


int nbPrefixHT(HTptr hybridTrie, char* word) {
  if (*word == 0)
    return countwHT(hybridTrie);

  if (*word < hybridTrie->key)
    return nbPrefixHT(hybridTrie->inf, word);

  else if (*word > hybridTrie->key)
    return nbPrefixHT(hybridTrie->sup, word);

  else 
    return hybridTrie->isKey + nbPrefixHT(hybridTrie->eq, ++word);
}

HTptr removeHT(HTptr hybridTrie, char* word) {
  if (hybridTrie == NULL)
    return NULL;

  if (*word == 0 && hybridTrie->inf == NULL && hybridTrie->eq == NULL && hybridTrie->sup == NULL)
    return NULL;

  if (*word == 0 && hybridTrie->inf == NULL && hybridTrie->eq == NULL)
    return hybridTrie->sup;
  
  if (*word == 0 && hybridTrie->sup == NULL && hybridTrie->eq == NULL)
    return hybridTrie->inf;
  
  if (*word == 0) {
    hybridTrie->isKey = false;
    return hybridTrie;
  }
  
  /* TODO */
  return NULL;
}