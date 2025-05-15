#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * next;
}node;

int main(){
	node* head = NULL; // set head and tail 
	node* tail = NULL;
	for (int i = 0 ; i < 3 ;i++){
		node *temp = malloc(sizeof(node));
		int x;
		scanf("%d",&x);
		temp->data = x;  
		temp->next = NULL;
		if (head == NULL){  // if head free
			head = temp; // head,tail point to temp 
			tail = temp;
			tail->next = head ; //tail->next = head it mean change to 1->1 from 1->null
		}else {
			temp->next = head; // if head busy temp->next connect to head 2->null , 1->1, changed to 2->1->1
			tail->next = temp; // now need to changed where tail point to . 2->1->2;
			tail = temp;//
		}	
	}
	node* current = head;
        int count = 0;
        while (count < 4) {
		printf("%d ", current->data);
		current = current->next;
		count++;
	}

    return 0;

}

