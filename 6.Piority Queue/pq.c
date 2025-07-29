#include <stdio.h>
#include <stdlib.h> 
#define MAX 100

typedef struct pq {
    int arr[MAX];
    int size;
} pg;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

pg* create() {
    pg* new_node = malloc(sizeof(pg));
    new_node->size = 0;
    return new_node;
}

int isEmpty(pg* temp) {
    return temp->size <= 0;
}

int isFull(pg* temp) {
    return temp->size >= MAX;
}

void insert(pg* temp, int data) {
    if (isFull(temp)) return;
    int i = temp->size;
    temp->arr[i] = data;
    temp->size++;
    while (i != 0 && temp->arr[parent(i)] < temp->arr[i]) {
        int x = temp->arr[i];
        temp->arr[i] = temp->arr[parent(i)];
        temp->arr[parent(i)] = x;
        i = parent(i);
    }
}

void heapify(pg* temp, int data) {
    int most = data;
    int mleft = left(data);
    int mright = right(data);

    if (mleft < temp->size && temp->arr[mleft] > temp->arr[most]) {
        most = mleft;
    }
    if (mright < temp->size && temp->arr[mright] > temp->arr[most]) {
        most = mright;
    }

    if (most != data) {
        int x = temp->arr[data];
        temp->arr[data] = temp->arr[most];
        temp->arr[most] = x;
        heapify(temp, most);
    }
}

int pop(pg* temp) {
    if (isEmpty(temp)) return -1;
    int rootValue = temp->arr[0];
    temp->arr[0] = temp->arr[temp->size - 1];
    temp->size--;
    heapify(temp, 0);
    return rootValue;
}

int main() {
    pg* temp = create();
    int choice, value;

    while (1) {
        printf("\n1: Push\n2: Pop\n3: isEmpty\n4: isFull\n5: Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &value);
                insert(temp, value);
                break;
            case 2: {
                int result = pop(temp);
                if (result == -1)
                    printf("Heap is empty!\n");
                else
                    printf("Popped: %d\n", result);
                break;
            }
            case 3:
                printf("isEmpty: %s\n", isEmpty(temp) ? "Yes" : "No");
                break;
            case 4:
                printf("isFull: %s\n", isFull(temp) ? "Yes" : "No");
                break;
            case 5:
                printf("Exit\n");
                free(temp);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

