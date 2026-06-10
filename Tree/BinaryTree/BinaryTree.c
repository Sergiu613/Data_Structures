#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void traverseInOrder(Node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->value);
        traverseInOrder(root->right);
    }
}

void traversePreOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traversePostOrder(Node* root) {
    if (root != NULL) {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("In-Order traversal: ");
    traverseInOrder(root);
    
    printf("\nPre-Order traversal: ");
    traversePreOrder(root);
    
    printf("\nPost-Order traversal: ");
    traversePostOrder(root);
    printf("\n");

    return 0;
}
