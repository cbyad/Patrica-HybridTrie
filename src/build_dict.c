#include "../include/build_dict.h"

#define SIZE_MAX 30



wlist read_dict(char* path){
    
    wlist myList =NULL ;
    
    char stringContent[SIZE_MAX];
    
    FILE* file=fopen(path,"r");
    
    if (file != NULL)
    {
        
        rewind(file); 
        myList = newList();
       
            while (fgets(stringContent,SIZE_MAX, file) != NULL)
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
