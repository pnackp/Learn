#include <stdio.h>
#include <stdlib.h>

#define Table_size 100

typedef struct max {
    int arr[Table_size];
    int size;
} max;

max *createnode() {
    max *new_node = malloc(sizeof(max));
    new_node->size = 0;
    return new_node;
}

int parent(int x) { return (x - 1) / 2; }
int left(int x) { return (x * 2) + 1; }
int right(int x) { return (x * 2) + 2; }

void insert(max *heap, int data) {
    if (heap->size >= Table_size) return;
    int i = heap->size;
    heap->arr[i] = data;
    heap->size++;

    while (i > 0 && heap->arr[parent(i)] < heap->arr[i]) { 
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;
        i = parent(i);
    }

    printf("Inserted!\n");
}

void heapify(max *heap, int i) {
    int highest = i;
    int leftI = left(i);
    int rightI = right(i);

    if (leftI < heap->size && heap->arr[leftI] > heap->arr[highest]) highest = leftI;
    if (rightI < heap->size && heap->arr[rightI] > heap->arr[highest]) highest = rightI;

    if (highest != i) {
        int temp = heap->arr[highest];
        heap->arr[highest] = heap->arr[i];
        heap->arr[i] = temp;
        heapify(heap, highest);
    }
}

void deleteMax(max *heap) { 
    if (heap->size <= 0) return;
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return;
}

void showheap(max *heap) { 
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    max *heap = createnode();
    int choice, value;

    while (1) {
        printf("\n1: Insert\n2: Delete Max\n3: Show Heap\n4: Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &value);
                insert(heap, value);
                break;
            case 2:
                deleteMax(heap);
                break;
            case 3:
                showheap(heap);
                break;
            case 4:
                printf("Exit\n");
                free(heap);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

