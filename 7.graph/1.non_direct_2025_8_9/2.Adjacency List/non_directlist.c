#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* createNode(int v){
  Node* new_node = malloc(sizeof(Node));
  new_node->data = v;
  new_node->next = NULL;
  return new_node;
}

void addEdge(Node* adjacencyList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacencyList[v];
    adjacencyList[v] = newNode;
}

int main() {
    int N = 4;
    Node* adjacencyList[N];

    for(int i = 0; i < N; i++) {
        adjacencyList[i] = NULL;
    }

    addEdge(adjacencyList, 0, 1);
    addEdge(adjacencyList, 0, 2);
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 2, 3);

    for(uint8_t i = 0; i < N; i++) {
        Node* temp = adjacencyList[i];
        printf("Adjacency list of vertex %d: ", i);
        while(temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
