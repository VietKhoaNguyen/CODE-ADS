#include <stdio.h>
/*Given a positive natural number N = 3450, we would like to study numbers by:
- Count the number of odd, even digits of N. Note that 0 is even.
Example:
- The number of odd digits of N = 3450 is 2 with odd digits = {3, 5};
- The number of even digits of N = 3450 is 2 with even digits = {4, 0}
*/
// Ex1: Propose two recursive pseudo-code algorithms to count the number of odd and even digits of N (one function for odd, one function for even)
// Recursive function to count odd digits
int countOddDigits(int N) {                      // O(log(n))
    if (N == 0) return 0;  // Base case
    int lastDigit = N % 10;
    if (lastDigit % 2 != 0)  // Check if the digit is odd
        return 1 + countOddDigits(N / 10);  // Count this digit and recurse on the remaining digits
    else
        return countOddDigits(N / 10);  // Recurse without counting
}

// Recursive function to count even digits
int countEvenDigits(int N) {
    if (N == 0) return 0;  // Base case
    int lastDigit = N % 10;
    if (lastDigit % 2 == 0)  // Check if the digit is even
        return 1 + countEvenDigits(N / 10);  // Count this digit and recurse on the remaining digits
    else
        return countEvenDigits(N / 10);  // Recurse without counting
}

int main() {
    int N = 3450;

    int oddCount = countOddDigits(N);
    int evenCount = countEvenDigits(N);

    printf("Number of odd digits: %d\n", oddCount);
    printf("Number of even digits: %d\n", evenCount);

    return 0;
}
/*function countOddDigits(N) {
    if N is 0, return 0
    lastDigit = N % 10
    if lastDigit is odd, return 1 + countOddDigits(N / 10)
    else, return countOddDigits(N / 10)
}

function countEvenDigits(N) {
    if N is 0, return 0
    lastDigit = N % 10
    if lastDigit is even, return 1 + countEvenDigits(N / 10)
    else, return countEvenDigits(N / 10)
}

main() {
    N = 3450

    oddCount = countOddDigits(N)
    evenCount = countEvenDigits(N)

    output "Number of odd digits: " + oddCount
    output "Number of even digits: " + evenCount
}*/


//Ex2: Implement the Question 1 using a Linked List data structure
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the front of the linked list
struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to create a linked list from the digits of the number N
struct Node* createLinkedList(int N) {
    struct Node* head = NULL;
    if (N == 0) {
        head = addNode(head, 0);  // Special case for 0
    }
    while (N > 0) {
        int digit = N % 10;
        head = addNode(head, digit);  // Add each digit to the list
        N /= 10;
    }
    return head;
}

// Recursive function to count odd digits in the linked list
int countOddDigits(struct Node* head) {
    if (head == NULL) return 0;  // Base case
    if (head->data % 2 != 0)  // Check if the current digit is odd
        return 1 + countOddDigits(head->next);  // Count this digit and recurse on the next node
    else
        return countOddDigits(head->next);  // Recurse without counting
}

// Recursive function to count even digits in the linked list
int countEvenDigits(struct Node* head) {
    if (head == NULL) return 0;  // Base case
    if (head->data % 2 == 0)  // Check if the current digit is even
        return 1 + countEvenDigits(head->next);  // Count this digit and recurse on the next node
    else
        return countEvenDigits(head->next);  // Recurse without counting
}

// Function to print the linked list (for debugging)
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int N = 3450;

    // Create the linked list from the digits of N
    struct Node* head = createLinkedList(N);

    // Count odd and even digits using the linked list
    int oddCount = countOddDigits(head);
    int evenCount = countEvenDigits(head);

    // Output the results
    printf("Number of odd digits: %d\n", oddCount);
    printf("Number of even digits: %d\n", evenCount);

    // Free memory (optional in this case since the program ends here)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
