#include <stdio.h>
#include <stdlib.h>
// Binary tree / queue(linked list)
//
typedef struct node{ // for tree 
  int data;
  struct node* left;
  struct node* right;
}node;

typedef struct q{ // for link list
  node* tree;
  struct q* next;
}q;

q* front = NULL;
q* rear = NULL;

void link(node *new_node){ // normal link list front far left // rear is new node f->1->2->rear->null; 
  q* temp = malloc(sizeof(q));
  temp->tree = new_node;
  temp->next = NULL;
  if(front == NULL){front = temp ; rear = temp; return;}
  rear->next = temp;
  rear = temp;
  return ;
}//This funtion use for create new node and used for move rear to next with newnode;

node* create(int data){ // normal create node concept
  node* new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void movefront(){//clear far left and move front to next 
  node*ptr = front;
  front = front->next;
  free(ptr);
  return;
}

void insert(node **root , int data){
  node* new_node = create(data); 
  if(*root == NULL){*root = new_node; link(new_node); return;} // If tree is empty, make new node the root
  node* current = front->tree;
  if(current->left == NULL){
    current->left = new_node;
  }else if (current->right == NULL) {
    current->right = new_node;
    movefront();// Move to the next node in the queue
  }
  link(new_node);
}
void print(node*root){ // Would print left main right
  if(root != NULL){
    print(root->left);
    printf("%d",root->data);
    print(root->right);
  }
  return ;
}

void clearlist(){
  while(front != NULL){
    node *ptr = front;
    front = front->next;
    free(ptr);
  }
  rear = NULL;
  return;
}

void cleartree(node *root){
  if (root == NULL) return;
  cleartree(root->left);
  cleartree(root->right);
  free(root);
  front = NULL;
}

void clearnode(node **root){
  clearlist();
  cleartree(*root);
  return ;
}

int main(){
  node* root = NULL; 
  int choice , data = 0;
  do {
    printf("1:Add\n");
    printf("2:Print\n");
    printf(":");scanf("%d",&choice);
    printf("\n");
    switch (choice) {
      case 1:printf("Enter Data:");scanf("%d",&data);insert(&root,data);break;
      case 2:print(root);break;
    }
  } while (choice != 3);
  clearnode(&root);
  printf("Good-Bye");
  return 0;
}
