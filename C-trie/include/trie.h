#ifndef TRIE_H
#define TRIE_H

#define NUM_CHAR 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[NUM_CHAR];
    bool isEndOfWord;
} TrieNode;

struct TrieNode* createNode();
void deletekey(struct TrieNode *root, const char *key);

void insert(struct TrieNode *root, const char *key);
bool search(struct TrieNode *root, const char *key);
void printAutocomplete(struct TrieNode *root, const char *key);

#endif /* TRIE_H */