#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*In this problem, we try to implement the navigation system in a web browser to
back/forward a visiting website using a stack for Backward and another for Forward.
Choose one method to implement a Stack data structure (Array-based or Stack using
Linked List) to implement this problem.
- A website may contain a url and a title; suppose that we have visited a list of
websites.
- The order of visited websites is stored in a Backward stack according to FILO.
- If we return to the previous website, we pop the Backward stack and push it
into the Forward stack.
- And otherwise, when we forward to the next website, we retrieve the top
website from the Forward stack and push it into the Backward stack.*/
typedef struct Node {
    char url[100];
    char title[100];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* Init() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void Push(Stack* stack, const char* url, const char* title) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    strcpy(newNode->title, title);
    newNode->next = stack->top;
    stack->top = newNode;
}

Node* Pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return NULL;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

void BackWard(Stack* backward, Stack* forward) {
    Node* temp = Pop(backward);
    if (temp) {
        Push(forward, temp->url, temp->title);
        free(temp); // Free the popped node after moving it
    }
}

void ForWard(Stack* backward, Stack* forward) {
    Node* temp = Pop(forward);
    if (temp) {
        Push(backward, temp->url, temp->title);
        free(temp); // Free the popped node after moving it
    }
}

void Display(Stack* backward, Stack* forward) {
    printf("Backward Stack:\n");
    for (Node* curr = backward->top; curr != NULL; curr = curr->next) {
        printf("URL: %s, Title: %s\n", curr->url, curr->title);
    }
    printf("\nForward Stack:\n");
    for (Node* curr = forward->top; curr != NULL; curr = curr->next) {
        printf("URL: %s, Title: %s\n", curr->url, curr->title);
    }
}

int main() {
    Stack* backward = Init();
    Stack* forward = Init();

    Push(backward, "kiga.github.io", "KigaGame");
    Push(backward, "ponhub.com", "PonHub");

    BackWard(backward, forward);
    BackWard(backward, forward);

    Display(backward, forward);

    // Freeing allocated memory
    free(backward);
    free(forward);

    return 0;
}
