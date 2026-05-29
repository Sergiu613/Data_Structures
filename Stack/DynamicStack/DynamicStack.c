#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} DynamicStack;

void initStack(DynamicStack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmpty(DynamicStack* stack) {
    return stack->top == NULL;
}

void push(DynamicStack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(DynamicStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->value;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int peek(DynamicStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->value;
}

int size(DynamicStack* stack) {
    return stack->size;
}

void printStack(DynamicStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top -> Bottom):\n");
    Node* current = stack->top;
    while (current != NULL) {
        printf("| %d |\n", current->value);
        current = current->next;
    }
    printf("-------\n");
}
void freeStack(DynamicStack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

int main() {
    DynamicStack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    printStack(&stack);

    freeStack(&stack);
    return 0;
}
