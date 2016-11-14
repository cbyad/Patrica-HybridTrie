#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_
#include <stdbool.h>
#include "word_list.h"

#define ALPHABET_SIZE 127

typedef struct patricia_node {
    char* val;
    int prefix_count ;
    struct patricia_node* child[ALPHABET_SIZE];
    struct patricia_node* sibling;
} *patriciaTrie;



/****************
 * PRIMITIVES
 ****************/


// Create a node with key as a key
patriciaTrie creerPatriciaVide(char* word);

// Insert a new word to a Patricia trie
patriciaTrie ajouterMot(patriciaTrie t ,char* mot);

// Remove a patricia trie from memory
void libererPT(patriciaTrie t);



/**********************
 * ADVANCES FUNCTIONS
 **********************/

// Search a word
bool recherche(patriciaTrie t ,char* mot);

// Count words in patricia trie
int comptageMot(patriciaTrie t);

// Return a word list from patricia trie
wlist listeMots(patriciaTrie t);

// Count NULL pointers in patricia trie
int comptageNil(patriciaTrie t);

// Return average patricia trie depth
int profondeurMoyenne(patriciaTrie t);

// Count word prefix from word
int prefixe(patriciaTrie t ,char* mot);

// Remove word from hybrid trie
patriciaTrie suppression(patriciaTrie t ,char* mot );


// Return height's patricia trie
int hauteur(patriciaTrie t);




#endif




