#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to delete duplicates from a sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Edge case: if the list is empty or has only one element, no duplicates to remove
    if (head == NULL) {
        return head;
    }

    // Pointer to traverse the linked list
    struct ListNode* current = head;

    // Traverse the list and check for duplicates
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Skip the duplicate node by linking to the next of next node
            current->next = current->next->next;
        } else {
            // Move to the next node if no duplicate is found
            current = current->next;
        }
    }

    return head;  // Return the modified list
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the deleteDuplicates function
int main() {
    // Creating a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    // Removing duplicates
    head = deleteDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
/*recrur O(n)
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Recursive function to delete duplicates from a sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Base case: If the list is empty or has only one element, return the list as is
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // If the current node's value is equal to the next node's value, skip the next node
    if (head->val == head->next->val) {
        head->next = head->next->next;
        // Recursively call deleteDuplicates for the next node
        return deleteDuplicates(head);
    } else {
        // Otherwise, just recursively process the next node
        head->next = deleteDuplicates(head->next);
        return head;
    }
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the deleteDuplicates function
int main() {
    // Creating a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    // Removing duplicates
    head = deleteDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
*/