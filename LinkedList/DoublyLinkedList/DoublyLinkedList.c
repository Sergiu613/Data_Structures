#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void prepend(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head != NULL) {
        (*head)->prev = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insert(Node** head, int value, int position) {
    if (position == 0) {
        prepend(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) return;
        current = current->next;
    }
    if (current == NULL) return;

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void deleteFirst(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteLast(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

void delete(Node** head, int position) {
    if (*head == NULL) return;
    if (position == 0) {
        deleteFirst(head);
        return;
    }
    Node* current = *head;
    for (int i = 0; i < position; i++) {
        if (current == NULL) return;
        current = current->next;
    }
    if (current == NULL) return;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

int search(Node* head, int value) {
    Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->value == value) return position;
        current = current->next;
        position++;
    }
    return -1;
}

void print(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Empty List\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) printf(" <-> ");
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    prepend(&head, 5);
    insert(&head, 15, 2);
    print(head); // 5 <-> 10 <-> 15 <-> 20
    delete(&head, 2);
    print(head); // 5 <-> 10 <-> 20
    return 0;
}
