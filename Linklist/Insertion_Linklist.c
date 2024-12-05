#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node in a sorted way in the linked list
void sortedInsert(struct Node** sorted, struct Node* newNode) {
    if (*sorted == NULL || (*sorted)->data >= newNode->data) {
        newNode->next = *sorted;
        *sorted = newNode;
    } else {
        struct Node* current = *sorted;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Insertion Sort function for linked list
void insertionSort(struct Node** head_ref) {
    struct Node* sorted = NULL;
    struct Node* current = *head_ref;
    while (current != NULL) {
        struct Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
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

// Main function to test insertion sort
int main() {
    struct Node* head = NULL;

    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    printf("Linked List before sorting: \n");
    printList(head);

    insertionSort(&head);

    printf("Linked List after insertion sort: \n");
    printList(head);

    return 0;
}
