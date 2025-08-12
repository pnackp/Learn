#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node{
  int data;
  struct node* next;
}node;

node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main(){
  node* arr[5];
  for(uint8_t i = 0 ; i < 5 ; i++){
    arr[i] = NULL;
  }
  node* x = createNode(2);
  x->next = arr[0];
  arr[0] = x;
  for(uint8_t i = 0; i < 5; i++) {
        printf("[%d] -> ", i);
        node* temp = arr[i];
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
  return 0;
}
