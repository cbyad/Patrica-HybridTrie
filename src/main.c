#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
#include "../include/hybrid_trie.h"
#include "../include/build_dict.h"
#include "../include/word_list.h"


void parcours(patriciaTrie pt){
    
    if (!isEmptyPatricia(pt)) {
        printf("%s---%d\n",pt->val,pt->isTerminal);
        parcours(pt->child);
        parcours(pt->next);
    }
    
}



int main() {

/* Hybrid test
 
 */
    HTptr my_hybridTrie = NULL;
   char* path = "example/basic";
    // char* path = "/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/dev_algav/dev_algav_trie/dev_algav_trie/algav/example/basic";
    wlist basic = read_dict(path);
    
    for (wlist tmp = basic->next; tmp != basic; tmp = tmp->next)
        my_hybridTrie = insertHT(my_hybridTrie, tmp->word);
    
    // printList(basic);
    
    printf("words: %d\n", countwHT(my_hybridTrie));
    printf("nbNULL: %d\n", nbNULLHT(my_hybridTrie));
     printf("heightHT: %d\n", heightHT(my_hybridTrie));
    
     char* search = "a";
    printf("search %s: %d\n", search, searchHT(my_hybridTrie, search));
    //printf("%d\n", depthAvgHT(my_hybridTrie));
    freeHT(my_hybridTrie);
    
 /* Patricia test
  */
    
    
    
    
    
    patriciaTrie pt = NULL;
    
    for (wlist tmp = basic->next; tmp != basic; tmp = tmp->next)
        pt = insertPatricia(pt, tmp->word);

   // printList(basic);
    
   
    
    printf("result %d\n",searchPatricia(pt, "elle") );
    printf("Height ....%d\n",heightPatricia(pt));
    printf("Null ....%d\n",countNilPatricia(pt));
    printf("nbWords ....%d\n",countWordPatricia(pt));
    
    //parcours(pt);
    
    freePatricia(pt);
    //freePatricia(patricia);
    //freePatricia(tr);
  exit(0);

}
