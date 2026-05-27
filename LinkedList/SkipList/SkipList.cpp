#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

class SkipNode {
public:
    int value;
    std::vector<SkipNode*> next;
    SkipNode(int val, int level) : value(val), next(level + 1, nullptr) {}
};

class SkipList {
private:
    int max_level;
    float p;
    int level;
    SkipNode* header;

    int randomLevel() {
        int lvl = 0;
        while ((float)rand() / RAND_MAX < p && lvl < max_level) lvl++;
        return lvl;
    }

public:
    SkipList(int max_lvl = 4, float prob = 0.5) : max_level(max_lvl), p(prob), level(0) {
        header = new SkipNode(INT_MIN, max_level);
    }

    void insert(int value) {
        std::vector<SkipNode*> update(max_level + 1, nullptr);
        SkipNode* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->value < value) {
                current = current->next[i];
            }
            update[i] = current;
        }
        current = current->next[0];

        if (!current || current->value != value) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            SkipNode* newNode = new SkipNode(value, rlevel);
            for (int i = 0; i <= rlevel; i++) {
                newNode->next[i] = update[i]->next[i];
                update[i]->next[i] = newNode;
            }
        }
    }

    bool search(int value) {
        SkipNode* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->value < value) {
                current = current->next[i];
            }
        }
        current = current->next[0];
        return current && current->value == value;
    }

    void deleteNode(int value) {
        std::vector<SkipNode*> update(max_level + 1, nullptr);
        SkipNode* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->value < value) {
                current = current->next[i];
            }
            update[i] = current;
        }
        current = current->next[0];

        if (current && current->value == value) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->next[i] != current) break;
                update[i]->next[i] = current->next[i];
            }
            delete current;
            while (level > 0 && !header->next[level]) {
                level--;
            }
        }
    }

    void print() {
        std::cout << "\n--- Skip List Levels ---\n";
        for (int i = level; i >= 0; i--) {
            SkipNode* node = header->next[i];
            std::cout << "Level " << i << ": ";
            while (node) {
                std::cout << node->value << " -> ";
                node = node->next[i];
            }
            std::cout << "nullptr\n";
        }
    }
};

int main() {
    SkipList sl;
    sl.insert(3);
    sl.insert(6);
    sl.insert(7);
    sl.print();
    std::cout << "Search 6: " << sl.search(6) << "\n";
    sl.deleteNode(6);
    sl.print();
    return 0;
}
