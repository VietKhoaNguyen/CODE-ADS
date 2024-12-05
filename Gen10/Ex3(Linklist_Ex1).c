#include <stdio.h>
#include <stdlib.h>

// Node structure for the Linked List
struct Node {                                       //Complexity:O(n^2)
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to calculate the GCD of two numbers using recursion (Euclidean Algorithm)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find and print co-prime pairs from the linked list
void findCoprimePairs(struct Node* head) {
    struct Node* ptr1 = head;
    struct Node* ptr2;

    printf("Co-prime pairs are:\n");

    // Iterate through all pairs of nodes in the list
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            // Check if GCD of ptr1->data and ptr2->data is 1
            if (gcd(ptr1->data, ptr2->data) == 1) {
                printf("(%d, %d)\n", ptr1->data, ptr2->data);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Given array of 10 elements
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert the array elements into the linked list
    for (int i = 0; i < n; i++) {
        insertNode(&head, arr[i]);
    }

    // Find and print all co-prime pairs from the linked list
    findCoprimePairs(head);

    // Free the linked list to release allocated memory
    freeList(head);

    return 0;
}
/*
include <stdio.h>
include <stdlib.h>

// Node structure for the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to calculate the GCD of two numbers using recursion (Euclidean Algorithm)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find and print co-prime pairs from the linked list
void findCoprimePairs(struct Node* head) {
    struct Node* ptr1 = head;
    struct Node* ptr2;

    printf("Co-prime pairs are:\n");

    // Iterate through all pairs of nodes in the list
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            // Check if GCD of ptr1->data and ptr2->data is 1
            if (gcd(ptr1->data, ptr2->data) == 1) {
                printf("(%d, %d)\n", ptr1->data, ptr2->data);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Given array of 10 elements
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert the array elements into the linked list
    for (int i = 0; i < n; i++) {
        insertNode(&head, arr[i]);
    }

    // Find and print all co-prime pairs from the linked list
    findCoprimePairs(head);

    // Free the linked list to release allocated memory
    freeList(head);

    return 0;
}
*/