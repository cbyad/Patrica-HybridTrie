#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
 
/****************
 * PRIMITIVES
 ****************/


patriciaTrie newPatricia(char* word){

    patriciaTrie pt =(patriciaTrie)malloc(sizeof(struct patricia_node));
    
    pt->child=NULL ;
    pt->next=NULL ;
    
    pt->val = (char*) malloc(sizeof(char)*strlen(word)+1);
    strcpy(pt->val,word);
    pt->val[strlen(word)]='\0';
    
    pt->isTerminal=true ; 

    return pt ;
}


void freePatricia(patriciaTrie pt){

    if (pt==NULL) return ;
    
            free(pt->val);
            freePatricia(pt->next);
            freePatricia(pt->child);
    
    free(pt);
}



bool isEmptyPatricia(patriciaTrie pt){
    return (pt==NULL)?true: (bool)(strcmp(pt->val," ")==0)  ;
}





// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  {

    if (isEmptyPatricia(pt)) return newPatricia(word);
    


    return NULL;
}
























