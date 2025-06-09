#include <stdio.h>
#include <stdlib.h>

:w

typedef struct node{
  int data;
  struct node * left;
  struct node * right;
}node;

node* createnode(int data){
  node* temp = malloc(sizeof(node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int main(){
  node * root = createnode(9);
  return 0;
}
