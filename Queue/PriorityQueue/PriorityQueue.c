#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CAPACITY 5

typedef struct {
    char value[20];
    int priority;
} Element;

typedef struct {
    Element data[CAPACITY];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

bool isFull(PriorityQueue* pq) {
    return pq->size == CAPACITY;
}

void insert(PriorityQueue* pq, const char* value, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue Overflow! Cannot insert %s\n", value);
        return;
    }

    int i = pq->size - 1;
    while (i >= 0 && pq->data[i].priority > priority) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }

    strcpy(pq->data[i + 1].value, value);
    pq->data[i + 1].priority = priority;
    pq->size++;
}

const char* dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue Underflow!\n");
        return NULL;
    }
    return pq->data[--(pq->size)].value;
}

void printQueue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue (Highest -> Lowest): ");
    for (int i = pq->size - 1; i >= 0; i--) {
        printf("[%s, P:%d] ", pq->data[i].value, pq->data[i].priority);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    insert(&pq, "Low Task", 1);
    insert(&pq, "High Task", 5);
    insert(&pq, "Medium Task", 3);
    printQueue(&pq);

    printf("Dequeued: %s\n", dequeue(&pq));
    printQueue(&pq);

    return 0;
}
