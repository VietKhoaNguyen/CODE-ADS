#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.                       // O (n)
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to add two numbers represented by linked lists.
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // Dummy node to simplify list operations
    struct ListNode* current = &dummy; // Pointer to build the result list
    dummy.next = NULL;

    int carry = 0; // Initialize carry to 0

    while (l1 || l2 || carry) {
        int sum = carry; // Start with carry from the previous step

        if (l1) {
            sum += l1->val; // Add value from l1 if it exists
            l1 = l1->next; // Move to the next node in l1
        }
        if (l2) {
            sum += l2->val; // Add value from l2 if it exists
            l2 = l2->next; // Move to the next node in l2
        }

        carry = sum / 10; // Compute the new carry
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10; // Store the current digit
        newNode->next = NULL;

        current->next = newNode; // Attach the new node to the result list
        current = current->next; // Move to the next node
    }

    return dummy.next; // Return the result list, skipping the dummy node
}

// Helper function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Test function
int main() {
    // Create first number: 342 (2 -> 4 -> 3)
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Create second number: 465 (5 -> 6 -> 4)
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // Add the two numbers
    struct ListNode* result = addTwoNumbers(l1, l2);

    // Print the result: 807 (7 -> 0 -> 8)
    printf("Result: ");
    printList(result);

    return 0;
}
/* Recursive approach
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Recursive helper function
struct ListNode* addTwoNumbersRec(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (!l1 && !l2 && carry == 0) {
        return NULL;
    }

    int sum = carry;
    if (l1) {
        sum += l1->val;
        l1 = l1->next;
    }
    if (l2) {
        sum += l2->val;
        l2 = l2->next;
    }

    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = sum % 10;
    newNode->next = addTwoNumbersRec(l1, l2, sum / 10);

    return newNode;
}

// Wrapper function
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumbersRec(l1, l2, 0);
}

// Helper functions
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Test function
int main() {
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
*/