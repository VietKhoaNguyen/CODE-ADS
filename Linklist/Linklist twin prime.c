#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure for Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to insert a prime number at the end of the linked list
void insertPrime(Node** head, int value) {
    if (isPrime(value)) {
        Node* newNode = createNode(value);
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to print all twin primes in the linked list
void printTwinPrimes(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data - temp->data == 2) {
            printf("(%d, %d) are twin primes.\n", temp->data, temp->next->data);
        }
        temp = temp->next;
    }
}

// Function to free the memory of the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    
    // Insert prime numbers into the linked list
    for (int i = 2; i <= 100; i++) {
        insertPrime(&head, i);
    }

    // Print twin primes
    printTwinPrimes(head);

    // Free the memory allocated for the linked list
    freeList(head);
    
    return 0;
}
/*recur O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure for Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to insert a prime number at the end of the linked list
void insertPrime(Node** head, int value) {
    if (isPrime(value)) {
        Node* newNode = createNode(value);
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to print all twin primes in the linked list
void printTwinPrimes(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data - temp->data == 2) {
            printf("(%d, %d) are twin primes.\n", temp->data, temp->next->data);
        }
        temp = temp->next;
    }
}

// Function to free the memory of the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    
    // Insert prime numbers into the linked list
    for (int i = 2; i <= 100; i++) {
        insertPrime(&head, i);
    }

    // Print twin primes
    printTwinPrimes(head);

    // Free the memory allocated for the linked list
    freeList(head);
    
    return 0;
}
*/