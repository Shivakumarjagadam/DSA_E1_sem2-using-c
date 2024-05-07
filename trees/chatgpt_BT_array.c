#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }
}

void insertNode(int value, int index) {
    if (tree[index] == -1) {
        tree[index] = value;
    } else {
        if (value < tree[index]) {
            insertNode(value, 2 * index + 1);
        } else {
            insertNode(value, 2 * index + 2);
        }
    }
}

void inorderTraversal(int index) {
    if (tree[index] != -1) {
        inorderTraversal(2 * index + 1);
        printf("%d ", tree[index]);
        inorderTraversal(2 * index + 2);
    }
}

int main() {
    initializeTree();

    int elements[] = {4, 2, 7, 1, 18, 6, 9};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; i++) {
        insertNode(elements[i], 0);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(0);

    return 0;
}