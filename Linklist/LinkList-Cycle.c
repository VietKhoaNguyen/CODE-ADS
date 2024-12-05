#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to check for a cycle
int hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, there can't be a cycle.
        return 0;
    }

    struct ListNode *slow = head; // Tortoise pointer
    struct ListNode *fast = head; // Hare pointer

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow by one step
        fast = fast->next->next;   // Move fast by two steps

        if (slow == fast) {
            // If slow and fast meet, there is a cycle.
            return 1;
        }
    }

    // If fast reaches the end of the list, there is no cycle.
    return 0;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example usage
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Creating a cycle for testing
    head->next->next->next->next = head->next;

    int result = hasCycle(head);
    if (result == 1) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    return 0;
}
