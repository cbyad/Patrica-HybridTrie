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
    pt->isTerminal=true ; //par default

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
    
    int result= getPrefix(mot, pt->val);
    if(result==0) return searchPatricia(pt->next, mot);
    if(result==strlen(pt->val) && pt->isTerminal && strlen(pt->val)==strlen(mot)) return true ;
    if(result==strlen(pt->val)) return searchPatricia(pt->child,mot+result);
    return false ;

}


int countNilPatricia(patriciaTrie pt){
    return (pt==NULL)?1:countNilPatricia(pt->child)+countNilPatricia(pt->next);
}


int heightPatricia(patriciaTrie pt){
    return (isEmptyPatricia(pt))? 0:1+max3(heightPatricia(pt->child),heightPatricia(pt->next),-1);
}

int countWordPatricia(patriciaTrie pt) {
    return (pt == NULL)? 0: (pt->isTerminal) + countWordPatricia(pt->child) + countWordPatricia(pt->next);
}



patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  { //??
    
        if (isEmptyPatricia(pt)) return newPatricia(word);
            

        int k =getPrefix(word,pt->val);
        if( k==0 ) pt->next = insertPatricia(pt->next,word);
        else if( k<strlen(word) )
        {
            if( k<strlen(pt->val) ) // cut or not to cut?
                split(pt,k);
            pt->child = insertPatricia(pt->child,word+k);
        }
        return pt;
    
}


void split(patriciaTrie pt, int k) // ???
{
    patriciaTrie p = newPatricia(pt->val+k);
    p->child = pt->child;
    pt->child = p;
    
    char* a = (char*) malloc(k*sizeof(char));
    strcpy(a,pt->val);
    free(pt->val);
    pt->val = a;

}
