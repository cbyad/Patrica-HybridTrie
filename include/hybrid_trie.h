#ifndef _HYBRID_TRIE_
#define _HYBRID_TRIE_

typedef struct hybridT {
  char val;
  struct hybridT* inf;
  struct hybridT* sup;
  struct hybridT* eq;
} *hybridTptr;

#endif