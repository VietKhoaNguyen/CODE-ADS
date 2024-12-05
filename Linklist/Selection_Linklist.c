#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to swap data between two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Selection Sort function for linked list
void selectionSort(struct Node* head) {
    struct Node* temp1 = head;
    while (temp1 != NULL) {
        struct Node* min = temp1;
        struct Node* temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp2->data < min->data) {
                min = temp2;
            }
            temp2 = temp2->next;
        }
        swap(temp1, min);
        temp1 = temp1->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Main function to test selection sort
int main() {
    struct Node* head = NULL;
    
    push(&head, 64);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    push(&head, 11);

    printf("Linked List before sorting: \n");
    printList(head);

    selectionSort(head);

    printf("Linked List after selection sort: \n");
    printList(head);

    return 0;
}
