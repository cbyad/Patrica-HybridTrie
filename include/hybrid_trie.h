#ifndef _HYBRID_TRIE_
#define _HYBRID_TRIE_

#include <stdbool.h>

#include "../include/word_list.h"
#include "../include/my_functions.h"

#define MAX(x, y) x > y ? x : y

// Hybrid trie structure
typedef struct hybridTrie {
  char key;
  bool isKey;
  struct hybridTrie* inf;
  struct hybridTrie* eq;
  struct hybridTrie* sup;
} *HTptr;

/****************
 * PRIMITIVES
 ****************/

// Create a new empty hybrid trie
HTptr newEmptyHT();

// Create a node with key as a key
HTptr newHybridTrie(char* word);

// Insert a new word to an hybrid trie
HTptr insertHT(HTptr hybridTrie, char* word);

// Remove an hybrid trie from memory
void freeHT(HTptr hybridTrie);

//Return true if hybrid trie is empty
bool isEmptyHT(HTptr hybridTrie);

/**********************
 * ADVANCES FUNCTIONS
 **********************/

// Search a word
bool searchHT(HTptr hybridTrie, char* word);

// Count words in hybrid trie
int countwHT(HTptr hybridTrie);

// Return a word list from hybrid trie
wlist wordListHT(HTptr hybridTrie);

// Count NULL pointers in hybrid trie
int nbNULLHT(HTptr hybridTrie);

// Return hybrid trie size
int sizeHT(HTptr hybridTrie);

// Return average hybrid trie depth
int depthAvgHT(HTptr hybridTrie);

// Count word prefix from word
int nbPrefixHT(HTptr hybridTrie, char* word);

// Remove word from hybrid trie
HTptr removeHT(HTptr hybridTrie, char* word);

#endif