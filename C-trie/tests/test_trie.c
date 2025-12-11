#include "../include/trie.h"
#include <assert.h>

int main() {
    TrieNode *root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "apt");
    insert(root, "cat");

    assert(searchWord(root, "apple") == 1);
    assert(searchWord(root, "app") == 1);
    assert(searchWord(root, "ap") == 0);
    assert(startsWith(root, "ap") == 1);
    assert(startsWith(root, "c") == 1);
    assert(startsWith(root, "dog") == 0);

    root = deletekey(root, "app");
    assert(searchWord(root, "app") == 0);
    assert(searchWord(root, "apple") == 1);

    root = deletekey(root, "apple");
    root = deletekey(root, "apt");
    root = deletekey(root, "cat");

    assert(root == NULL);

    printf("All tests passed!\n");
    return 0;
}
