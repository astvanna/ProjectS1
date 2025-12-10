#ifndef TRIE_H
#define TRIE_H

#define NUM_CHAR 256

#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[NUM_CHAR];
    bool isEndOfWord;
} TrieNode;

struct TrieNode* createNode();

struct TrieNode *deleteHelper(struct TrieNode *root, const char *key, int depth);

void deletekey(struct TrieNode *root, const char *key);


int searchWord(TrieNode *root, const char *word);

int startsWith(TrieNode *root, const char *prefix);

void autocomplete(TrieNode *root, const char *prefix);


#endif /* TRIE_H */