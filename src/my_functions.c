#include "../include/my_functions.h"

int max3(int a, int b, int c) {
  if (a >= b && a >= c)
    return a;
  if(b >= a && b >= c)
    return b;
  return c;
}

int getPrefix(char* stringA ,char* stringB){
    int sizeA =(int)strlen(stringA);
    int sizeB= (int)strlen(stringB);
    int i  ;
    
    for (i=0; i<sizeA; i++) {
        if (i==sizeB|| stringA[i]!=stringB[i]) {
            return i;
        }
    }
    return sizeA ;
}



char* getPrefixString(char* stringA ,char* stringB){
    int sizeA =(int)strlen(stringA);
    int sizeB=(int) strlen(stringB);
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


