#include <stdio.h>
#include <stdlib.h>

// !! This code i copy from chat and write comment , It's really hard for me this tree
// expect delete , find , print and logic of create , rotateLeft 
typedef enum { red , black  }Color;

typedef struct node{
  int data;
  struct node* left , * right , *parent;
  Color color;
}node;

node*create(int data){
  node* new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = new_node->right = new_node->parent = NULL;
  new_node->color = red;
  return new_node;
}

node *rotateLeft(node *root , node*x){
  node * y = x->right; 
  x->right = y->left; 
  if (y->left)y->left->parent = x;  
  y->parent = x->parent; 
  if (!x->parent){ 
  root = y;
  }else if (x == x->parent->right){ 
    x->parent->right = y;
  }else {
    x->parent->left = y;
  }
  y->left = x;  //dad -> y -> x 
  x->parent = y; // set new dad for x is y
  return root;
}

node *rotateRight(node *root , node*x){
  node * y = x->left; // y is main character = x->left 
  x->left = y->right; // set x->left = y->right; but y still exist
  if (y->right)y->right->parent = x; // if y->right alive set parent is x
  
  y->parent = x->parent; // set y = x->parent
  if (!x->parent){ // if dad of x dead set y set DAD
    root = y;
  }else if (x == x->parent->left){ // if still alive and x on left dad change dad -> y ->
    x->parent->left = y;
  }else {
    x->parent->right = y;
  }
  y->right = x; // y->right = x  dad -> y -> x 
  x->parent = y; // set new dad for x is y
  return root ;
}

node *fixinsert(node *root , node *new_node){
  while (new_node != root && new_node->parent->color == red){
    node * p = new_node->parent; // set dad is new_node dad;
    node * g = p->parent; // grandparent = father for dad;

    if (p == g->left){ // if dad on left of grandparent
      node *u = g->right; // uncle == grandparent right
      if (u && u->color == red){ // if uncle still alive and color is red
        p->color = black; // set dad are black;
        u->color = black;//set uncle are black;
        g->color = red; // set grandparent is red;
        new_node = g; //move pointer to grandparent from new 
      }else { // if not
        if (new_node == p->right){ // if new kid on dad right 
          new_node = p ; //move new_node pointer to dad ; 
          root =rotateRight(root , new_node); // and rotate 3->2 ; out 2->3 // rotate dad and new kid
        }
        p->color = black; // set 3(p,n) -> 2 // 2(p,n) -> 3 ; set 2 is black;
        g->color = red; // set color grandparent is red
        root = rotateLeft(root , g); // now rotate family member expect uncle; 
      }
    }else { // it's same as u = g->right
      node* u = g->left;
            if (u && u->color == red) {
                p->color = black;
                u->color = black;
                g->color = red;
                new_node = g;
            } else {
                if (new_node == p->left) {
                    new_node = p;
                    root = rotateRight(root, new_node);
                }
                p->color = black;
                g->color = red;
                root = rotateLeft(root, g);
            }
   }
  }
  root->color = black;
  return root;
}

node* insert(node *root , int data){
  node *new_node = create(data);
  node *y = NULL;
  node *x = root;

  while (x) {
    y = x;
    if (data < x->data) x = x->left;
    else {
      x = x->right;
    }
  }

  new_node->parent = y;
  if (!y) root = new_node;
  else if (data < y->data) {
    y->left = new_node;
  }else {
    y->right = new_node;
  }
  fixinsert(root , new_node);
  return root;
}

void print(node *root){
  if (!root){return;}
  print(root->left);
  printf("%d(%c)",root->data ,root->color == red ? 'R' : 'B');
  print(root->right);
}

void find(node *root , int data){
  if (root == NULL){printf("Not found\n");return ;}
  if (data == root->data){printf("Founded %d(%c)\n",root->data,root->color == red ? 'R' : 'B');return;}
  if (data < root->data){find(root->left , data);}
  else {
    find(root->right ,data);
  }
}

node *findmin(node*root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

node *delete(node *root , int data){
  if (root == NULL){return NULL;}
  if (data < root->data){root->left = delete(root->left , data);}
  else if (data > root->data){
    root->right = delete(root->right ,data);
  }else{
    if(root->left == NULL && root->right == NULL){
      free(root);
      return NULL;
    }else if (root->left == NULL) {
      node* ptr = root->right;
      free(root);
      return ptr;
    }else if (root->right == NULL) {
      node *ptr = root->left;
      free(root);
      return ptr;
    }else {
      node*ptr = findmin(root->right);
      root->data = ptr->data;
      root->right = delete(root->right , ptr->data);
    }
  }
  return root;
}

node *freeall(node*root){
  if (root != NULL){
    freeall(root->left);
    freeall(root->right);
    free(root);
  }
  return root;
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
