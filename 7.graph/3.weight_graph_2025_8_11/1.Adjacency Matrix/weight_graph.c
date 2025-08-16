#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define V 4

void addEdge(uint8_t mat[V][V], uint8_t i, uint8_t j , uint16_t weight) {
  mat[i][j] = weight;
  mat[j][i] = weight;
}

int main(){
    uint8_t mat[V][V] = {0};
    addEdge(mat,0,1,3);
    addEdge(mat,1,3,5);
    addEdge(mat,3,2,8);
    for(uint8_t i = 0 ; i < V ; i++){
        for(uint8_t j = 0 ; j < V ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

