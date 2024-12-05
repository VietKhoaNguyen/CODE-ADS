#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to simplify the merge process
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    
    // Traverse both lists and merge them
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // If one of the lists is not empty, append the remaining elements
    if (list1 != NULL) {
        current->next = list1;
    } else if (list2 != NULL) {
        current->next = list2;
    }
    
    // Return the merged list, which is next to the dummy node
    return dummy.next;
}

// Function to create a new node (for testing purposes)
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list (for testing purposes)
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create first list: 1 -> 2 -> 4
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    
    // Create second list: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    // Merge the two sorted lists
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    
    // Print the merged list: Expected output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL
    printList(mergedList);
    
    return 0;
}
/*recur O(n+m)
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists recursively
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Base cases:
    if (list1 == NULL) return list2; // If list1 is empty, return list2
    if (list2 == NULL) return list1; // If list2 is empty, return list1

    // Recursive step: compare the values of list1 and list2
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2); // Merge the rest of list1 with list2
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next); // Merge list1 with the rest of list2
        return list2;
    }
}

// Function to create a new node (for testing purposes)
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list (for testing purposes)
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create first list: 1 -> 2 -> 4
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    
    // Create second list: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    // Merge the two sorted lists recursively
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    
    // Print the merged list: Expected output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL
    printList(mergedList);
    
    return 0;
}
*/