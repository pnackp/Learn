#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    char name[100];
    struct node *left, *right;
}node;

node* create(char *name){// normal create node
  node*new_node = malloc(sizeof(node));
  strcpy(new_node->name , name);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node* insert(node* root, char* name){
  if (root == NULL){root = create(name); return root;} // if find null create node for em
  if (strcmp(name , root->name)<0){ // if < go left
    root->left = insert(root->left , name); 
  }else if (strcmp(name , root->name)>0) { // if > go right
    root->right = insert(root->right , name);
  }:
  return root; // return for update
}

void search(node* root, char* name){
  if (root == NULL){printf("Not Found\n"); return ;}
  int cmp = strcmp(name, root->name);
  if (cmp == 0){printf("Found : %s is in the contract book.\n",root->name);return ;}
  if (cmp<0){
    search(root->left,name);
  }else if (cmp>0) {
    search(root->right,name);
  }
}

node* lowest(node *root){
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

node* delete(node* root, char* name){
  if (root == NULL){printf("Not Found\n"); return NULL;}
  int cmp = strcmp(name, root->name);
  if (cmp < 0){
    root->left = delete(root->left , name); 
  }else if (cmp>0) {
    root->right = delete(root->right , name);
  }else {
    if (root->left == NULL && root->right == NULL){free(root);return NULL;}
    else if (root->left == NULL) { // if no left replace root with right 
      node*temp = root->right;
      free(root);
      return temp;
    }else if (root->right == NULL){ //if no right replcae with left
      node*temp = root->left;
      free(root);
      return temp;
    }
    else {
      node*temp = lowest(root->right); // create * for keep data
      strcpy(root->name,temp->name); // replace with lowest data
      root->right = delete(root->right , temp->name); // delete lowest data
    }
  }
  return root;
}
void inorder(node* root){ 
  if (root != NULL){
    inorder(root->left);
    printf("-%s\n",root->name);
    inorder(root->right);
  }
  return;
}

void freenode(node *root){
  if (root != NULL){
    freenode(root->left);
    freenode(root->right);
    free(root);
  }
  return;
}

int main(){
  int choice = 0;
  char nm[100];  
  node *root = NULL;
  do {
    printf("=== Contact Book ===\n");
    printf("1. Add name\n");
    printf("2. Search name\n");
    printf("3. Delete name\n");
    printf("4. Show all names\n");
    printf("5. Exit\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    getchar();
    switch (choice) {
      case 1: printf("Enter name:");fgets(nm, 100 , stdin);nm[strcspn(nm, "\n")] = '\0';
        root = insert(root , nm);break;
      case 2: printf("Enter name:");fgets(nm, 100 , stdin);nm[strcspn(nm, "\n")] = '\0';search(root , nm);break;
      case 3: printf("Enter name to delete: ");fgets(nm, 100, stdin); nm[strcspn(nm, "\n")] = '\0';root = delete(root , nm);break;
      case 4: printf("All contacts:\n");inorder(root);break;
      case 5: printf("Goodbye!\n");freenode(root);break;
      default:printf("Enter 1-5\n");
    }
  } while (choice != 5);
  root = NULL;
  return 0;
}
