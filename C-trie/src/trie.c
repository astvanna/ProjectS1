#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/trie.h"

bool isempty(struct TrieNode *root) {
    for (int i = 0; i < NUM_CHAR; i++) {
        if (root->children[i]) return false;
    }
    return true;
}

struct TrieNode* createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < NUM_CHAR; ++i) node->children[i] = NULL;
    }
    return node;
}

struct TrieNode *deleteHelper(struct TrieNode *root, const char *key, int depth) {
    if (!root) return NULL;
    if (depth == strlen(key)) {
        if (root->isEndOfWord) root->isEndOfWord = false;
        if (isempty(root)) { free(root); root = NULL; }
        return root;
    }
    int index = key[depth] - 'a';
    if (index >= 0 && index < NUM_CHAR) 
        root->children[index] = deleteHelper(root->children[index], key, depth + 1);
    
    if (isempty(root) && !root->isEndOfWord) { free(root); root = NULL; }
    return root;
}

void deletekey(struct TrieNode *root, const char *key) {
    deleteHelper(root, key, 0);
}

