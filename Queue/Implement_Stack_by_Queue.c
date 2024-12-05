#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for a queue
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Function to create a new queue node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue function
void enqueue(Queue* q, int data) {
    Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue function
void dequeue(Queue* q) {
    if (q->front == NULL) {
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Get the front element of the queue
int front(Queue* q) {
    if (q->front == NULL) {
        return -1; // return -1 if queue is empty
    }
    return q->front->data;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Stack structure using two queues
typedef struct Stack {
    Queue *q1, *q2;
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push function for stack
void push(Stack* stack, int data) {
    // Enqueue data into q2
    enqueue(stack->q2, data);

    // Move all elements from q1 to q2
    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, front(stack->q1));
        dequeue(stack->q1);
    }

    // Swap the queues q1 and q2
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

// Pop function for stack
void pop(Stack* stack) {
    // If q1 is empty, return
    if (isEmpty(stack->q1)) {
        return;
    }
    dequeue(stack->q1);
}

// Top function for stack
int top(Stack* stack) {
    if (isEmpty(stack->q1)) {
        return -1; // return -1 if stack is empty
    }
    return front(stack->q1);
}

// Get the size of the stack
int size(Stack* stack) {
    Node* temp = stack->q1->front;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Driver code
int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Current size: %d\n", size(stack));
    printf("Top element: %d\n", top(stack));

    pop(stack);
    printf("Top element after pop: %d\n", top(stack));

    pop(stack);
    printf("Top element after second pop: %d\n", top(stack));

    printf("Current size: %d\n", size(stack));

    return 0;
}
