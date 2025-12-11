#include "../include/trie.h"

int main() {
    TrieNode *root = createNode();
    char buffer[100];
    int choice;

    printf("Loading dictionary.txt ...\n");
    loadDictionary(root, "../dictionary.txt");

    while (1) {
        printf("\n--- C-TRIE DEMO ---\n");
        printf("1. Insert word\n2. Search\n3. Autocomplete\n4. Visualize Trie\n5. Delete word\n6. Exit\n");
        printf("Select: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (choice == 6) break;

        if (choice == 4) {
            visualizeTrie(root);
            continue;
        }

        printf("Enter word/prefix: ");
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        switch (choice) {
            case 1: insert(root, buffer); break;
            case 2: printf(searchWord(root, buffer) ? "Found!\n" : "Not Found.\n"); break;
            case 3: autocomplete(root, buffer); break;
            case 5: root = deletekey(root, buffer); break;
        }
    }

    freeTrie(root);
    return 0;
}
