#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    int result = 0;
    
    // Traverse the linked list
    while (head != NULL) {
        // Shift the result left by 1 and add the current node's value
        result = result * 2 + head->val;
        // Move to the next node
        head = head->next;
    }
    
    return result;  // Return the decimal value
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list (for testing purposes)
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Creating a linked list: 1 -> 0 -> 1
    struct ListNode* head = createNode(1);
    head->next = createNode(0);
    head->next->next = createNode(1);
    
    // Print the linked list
    printList(head);
    
    // Get the decimal value of the binary number represented by the linked list
    int decimalValue = getDecimalValue(head);
    
    // Print the result
    printf("Decimal value: %d\n", decimalValue);  // Expected output: 5
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Recursive function to calculate the decimal value from the binary list
int getDecimalValue(struct ListNode* head) {
    if (head == NULL) {
        return 0;  // Base case: if the node is NULL, return 0
    }
    
    // Recursive case: Calculate the decimal value of the current node and recursively solve for the rest
    return head->val + 2 * getDecimalValue(head->next);
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list (for testing purposes)
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Creating a linked list: 1 -> 0 -> 1
    struct ListNode* head = createNode(1);
    head->next = createNode(0);
    head->next->next = createNode(1);
    
    // Print the linked list
    printList(head);
    
    // Get the decimal value of the binary number represented by the linked list
    int decimalValue = getDecimalValue(head);
    
    // Print the result
    printf("Decimal value: %d\n", decimalValue);  // Expected output: 5
    
    return 0;
}
*/