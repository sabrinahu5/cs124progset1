#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->data = (int*) malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void destroyMinHeap(MinHeap *heap) {
    free(heap->data);
    free(heap);
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heap->size && heap->data[l] < heap->data[smallest])
        smallest = l;

    if (r < heap->size && heap->data[r] < heap->data[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap->data[i], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

int getMin(MinHeap *heap) {
    if (heap->size == 0)
        return -1;
    return heap->data[0];
}

int deleteMin(MinHeap *heap) {
    if (heap->size == 0)
        return -1;

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);

    return root;
}

void insert(MinHeap *heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Error: heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = key;

    while (i != 0 && heap->data[parent(i)] > heap->data[i]) {
        swap(&heap->data[i], &heap->data[parent(i)]);
        i = parent(i);
    }
}