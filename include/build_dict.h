#ifndef _BUILD_DICT_
#define _BUILD_DICT_

#include <stdio.h>
#include <errno.h>

#include "../include/hybrid_trie.h"
#include "../include/patricia_trie.h"
#include "../include/word_list.h"



//new ----added for import all files from Shakespeare
#define _XOPEN_SOUCE 700

#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>



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

// Remove words from wlist of hybrid trie
HTptr removeListHT(HTptr hybridTrie, wlist list);

//insert all files from Shakespeare to hybrid
HTptr buildShakespeareHT(char* directory);

/*----------------------------------------------------------*/
// Insert  words from wlist into patricia
patriciaTrie insertListPT(patriciaTrie pt , wlist list);

//insert all files from Shakespeare to patricia
patriciaTrie buildShakespearePT(char* directory);




#endif
