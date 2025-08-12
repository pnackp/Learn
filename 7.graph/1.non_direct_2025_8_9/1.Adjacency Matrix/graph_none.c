#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define V 4

void addEdge(uint8_t mat[V][V], uint8_t i, uint8_t j) {
    mat[i][j] = 1;
    mat[j][i] = 1;  
}

int main(){
    uint8_t mat[V][V] = {0};
    addEdge(mat,0,1);
    addEdge(mat,1,3);
    addEdge(mat,3,2);
    for(uint8_t i = 0 ; i < V ; i++){
        for(uint8_t j = 0 ; j < V ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}