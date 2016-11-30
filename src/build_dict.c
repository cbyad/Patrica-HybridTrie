#include "../include/build_dict.h"


#define SIZE_MAX_STRING 100
#define BUFF_SIZE 100


wlist read_dict(char* path) {
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
    }
    fclose(file);
  }
  return myList;
}


HTptr insertListHT(HTptr hybridTrie, wlist list) {
  for (wlist tmp = list->next; tmp != list; tmp = tmp->next)
    hybridTrie = insertHT(hybridTrie, tmp->word);
  return hybridTrie;
}

HTptr removeListHT(HTptr hybridTrie, wlist list) {
  for (wlist tmp = list->next; tmp != list; tmp = tmp->next)
    hybridTrie = removeHT(hybridTrie, tmp->word);
  return hybridTrie;
}


patriciaTrie insertListPT(patriciaTrie pt , wlist list){

    for (wlist tmp=list->next; tmp!=list; tmp=tmp->next) {
        pt=insertPatricia(pt, tmp->word);
    }
    return pt ;
}



patriciaTrie buildShakespearePT(char* directory){
    
    patriciaTrie pt =NULL ;
    
    /* open the directory */
    DIR *pt_Dir = opendir(directory);
    
    if( !pt_Dir ){
        perror("Error: opendir\n");
        return pt;
    }
    
    struct dirent* dirEnt;
    struct stat buf;

    char filepath[BUFF_SIZE]; /* store path to the current file */

    
    /* read all files in the directoty */
    while ( (dirEnt = readdir(pt_Dir)) ) {
        
        /* don't care about hidden file  */
        if( dirEnt->d_name[0] == '.' )
            continue;
        
        /* setting of filepath */
        memset(filepath, '\0', BUFF_SIZE);
        strcat(filepath, directory);
        strcat(filepath, "/");
        strcat(filepath, dirEnt->d_name);
        
        
        /*  i-node verify regulary of the file before  */
        if( stat(filepath, &buf) == -1){
            perror("Error: stat\n");
            exit(1);
        }
        if( !S_ISREG(buf.st_mode) ){
            continue;
        }
        
        /* insert list from filepath in patricia */
        wlist list = read_dict(filepath);
        pt=insertListPT(pt, list);
       
    }
    
    /* end  ---> close directory */
    if( closedir(pt_Dir) == -1 ){
        perror("Error: closedir\n");
        exit(1);
    }
    
    return pt ;
    
}



HTptr buildShakespeareHT( char* directory){

    HTptr hybrid =NULL ;
    
    /* open the directory */
    DIR *pt_Dir = opendir(directory);
    
    if( !pt_Dir ){
        perror("Error: opendir\n");
        return hybrid;
    }
    
    struct dirent* dirEnt;
    struct stat buf;
    
    char filepath[BUFF_SIZE]; /* store path to the current file */
    
    
    /* read all files in the directoty */
    while ( (dirEnt = readdir(pt_Dir)) ) {
        
        /* don't care about hidden file  */
        if( dirEnt->d_name[0] == '.' )
            continue;
        
        /* setting of filepath */
        memset(filepath, '\0', BUFF_SIZE);
        strcat(filepath, directory);
        strcat(filepath, "/");
        strcat(filepath, dirEnt->d_name);
        
        
        /*  i-node verify regulary of the file before  */
        if( stat(filepath, &buf) == -1){
            perror("Error: stat\n");
            exit(1);
        }
        if( !S_ISREG(buf.st_mode) ){
            continue;
        }
        
        /* insert list from filepath in hybrid */
        wlist list = read_dict(filepath);
       hybrid= insertListHT(hybrid, list);
        
    }
    
    /* end  ---> close directory */
    if( closedir(pt_Dir) == -1 ){
        perror("Error: closedir\n");
        exit(1);
    }
    
    return hybrid ;

}

