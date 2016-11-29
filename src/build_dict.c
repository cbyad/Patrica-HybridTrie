#include "../include/build_dict.h"


#define SIZE_MAX_STRING 100

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