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

  HTptr my_hybridTrie = NULL;
  
  /*****************
   * TEST hybridHT *
   ****************/
  // my_hybridTrie = insertHT(my_hybridTrie, "test");
  // insertHT(my_hybridTrie, "tests");
  // insertHT(my_hybridTrie, "testosterone");
  // insertHT(my_hybridTrie, "bon");
  // insertHT(my_hybridTrie, "bonjour");

  // char* search = "testosterone";



  /**************
   * TEST WLIST *
   *************/
  char* path = "example/basic";
  wlist basic = read_dict(path);
  // printList(basic);

  wlist tmp;
  for (tmp = basic->next; tmp != basic; tmp = tmp->next)
    my_hybridTrie = insertHT(my_hybridTrie, tmp->word);

  // printf("nbPrefix: %d\n", nbPrefixHT(my_hybridTrie, "te"));
  printf("words: %d\n", countwHT(my_hybridTrie));
  // printf("search %s: %d\n", search, searchHT(my_hybridTrie, search));
  printf("nbNULL: %d\n", nbNULLHT(my_hybridTrie));
  printf("heightHT: %d\n", heightHT(my_hybridTrie));
  freeHT(my_hybridTrie);

  exit(0);
}
