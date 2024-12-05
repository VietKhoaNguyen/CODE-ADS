#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the structure for the queue using two stacks
typedef struct {
    int *inStack;  // Stack for pushing elements
    int *outStack; // Stack for popping elements
    int inTop;      // Pointer for the top of inStack
    int outTop;     // Pointer for the top of outStack
    int capacity;   // Maximum capacity of the stacks
} MyQueue;

// Function to create a new queue
MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100; // Set capacity to a default value
    queue->inStack = (int*)malloc(sizeof(int) * queue->capacity);
    queue->outStack = (int*)malloc(sizeof(int) * queue->capacity);
    queue->inTop = 0;  // Initialize top pointer for inStack
    queue->outTop = 0; // Initialize top pointer for outStack
    return queue;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    // Push the element to inStack
    obj->inStack[obj->inTop++] = x;
}

// Function to pop an element from the queue
int myQueuePop(MyQueue* obj) {
    // If outStack is empty, move all elements from inStack to outStack
    if (obj->outTop == 0) {
        while (obj->inTop > 0) {
            obj->outStack[obj->outTop++] = obj->inStack[--obj->inTop];
        }
    }
    // Pop the element from outStack
    return obj->outStack[--obj->outTop];
}

// Function to peek at the front element of the queue
int myQueuePeek(MyQueue* obj) {
    // If outStack is empty, move all elements from inStack to outStack
    if (obj->outTop == 0) {
        while (obj->inTop > 0) {
            obj->outStack[obj->outTop++] = obj->inStack[--obj->inTop];
        }
    }
    // Return the top element of outStack (front of the queue)
    return obj->outStack[obj->outTop - 1];
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return obj->inTop == 0 && obj->outTop == 0;
}

// Function to free the memory of the queue
void myQueueFree(MyQueue* obj) {
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
int main() {
    MyQueue* obj = myQueueCreate();
    
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    printf("Front element: %d\n", myQueuePeek(obj)); // Output: 1
    printf("Pop element: %d\n", myQueuePop(obj));   // Output: 1
    printf("Is queue empty? %d\n", myQueueEmpty(obj)); // Output: false
    myQueueFree(obj);

    return 0;
}
