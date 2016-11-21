#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/patricia_trie.h"
#include "../include/hybrid_trie.h"
#include "../include/build_dict.h"
#include "../include/word_list.h"


int main() {
  /*******
  * INIT 
  *******/

  HTptr my_hybridTrie = newEmptyHT();
  // wlist basic = read_dict("../example/basic"); 
  
  /*************
   * TEST
   *************/
  insertHT(my_hybridTrie, "test");
  insertHT(my_hybridTrie, "testament");
  insertHT(my_hybridTrie, "testosterone");
  insertHT(my_hybridTrie, "bon");
  insertHT(my_hybridTrie, "bonjour");

  char* search = "testosterone";

  printf("nbPrefix: %d\n", nbPrefixHT(my_hybridTrie, "te"));
  printf("words: %d\n", countwHT(my_hybridTrie));
  printf("search %s: %d\n", search, searchHT(my_hybridTrie, search));

  freeHT(my_hybridTrie);
  exit(0);
}
