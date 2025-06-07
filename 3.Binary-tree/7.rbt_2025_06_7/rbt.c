#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {red , black;}color;

typedef struct node {
  int data;
  struct node*left ,*right ,*parent;
  color type;
}node;

node* rotateleft(node*root , node* n){
  node* y = n->right;
  n->right = y->left;
  if(y->left != NULL){y->left->parent = n;}
  y->parent = n->parent;
  if(n->parent == NULL){
    root = y;
  }else if(n == n->parent->right){
    n->parent->right = y;
  }else {
    n->parent->left = y;
  }
  y->left = n;
  n->parent = y;

  return root;
}

node* rotateright(node*root , node* n){
  node* y = n->left;
  n->left = y->right;
  if(y->right != NULL){y->right->parent = n;}
  y->parent = n->parent;
  if(n->parent == NULL){
    root = y;
  }else if(n == n->parent->right){
    n->parent->right = y;
  }else {
    n->parent->left = y;
  }
  y->right = n;
  n->parent = y;

  return root;
}

node* createnode(int data){
  node * new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  new_node->color = red;
  return new_node;
}

node* insertfix(node*root , node* new_node){
  node * p = NULL;
  node * g = NULL;
  node * u = NULL;
  while((new_node != root) && (new_node->parent->color == red) && (new_node->parent->color == red)){
    p = new_node->parent;
    g = p->parent;
    if (p == g->left){
      u = g->right;
      if(u != NULL && u->color == red){
        g->color = red;
        p->color = black;
        u->color = black;
        new_node = g; // move
      }else {
        if(new_node == p->right){
          new_node = p;
          root = rotateleft(root,p);
        }
        p->color = black;
        g->color = red;
        root = rotateright(root,g);
      }
    }else {
      u = g->left;
      if(u != NULL && u->color == red){
        g->color = red;
        p->color = black;
        u->color = black;
        new_node = g;
      }else {
        if(new_node == p->left){
          new_node = p;
          root = rotateright(root,p);
        }
        p->color = black;
        g->color = red;
        root = rotateleft(root,g);
      }
    }
  }
  root->color = black;
  return root;
}

node* insert(node*root , int data){
  node*new_node = createnode(data);
  node* x = root;
  node* y = NULL;
  while(x != NULL){
    y = x;
    if(data < x->data){
      x = x->left;
    }else {
      x = x->right;
    }
  }
  new_node->parent = y;
  if(y == NULL){
    root = new_node;
    root->color = black;
    return root;
  }else if (data < y->data) {
    y->left = new_node;
  }else {
    y->right = new_node;
  }
  return insertfix(root,new_node);
}

void find(node *root , int data){
  if(root == NULL){return;}
  if(root->data == data){printf("Found\n");return ;}
  if(data < root->data){find(root->left , data);}else {
    find(root->right,data);
  }
}

void print(node*root){
  if(root != NULL){
    print(root->left);
    printf("%d",root->data);
    print(root->right);
  }
  return;
}

node* Findmin(node *root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

node* changecolor(){
}

node* delete(node*root , int data){ 
}


node * freeall(node*root){
  if(root != NULL){
    root->left = freeall(root->left);
    root->right = freeall(root->right);
    free(root);
  }
  return NULL;
}
int main(){
  node *root = NULL;
  int choice , data = 0;
  do {
    printf("1:Insert\n2:Find\n3:Remove\n4:Print tree\n:");
    scanf("%d",&choice);
    switch (choice) {
      case 1: printf("Enter Number:");scanf("%d",&data);root = insert(root , data);break;
      case 2: printf("Enter Number:");scanf("%d",&data);find(root , data);break;
      case 3: printf("Enter Number");scanf("%d",&data);root = delete(root , data);break;
      case 4: print(root); printf("\n");break;
      default: printf("invalid\n"); 
    }
  } while (choice != 5);
  root = freeall(root);
  root = NULL;
  printf("Good bye");
}
