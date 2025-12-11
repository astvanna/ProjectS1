#ifndef TRIE_H
#define TRIE_H

#define NUM_CHAR 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[NUM_CHAR];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode();
bool isempty(TrieNode *root);

void insert(TrieNode *root, const char *key);
TrieNode* deletekey(TrieNode *root, const char *key);

int searchWord(TrieNode *root, const char *word);
int startsWith(TrieNode *root, const char *prefix);

void autocomplete(TrieNode *root, const char *prefix);
void loadDictionary(struct TrieNode *root, const char *filename);
void visualizeTrie(struct TrieNode *root);
void freeTrie(struct TrieNode *root);

#endif /* TRIE_H */