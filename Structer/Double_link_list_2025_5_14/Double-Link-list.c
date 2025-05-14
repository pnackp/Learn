#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} node;

int main() {
    node *head = NULL;

    for (int i = 0; i < 3; i++) {
        int x;
        scanf("%d", &x);

        node *temp = malloc(sizeof(node));
        temp->data = x; 
        temp->next = head;
        temp->prev = NULL;

        if (head != NULL) {
            head->prev = temp;
        }

        head = temp;
    }
}
