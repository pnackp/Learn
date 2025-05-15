#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    struct node *next;
} node;

void addstudent(node **head, node **tail, char name[100]) {
    node *temp = malloc(sizeof(node));
    strcpy(temp->name, name); // Must use strcpy to copy string data into the struct
    temp->next = NULL;

    if (*head == NULL) {
        // If the list is empty, initialize head and tail
        *head = temp;
        *tail = temp;
        (*tail)->next = *head; // Make it circular: point to itself
        return;
    } else {
        // Insert new node at the end, before looping back to head
        temp->next = *head;         // New node points to the current head
        (*tail)->next = temp;       // Current tail points to new node
        *tail = temp;               // Update tail to the new node
        return;
    }
}

void showstuden(node *head, node *tail) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    node *current = head;
    do {
        printf("%s\n", current->name);
        current = current->next;
    } while (current != head); // Stop when looped back to the head
    return;
}

int main() {
    int x;
    char name[100];
    node *head = NULL;
    node *tail = NULL;

    do {
        printf("Select-------\n");
        printf("1: Add student\n");
        printf("2: Show all students\n");
        printf("3: Exit\n");
        printf(": ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                addstudent(&head, &tail, name);
                break;
            case 2:
                showstuden(head, tail);
                break;
            case 3:
                return 0;
        }
    } while (x != 3);

    return 0;
}

