#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 4

typedef struct SkipNode {
    int value;
    struct SkipNode** next;
} SkipNode;

typedef struct SkipList {
    int level;
    SkipNode* header;
} SkipList;

SkipNode* createNode(int value, int level) {
    SkipNode* node = (SkipNode*)malloc(sizeof(SkipNode));
    node->value = value;
    node->next = (SkipNode**)malloc((level + 1) * sizeof(SkipNode*));
    for (int i = 0; i <= level; i++) node->next[i] = NULL;
    return node;
}

SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(INT_MIN, MAX_LEVEL);
    return list;
}

int randomLevel() {
    int lvl = 0;
    while (rand() < RAND_MAX / 2 && lvl < MAX_LEVEL) lvl++;
    return lvl;
}

void insert(SkipList* list, int value) {
    SkipNode* update[MAX_LEVEL + 1];
    SkipNode* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->value < value) {
            current = current->next[i];
        }
        update[i] = current;
    }
    current = current->next[0];

    if (current == NULL || current->value != value) {
        int rlevel = randomLevel();

        if (rlevel > list->level) {
            for (int i = list->level + 1; i <= rlevel; i++) {
                update[i] = list->header;
            }
            list->level = rlevel;
        }

        SkipNode* newNode = createNode(value, rlevel);
        for (int i = 0; i <= rlevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
}

int search(SkipList* list, int value) {
    SkipNode* current = list->header;
    for (int i = list->level; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->value < value) {
            current = current->next[i];
        }
    }
    current = current->next[0];
    return (current != NULL && current->value == value);
}

void deleteNode(SkipList* list, int value) {
    SkipNode* update[MAX_LEVEL + 1];
    SkipNode* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->value < value) {
            current = current->next[i];
        }
        update[i] = current;
    }
    current = current->next[0];

    if (current != NULL && current->value == value) {
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->next[i] != current) break;
            update[i]->next[i] = current->next[i];
        }
        free(current);
        while (list->level > 0 && list->header->next[list->level] == NULL) {
            list->level--;
        }
    }
}

void print(SkipList* list) {
    printf("\n--- Skip List Levels ---\n");
    for (int i = list->level; i >= 0; i--) {
        SkipNode* node = list->header->next[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("%d -> ", node->value);
            node = node->next[i];
        }
        printf("NULL\n");
    }
}

int main() {
    SkipList* sl = createSkipList();
    insert(sl, 3);
    insert(sl, 6);
    insert(sl, 7);
    insert(sl, 9);
    print(sl);

    printf("Search 7: %d\n", search(sl, 7));
    deleteNode(sl, 7);
    print(sl);

    return 0;
}
