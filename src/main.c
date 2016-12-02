#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
#include "../include/hybrid_trie.h"
#include "../include/build_dict.h"
#include "../include/word_list.h"


void parcours(patriciaTrie pt){
    
    if (!isEmptyPatricia(pt)) {
        printf("%s---%d\n",pt->val,isTerminal(pt));
        parcours(pt->child);
        parcours(pt->next);
    }
    
}

void dispHT(HTptr pt) {
  if (pt == NULL)
    printf("NULL");
  else
    printf("%c(%d)", pt->key, pt->isKey);
}

void parcoursHT(HTptr pt) {
  if (pt == NULL)
    return;
  printf("KEY: ");
  dispHT(pt);
  printf("\nINF: ");
  dispHT(pt->inf);
  printf("\nSUP: ");
  dispHT(pt->sup);
  printf("\nEQ: ");
  dispHT(pt->eq);
  printf("\n\n");
  parcoursHT(pt->inf);
  parcoursHT(pt->eq);
  parcoursHT(pt->sup);
}

int main(){

     char * directory ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/Shakespeare" ;
    // char * directory ="Shakespeare" ;
  // char* path = "example/basic";
    
   // wlist basic = read_dict(path);
    
    //HTptr hybrid = NULL;
   // hybrid = insertListHT(hybrid, basic);
    
    // parcoursHT(hybrid);
     HTptr hybrid =buildShakespeareHT(directory);
    
   // wlist tmp = wordListHT(hybrid);
   // printList(tmp);
    if(!isEmptyHT(hybrid)) {
        
        printf("NbWords : %d \n",countwHT(hybrid));
        printf("nbNULL: %d\n", nbNULLHT(hybrid));
        printf("heightHT: %d\n", heightHT(hybrid));
        printf("search: %d\n", searchHT(hybrid, "enter"));
        
    
    }
    
     printf("--------------\n");
     patriciaTrie pt = buildShakespearePT(directory);
    
    
     if(!isEmptyPatricia(pt)) {
        
            printf("NbWords : %d \n",countWordPatricia(pt));
            printf("nbNULL: %d\n", countNilPatricia(pt));
            printf("heightHT: %d\n", heightPatricia(pt));
            printf("search: %d\n", searchPatricia(pt, "enter"));
        
        
        }
    
    
    
    freeHT(hybrid);
     freePatricia(pt);
    return 0 ;
}
