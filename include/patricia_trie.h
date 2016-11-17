#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_
#include <stdbool.h>
#include "word_list.h"


//#define ALPHABET_SIZE 128
//#define END_WORD '/0'
typedef struct patricia_node {
    char* val;
    bool isTerminal ; // tell us about if is val is terminal or not
    //struct patricia_node* child[ALPHABET_SIZE];
    struct patricia_node* next ;
    struct patricia_node* child;
} *patriciaTrie;



/****************
 * PRIMITIVES
 ****************/


// Create a node with key as a key
patriciaTrie newPatricia(char* word);                         //ok

// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* mot);   //debut


// Remove a patricia trie from memory
void freePatricia(patriciaTrie t);                                     //ok


//return a boolean
bool isEmptyPatricia(patriciaTrie pt);                              //ok

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

// Return average patricia trie depth
int averageDepthPatricia(patriciaTrie pt);

// Count word prefix from word
int prefixPatricia(patriciaTrie pt ,char* mot);

// Remove word from hybrid trie
patriciaTrie deletePatricia(patriciaTrie pt ,char* mot );


// Return height's patricia trie
int height(patriciaTrie pt);

#endif




