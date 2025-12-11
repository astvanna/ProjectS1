#include "../include/trie.h"

bool isempty(struct TrieNode *root) {
    for (int i = 0; i < NUM_CHAR; ++i) {
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

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *curr = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = createNode();
        curr = curr->children[index];
    }

    curr->isEndOfWord = true;
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

int searchWord(TrieNode *root, const char *word) {
    TrieNode *curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (index < 0 || index >= NUM_CHAR)
            return 0;
        if (!curr->children[index])
            return 0;

        curr = curr->children[index];
    }

    return curr->isEndOfWord;
}

int startsWith(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (index < 0 || index >= NUM_CHAR)
            return 0;
        if (!curr->children[index])
            return 0;

        curr = curr->children[index];
    }

    return 1;
}

static void dfsCollect(TrieNode *node, char *buffer, int depth) {
    if (!node) return;

    if (node->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < NUM_CHAR; i++) {
        if (node->children[i]) {
            buffer[depth] = 'a' + i;
            dfsCollect(node->children[i], buffer, depth + 1);
        }
    }
}

void autocomplete(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (index < 0 || index >= NUM_CHAR) {
            printf("Invalid prefix.\n");
            return;
        }
        if (!curr->children[index]) {
            printf("No suggestions.\n");
            return;
        }

        curr = curr->children[index];
    }

    char buffer[256];
    strcpy(buffer, prefix);

    dfsCollect(curr, buffer, strlen(prefix));
}


