#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct hash{
  char *key;
  int data;
}hash;

typedef struct node{
  hash * data;
  struct node *next;
}node;

node* hashtable[TABLE_SIZE];

unsigned int hashkey(const char* key) {
    unsigned int hashk = 0;
    while (*key) {
        hashk = (hashk * 31) + *key++;
    }
    return hashk % TABLE_SIZE;
}

void insert(const char *data , int val){
  const int index = hashkey(data);
  hash* temp = malloc(sizeof(hash));
  temp->key = strdup(data);
  temp->data = val;
  node* new_node = malloc(sizeof(node));
  new_node->data = temp;
  new_node->next = hashtable[index];
  hashtable[index] = new_node;
  return ;
}

int main(){
  int r = 1;
  char* data;
  int val;
  int choice = 0 ;
  do {
    printf("1:insert\n":);
    scanf("%d",&choice);
    switch (choice) {
      case 1:pritnf("Enter Choice:");scanf("%s",data);scanf("%d",&val);insert(data , val);break;
      case 3: r = 0 ;break; 
    }
  } while (r);
}
