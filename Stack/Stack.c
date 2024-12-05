#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int* stack; 
    int size;
    int capicity;
} Stack;

Stack* Init(int capicity)
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->stack = (int*)malloc(sizeof(int) * capicity);
    newStack->size = 0;
    newStack->capicity = capicity;
    return newStack;
}

void PrintStack(Stack* myStack)
{
    for (int i = 0; i < myStack->size; i++)
    {
        printf("%d ", myStack->stack[i]);
    }
    printf("\n");
}

void Push(Stack* myStack, int newData)
{
    if (myStack->size < myStack->capicity)
    {
        myStack->stack[myStack->size++] = newData;
    }
}

int Pop(Stack* myStack)
{
    if (myStack->size > 0)
    {
        return myStack->stack[--myStack->size];
    }

    return -1;
}

int Peek(Stack* myStack)
{
    if (myStack->size > 0)
    {
        return myStack->stack[myStack->size-1];
    }

    return -1;
}

int Size(Stack* myStack)
{
    return myStack->size;
}

int IsEmpty(Stack* myStack)
{
    return myStack->size == 0;
}

int main()
{
    Stack* myStack = Init(5);
    Push(myStack, 1);
    Push(myStack, 2);
    Push(myStack, 3);
    Pop(myStack);
    Push(myStack, 4);

    printf("%d\n", Pop(myStack));
    PrintStack(myStack);
}