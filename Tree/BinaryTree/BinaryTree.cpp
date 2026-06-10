#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree(int rootValue) {
        root = new Node(rootValue);
    }

    void traverseInOrder(Node* node) const {
        if (node) {
            traverseInOrder(node->left);
            std::cout << node->value << " ";
            traverseInOrder(node->right);
        }
    }

    void traversePreOrder(Node* node) const {
        if (node) {
            std::cout << node->value << " ";
            traversePreOrder(node->left);
            traversePreOrder(node->right);
        }
    }

    void traversePostOrder(Node* node) const {
        if (node) {
            traversePostOrder(node->left);
            traversePostOrder(node->right);
            std::cout << node->value << " ";
        }
    }
};

int main() {
    BinaryTree tree(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);

    std::cout << "In-Order: ";
    tree.traverseInOrder(tree.root);
    std::cout << "\nPre-Order: ";
    tree.traversePreOrder(tree.root);
    std::cout << "\nPost-Order: ";
    tree.traversePostOrder(tree.root);
    std::cout << std::endl;

    return 0;
}
