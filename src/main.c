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

    char * directory ="Shakespeare" ;
    char* basic = "example";
    
    char** repertoireChargement=(char**)malloc(2*sizeof(char*));
    repertoireChargement[0]=basic;
    repertoireChargement[1]=directory;
    
    HTptr hybrid = NULL;
    patriciaTrie pt =NULL;
    patriciaTrie fusion =NULL ;
    int choix ;
    bool continuer=true;
    
    printf("-------------------------------[DEVOIR DE PROGRAMMATION TRIE HYBRIDE & PATRICIA]---------------------------------\n");

    while (continuer)
    {
        printf("1.Chargements des Tries & info \n2.Recherche \n3. Insertion\n4.Nombre prefix \n5.Suppression \n6.Ordre alphabetique \n7.Fusion de patricia   \n8.profondeur moyenne \n9.Nb null \n0.Quitter\n" );
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
                clock_t beg1 , end1 ;
                clock_t beg2, end2 ;

                printf("-------------Recherche ------------\n");
                printf("saisir le mot à rechercher  ----> \t");
                getchar();
                char* mot =saisirChaine();
                beg1=clock();
                printf("Résultat recherche ---> hybrid: %d\n", searchHT(hybrid, mot));
                end1=clock();
                printf("time used for searching in Hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock();
                printf("Résultat recherche ---> patricia: %d\n", searchPatricia(pt, mot));
                end2=clock();
                printf("time used for searching in patricia --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);
            }
                break;
            case 3:
            {
                clock_t beg1 , end1 ;
                clock_t beg2, end2 ;

                printf("-------------Insertion ------------\n");
                printf("Saisir le mot à insérer  ----> \t");
                getchar();
                char* mot =saisirChaine();
                beg1=clock();
                pt=insertPatricia(pt, mot);
                end1=clock();
                printf("time used for inserting in patricia --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock() ;
                hybrid=insertHT(hybrid, mot);
                end2=clock();
                printf("time used for inserting in hybrid --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);
                
            }
                break;
            case 4 :
            {
                clock_t beg1 , end1 ;
                clock_t beg2, end2 ;

                printf("-------------Prefix ------------\n");
                printf("saisir le mot  ----> \t");
                getchar();
                char* mot =saisirChaine();
                beg1=clock() ;
                printf("result nombre de mot prefix ---> hybrid: %d\n", nbPrefixHT(hybrid, mot));
                end1=clock();
                printf("time used for counting prefix in hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock() ;
                printf("result nombre de mot prefix  ---> patricia: %d\n", nbPrefixPatricia(pt, mot));
                end2=clock();
                printf("time used for counting in patricia --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);
            
            }
                break;
            case 5:
            {
                clock_t end1 ,beg1 ;
                printf("-------------Suppression ------------\n");
                printf("saisir le mot à supprimer  ----> \t");
                getchar();
                char* mot =saisirChaine();
                beg1=clock() ;
                hybrid=removeHT(hybrid,mot);
                end1=clock();
                printf("time used for removing in hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
            }
                break;
            case 6:
            {
                clock_t beg1 ,end1 ,beg2,end2 ;
                printf("-------------affichage dans l'ordre Alphabetique ------------\n");
                printf("-------hybride----\n");
                
                beg1=clock();
                printList(wordListHT(hybrid));
                end1=clock();
                printf("time used for printing list---  hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock();
                printf("-------patricia---- \n");
                printList(listWords(pt));
                end2=clock();
                
                printf("time used for printing list--- patricia --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);
            }
                break;
            
                case 7:
            {
                printf("-------------Fusion patricia ------------\n");
                printf("-------patricia----\n");
                clock_t beg , end ;
                patriciaTrie aux = buildShakespearePT(repertoireChargement[0]);
                beg=clock();
                fusion=mergePatricia(pt,aux);
                end=clock();
                printf("time used for merging  patricia --> %f seconds\n",(float)(end-beg)/CLOCKS_PER_SEC);
                if(!isEmptyPatricia(fusion)) {
               
                    printf("NbWords : %d \n",countWordPatricia(fusion));
                    printf("nbNULL: %d\n", countNilPatricia(fusion));
                    printf("heightPT: %d\n", heightPatricia(fusion));
                    printf("AverageDeph: %d \n",averageDepthPatricia(fusion));
                }

        
            }
            break;
                
            case 8:
            {
                clock_t beg1 ,end1 ,beg2,end2 ;
                printf("-------------Profondeur Moyenne ------------\n");
        
                beg1=clock();
                printf("AverageDeph: %d \n",depthAvgHT(hybrid));
                end1=clock();
                printf("time used for  DepthAverage --- hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock();
                printf("AverageDeph: %d \n",averageDepthPatricia(pt));
                end2=clock();
                 printf("time used for DepthAverage --- patricia --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);
                
            }
                break;
                
            case 9:
            {
                clock_t beg1 ,end1 ,beg2,end2 ;
                printf("-------------Nombre Null ------------\n");
                
                beg1=clock();
                printf("NbNUll: %d \n",nbNULLHT(hybrid));
                end1=clock();
                printf("time used for  counting NbNull --- hybrid --> %f seconds\n",(float)(end1-beg1)/CLOCKS_PER_SEC);
                
                beg2=clock();
                printf("NbNull: %d \n",countNilPatricia(pt));
                end2=clock();
                printf("time used for counting NbNull --- patricia --> %f seconds\n",(float)(end2-beg2)/CLOCKS_PER_SEC);

            }
                break;

            default:
                printf("Commande incorrecte" );
                break;
        }
    }
    
    // -------------------LIBERATION TOTALE DE LA MEMOIRE UTILISEE DANS LES STRUCTURES--------------------
    freeHT(hybrid);
    freePatricia(pt);
    // ---------------------------------------------------------------------------------------------------
    return 0 ;
}
