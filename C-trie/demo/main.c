#include "../include/trie.h"

int main() {
    struct TrieNode *root = createNode(); 
    char buffer[100];
    int choice;

    while(1) {
        printf("\n--- C-TRIE DEMO ---\n");
        printf("1. Insert  2. Search  3. Autocomplete  4. Exit\n");
        printf("Select: ");
        
        if (scanf("%d", &choice) != 1) { 
            while(getchar() != '\n'); 
            continue; 
        }
        getchar();

        if (choice == 4) break;

        printf("Enter word: ");
        if (fgets(buffer, 100, stdin)) {
            buffer[strcspn(buffer, "\n")] = 0; 
        }

        if (choice == 1) insert(root, buffer);
        else if (choice == 2) {
            printf(search(root, buffer) ? "Found!\n" : "Not Found.\n");
        }
        else if (choice == 3) {
            printAutocomplete(root, buffer);
        }
    }
    return 0;
}