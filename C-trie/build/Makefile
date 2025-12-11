CC = gcc
CFLAGS = -Wall -Wextra -I../include

SRC = ../src/trie.c
DEMO = ../demo/demo_main.c
TEST = ../tests/test_trie.c

all: demo test

demo: $(SRC) $(DEMO)
	$(CC) $(CFLAGS) $(SRC) $(DEMO) -o c_trie_demo

test: $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o test_trie
	./test_trie

clean:
	rm -f c_trie_demo test_trie