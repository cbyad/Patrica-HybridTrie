#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
#include "../include/my_functions.h"
/****************
 * PRIMITIVES
 ****************/



patriciaTrie newPatricia(char* word){
    
    if(strcmp(word," ")==0) return NULL;
    patriciaTrie pt =(patriciaTrie)malloc(sizeof(struct patricia_node));
    
    pt->child=NULL ;
    pt->next=NULL ;
    
    pt->val = (char*) malloc(sizeof(char)*strlen(word)+1); //  +1 pour '\0'
    strcpy(pt->val,word);
    pt->val[strlen(word)]='\0';
    pt->isTerminal=false ; //par default

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
    return (pt==NULL)?true: (bool)(strcmp(pt->val," ")==0 )  ;
}


bool searchPatricia(patriciaTrie pt ,char* mot){

    
   
    if (isEmptyPatricia(pt)) return false ;
    
    int k= getPrefix(mot, pt->val);
    if(k==0) return searchPatricia(pt->next, mot);
    if(k==(int)strlen(pt->val) && pt->isTerminal && strlen(pt->val)==strlen(mot)) return true ;
    if(k==(int)strlen(pt->val)) return searchPatricia(pt->child,mot+k);
    return false ;

}





// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  {

    if (isEmptyPatricia(pt)) return newPatricia(word);
    


    return NULL;
}



int countNilPatricia(patriciaTrie pt){
    return (pt==NULL)?1:countNilPatricia(pt->child)+countNilPatricia(pt->next);
}



int heightPatricia(patriciaTrie pt){
    return (isEmptyPatricia(pt))? 0:1+max3(heightPatricia(pt->child),heightPatricia(pt->next),-1);
}

int countWordPatricia(patriciaTrie pt) {
    if(pt == NULL) return 0;
    int isTerminal = pt->isTerminal;
    return isTerminal + countWordPatricia(pt->child) + countWordPatricia(pt->next);
}










