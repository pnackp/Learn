#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *left,*right;
  int height;
}node;

node *create(int data){
  node*new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->right = new_node->left = NULL;
  new_node->height = 1;
  return new_node;
}

int compare(int a,int b){
  return a - b;
}

int max(int a,int b){
  return (a > b) ?a: b;
}

node *turnright(node *root){
  node * x = root->left;
  node * lx = x->right;

  x->right = root;
  root->left = lx;

  root->height = 1 + max(
    root->left ? root->left->height : 0,
    root->right ? root->right->height : 0
  );
  x->height = 1 + max(
    x->left ? x->left->height : 0,
    x->right ? x->right->height : 0
  );

  return x;
}

node *turnleft(node *root){
  node * x = root->right;
  node * lx = x->left;

  x->left = root;
  root->right = lx;

  root->height = 1 + max(
    root->left ? root->left->height : 0,
    root->right ? root->right->height : 0
  );
  x->height = 1 + max(
    x->left ? x->left->height : 0,
    x->right ? x->right->height : 0
  );

  return x;
}

node *insert(node*root , int data){
  if (root == NULL){return create(data);}
  if (data > root->data){
    root->right = insert(root->right , data);
  }else if (data < root->data) {
    root->left = insert(root->left , data);
  }
  
  int leftHeight = root->left ? root->left->height : 0;
  int rightHeight = root->right ? root->right->height : 0;

  root->height = leftHeight > rightHeight? leftHeight+1 : rightHeight+1;

  int cm = leftHeight - rightHeight;

  if (cm > 1 && data < root->data){
    return turnright(root);
  }else if(cm < -1 && data > root->data){
    return turnleft(root);
  }else if (cm > 1 && data > root->data) {
    root->left = turnright(root->left);
    return turnright(root);
  }else if (cm < -1 && data < root->data) {
    root->right = turnleft(root->right);
    return turnleft(root);
  }
  return root;
}

node *findmin(node* root){
  while (root->left != NULL){
    root = root->left;
  }
  return root;
}

node *Removenode(node*root , int data){
  if (root == NULL){ printf("Not Found\n");return NULL;}
  if (data < root->data){
    root->left = Removenode(root->left , data);
  }else if (data > root->data) {
    root->right = Removenode(root->right, data);
  }else {
    if (root->left == NULL && root->right == NULL){
      free(root);return NULL;
    }
    else if (root->right == NULL) {
      node*temp = root->left;
      free(root);
      return temp;
    }
    else if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    }else {
      node*temp = findmin(root->right);
      root->data = temp->data;
      root->right = Removenode(root->right,temp->data);
    }
  }
  return root;
}

void inorder(node* root){ 
  if (root != NULL){
    inorder(root->left);
    printf("-%d\n",root->data);
    inorder(root->right);
  }
  return;
}

int main(){
  node *root = NULL;
  int choice = 0;
  do {
    int data = 0;
    printf("1:Add Number\n2:Remove Number\n3:Show All data\n4:Exit\n:");
    scanf("%d",&choice);
    switch (choice) {
      case 1: printf("Number:");scanf("%d",&data);root = insert(root,data);break;
      case 2: printf("Number:");scanf("%d",&data);root = Removenode(root,data);break;
      case 3: inorder(root);break;
    }
  } while (choice != 4);
  return 0;
}
