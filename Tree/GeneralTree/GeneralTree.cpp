#include <iostream>
#include <vector>
#include <string>

class TreeNode {
public:
    std::string value;
    std::vector<TreeNode*> children;

    TreeNode(std::string val) : value(val) {}
};

class GeneralTree {
private:
    TreeNode* root;

    TreeNode* searchRecursive(TreeNode* current, const std::string& value) {
        if (!current) return nullptr;
        if (current->value == value) return current;

        for (TreeNode* child : current->children) {
            TreeNode* found = searchRecursive(child, value);
            if (found) return found;
        }
        return nullptr;
    }

    void printRecursive(TreeNode* node, int level) const {
        if (!node) return;
        for (int i = 0; i < level; ++i) std::cout << "  ";
        std::cout << "|-- " << node->value << "\n";
        for (TreeNode* child : node->children) {
            printRecursive(child, level + 1);
        }
    }

public:
    GeneralTree(std::string rootValue) {
        root = new TreeNode(rootValue);
    }

    void addChild(const std::string& parentValue, const std::string& childValue) {
        TreeNode* parent = searchRecursive(root, parentValue);
        if (parent) {
            parent->children.push_back(new TreeNode(childValue));
        } else {
            std::cout << "Parent '" << parentValue << "' not found!\n";
        }
    }

    void print() const {
        printRecursive(root, 0);
    }
};

int main() {
    GeneralTree tree("Root");
    tree.addChild("Root", "Folder_A");
    tree.addChild("Root", "Folder_B");
    tree.addChild("Folder_A", "File_A1");
    tree.addChild("Folder_A", "File_A2");
    tree.addChild("Folder_B", "File_B1");

    tree.print();
    return 0;
}
