#include "../include/build_dict.h"

#define SIZE_MAX_STRING 30



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
    }
    else
    {
        return NULL ;
    }

}
