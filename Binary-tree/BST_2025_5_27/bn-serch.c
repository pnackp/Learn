#include <stdio.h>
#include <stdlib.h>

// tree structer
typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;


node* create(int val) { // normal create node
  node* new_node = malloc(sizeof(node));
  new_node->data = val;
  new_node->left = new_node->right = NULL;
  return new_node;
}


node* insert(node* root, int val) { // it's a loop function until found null if value < data sent left data 
  if (root == NULL) return create(val);  // when find null create space and return root new ver
  if (val < root->data)
    root->left = insert(root->left, val);  
  else
    root->right = insert(root->right, val);
  return root;
}

void print(node* root) {
  if (root != NULL) {
    print(root->left);
    printf(" %d ", root->data);
    print(root->right);
  }
}

void cleartree(node *root){ // free fron far node and move in 
  if (root == NULL) return;
  cleartree(root->left);
  cleartree(root->right);
  free(root);
}

int main() {
  node* root = NULL;
  int val = 0, ch;

  do {
    printf("\n==== MENU ====\n");
    printf("1: Add Value\n");
    printf("2: Print Tree\n");
    printf("3: Exit\n");
    printf("Choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter Value: ");
        scanf("%d", &val);
        root = insert(root, val);
        break;

      case 2:
        print(root);
        printf("\n");
        break;

      case 3:
        printf("Goodbye\n");
        break;

      default:
        printf("Valid\n");
    }
  } while (ch != 3);
  cleartree(root);
  return 0;
}
