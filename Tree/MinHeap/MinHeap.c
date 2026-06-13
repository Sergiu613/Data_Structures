#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 20

typedef struct {
    int data[CAPACITY];
    int size;
} MinHeap;

void initHeap(MinHeap* hp) {
    hp->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* hp, int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && hp->data[i] < hp->data[parent]) {
        swap(&hp->data[i], &hp->data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void insert(MinHeap* hp, int value) {
    if (hp->size >= CAPACITY) {
        printf("Heap Overflow!\n");
        return;
    }
    hp->data[hp->size] = value;
    hp->size++;
    heapifyUp(hp, hp->size - 1);
}

void heapifyDown(MinHeap* hp, int i) {
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < hp->size && hp->data[left] < hp->data[smallest])
        smallest = left;
    if (right < hp->size && hp->data[right] < hp->data[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&hp->data[i], &hp->data[smallest]);
        heapifyDown(hp, smallest);
    }
}

int extractMin(MinHeap* hp) {
    if (hp->size <= 0) return -1;
    if (hp->size == 1) {
        hp->size--;
        return hp->data[0];
    }

    int root = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;
    heapifyDown(hp, 0);

    return root;
}

void printHeap(MinHeap* hp) {
    printf("Min Heap Array: ");
    for (int i = 0; i < hp->size; i++) {
        printf("%d ", hp->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap hp;
    initHeap(&hp);

    insert(&hp, 15);
    insert(&hp, 10);
    insert(&hp, 20);
    insert(&hp, 5);
    insert(&hp, 8);

    printHeap(&hp); // 5 should be at index 0

    printf("Extracted min: %d\n", extractMin(&hp));
    printHeap(&hp);

    return 0;
}
