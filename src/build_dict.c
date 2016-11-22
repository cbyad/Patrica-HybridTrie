#include "../include/build_dict.h"

<<<<<<< HEAD
#define SIZE_MAX_STRING 30


//ffrf
wlist read_dict(char* path){
    //frf
    wlist myList =NULL ;
    
    char stringContent[SIZE_MAX_STRING];
    FILE* file=fopen(path,"r");
    
    if (file != NULL)
    {
        
        rewind(file); 
        myList = newList();
       
            while (fgets(stringContent,SIZE_MAX_STRING, file) != NULL)
            {
                addList(myList, stringContent);
            }
    
            fclose(file);
            return myList ;
=======
#define SIZE_MAX_STRING 100

wlist read_dict(char* path){
  wlist myList = NULL ;
  char stringContent[SIZE_MAX_STRING];
  FILE* file=fopen(path,"r");
  myList = newList();
  if (file != NULL) {
    rewind(file);
    while (fgets(stringContent,SIZE_MAX_STRING, file) != NULL) {
      if (stringContent[strlen(stringContent)-1] == '\n')
    stringContent[strlen(stringContent)-1] = 0;
    addList(myList, stringContent);
>>>>>>> c2586fe4e9ebefb70a294c388bd984e02c887972
    }
  fclose(file);
  }
  return myList;
}