#include <iostream>
#include <algorithm>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (!current) return new Node(value);
        if (value < current->value) current->left = insertRecursive(current->left, value);
        else if (value > current->value) current->right = insertRecursive(current->right, value);
        return current;
    }

    Node* findMinRecursive(Node* node) const {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    Node* findMaxRecursive(Node* node) const {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (!current) return current;

        if (value < current->value) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->value) {
            current->right = deleteRecursive(current->right, value);
        } else {
            if (!current->left) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (!current->right) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* temp = findMinRecursive(current->right);
            current->value = temp->value;
            current->right = deleteRecursive(current->right, temp->value);
        }
        return current;
    }

    int getHeightRecursive(Node* node) const {
        if (!node) return -1;
        return std::max(getHeightRecursive(node->left), getHeightRecursive(node->right)) + 1;
    }

    void inOrderRecursive(Node* node) const {
        if (node) {
            inOrderRecursive(node->left);
            std::cout << node->value << " ";
            inOrderRecursive(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) { root = insertRecursive(root, value); }
    void remove(int value) { root = deleteRecursive(root, value); }
    int getMin() const { return findMinRecursive(root)->value; }
    int getMax() const { return findMaxRecursive(root)->value; }
    int getHeight() const { return getHeightRecursive(root); }
    
    void printInOrder() const { 
        inOrderRecursive(root); 
        std::cout << std::endl; 
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50); bst.insert(30); bst.insert(70);
    bst.insert(20); bst.insert(40); bst.insert(60); bst.insert(80);

    std::cout << "BST Data: ";
    bst.printInOrder();

    std::cout << "Height: " << bst.getHeight() << "\n";
    std::cout << "Removing 70...\n";
    bst.remove(70);
    
    std::cout << "BST Post-Removal: ";
    bst.printInOrder();
    return 0;
}
