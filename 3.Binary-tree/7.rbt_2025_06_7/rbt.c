#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { red, black } Color;

typedef struct node {
    int data;
    struct node *left, *right, *parent;
    Color color;
} node;

node* rotateleft(node* root, node* n) {
    node* y = n->right;
    n->right = y->left;
    if (y->left != NULL) { y->left->parent = n; }
    y->parent = n->parent;
    if (n->parent == NULL) {
        root = y;
    } else if (n == n->parent->right) {
        n->parent->right = y;
    } else{
        n->parent->left = y;
    }
    y->left = n;
    n->parent = y;

    return root;
}

node* rotateright(node* root, node* n) {
    node* y = n->left;
    n->left = y->right;
    if (y->right != NULL) { y->right->parent = n; }
    y->parent = n->parent;
    if (n->parent == NULL) {
        root = y;
    } else if (n == n->parent->right) {
        n->parent->right = y;
    } else {
        n->parent->left = y;
    }
    y->right = n;
    n->parent = y;

    return root;
}

node* createnode(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    new_node->color = red;
    new_node->parent = NULL;
    return new_node;
}

node* insertfix(node* root, node* new_node) {
    node* p = NULL;
    node* g = NULL;
    node* u = NULL;
    while ((new_node != root) && (new_node->parent->color == red)) {
        p = new_node->parent;
        g = p->parent;
        if (p == g->left) {
            u = g->right;
            if (u != NULL && u->color == red) {
                g->color = red;
                p->color = black;
                u->color = black;
                new_node = g;
            } else {
                if (new_node == p->right) {
                    new_node = p;
                    root = rotateleft(root, p);
                }
                p->color = black;
                g->color = red;
                root = rotateright(root, g);
            }
        } else {
            u = g->left;
            if (u != NULL && u->color == red) {
                g->color = red;
                p->color = black;
                u->color = black;
                new_node = g;
            } else {
                if (new_node == p->left) {
                    new_node = p;
                    root = rotateright(root, p);
                }
                p->color = black;
                g->color = red;
                root = rotateleft(root, g);
            }
        }
    }
    root->color = black;
    return root;
}

node* insert(node* root, int data) {
    node* new_node = createnode(data);
    node* x = root;
    node* y = NULL;
    while (x != NULL) {
        y = x;
        if (data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    new_node->parent = y;
    if (y == NULL) {
        root = new_node;
        root->color = black;
        return root;
    } else if (data < y->data) {
        y->left = new_node;
    } else {
        y->right = new_node;
    }
    return insertfix(root, new_node);
}

void find(node* root, int data) {
    if (root == NULL) { return; }
    if (root->data == data) { printf("Found\n"); return; }
    if (data < root->data) { find(root->left, data); } else {
        find(root->right, data);
    }
}

void print(node* root) {
    if (root != NULL) {
        print(root->left);
        printf("%d(%c) ", root->data , root->color == black ? 'B' : 'R');
        print(root->right);
    }
    return;
}

node* Findmin(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void rbt_transplant(node** root, node* u, node* v) {
    if (u->parent == NULL) { // if u is root
        *root = v;
    } else if (u == u->parent->left) { // if u on left
        u->parent->left = v;
    } else {
        u->parent->right = v; 
    }
    if (v != NULL) { 
        v->parent = u->parent;// set new parent is root
    }
}

void deletefixup(node **root , node*x){
  node*s = NULL;
  while(x != *root && (x== NULL || x->color == black)){
    if (x == x->parent->left) {
      s = x->parent->right;
      if(s->color == red){
        s->color = black;
        x->parent->color = red;
        *root = rotateleft(*root , x->parent);
      }
      if((s->left == NULL || s->left->color == black) && (s->right == NULL || s->right->color == black))
      {
        s->color = red;
        x = x->parent;
      }else {
        if(s->right == NULL || s->right->color == black){
          if (s->left != NULL) s->left->color = black;
          s->color = red;
          *root = rotateright(*root, s);
          s = x->parent->right;
        }
        s->color = x->parent->color;
        x->parent->color = black;
        if(s->right != NULL) s->right->color = black;
        *root = rotateleft(*root, x->parent);
        x = *root;
      }
    }else {
      s = x->parent->left;
      if (s->color == red) {
        s->color = black;
        x->parent->color = red;
        *root = rotateright(*root, x->parent);
        s = x->parent->left;
      }
      if((s->right == NULL || s->right->color == black) && (s->left == NULL || s->left->color == black))
      {
        s->color = red;
        x = x->parent;
      }else {
        if(s->left == NULL || s->left->color == black){
          if (s->right != NULL) s->right->color = black;
          s->color = red;
          *root = rotateleft(*root, s);
          s = x->parent->left;
        }
        s->color = x->parent->color;
        x->parent->color = black;
        if(s->left != NULL) s->left->color = black;
        *root = rotateright(*root, x->parent);
        x = *root;
      }
    }
  }
  return ;
}

node* delete(node* root, int data) {
    node* x = root; // set   = root
    while (x != NULL && x->data != data) { // move x to node same as data
        if (x->data < data) {
            x = x->right;
        } else {
            x = x->left;
        }
    }
    if (x == NULL) return root;  // not found

    node* y = x; // create new = x
    Color type = y->color; // set color type = y , x
    node* z = NULL; // NULL

    if (x->left == NULL) { // node data left = null 
        z = x->right;  // move z to right of node data
        rbt_transplant(&root, x, z); 
    } else if (x->right == NULL) { 
        z = x->left;
        rbt_transplant(&root, x, z);
    } else {
        y = Findmin(x->right); // replace y with lowest node from right
        type = y->color; // remem color
        z = y->right;
        if (y->parent == x) { 
            if (z != NULL) z->parent = y; 
        } else {
            rbt_transplant(&root, y, y->right);
            y->right = x->right; 
            if (y->right) y->right->parent = y;
        }
        rbt_transplant(&root, x, y);
        y->left = x->left; 
        if (y->left) y->left->parent = y;
        y->color = x->color;
    }
    free(x);
    if (type == black) {
        deletefixup(&root,z);
    }
    return root;
}

node* freeall(node* root) {
    if (root != NULL) {
        root->left = freeall(root->left);
        root->right = freeall(root->right);
        free(root);
    }
    return NULL;
}

int main() {
    node* root = NULL;
    int choice, data = 0;
    do {
        printf("1:Insert\n2:Find\n3:Remove\n4:Print tree\n:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter Number:"); scanf("%d", &data); root = insert(root, data); break;
            case 2: printf("Enter Number:"); scanf("%d", &data); find(root, data); break;
            case 3: printf("Enter Number:"); scanf("%d", &data); root = delete(root, data); break;
            case 4: print(root); printf("\n"); break;
            default: printf("invalid\n");
        }
    } while (choice != 5);
    root = freeall(root);
    root = NULL;
    printf("Good bye");
}
