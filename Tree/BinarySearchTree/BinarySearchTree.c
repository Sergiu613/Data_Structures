#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

bool search(Node* root, int value) {
    if (root == NULL) return false;
    if (root->value == value) return true;
    if (value < root->value) return search(root->left, value);
    return search(root->right, value);
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* findMaxNode(Node* node) {
    Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // Case 1 & 2: One child or no children
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMinNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int getHeight(Node* node) {
    if (node == NULL) return -1;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void traverseInOrder(Node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->value);
        traverseInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-Order: ");
    traverseInOrder(root);
    printf("\n");

    Node* min = findMinNode(root);
    Node* max = findMaxNode(root);
    printf("Min: %d | Max: %d\n", min->value, max->value);
    printf("Height: %d\n", getHeight(root));

    printf("Deleting 50 (Root node)...\n");
    root = deleteNode(root, 50);
    
    printf("In-Order after deletion: ");
    traverseInOrder(root);
    printf("\n");

    return 0;
}
