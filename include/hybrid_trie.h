#ifndef _HYBRID_TRIE_
#define _HYBRID_TRIE_

#include <stdbool.h>

#include "../include/word_list.h"

// Hybrid trie structure
typedef struct hybridTrie {
  char key;
  bool isKey;
  struct hybridTrie* inf;
  struct hybridT* eq;
  struct hybridT* sup;
} *HTptr;

/****************
 * PRIMITIVES
 ****************/
// Create a node with key as a key
HTptr newHybridTrie(char* word);

// Insert a new word to an hybrid trie
HTptr insertHT(HTptr hybridTrie, char* word);

// Remove an hybrid trie from memory
void freeHT(HTptr hybridTrie);

/**********************
 * ADVANCES FUNCTIONS
 **********************/
// Search a word
bool searchHT(HTptr hybridTrie, char* word);

// 
int nbWordsHT(HTptr hybridTrie);

// 
list wordListHT(HTptr hybridTrie);

#endif