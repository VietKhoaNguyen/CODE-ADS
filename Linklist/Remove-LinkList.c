#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to remove elements from the linked list
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node pointing to the head of the list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* current = dummy;

    // Traverse the list and remove nodes with the given value
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Skip the node with the given value
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);  // Free the removed node
        } else {
            current = current->next;  // Move to the next node
        }
    }

    struct ListNode* newHead = dummy->next;  // The new head of the list after removal
    free(dummy);  // Free the dummy node
    return newHead;
}

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Create a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original List: ");
    printList(head);

    int valToRemove = 6;
    head = removeElements(head, valToRemove);

    printf("List after removing %d: ", valToRemove);
    printList(head);

    return 0;
}
