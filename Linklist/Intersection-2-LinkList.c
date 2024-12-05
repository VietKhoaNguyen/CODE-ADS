#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the intersection node of two linked lists
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    // Traverse both lists. When one pointer reaches the end, reset it to the head of the other list.
    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    // Either the intersection node or NULL
    return ptrA;
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

// Example to test the getIntersectionNode function
int main() {
    // Create two linked lists with an intersection
    struct ListNode* headA = createNode(1);
    headA->next = createNode(2);

    struct ListNode* headB = createNode(3);
    headB->next = createNode(4);

    // Create an intersection node
    struct ListNode* intersection = createNode(5);
    headA->next->next = intersection;
    headB->next->next = intersection;

    // Add more nodes to the intersection
    intersection->next = createNode(6);
    intersection->next->next = createNode(7);

    // Print the lists
    printf("List A: ");
    printList(headA);
    printf("List B: ");
    printList(headB);

    // Find the intersection node
    struct ListNode* result = getIntersectionNode(headA, headB);
    if (result != NULL) {
        printf("Intersection at node with value: %d\n", result->val);
    } else {
        printf("No intersection.\n");
    }

    return 0;
}
