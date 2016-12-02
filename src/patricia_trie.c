
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
#include "../include/my_functions.h"
/****************
 * PRIMITIVES
 ****************/


patriciaTrie newPatricia(char* word){
    
    patriciaTrie pt =(patriciaTrie)malloc(sizeof(struct patricia_node));
    
    pt->val = (char*) malloc(sizeof(char)*strlen(word)+1); //  +1 pour '\0'
    strcpy(pt->val,word);
    pt->val[strlen(word)]='\0';
    pt->next=NULL ;
    pt->child=NULL;
    
    return pt ;
}


patriciaTrie newPatricia_aux( patriciaTrie child , patriciaTrie next , char* word){
    
    patriciaTrie pt =(patriciaTrie)malloc(sizeof(struct patricia_node));
    
    pt->val = (char*) malloc(sizeof(char)*strlen(word)+1); //  +1 pour '\0'
    strcpy(pt->val,word);
    pt->val[strlen(word)]='\0';
    pt->child=child ;
    pt->next=next ;
    
    return pt ;
}


bool isTerminal (patriciaTrie pt){
    return strlen(pt->val)==0 ;
}

void freePatricia(patriciaTrie pt){
    
    if (pt==NULL) return ;
    
    free(pt->val);
    freePatricia(pt->next);
    freePatricia(pt->child);
    
    free(pt);
}

bool isEmptyPatricia(patriciaTrie pt){
    return (pt==NULL)  ;
}

bool searchPatricia(patriciaTrie pt ,char* word){
    if (isEmptyPatricia(pt)) return false ;
    
    int result= getPrefix(word, pt->val);
    if(result==0) return searchPatricia(pt->next, word);
    if(result==(int)strlen(word) && isTerminal(pt->child) ) return true ;
    if(result==(int)strlen(pt->val)) return searchPatricia(pt->child,word+result);
    
    return false ;
}


int countNilPatricia(patriciaTrie pt){
    return (pt==NULL)?1:countNilPatricia(pt->child)+countNilPatricia(pt->next);
}


// size is caracterized by size of the longest children
int heightPatricia(patriciaTrie pt){
    
    return isEmptyPatricia(pt)?-1 : max3(1+heightPatricia(pt->child), heightPatricia(pt->next), -1);
}

int countWordPatricia(patriciaTrie pt) {
    
    return (pt == NULL)? 0: (int)isTerminal(pt) + countWordPatricia(pt->child) + countWordPatricia(pt->next);
}


patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  {
    
    if(isEmptyPatricia(pt)) return  newPatricia_aux(newPatricia("\0"), NULL, word);
    if(strlen(word)==0) return pt; //don't insert blank space
    
    if ( strcmp(pt->val,word)==0 && isTerminal(pt->child)) {
        return pt ;
    }
    
    int k = getPrefix(word, pt->val);
    int sizeWord = (int)strlen(word);
    int sizeRoot =(int)strlen(pt->val);
    
    if(k==0) pt->next=insertPatricia(pt->next,word);
    
    else if (sizeWord>sizeRoot) {           // example:                 ap | --> apple
        
        if (k==sizeRoot) {
            pt->child=insertPatricia(pt->child, word+k);  //
        }
        
        else if(k<sizeRoot){       //example                            apT  | -->apple
            split(pt, k);
            pt->child=insertPatricia(pt->child, word+k);
        }
    }
    else if (sizeWord<sizeRoot ) { //example                           apple | ---> ap
        
        if (k==sizeWord) {
            split(pt, k);
            pt=insertPatricia(pt, pt->val);
        }
        else if (k<sizeWord) {
            split(pt, k);
            pt->child=insertPatricia(pt->child, word+k);
        }
    }
    else if (sizeRoot==sizeWord) {
        
        if(k==sizeWord && !isTerminal(pt->child)){
            patriciaTrie p =newPatricia("\0");
            p->next=pt->child;
            pt->child=p ;
            return pt ;
        }
        else if (k<sizeWord) {
            split(pt, k);
            pt->child=insertPatricia(pt->child, word+k);
        }
    }
    return pt ;
}


void split(patriciaTrie pt, int k)
{
    patriciaTrie p = newPatricia(pt->val+k);
    
    p->child=pt->child ;
    pt->child=p ;
    
    char* a = (char*) malloc(sizeof(char)*(k+1));
    strncpy(a,pt->val,k);
    a[k]='\0';
    free(pt->val);
    pt->val = a;
}


int prefixPatricia(patriciaTrie pt ,char* word){
    
    /*
     if(isEmptyPatricia(pt)) return  0 ;
     
     if(*pt->val!=*word) return prefixPatricia(pt->next,word); // k==0
     int k=getPrefix(pt->val, word);
     if(k==strlen(word)){
     return //
     }
     
     */
    return  0 ;
    
    
}




