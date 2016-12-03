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
/*
     char * directory ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/Shakespeare" ;
     char * directory ="Shakespeare" ;
 */
    char * directory ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/Shakespeare" ;
    HTptr hybrid = NULL;
    patriciaTrie pt =NULL;
    int choix ;
    char* continuer="oui";
    
    printf("-------------------------------[DEVOIR DE PROGRAMMATION TRIE HYBRIDE & PATRICIA]---------------------------------\n");
    
    
    while (strcmp(continuer,"oui")==0)
    {
        
        printf("1. Chargements des Tries & info \n2.Recherche \n3. Insertion \n4.Nbre prefix \n5. Suppresion..\n" );
        printf("Saisir une operation ---> \t");
        scanf("%d",&choix);
        printf("-----------------------------------\n");
        switch(choix)
        {
            case 1:
            {
                pt = buildShakespearePT(directory);
                hybrid=buildShakespeareHT(directory);
                if(!isEmptyHT(hybrid)) {
                
                    printf("-------Hybrid--------\n");
                    printf("NbWords : %d \n",countwHT(hybrid));
                    printf("nbNULL: %d\n", nbNULLHT(hybrid));
                    printf("heightHT: %d\n", heightHT(hybrid));
                    printf("AverageDeph: %d \n",depthAvgHT(hybrid));
                }
                
                if(!isEmptyPatricia(pt)) {
                    printf("-------patricia--------\n");
                    printf("NbWords : %d \n",countWordPatricia(pt));
                    printf("nbNULL: %d\n", countNilPatricia(pt));
                    printf("heightHT: %d\n", heightPatricia(pt));
                    printf("AverageDeph: %d \n",averageDepthPatricia(pt));
                }
            }
                break;
            case 2:
            {
                printf("saisir le mot a rechercher  ----> \t");
                getchar();
                char* mot =saisirChaine();
                printf("result search ---> hybrid: %d\n", searchHT(hybrid, mot));
                printf("result search ---> patricia: %d\n", searchPatricia(pt, mot));
                
            }
                break;
            case 3:
            {
                printf("saisir le mot a inserer  ----> \t");
                getchar();
                char* mot =saisirChaine();
                pt=insertPatricia(pt, mot);
                hybrid=insertHT(hybrid, mot);

            }
                break;
            case 4 :
            {
                printf("saisir le mot  ----> \t");
                getchar();
                char* mot =saisirChaine();
                
                printf("result nombre de mot prefix ---> hybrid: %d\n", nbPrefixHT(hybrid, mot));
                printf("result nombre de mot prefix  ---> patricia: %d\n", prefixPatricia(pt, mot));
            
            }
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            default:
                printf("Commande entree incorrecte" );
                break;
                
        }
        printf("Voulez vous effectuer une autre action sur les structures ? oui||non \n") ;
        getchar();
        continuer=saisirChaine();
        
    }
    
    //-------------------LIBERATION TOTALE DE LA MEMOIRE UTILISEE DANS LES STRUCTURES---------------------
    freeHT(hybrid);
    freePatricia(pt);
    //---------------------------------------------------------------------------------------------------
    
    return 0 ;
}
