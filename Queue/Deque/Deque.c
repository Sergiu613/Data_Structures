#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int arr[CAPACITY];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

bool isFull(Deque* dq) {
    return dq->size == CAPACITY;
}

bool isEmpty(Deque* dq) {
    return dq->size == 0;
}

bool insertFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert %d at Front\n", value);
        return false;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + CAPACITY) % CAPACITY;
    }
    dq->arr[dq->front] = value;
    dq->size++;
    return true;
}

bool insertRear(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert %d at Rear\n", value);
        return false;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % CAPACITY;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot delete from Front\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % CAPACITY;
    }
    dq->size--;
    return value;
}

int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot delete from Rear\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + CAPACITY) % CAPACITY;
    }
    dq->size--;
    return value;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque (Front -> Rear): ");
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % CAPACITY;
        printf("%d ", dq->arr[idx]);
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    printDeque(&dq); // 5 10 20

    deleteRear(&dq);
    printDeque(&dq); // 5 10

    deleteFront(&dq);
    printDeque(&dq); // 10

    return 0;
}
