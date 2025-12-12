#include "../include/trie.h"

static TrieNode* makeRoot(TrieNode *root) {
    if (!root) {
        root = createNode();
        if (!root) {
            fprintf(stderr, "Fatal: Failed to allocate new trie root.\n");
            exit(1);
        }
    }
    return root;
}

int main() {
    TrieNode *root = createNode();
    if (!root) {
        fprintf(stderr, "Fatal: Failed to allocate root node.\n");
        return 1;
    }

    printf("Loading dictionary.txt ...\n");
    loadDictionary(root, "../dictionary.txt");

    char buffer[100];
    int choice;

    while (1) {
        printf("\n--- C-TRIE DEMO ---\n");
        printf("1. Insert word\n");
        printf("2. Search word\n");
        printf("3. Autocomplete\n");
        printf("4. Visualize Trie\n");
        printf("5. Delete word\n");
        printf("6. Exit\n");
        printf("Select: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (choice == 6) break;

        if (choice == 4) {
            if (!root) {
                printf("Trie is empty.\n");
            } else {
                visualizeTrie(root);
            }
            continue;
        }

        printf("Enter word/prefix: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        switch (choice) {
            case 1:
                root = makeRoot(root);
                insert(root, buffer);
                break;

            case 2:
                if (!root) {
                    printf("Trie is empty.\n");
                } else {
                    printf(searchWord(root, buffer) ? "Found!\n" : "Not Found.\n");
                }
                break;

            case 3:
                if (!root) {
                    printf("Trie is empty.\n");
                } else {
                    autocomplete(root, buffer);
                }
                break;

            case 5:
                if (!root) {
                    printf("Trie is already empty.\n");
                } else {
                    root = deletekey(root, buffer);

                    if (!root)
                        printf("That deletion emptied the trie. Root reset.\n");
                }
                break;
        }
    }

    freeTrie(root);
    return 0;
}
