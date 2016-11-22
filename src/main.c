#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/patricia_trie.h"
#include "../include/hybrid_trie.h"
#include "../include/build_dict.h"
#include "../include/word_list.h"

int main() {
    HTptr my_hybridTrie = NULL;
    char* path = "example/basic";
    wlist basic = read_dict(path);
    for (wlist tmp = basic->next; tmp != basic; tmp = tmp->next)
        my_hybridTrie = insertHT(my_hybridTrie, tmp->word);
    printf("words: %d\n", countwHT(my_hybridTrie));
    printf("nbNULL: %d\n", nbNULLHT(my_hybridTrie));
    printf("heightHT: %d\n", heightHT(my_hybridTrie));
    char* search = "professeur";
    printf("search %s: %d\n", search, searchHT(my_hybridTrie, search));
    freeHT(my_hybridTrie);
    exit(0);
    //enfnf
}
