#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

int push(node** head , int data){
	node * temp = malloc(sizeof(node)); 
	if (temp == NULL){return 1;}
	temp->data = data ;
	temp->next = *head ;
	*head = temp;
	return 0;
}

int pop(node** head){
	if (*head != NULL){
		node* ptr = *head;
	        printf("Delete head(%d)",ptr->data);
		*head = (*head)->next;
		free(ptr);
		return 0;
	}
	printf("\nEmpty");
	return 0;
}

void printfAll(node *head){
	node*ptr = head;
	while (ptr != NULL) {
		printf("%d ->",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
	return;
}

int main(){
	node* head = NULL;
	int choice , data ;
	do {
		printf("1:Push\n");
		printf("2:Pop\n");
		printf("printall\n:");
		scanf("%d",&choice);
		switch (choice) {
			case 1: printf("Data:"); scanf("%d",&data); push(&head,data); break;
			case 2: pop(&head); break;
			case 3: printfAll(head); break;
			default: printf("Invalid input"); break;
		}
	}while (choice != 4);
	free(head);
	return 0 ;
}
// link list stack 
