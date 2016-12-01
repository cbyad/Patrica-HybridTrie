#ifndef _HYBRID_TRIE_
#define _HYBRID_TRIE_

#include <stdbool.h>
#include <math.h>

#include "../include/word_list.h"
#include "../include/my_functions.h"

#define MAX(x, y) x > y ? x : y

/* Hybrid trie structure */
typedef struct hybridTrie 
{
  char key;
  bool isKey;
  struct hybridTrie* inf;
  struct hybridTrie* eq;
  struct hybridTrie* sup;
} *HTptr;

/****************
 * PRIMITIVES
 ****************/

/* Create a node with key as a key */
HTptr newHybridTrie(char word, bool key, HTptr inf, HTptr eq, HTptr sup);

/* Insert a new word to an hybrid trie */
HTptr insertHT(HTptr hybridTrie, char* word);

/* Remove an hybrid trie from memory */
void freeHT(HTptr hybridTrie);

/* Return true if hybrid trie is empty */
bool isEmptyHT(HTptr hybridTrie);

/**********************
 * ADVANCES FUNCTIONS
 **********************/

/* Search a word */
bool searchHT(HTptr hybridTrie, char* word);

/* Count words in hybrid trie */
int countwHT(HTptr hybridTrie);

/* Auxiliary function to wordListHT() */
wlist wordListHT_aux(HTptr hybridTrie, wlist list, char* word);

/* Return a word list from hybrid trie */
wlist wordListHT(HTptr hybridTrie);

/* Count NULL pointers in hybrid trie */
int nbNULLHT(HTptr hybridTrie);

/* Return hybrid trie size */
int heightHT(HTptr hybridTrie);

/* Auxiliary function to depthAvgHT() */
int depthAvgHT_aux(HTptr hybridTrie, int depth, int *nbLeaf);

/* Return average hybrid trie depth */
int depthAvgHT(HTptr hybridTrie);

/* Count word prefix from word */
int nbPrefixHT(HTptr hybridTrie, char* word);

/* Remove word from hybrid trie
 * WARNING: this function may return an unbalanced hybrid trie */
HTptr removeHT(HTptr hybridTrie, char* word);

/********************
 * COMPLEX FUNCTIONS
 *******************/

/* Return true if hybridTrie is balanced */
bool isBalanced(HTptr hybridTrie);

int countInfChild(HTptr hybridTrie);

int countSupChild(HTptr hybridTrie);

/* Insert a new word to an hybrid trie + balancing */
HTptr insertHT(HTptr hybridTrie, char* word);

#endif
