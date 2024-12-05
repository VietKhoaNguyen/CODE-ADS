#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3
/*Write the program to solve Problem 1 using Linked List ADT with necessary functions and
Linked List principle
Note:
The size of stack is a constant (size = 3) and to use Stack ADT, there should be three steps:
- Step 1: Find and push every prime numbers that constitute a specific sphenic number in the
stack 
Step 2: Pop out all numbers found in the stack and calculate the product of these 3 prime
numbers 
Step 3: Display the result in the stack
*/
struct Node {                                   //Complexity:O(sqrt(n))
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size; 
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(struct Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int isFull(struct Stack* stack) {
    return stack->size == STACK_SIZE;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void findPrimeFactors(int num, struct Stack* stack) {
    for (int i = 2; i <= num && stack->size < STACK_SIZE; i++) {
        if (num % i == 0 && isPrime(i)) {
            push(stack, i); 
            num /= i;
            i--; 
        }
    }
}

int main() {
    struct Stack stack;
    int number;

    initStack(&stack);

    printf("Enter a sphenic number: ");
    scanf("%d", &number);

    findPrimeFactors(number, &stack);

    if (stack.size != STACK_SIZE) {
        printf("The number is not a sphenic number.\n");
    } else {
        int product = 1;
        printf("Prime factors: ");
        while (!isEmpty(&stack)) {
            int prime = pop(&stack);
            printf("%d ", prime);
            product *= prime;
        }
        printf("\nProduct of prime factors: %d\n", product);
    }

    return 0;
}
/*
// Define the size of the stack
STACK_SIZE = 3

// Define a node struct
struct Node {                              
    int data
    Node* next
}

// Define a stack struct
struct Stack {
    Node* top
    int size
}

// Function to create a new node with data
function createNode(data):
    newNode = new Node
    newNode.data = data
    newNode.next = NULL
    return newNode

// Function to initialize the stack
function initStack(stack):
    stack.top = NULL
    stack.size = 0

// Function to check if the stack is empty
function isEmpty(stack):
    return stack.top == NULL

// Function to check if the stack is full
function isFull(stack):
    return stack.size == STACK_SIZE

// Function to push a value onto the stack
function push(stack, value):
    if isFull(stack):
        print "Stack overflow"
        return
    newNode = createNode(value)
    newNode.next = stack.top
    stack.top = newNode
    stack.size++

// Function to pop a value from the stack
function pop(stack):
    if isEmpty(stack):
        print "Stack underflow"
        return -1
    temp = stack.top
    poppedValue = temp.data
    stack.top = stack.top.next
    free(temp)
    stack.size--
    return poppedValue

// Function to check if a number is prime
function isPrime(num):
    if num <= 1:
        return 0
    for i from 2 to sqrt(num):
        if num % i == 0:
            return 0
    return 1

// Function to find prime factors of a number and push them onto the stack
function findPrimeFactors(num, stack):
    for i from 2 to num and stack.size < STACK_SIZE:
        if num % i == 0 and isPrime(i):
            push(stack, i)
            num /= i
            i--

function main():
    // Initialize the stack
    stack = new Stack
    number = 0

    initStack(stack)

    // Prompt the user to enter a sphenic number
    print "Enter a sphenic number: "
    number = input()

    findPrimeFactors(number, stack)

    if stack.size != STACK_SIZE:
        print "The number is not a sphenic number."
    else:
        product = 1
        print "Prime factors: "
        while not isEmpty(stack):
            prime = pop(stack)
            print prime + " "
            product *= prime
        print "\nProduct of prime factors: " + product

main()
*/