#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_
#include <stdbool.h>
#include <string.h>
#include "word_list.h"
#include "../include/hybrid_trie.h"


typedef struct patricia_node {
    char* val;
    struct patricia_node* next ;
    struct patricia_node* child;
} *patriciaTrie;



/****************
 * PRIMITIVES
 ****************/
patriciaTrie newpatricia_aux( patriciaTrie child , patriciaTrie next , char* word);

bool isTerminal(patriciaTrie pt);

// Create a node with key as a key
patriciaTrie newPatricia(char* word);

// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* mot);

//split a node 
void split(patriciaTrie pt, int k);

// Remove a patricia trie from memory
void freePatricia(patriciaTrie t);

//return a boolean
bool isEmptyPatricia(patriciaTrie pt);

/**********************
 * ADVANCES FUNCTIONS
 **********************/

// Search a word
bool searchPatricia(patriciaTrie pt ,char* mot);

// Count words in patricia trie
int countWordPatricia(patriciaTrie pt);

// Return a word list from patricia trie
wlist listWords(patriciaTrie pt);

// Count NULL pointers in patricia trie
int countNilPatricia(patriciaTrie pt);

void averageInside(patriciaTrie pt, int * deph, int * total, int Cdepth); //useful for computing averagedepth
// Return average patricia trie depth
int averageDepthPatricia(patriciaTrie pt);

// Count word prefix from word
int nbPrefixPatricia(patriciaTrie pt ,char* mot);

void join(patriciaTrie pt );
// Remove word from hybrid trie
patriciaTrie deletePatricia(patriciaTrie pt ,char* mot );

// Return height's patricia trie
int heightPatricia(patriciaTrie pt);

/********************
 * COMPLEX FUNCTIONS
 *******************/

//Merge 2 Patricia tries
patriciaTrie mergePatricia(patriciaTrie pt1 ,patriciaTrie pt2);


//patricia trie to hybrid
HTptr patriciaToHybrid(patriciaTrie pt);

/* hybrid to patricia */
patriciaTrie hybrid2patricia(HTptr hybridTrie);


#endif




