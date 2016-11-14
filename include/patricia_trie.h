#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_
#include <stdbool.h>
#include "word_list.h"

struct patricia_node {
  char* val;
  struct patricia_node* child;
  struct patricia_node* sibling;
};
typedef struct patricia_node* patricia_node;


/****************
 * PRIMITIVES
 ****************/


// Create a node with key as a key
patricia_node creerPatriciaVide(char* word);

// Insert a new word to a Patricia trie
patricia_node ajouterMot(patricia_node t ,char* mot);

// Remove a patricia trie from memory
void libererPT(patricia_node t);



/**********************
 * ADVANCES FUNCTIONS
 **********************/

// Search a word
bool recherche(patricia_node t ,char* mot);

// Count words in patricia trie
int comptageMot(patricia_node t);

// Return a word list from patricia trie
wlist listeMots(patricia_node t);

// Count NULL pointers in patricia trie
int comptageNil(patricia_node t);

// Return average patricia trie depth
int profondeurMoyenne(patricia_node t);

// Count word prefix from word
int prefixe(patricia_node t ,char* mot);

// Remove word from hybrid trie
patricia_node suppression(patricia_node t ,char* mot );


// Return height's patricia trie
int hauteur(patricia_node t);




#endif




