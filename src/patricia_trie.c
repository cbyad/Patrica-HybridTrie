
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


patriciaTrie insertPatricia(patriciaTrie pt ,char* word)  {
    
    if(isEmptyPatricia(pt)) return newPatricia_aux(newPatricia("\0"), NULL, word);
    if(strlen(word)==0) return pt; //don't insert blank space
    
    if ( strcmp(pt->val,word)==0 && isTerminal(pt->child)) {
        return pt ;
    }
    
    int k = getPrefix(word, pt->val);
    int sizeWord = (int)strlen(word);
    int sizeRoot =(int)strlen(pt->val);
    
    if(k==0) pt->next=insertPatricia(pt->next,word);
    
    else if (sizeWord>sizeRoot) {                                                                       //                 ap | --> apple
        
        if (k==sizeRoot) {
            pt->child=insertPatricia(pt->child, word+k);
        }
        
        else if(k<sizeRoot){                                                                            //                 apT  | -->apple
            split(pt, k);
            pt->child=insertPatricia(pt->child, word+k);
        }
    }
    else if (sizeWord<sizeRoot ) {                                                                      //                  apple | ---> ap
        
        if (k==sizeWord) {
            split(pt, k);
            pt=insertPatricia(pt, pt->val);
        }
        else if (k<sizeWord) {
            split(pt, k);
            pt->child=insertPatricia(pt->child, word+k);
        }
    }
    else if (sizeRoot==sizeWord) {                                                                      //                  balle | ---> bille
        
        if(k==sizeWord && !isTerminal(pt->child)){                                                      //                  balle | ---> balle
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


/*********************
 * ADVANCED FUNCTIONS
 *********************/

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


int nbPrefixPatricia(patriciaTrie pt ,char* word){
    
    if(isEmptyPatricia(pt)) return 0;
    if(*word==0) return countWordPatricia(pt);
    
    int k = getPrefix(pt->val,word);
    if(k==0) return nbPrefixPatricia(pt->next,word);
    if(strcmp(word,pt->val)==0) return countWordPatricia(pt->child);
    
    return nbPrefixPatricia(pt->child, word+k);
}


int averageDepthPatricia(patriciaTrie pt){
    
    int  deph = 0, total = 0, Cdepth = 1;
    averageInside(pt, &deph, &total, Cdepth);
    if(total == 0) return 0.0;
    return deph / total;
    
}

void averageInside(patriciaTrie pt, int * deph, int * total, int Cdepth){
    
    if(isEmptyPatricia(pt)) return;
    (*deph) =(*deph)+ Cdepth;
    (*total)++;
    if(!isEmptyPatricia(pt->child)) averageInside(pt->child, deph, total, Cdepth + 1);
    if(!isEmptyPatricia(pt->next)) averageInside(pt->next, deph, total, Cdepth);
}


patriciaTrie deletePatricia(patriciaTrie pt ,char* mot ){
    if(isEmptyPatricia(pt)) return pt ;
    if(!searchPatricia(pt, mot)) return pt ;
    
    return NULL ;// not completed
}



/*********************
 * COMPLEX FUNCTIONS *
 ********************/


patriciaTrie mergePatricia(patriciaTrie pt1 ,patriciaTrie pt2){
    //printf("1= %s  , 2= %s  \n",pt1->val,pt2->val);
    if(isEmptyPatricia(pt1)) return pt2;
    if(isEmptyPatricia(pt2)) return pt1; 
    
    int k =getPrefix(pt1->val, pt2->val);
    if(k==0) return newPatricia_aux(pt2->child, mergePatricia(pt1, pt2->next), pt2->val);
    
    if(strlen(pt1->val)!=strlen(pt2->val)) return newPatricia_aux(pt1->child, mergePatricia(pt1->next, pt2), pt1->val);
    else
        return newPatricia_aux(mergePatricia(pt1->child, pt2->child), mergePatricia(pt1->next, pt2->next), pt1->val); // pt1->val==pt2->val

}

