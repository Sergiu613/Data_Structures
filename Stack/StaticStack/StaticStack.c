#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int data[CAPACITY];
    int top;
} StaticStack;

void initStack(StaticStack* stack) {
    stack->top = -1;
}

bool isFull(StaticStack* stack) {
    return stack->top == CAPACITY - 1;
}

bool isEmpty(StaticStack* stack) {
    return stack->top == -1;
}

bool push(StaticStack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return false;
    }
    stack->data[++(stack->top)] = value;
    return true;
}

int pop(StaticStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}

int peek(StaticStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data[stack->top];
}

int size(StaticStack* stack) {
    return stack->top + 1;
}

void printStack(StaticStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top -> Bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("| %d |\n", stack->data[i]);
    }
    printf("-------\n");
}

int main() {
    StaticStack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    printStack(&stack);

    return 0;
}
