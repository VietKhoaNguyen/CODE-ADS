#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SIZE 10

// Define the MyStack structure
typedef struct {
    int *data;      // Dynamic array to store stack elements
    int top;        // Index of the top element
    int capacity;   // Current capacity of the stack
} MyStack;

// Function to create a new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->data = (int*)malloc(INITIAL_SIZE * sizeof(int));  // Allocate memory for the stack
    stack->top = -1;   // Stack is empty
    stack->capacity = INITIAL_SIZE;
    return stack;
}

// Function to push an element onto the stack
void myStackPush(MyStack* obj, int x) {
    if (obj->top == obj->capacity - 1) {
        // Resize the array if the stack is full
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
    }
    obj->data[++(obj->top)] = x;
}

// Function to pop the top element from the stack
int myStackPop(MyStack* obj) {
    if (obj->top == -1) {
        // Stack is empty, handle underflow
        return -1;  // Could also handle with an error value or message
    }
    return obj->data[(obj->top)--];
}

// Function to get the top element of the stack
int myStackTop(MyStack* obj) {
    if (obj->top == -1) {
        // Stack is empty, handle error
        return -1;  // Could also handle with an error value or message
    }
    return obj->data[obj->top];
}

// Function to check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

// Function to free the stack's allocated memory
void myStackFree(MyStack* obj) {
    free(obj->data);  // Free the memory used by the stack array
    free(obj);         // Free the memory used by the stack structure
}

// Example usage
int main() {
    MyStack* stack = myStackCreate();
    
    myStackPush(stack, 10);
    myStackPush(stack, 20);
    myStackPush(stack, 30);
    
    printf("Top element: %d\n", myStackTop(stack));  // Should print 30
    printf("Pop element: %d\n", myStackPop(stack));  // Should print 30
    printf("Top element after pop: %d\n", myStackTop(stack));  // Should print 20
    printf("Is stack empty? %d\n", myStackEmpty(stack));  // Should print 0 (false)
    
    myStackFree(stack);
    return 0;
}
