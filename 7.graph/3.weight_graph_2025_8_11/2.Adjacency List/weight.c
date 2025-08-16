#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node{
  uint8_t dest;
  uint8_t weight;
  struct node* next;
}node;

node* createNode(uint8_t dest, uint8_t weight) {
    node* newNode = malloc(sizeof(node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node* array[], uint8_t src, uint8_t dest, uint8_t weight) {
    node* newNode = createNode(dest, weight);
    newNode->next = array[src];  
    array[src] = newNode;
}

int main(){
  node* array[4];
  for(uint8_t i = 0; i < 4 ; i++){
    array[i] = NULL;
  }
  addEdge(array, 0, 1, 5);
  addEdge(array, 0, 2, 3);
  addEdge(array, 1, 2, 2);
  addEdge(array, 2, 3, 7);
  addEdge(array, 3, 0, 4);
  return 0;
}
