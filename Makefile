EXEC=algav
SOURCES=main.c patricia_trie.c hybrid_trie.c
OBJECTS=$(SOURCES:.c=.o)
CC=gcc
CFLAGES= -std=gnu99 -Wall -Werror
.PHONY: default clean

default: $(EXEC)

main.o: main.c
patricia_trie.o: patricia_trie.c patricia_trie.h
hybrid_trie.o: hybrid_trie.c hybrid_trie.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGES)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm $(EXEC) $(OBJECTS)