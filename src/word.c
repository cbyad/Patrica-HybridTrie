#include <string.h>
#include "../include/word.h"

char w_head(char* w) {
  if(w == NULL)
    return 0;
  return w[0];
}

char* w_tail(char* w) {
  if(w == NULL)
    return NULL;
  char* ret = malloc(sizeof(char)*(strlen(w)));
  strcpy(ret, w+1);
  return ret;
}