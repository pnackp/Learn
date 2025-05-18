#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int Size; 
	int array[10];
} box;

int push(box *temp, int data) {
	if (temp->Size < 10) { // if box isn't full
		temp->array[temp->Size] = data; // temp->Size similar array[i] it's mean array at Size(ex:1) = data = array[1] = Data;
		temp->Size++; // i++
		printf("Added\n");
		return 0;
	}
	printf("Box is full!\n");
	return 1;
}

int pop(box *temp) {
	if (temp->Size > 0) { //if box isn't Empty
		temp->Size--; // detele top
		printf("Removed\n");
		return 0;
	}
	printf("Box is empty!\n");
	return 1;
}

void printBox(box *temp) {
	printf("Current Stack: ");
	if (temp->Size == 0) { // if empty stop and return
		printf("Empty\n");
		return;
	}
	for (int i = 0; i < temp->Size; i++) {
		printf("%d ", temp->array[i]); // print all data in start 0->top ;
	}
	printf("\n");
}

int main() {
	box *temp = malloc(sizeof(box));
	temp->Size = 0; // set base = 0 

	int x;
	int data;

	do {
		printf("\n1: Add\n2: Remove\n3: Exit\nChoice: ");
		scanf("%d", &x);
		switch (x) {
			case 1:
				printf("Add: ");
				scanf("%d", &data);
				push(temp, data);
				break;
			case 2:
				pop(temp);
				break;
		}
		printBox(temp);// print inside the box
	} while (x != 3);

	free(temp);
	printf("Goodbye!\n");
	return 0;
}

