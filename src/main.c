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
/*
int main(){

  // char * directory ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/Shakespeare" ;
  char * directory ="Shakespeare";

  // char* path = "example/test";

  // wlist basic = read_dict(path);
  // HTptr hybrid = NULL;
  // hybrid = insertListHT(hybrid, basic);
  // parcoursHT(hybrid);

  // if(!isEmptyHT(hybrid)) {
  //   printf("-------Hybrid--------\n");
  //   printf("NbWords : %d \n",countwHT(hybrid));
  //   printf("nbNULL: %d\n", nbNULLHT(hybrid));
  //   printf("heightHT: %d\n", heightHT(hybrid));
  //   printf("AverageDeph: %d \n",depthAvgHT(hybrid));
  //   printf("Prefix: %d\n", nbPrefixHT(hybrid, "tes"));
  // }

    HTptr hybrid = NULL;
    patriciaTrie pt =NULL;
    int choix ;
    bool continuer=true;
    
    printf("-------------------------------[DEVOIR DE PROGRAMMATION TRIE HYBRIDE & PATRICIA]---------------------------------\n");

    
    while (continuer)
    {
        
        printf("1. Chargements des Tries & info \n2. Recherche \n3. Insertion\n4. Nombre prefix\n5. Suppression\n0. Quitter\n" );
        printf("Saisir une opération ---> \t");
        if (scanf("%d",&choix) == EOF) {
          perror("scanf");
          return errno;
        }
        printf("-----------------------------------\n");
        switch(choix)
        {
            case 0:
                continuer = false;
                break;
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
                printf("saisir le mot à rechercher  ----> \t");
                getchar();
                char* mot =saisirChaine();
                printf("Résultat recherche ---> hybrid: %d\n", searchHT(hybrid, mot));
                printf("Résultat recherche ---> patricia: %d\n", searchPatricia(pt, mot));
                
            }
                break;
            case 3:
            {
                printf("Saisir le mot à insérer  ----> \t");
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
                // printf("result nombre de mot prefix  ---> patricia: %d\n", prefixPatricia(pt, mot));
            
            }
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            default:
                printf("Commande incorrecte" );
                break;
                
        }
    }
    
    // -------------------LIBERATION TOTALE DE LA MEMOIRE UTILISEE DANS LES STRUCTURES---------------------
    freeHT(hybrid);
    freePatricia(pt);
    // ---------------------------------------------------------------------------------------------------

    return 0 ;
}
*/

/*
int main(){
    

    char* path = "/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/dev_algav/dev_algav_trie/dev_algav_trie/algav/example/basic";
    
    wlist basic = read_dict(path);
    HTptr hybrid = NULL;
    hybrid = insertListHT(hybrid, basic);
    patriciaTrie pt = NULL ;
    pt=insertListPT(pt, basic);
    
    if(!isEmptyHT(hybrid)) {
        
        parcoursHT(hybrid);
        printf("-------Hybrid--------\n");
        printf("NbWords : %d \n",countwHT(hybrid));
        printf("nbNULL: %d\n", nbNULLHT(hybrid));
        printf("heightHT: %d\n", heightHT(hybrid));
        printf("AverageDeph: %d \n",depthAvgHT(hybrid));
        printf("result nombre de mot prefix ---> hybrid: %d\n", nbPrefixHT(hybrid, "ballo"));
        
    }
    
    if(!isEmptyPatricia(pt)) {
        printf("-------patricia--------\n");
        printf("NbWords : %d \n",countWordPatricia(pt));
        printf("nbNULL: %d\n", countNilPatricia(pt));
        printf("heightHT: %d\n", heightPatricia(pt));
        printf("AverageDeph: %d \n",averageDepthPatricia(pt));
        printf("result nombre de mot prefix  ---> patricia: %d\n", prefixPatricia(pt, "ballon"));

    }
    
    
    freePatricia(pt);
    freeHT(hybrid);
    
    

    return  0;
    
}
*/



int main(){
    
    
    
    
    
    char* path = "/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/dev_algav/dev_algav_trie/dev_algav_trie/algav/example/basic";
    
    wlist basic = read_dict(path);
    
    patriciaTrie pt1 = NULL ;
    pt1=insertListPT(pt1, basic);
    patriciaTrie pt2 = NULL ;
   pt2=insertListPT(pt2, basic);
  pt2=insertPatricia(pt2, "dactylographies");
    pt2=insertPatricia(pt2, "genre");
     pt2=insertPatricia(pt2, "dactylo");
  //  pt2=insertPatricia(pt2, "a");
    
    
    
    
    
    patriciaTrie k=NULL ;
    if(!isEmptyPatricia(pt1)) {
        printf("-------patricia--------\n");
        printf("NbWords : %d \n",countWordPatricia(pt1));
        printf("nbNULL: %d\n", countNilPatricia(pt1));
        printf("heightHT: %d\n", heightPatricia(pt1));
        printf("AverageDeph: %d \n",averageDepthPatricia(pt1));
        printf("Search: %d \n",searchPatricia(pt1,""));
        printf("result nombre de mot prefix  ---> patricia: %d\n", nbPrefixPatricia(pt1, "dactylo"));
        
        
        
    }
    
    if(!isEmptyPatricia(pt2)) {
        printf("-------patricia--------\n");
        printf("NbWords : %d \n",countWordPatricia(pt2));
        printf("nbNULL: %d\n", countNilPatricia(pt2));
        printf("heightHT: %d\n", heightPatricia(pt2));
        printf("AverageDeph: %d \n",averageDepthPatricia(pt2));
        printf("Search: %d \n",searchPatricia(pt2,"ZOK"));
        printf("result nombre de mot prefix  ---> patricia: %d\n", nbPrefixPatricia(pt2, "dactylo"));
        
    }
    
    k=mergePatricia(pt1, pt2);
    if(!isEmptyPatricia(k)) {
        printf("-------patricia fusion--------\n");
        printf("NbWords : %d \n",countWordPatricia(k));
        printf("nbNULL: %d\n", countNilPatricia(k));
        printf("heightHT: %d\n", heightPatricia(k));
        printf("AverageDeph: %d \n",averageDepthPatricia(k));
        printf("Search: %d \n",searchPatricia(k,"ballon"));
          printf("Search: %d \n",searchPatricia(k,"dactylographies"));
         
        
        printf("result nombre de mot prefix  ---> patricia: %d\n", nbPrefixPatricia(k, "dactylo"));
        parcours(k);
        
    }
    
    
    freePatricia(pt1);
    freePatricia(pt2);
   // freePatricia(k);
    
    
    
    return  0;
    
}

 
