#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
 
/****************
 * PRIMITIVES
 ****************/

/*On suppose que creation patricia avec "$" pas possible*/

patriciaTrie newPatricia(char* word){

    patriciaTrie pt =(patriciaTrie)malloc(sizeof(struct patricia_node));
    
    pt->child=NULL ;
    pt->next=NULL ;
    
    pt->val = (char*) malloc(sizeof(char)*strlen(word)+2); // +1 pour '$' et +1 pour '\0'
    strcpy(pt->val,word);
    pt->val[strlen(word)]='$';
    pt->val[strlen(word)+1]='\0';
    
    
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
    return (pt==NULL)?true: (bool)(strcmp(pt->val," ")==0 )  ;
}




int getPrefix(char* stringA ,char* stringB){
    int sizeA =strlen(stringA);
    int sizeB= strlen(stringB);
    int i  ;
    
    for (i=0; i<sizeA; i++) {
        if (i==sizeB|| stringA[i]!=stringB[i]) {
            return i;
        }
    }
    return sizeA ;
}



char* getPrefixString(char* stringA ,char* stringB){
    int sizeA =strlen(stringA);
    int sizeB= strlen(stringB);
    int i  ;
    int nSize=1 ;
    char* newString =(char*)malloc(sizeof(char)*nSize);
    newString[0]='a';
    for (i=0; i<sizeA; i++) {
        if (i==sizeB|| stringA[i]!=stringB[i]) {
            
            if (strlen(newString)==1) {
                newString[i]='\0';
                return newString;
            }
            else {
            
                newString=realloc(newString,(++nSize)*sizeof(char));
                newString[i+1]='\0';
                return newString;
            }
            
        }
        newString[i]=stringB[i];
        newString=realloc(newString,(++nSize)*sizeof(char));
    }
    
    newString=realloc(newString,(++nSize)*sizeof(char));
    newString[nSize]='\0';
    return newString ;

}



bool searchPatricia(patriciaTrie pt ,char* mot){

    
   
    if (isEmptyPatricia(pt)) return false ;
    
    int k= getPrefix(mot, pt->val);
    if(k==0) return searchPatricia(pt->next, mot);
    if(k==strlen(mot)) return true ;
    if(k==strlen(pt->val)) return searchPatricia(pt->child,mot+k);
    return false ;

}





// Insert a new word to a Patricia trie
patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  {

    if (isEmptyPatricia(pt)) return newPatricia(word);
    


    return NULL;
}
























