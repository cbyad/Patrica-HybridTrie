#ifndef _BUILD_DICT_
#define _BUILD_DICT_

#include <stdio.h>
#include <errno.h>

#include "../include/hybrid_trie.h"
#include "../include/patricia_trie.h"
#include "../include/word_list.h"

#define BUF_SIZE 100

/**************************
 * Text file conataining
 * word must separate each
 * words by a new line
 **************************/

// Return word list from text file path
wlist read_dict(char* path);

// Insert words from wlist into hybrid trie
HTptr insertListHT(HTptr hybridTrie, wlist list);

<<<<<<< HEAD
//efe
=======
>>>>>>> c2586fe4e9ebefb70a294c388bd984e02c887972
//insert  words from wlist into patricia
patriciaTrie insertListPT(patriciaTrie pt , wlist list);
//r43r4
#endif
