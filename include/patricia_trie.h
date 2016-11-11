#ifndef _PATRICIA_TRIE_
#define _PATRICIA_TRIE_

struct patricia_node {
  char* val;
  struct patricia_node* child;
  struct patricia_node* sibling;
};
typedef struct patricia_node* patricia_node;

#endif



/*bla bla bla 3444**/
