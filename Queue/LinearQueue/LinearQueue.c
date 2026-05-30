#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int data[CAPACITY];
    int front;
    int rear;
    int size;
} LinearQueue;

void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isFull(LinearQueue* q) {
    return q->size == CAPACITY;
}

bool isEmpty(LinearQueue* q) {
    return q->size == 0;
}

bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }
    q->data[++(q->rear)] = value;
    q->size++;
    return true;
}

int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = q->data[q->front++];
    q->size--;
    return value;
}

int peek(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int size(LinearQueue* q) {
    return q->size;
}

void printQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (Front -> Rear): ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front element: %d\n", peek(&q));
    printQueue(&q);

    return 0;
}
