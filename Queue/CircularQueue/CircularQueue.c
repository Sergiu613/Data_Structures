#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int data[CAPACITY];
    int front;
    int rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isFull(CircularQueue* q) {
    return q->size == CAPACITY;
}

bool isEmpty(CircularQueue* q) {
    return q->size == 0;
}

bool enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }
    q->rear = (q->rear + 1) % CAPACITY;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return value;
}

int peek(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (Front -> Rear): ");
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % CAPACITY;
        printf("%d ", q->data[idx]);
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    
    enqueue(&q, 60);
    enqueue(&q, 70);
    printQueue(&q);

    return 0;
}
