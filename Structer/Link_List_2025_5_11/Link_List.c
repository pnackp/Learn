#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

int main(){
    node *TheFirst = NULL; // Set Head = NULl
    for (int i = 0 ; i < 3 ; i++){
        node *Temp = malloc(sizeof(node)); // Create New node and malloc them with sizeof(node);
        if (Temp == NULL) {
            return 1;
        }

        int x;
        scanf("%d", &x);
        Temp->data = x; // insert number of x into the temp ; 
        Temp->next = TheFirst; // This line mean the first time head would be Null
        TheFirst = Temp; // example = (1(2)) = 1/NULL (3(2)) = 3/1/NUll / (4(3)) = 4/3/1/Null;
    }

    node *ptr = TheFirst;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    ptr = TheFirst;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
