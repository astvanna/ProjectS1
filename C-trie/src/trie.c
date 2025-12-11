#include "../include/trie.h"

/* CORE FUNCTIONS */

TrieNode* createNode() {
    TrieNode *node = malloc(sizeof(TrieNode));
    if (!node) return NULL;

    node->isEndOfWord = false;
    for (int i = 0; i < NUM_CHAR; ++i)
        node->children[i] = NULL;

    return node;
}

bool isempty(TrieNode *root) {
    for (int i = 0; i < NUM_CHAR; ++i)
        if (root->children[i] != NULL)
            return false;
    return true;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *curr = root;

    for (int i = 0; key[i] != '\0'; ++i) {
        if (key[i] < 'a' || key[i] > 'z') continue;

        int index = key[i] - 'a';

        if (!curr->children[index])
            curr->children[index] = createNode();

        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

/* DELETE */

static TrieNode* deleteHelper(TrieNode *root, const char *key, int depth) {
    if (!root) return NULL;

    if (depth == (int)strlen(key)) {
        root->isEndOfWord = false;

        if (isempty(root)) {
            free(root);
            return NULL;
        }
        return root;
    }

    int index = key[depth] - 'a';
    if (index >= 0 && index < NUM_CHAR)
        root->children[index] = deleteHelper(root->children[index], key, depth + 1);

    if (isempty(root) && !root->isEndOfWord) {
        free(root);
        return NULL;
    }

    return root;
}

TrieNode* deletekey(TrieNode *root, const char *key) {
    return deleteHelper(root, key, 0);
}

/* SEARCH */

int searchWord(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; ++i) {
        int index = word[i] - 'a';
        if (index < 0 || index >= NUM_CHAR) return 0;
        if (!curr->children[index]) return 0;
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

int startsWith(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    for (int i = 0; prefix[i] != '\0'; ++i) {
        int index = prefix[i] - 'a';
        if (index < 0 || index >= NUM_CHAR) return 0;
        if (!curr->children[index]) return 0;
        curr = curr->children[index];
    }
    return 1;
}

/* AUTOCOMPLETE DFS */

static void dfsCollect(TrieNode *node, char *buffer, int depth) {
    if (!node) return;

    if (node->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < NUM_CHAR; ++i) {
        if (node->children[i]) {
            buffer[depth] = 'a' + i;
            dfsCollect(node->children[i], buffer, depth + 1);
        }
    }
}

void autocomplete(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;

    for (int i = 0; prefix[i] != '\0'; ++i) {
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

    char buffer[128];
    strcpy(buffer, prefix);

    dfsCollect(curr, buffer, strlen(prefix));
}

/* DICTIONARY LOADING */

void loadDictionary(struct TrieNode *root, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Could not open dictionary: %s\n", filename);
        return;
    }

    char word[128];
    while (fgets(word, sizeof(word), f)) {
        word[strcspn(word, "\n")] = '\0';
        insert(root, word);
    }

    fclose(f);
}

/* TRIE VISUALIZATION */

static void visualizeHelper(TrieNode *node, int depth, char c) {
    for (int i = 0; i < depth; ++i) printf("│  ");

    if (depth > 0)
        printf("├─ '%c'%s\n", c, node->isEndOfWord ? " (word)" : "");
    else
        printf("(root)\n");

    for (int i = 0; i < NUM_CHAR; ++i) {
        if (node->children[i])
            visualizeHelper(node->children[i], depth + 1, 'a' + i);
    }
}

void visualizeTrie(TrieNode *root) {
    visualizeHelper(root, 0, '*');
}

/* FREE MEMORY */

void freeTrie(TrieNode *root) {
    if (!root) return;

    for (int i = 0; i < NUM_CHAR; ++i)
        freeTrie(root->children[i]);

    free(root);
}