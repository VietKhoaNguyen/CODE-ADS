#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Stack* StackInit() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

StackNode* StackNodeInit(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

Stack* Insert(Stack* stack, int data) {
    StackNode* node = StackNodeInit(data);
    node->next = stack->top;
    stack->top = node;
    return stack;
}

void Pop(Stack* stack) {
    if (stack->top == NULL) {
        return;
    }
    StackNode* temp = stack->top; 
    stack->top = stack->top->next;
    free(temp);
}

int Top(Stack* stack) {
    if (stack->top == NULL) {
        return -1; 
    }
    return stack->top->data;
}

void Print(Stack* stack) {
    StackNode* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data); 
        node = node->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = StackInit();
    Insert(stack, 1);
    Insert(stack, 2);
    Insert(stack, 3);
    Insert(stack, 4);

    printf("Top element: %d\n", Top(stack)); 
    Pop(stack);
    Print(stack);

    return 0;
} 
