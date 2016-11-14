#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/patricia_trie.h"
#include "../include/hybrid_trie.h"

int main() {
  HTptr my_hybridTrie = NULL;
  
  /*************
   * TEST
   *************/
  my_hybridTrie = insertHT(my_hybridTrie, "test");
  insertHT(my_hybridTrie, "testament");
  insertHT(my_hybridTrie, "testosterone");
  insertHT(my_hybridTrie, "bon");
  insertHT(my_hybridTrie, "bonjour");
  removeHT(my_hybridTrie, "testamentj");
  printf("%d\n", nbPrefixHT(my_hybridTrie, "te"));

  freeHT(my_hybridTrie);
  exit(0);
}
