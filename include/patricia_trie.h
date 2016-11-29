#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_
#include <stdbool.h>
#include "word_list.h"


//#define ALPHABET_SIZE 128
#define END_WORD '$'

/*
 le langage c definie de base le caractere '\0' comme caractere de fin de chaine.
 Donc pour eviter une confusion pour la terminaison d'un mot du trie patricia ,
 on choisira un autre caractere '$' pour reelement marqué cette difference.
 
*/

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
patriciaTrie newPatricia(char* word);                                        //ok

// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* mot);                    //ok mais bugger a revoir

//split a node 
void split(patriciaTrie pt, int k);                                         //ok

// Remove a patricia trie from memory
void freePatricia(patriciaTrie t);                                          //ok


//return a boolean
bool isEmptyPatricia(patriciaTrie pt);                                      //ok

/**********************
 * ADVANCES FUNCTIONS
 **********************/

// Search a word
bool searchPatricia(patriciaTrie pt ,char* mot);                           // ok

// Count words in patricia trie
int countWordPatricia(patriciaTrie pt);                                    //ok

// Return a word list from patricia trie
wlist listWords(patriciaTrie pt);

// Count NULL pointers in patricia trie
int countNilPatricia(patriciaTrie pt);                                     //ok

// Return average patricia trie depth
int averageDepthPatricia(patriciaTrie pt);

// Count word prefix from word
int prefixPatricia(patriciaTrie pt ,char* mot);

void join(patriciaTrie pt );
// Remove word from hybrid trie
patriciaTrie deletePatricia(patriciaTrie pt ,char* mot );

// Return height's patricia trie
int heightPatricia(patriciaTrie pt);                                     //ok

//Merge 2 Patricia tries
patriciaTrie mergePatricia(patriciaTrie pt1 ,patriciaTrie pt2);

#endif




