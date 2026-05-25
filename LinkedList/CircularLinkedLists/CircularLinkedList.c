#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void prepend(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;
}

void insert(Node** head, int value, int position) {
    if (position == 0) {
        prepend(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == *head) return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirst(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    Node* temp = *head;
    current->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while (current->next != *head) {
        prev = current;
        current = current->next;
    }
    prev->next = *head;
    free(current);
}

void delete(Node** head, int position) {
    if (*head == NULL) return;
    if (position == 0) {
        deleteFirst(head);
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    for (int i = 0; i < position; i++) {
        prev = current;
        current = current->next;
        if (current == *head) return;
    }
    prev->next = current->next;
    free(current);
}

int search(Node* head, int value) {
    if (head == NULL) return -1;
    Node* current = head;
    int position = 0;
    do {
        if (current->value == value) return position;
        current = current->next;
        position++;
    } while (current != head);
    return -1;
}

void print(Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

int main() {
    Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    prepend(&head, 5);
    insert(&head, 15, 2);
    print(head); // 5 -> 10 -> 15 -> 20 -> (head)
    delete(&head, 2);
    print(head); // 5 -> 10 -> 20 -> (head)
    return 0;
}
