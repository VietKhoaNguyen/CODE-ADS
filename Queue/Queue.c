#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int* queue;
    int capicity;
    int size;
    int front;
} Queue;

Queue* Init(int capicity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->capicity = capicity;
    newQueue->size = 0;
    newQueue->front = 0;
    newQueue->queue = (int*)malloc(sizeof(int) * capicity);
    return newQueue;
}

void PrintQueue(Queue* myqueue)
{
    for (int i = 0; i < myqueue->size; i++)
    {
        printf("%d ", myqueue->queue[(myqueue->front + i) % myqueue->capicity]);
    }
    printf("\n");
}

int Size(Queue* myqueue)
{
    return myqueue->size;
}

int IsEmpty(Queue* myqueue)
{
    return myqueue->size == 0;
}

void Enqueue(Queue* myqueue, int newData)
{
    if (myqueue->size < myqueue->capicity)
    {
        myqueue->queue[(myqueue->front + myqueue->size) % myqueue->capicity] = newData;
        myqueue->size++;
    }
}

int Dequeue(Queue* myqueue)
{
    if (myqueue->size > 0)
    {
        int last =  myqueue->queue[myqueue->front];
        myqueue->size--;
        myqueue->front = (myqueue->front + 1) % myqueue->capicity;
        return last;
    }

    return -1;
}

int Peek(Queue* myqueue)
{
    if (myqueue->size > 0)
    {
        return myqueue->queue[myqueue->front];
    }

    return -1;
}

int main()
{
    Queue* myqueue = Init(3);
    Enqueue(myqueue, 1);
    Enqueue(myqueue, 2);
    Enqueue(myqueue, 3);
    Dequeue(myqueue);
    Dequeue(myqueue);
    Enqueue(myqueue, 4);
    Enqueue(myqueue, 5);

    PrintQueue(myqueue);
    printf("%d\n", Peek(myqueue));
}