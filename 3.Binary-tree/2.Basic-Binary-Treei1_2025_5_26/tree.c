// binary tree i(1)
// i dont know how to explain ts code but i undetstand i'll draw logic 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node;

node* queue[100]; // set ma
int front = 0, rear = 0;

node* create(int value){ // normal create
  node *new_node = malloc(sizeof(node));
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *peek(){
    return queue[front];
}

void enquque(node* node_c){
  queue[rear++] = node_c;
}

void insert(node **root ,int value){ 
  node *new = create(value);
  if(*root == NULL){*root = new; enquque(new); return ;} // if null set root = newnode and set q[0] = root
  node *current = peek();

  if(current->left == NULL){
    current->left = new;
  }else if (current->right == NULL) {
    current->right = new;
    front++; // move to new 
  }
  enquque(new); 
  return;
}

void print(node *root){
  if (root != NULL){
    print(root->left);
    printf("%d -> ",root->data);
    print(root->right);
  }
}

int main(){
  int x = 0;
  node *root = NULL;
  do {
    printf("ADD:");
    scanf("%d",&x);
    insert(&root , x);
  } while (x != 99);
  print(root);
  printf("\n");
  return 0;
}
