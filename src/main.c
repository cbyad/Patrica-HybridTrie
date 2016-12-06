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

void displayHybrid_aux(HTptr hybrid,FILE* p){
    static int i= 0;
    if (p != NULL) {
       
        if (hybrid==NULL) {
            
            return ;
        }
        
        else{
            ++i;
            if(hybrid->inf==NULL){  fprintf(p, "%c_%d -> NULL_%d  \n",hybrid->key,i-1,i-1);  }
            
            else
            {
                
                fprintf(p, "%c_%d -> %c_%d \n",hybrid->key,i,hybrid->inf->key,i-1);

            }
                
                i++;
                if(hybrid->eq==NULL){fprintf(p, "%c_%d -> NULL_%d  \n",hybrid->key,i-2,i-2);}
            
                else{
               
                    fprintf(p, "%c_%d -> %c_%d \n",hybrid->key,i-2,hybrid->eq->key,i);
                
                }
            
                    i++;
                    if(hybrid->sup==NULL){fprintf(p, "%c_%d -> NULL_%d  \n",hybrid->key,i-3,i-3);}
            
                    else{
                    
                        fprintf(p, "%c_%d -> %c_%d \n",hybrid->key,i-3,hybrid->sup->key,i);

                    }
                
                    displayHybrid_aux(hybrid->inf,p);
                    displayHybrid_aux(hybrid->eq, p);
                    displayHybrid_aux(hybrid->sup, p);
        }
     
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

int main(int argc , char* argv[]){

    char * directory ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/Shakespeare" ;
    char* basic = "/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/dev_algav/dev_algav_trie/dev_algav_trie/algav/example";
    
    char** repertoireChargement=(char**)malloc(2*sizeof(char*));
    repertoireChargement[0]=basic;
    repertoireChargement[1]=directory;
    
  //char * directory ="Shakespeare";
  // char* path = "example/test";

    HTptr hybrid = NULL;
    patriciaTrie pt =NULL;
    patriciaTrie fusion =NULL ;
    int choix ;
    bool continuer=true;
    
    printf("-------------------------------[DEVOIR DE PROGRAMMATION TRIE HYBRIDE & PATRICIA]---------------------------------\n");

    
    while (continuer)
    {

        printf("1.Chargements des Tries & info \n2.Recherche \n3. Insertion\n4.Nombre prefix \n5.Suppression \n6.Ordre alphabetique \n7.Fusion de patricia   \n8.Afficher    \n0.Quitter\n" );
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
                printf("-------------Construction des tries ------------\n");
                printf("Repertoire a charger --------> 1.basic   2.Shakespeare  \t ");
                int ChoixRepertoire ;
                scanf("%d",&ChoixRepertoire);
                
                pt = buildShakespearePT(repertoireChargement[ChoixRepertoire-1]);
                hybrid=buildShakespeareHT(repertoireChargement[ChoixRepertoire-1]);
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
                    printf("heightPT: %d\n", heightPatricia(pt));
                    printf("AverageDeph: %d \n",averageDepthPatricia(pt));
                }
            }
                break;
            case 2:
            {
                printf("-------------Recherche ------------\n");
                printf("saisir le mot à rechercher  ----> \t");
                getchar();
                char* mot =saisirChaine();
                printf("Résultat recherche ---> hybrid: %d\n", searchHT(hybrid, mot));
                printf("Résultat recherche ---> patricia: %d\n", searchPatricia(pt, mot));
            }
                break;
            case 3:
            {
                printf("-------------Insertion ------------\n");
                printf("Saisir le mot à insérer  ----> \t");
                getchar();
                char* mot =saisirChaine();
                pt=insertPatricia(pt, mot);
                hybrid=insertHT(hybrid, mot);

            }
                break;
            case 4 :
            {
                printf("-------------Prefix ------------\n");
                printf("saisir le mot  ----> \t");
                getchar();
                char* mot =saisirChaine();
                
                printf("result nombre de mot prefix ---> hybrid: %d\n", nbPrefixHT(hybrid, mot));
                printf("result nombre de mot prefix  ---> patricia: %d\n", nbPrefixPatricia(pt, mot));
            
            }
                break;
            case 5:
            {
                printf("-------------Suppression ------------\n");
                printf("saisir le mot à supprimer  ----> \t");
                getchar();
                char* mot =saisirChaine();
                hybrid=removeHT(hybrid,mot);
            }
                break;
            case 6:
            {
                printf("-------------affichage dans l'ordre Alphabetique ------------\n");
                printf("-------hybride----\n");
                printList(wordListHT(hybrid));
 
                printf("-------patricia---- \n");
                printList(listWords(pt));
            }
                break;
            
                case 7:
            {
                printf("-------------Fusion patricia ------------\n");
                printf("-------patricia----\n");
                fusion=mergePatricia(pt,pt);
            }
            break;
                
            case 8:
            {
                printf("-------------Affichage ------------\n");
                //printf("-------patricia----\n");
                char* path ="/Users/cb_mac/Desktop/UPMC/SEMESTRE1/ALGAV/dev/dev_algav/dev_algav_trie/dev_algav_trie/algav/hybrid.dot";
                
                FILE* file =fopen(path,"w");
                fprintf(file,"digraph d { \n") ;
                displayHybrid_aux(hybrid, file);
                //fseek(file, 0, SEEK_END);
                fprintf(file,"} \n") ;
                
                
            }
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
