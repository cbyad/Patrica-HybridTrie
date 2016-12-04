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
patriciaTrie newpatricia_aux( patriciaTrie child , patriciaTrie next , char* word); //ok

bool isTerminal(patriciaTrie pt);                                          //ok

// Create a node with key as a key
patriciaTrie newPatricia(char* word);                                       //ok

// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* mot);                    //ok

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



void averageInside(patriciaTrie pt, int * deph, int * total, int Cdepth); //useful for computing averagedepth       //ok
// Return average patricia trie depth
int averageDepthPatricia(patriciaTrie pt);                                  //ok

// Count word prefix from word
int nbPrefixPatricia(patriciaTrie pt ,char* mot);                            //ok

void join(patriciaTrie pt );
// Remove word from hybrid trie
patriciaTrie deletePatricia(patriciaTrie pt ,char* mot );

// Return height's patricia trie
int heightPatricia(patriciaTrie pt);                                     //ok

//Merge 2 Patricia tries
patriciaTrie mergePatricia(patriciaTrie pt1 ,patriciaTrie pt2);             //ok mais a revoir 


//patricia trie to hybrid
HTptr patriciaToHybrid(patriciaTrie pt);

/* hybrid to patricia */
patriciaTrie hybrid2patricia(HTptr hybridTrie);


#endif




