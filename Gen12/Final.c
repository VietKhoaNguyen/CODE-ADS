/*Twin prime */
//Ex1: Recursion
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define the maximum number to check for primes

// Function to fill an array with prime numbers up to a given limit
void fillPrimesArray(int primes[], int* primeCount, int limit) {      // O(n^2)
    for (int i = 2; i <= limit; i++) {
        int isPrime = 1;  // Assume i is prime
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;  // Found a divisor, so i is not prime
                break;  // Exit the inner loop
            }
        }
        if (isPrime) {
            primes[(*primeCount)++] = i;  // Store the prime and increment the count
        }
    }
}

// Recursive function to find and print twin primes
void findTwinPrimes(int primes[], int index, int primeCount) {
    if (index >= primeCount - 1) return;  // Base case: no more pairs to check
    if (primes[index + 1] - primes[index] == 2) {
        printf("(%d, %d)\n", primes[index], primes[index + 1]);  // Print twin prime pair
    }
    findTwinPrimes(primes, index + 1, primeCount);  // Recursive call
}

int main() {
    int limit = MAX;
    int primes[MAX];  // Array to hold prime numbers
    int primeCount = 0;

    // Fill the primes array
    fillPrimesArray(primes, &primeCount, limit);

    // Find and print twin primes
    printf("Twin primes up to %d are:\n", limit);
    findTwinPrimes(primes, 0, primeCount);

    return 0;
}
/*/*function fillPrimesArray(primes[], primeCount, limit):
    for i from 2 to limit:
        isPrime = 1
        for j from 2 to sqrt(i):
            if i mod j == 0:
                isPrime = 0
                break
        if isPrime:
            primes[primeCount] = i
            primeCount = primeCount + 1

function findTwinPrimes(primes[], index, primeCount):
    if index >= primeCount - 1:
        return
    if primes[index + 1] - primes[index] == 2:
        print "(" + primes[index] + ", " + primes[index + 1] + ")"
    findTwinPrimes(primes, index + 1, primeCount)

function main():
    MAX = 100
    limit = MAX
    primes[MAX]
    primeCount = 0

    fillPrimesArray(primes, primeCount, limit)

    print "Twin primes up to " + limit + " are:"
    findTwinPrimes(primes, 0, primeCount)*/

//Ex2: Linklist ADT
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Not prime
    }
    return 1; // Prime
}

// Function to fill the linked list with prime numbers up to a given limit
struct Node* fillPrimesList(int limit) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            struct Node* newNode = createNode(i);
            if (head == NULL) {
                head = newNode; // First node
                tail = head;
            } else {
                tail->next = newNode; // Add to the end
                tail = newNode;
            }
        }
    }
    return head;
}

// Recursive function to find and print twin primes
void findTwinPrimes(struct Node* head) {
    if (head == NULL || head->next == NULL) return; // Base case

    if (head->next->data - head->data == 2) {
        printf("(%d, %d)\n", head->data, head->next->data); // Print twin prime pair
    }
    findTwinPrimes(head->next); // Recursive call
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
    int limit = 100; // Define the maximum number to check for primes

    // Fill the linked list with prime numbers
    struct Node* primesList = fillPrimesList(limit);

    // Find and print twin primes
    printf("Twin primes up to %d are:\n", limit);
    findTwinPrimes(primesList);

    // Free the linked list
    freeList(primesList);

    return 0;
}
/*FUNCTION createNode(data)
    newNode = new Node
    newNode.data = data
    newNode.next = NULL
    RETURN newNode

FUNCTION isPrime(num)
    IF num <= 1 THEN
        RETURN 0 // Not prime
    END IF
    FOR i = 2 to i * i <= num
        IF num % i == 0 THEN
            RETURN 0 // Not prime
        END IF
    END FOR
    RETURN 1 // Prime

FUNCTION fillPrimesList(limit)
    head = NULL
    tail = NULL
    FOR i = 2 to i <= limit
        IF isPrime(i) THEN
            newNode = createNode(i)
            IF head == NULL THEN
                head = newNode // First node
                tail = head
            ELSE
                tail.next = newNode // Add to the end
                tail = newNode
            END IF
        END IF
    END FOR
    RETURN head

FUNCTION findTwinPrimes(head)
    IF head == NULL OR head.next == NULL THEN
        RETURN // Base case
    END IF
    IF head.next.data - head.data == 2 THEN
        PRINT "(" + head.data + ", " + head.next.data + ")" // Print twin prime pair
    END IF
    findTwinPrimes(head.next) // Recursive call

FUNCTION freeList(head)
    WHILE head != NULL
        temp = head
        head = head.next
        free(temp)
    END WHILE

limit = 100
primesList = fillPrimesList(limit)

PRINT "Twin primes up to " + limit + " are:"
findTwinPrimes(primesList)

freeList(primesList)*/

