#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode* next;
} StackNode;

StackNode* Init(int newData)
{
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->data = newData;
    newStackNode->next = NULL;
    return newStackNode;
}

void PrintLinkedList(StackNode* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int LengthLinkedList(StackNode* head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void Push(StackNode** head, int newData)
{
    StackNode* newStackNode = Init(newData);
    newStackNode -> next = *head;
    *head = newStackNode;
    return head;
}

int Pop(StackNode** head)
{
    if(*head == NULL){
        printf("error");
        return -1;
    }
    StackNode* temp = *head;
    int Popped = temp -> data;
    *head = (*head) -> next;
    free(temp);
    return Popped;
}

int Peek(StackNode* head)
{
    if(head == NULL){
        printf("empty");
        return -1;
    }return head -> data;
}

int main()
{
     StackNode* stack = NULL;  // Initialize an empty stack

    // Push elements onto the stack
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    Push(&stack, 40);

    // Print the stack
    printf("Stack: ");
    PrintLinkedList(stack);

    // Pop the top element
    printf("Popped: %d\n", Pop(&stack));

    // Print the stack after pop
    printf("Stack after pop: ");
    PrintLinkedList(stack);

    // Peek the top element
    printf("Top element: %d\n", Peek(stack));

    // Print the length of the stack
    printf("Stack length: %d\n", LengthLinkedList(stack));

    return 0;
}
/*recur O(1)
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Function to initialize a new stack node
StackNode* Init(int newData) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->data = newData;
    newStackNode->next = NULL;
    return newStackNode;
}

// Function to print the stack
void PrintLinkedList(StackNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to calculate the length of the stack
int LengthLinkedList(StackNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to push a new element onto the stack
void Push(StackNode** head, int newData) {
    StackNode* newStackNode = Init(newData);
    newStackNode->next = *head;
    *head = newStackNode;
}

// Function to pop an element from the stack
int Pop(StackNode** head) {
    if (*head == NULL) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    StackNode* temp = *head;
    int Popped = temp->data;
    *head = (*head)->next;
    free(temp);
    return Popped;
}

// Function to peek at the top element of the stack
int Peek(StackNode* head) {
    if (head == NULL) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return head->data;
}

int main() {
    StackNode* stack = NULL;  // Initialize an empty stack

    // Push elements onto the stack
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    Push(&stack, 40);

    // Print the stack
    printf("Stack: ");
    PrintLinkedList(stack);

    // Pop the top element
    printf("Popped: %d\n", Pop(&stack));

    // Print the stack after pop
    printf("Stack after pop: ");
    PrintLinkedList(stack);

    // Peek the top element
    printf("Top element: %d\n", Peek(stack));

    // Print the length of the stack
    printf("Stack length: %d\n", LengthLinkedList(stack));

    return 0;
}
*/