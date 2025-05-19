#include <stdio.h>
#include <stdlib.h>

typedef struct q{
	int data;
	struct q * next;
}q;

void pop(q** head){
	q *ptr = *head;
	if (ptr != NULL){
		*head = (*head)->next;
		free(ptr);
	}
}

int main(){
	q* head = NULL;
	q* rear = NULL;  
	int x;
	for (int i = 0 ; i < 3 ; i++){
		q*temp = malloc(sizeof(q));
		scanf("%d",&x);
		temp->data = x;
		temp->next = NULL;
		if (head == NULL){
			head = temp;
			rear = temp;
		}else {
			rear->next = temp;
			rear = temp;
		}
	}
	pop(&head);
	while (head != NULL) {
		printf("%d",head->data);
		pop(&head);
	}
	return 0;
}
