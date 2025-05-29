// Doubly Circular Link-list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data; 
	struct node* next;
	struct node* prev;
}node;

int main(){
	node * head = NULL;
	node * tail = NULL;
	for (int i = 0 ; i < 3 ; i++){
		node* temp = malloc(sizeof(node));
		int x;
		scanf("%d",&x);
		temp->data = x;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL){
			head = temp;
			tail = temp;
			tail->next = head;
			tail->prev = head;
		}else {
			temp->next = head; // set new node connect to head
			temp->prev = tail; // previous go to first node;
			head->prev = temp;// head previous connect to newnode
			tail->next = temp; //next first node connect to temp;
			head = temp;//set new node is head
		}
	}
	int x = 0;
	node *ptr = head;
	while(x<=4){
		printf("%d",ptr->data);
		x++;
		ptr = ptr->next;
	}
	return 0;
}
