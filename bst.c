#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 50

// Struktur untuk Node Linked List
typedef struct ListNode {
    char word[MAX_WORD];
    int line;
    struct ListNode *next;
} ListNode;

// Struktur untuk Node BST
typedef struct BSTNode {
    char letter;
    ListNode *head;
    int count;
    struct BSTNode *left, *right;
} BSTNode;

// Fungsi untuk membuat node baru BST
BSTNode *createBSTNode(char letter) {
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->letter = letter;
    newNode->head = NULL;
    newNode->count = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menambah kata ke Linked List
void insertLinkedList(BSTNode *root, char *word, int line) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    strcpy(newNode->word, word);
    newNode->line = line;
    newNode->next = root->head;
    root->head = newNode;
    root->count++;
}

// Fungsi untuk menambah node ke BST
BSTNode *insertBST(BSTNode *root, char *word, int line) {
    char letter = word[0];
    if (root == NULL) {
        root = createBSTNode(letter);
        insertLinkedList(root, word, line);
    } else if (letter < root->letter) {
        root->left = insertBST(root->left, word, line);
    } else if (letter > root->letter) {
        root->right = insertBST(root->right, word, line);
    } else {
        insertLinkedList(root, word, line);
    }
    return root;
}

// Fungsi untuk menampilkan kata berdasarkan huruf pertama
void displayWords(BSTNode *root, char letter) {
    if (root == NULL) return;
    if (letter < root->letter) displayWords(root->left, letter);
    else if (letter > root->letter) displayWords(root->right, letter);
    else {
        printf("%c ", letter);
        ListNode *temp = root->head;
        int count = 0;
        while (temp && count < 5) {
            printf("%s:%d, ", temp->word, temp->line);
            temp = temp->next;
            count++;
        }
        printf("(%d)\n", root->count);
    }
}

// Fungsi untuk menampilkan statistik kata
void displayStatistics(BSTNode *root) {
    if (root == NULL) return;
    displayStatistics(root->left);
    printf("%c %d\n", root->letter, root->count);
    displayStatistics(root->right);
}

// Fungsi untuk membebaskan memori
void freeMemory(BSTNode *root) {
    if (root == NULL) return;
    freeMemory(root->left);
    freeMemory(root->right);
    ListNode *temp;
    while (root->head) {
        temp = root->head;
        root->head = root->head->next;
        free(temp);
    }
    free(root);
}

int main() {
    BSTNode *root = NULL;
    FILE *file = fopen("dbterms.txt", "r");
    if (!file) {
        printf("Gagal membuka file!\n");
        return 1;
    }
    
    char word[MAX_WORD];
    int line = 1;
    while (fscanf(file, "%s", word) != EOF) {
        root = insertBST(root, word, line++);
    }
    fclose(file);
    
    int choice;
    char letter;
    while (1) {
        printf("\nMenu Pilihan: ");
        printf("\n1) Menampilkan kata-kata sesuai huruf pertama");
        printf("\n2) Menampilkan statistik kata");
        printf("\n3) Selesai (free memory)");
        printf("\nPilihan Anda: ");
        scanf(" %d", &choice);
        
        if (choice == 1) {
            printf("Huruf: ");
            scanf(" %c", &letter);
            displayWords(root, letter);
        } else if (choice == 2) {
            displayStatistics(root);
        } else if (choice == 3) {
            freeMemory(root);
            printf("Memori dibebaskan. Program selesai.\n");
            break;
        } else {
            printf("Pilihan anda tidak valid!\n");
        }
    }
    return 0;
}
