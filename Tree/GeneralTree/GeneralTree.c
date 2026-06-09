#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char value[30];
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
} TreeNode;

TreeNode* createNode(const char* value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->value, value);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

TreeNode* searchNode(TreeNode* root, const char* value) {
    if (root == NULL) return NULL;
    if (strcmp(root->value, value) == 0) return root;

    TreeNode* found = searchNode(root->firstChild, value);
    if (found != NULL) return found;

    return searchNode(root->nextSibling, value);
}

void addChild(TreeNode* root, const char* parentValue, const char* childValue) {
    TreeNode* parent = searchNode(root, parentValue);
    if (parent == NULL) {
        printf("Parent '%s' not found!\n", parentValue);
        return;
    }

    TreeNode* newChild = createNode(childValue);
    if (parent->firstChild == NULL) {
        parent->firstChild = newChild;
    } else {
        TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newChild;
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("|-- %s\n", root->value);

    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int main() {
    TreeNode* root = createNode("Root");
    addChild(root, "Root", "Folder_A");
    addChild(root, "Root", "Folder_B");
    addChild(root, "Folder_A", "File_A1");
    addChild(root, "Folder_A", "File_A2");
    addChild(root, "Folder_B", "File_B1");

    printTree(root, 0);
    return 0;
}
