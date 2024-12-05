#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* top;
    Node* bot;
}Queue;

Queue* QueueInit()
{
    Queue* queue= (Queue*)malloc(sizeof(Queue));
    queue->bot=NULL;
    queue->top=NULL;
    return queue;
}

Node* NodeInit(int data)
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

Queue* Enqueue(Queue* queue, int data)
{
    Node* newNode= NodeInit(data);

    if (queue->top==NULL)
    {
        queue->top=newNode;
        queue->bot=newNode;
        return queue;
    }
    queue->bot->next=newNode;
    queue->bot=newNode;
    return queue;
}

Queue* Dequeue(Queue* queue)
{
    if (queue->top==NULL)
    {
        return queue;
    }

    Node* tempNode=queue->top;
    queue->top=queue->top->next;
    if (queue->top==NULL)
    {
        queue->bot=NULL;
    }
    free(tempNode);
    return queue;
}

int Front(Queue* queue)
{
    if (queue->top==NULL)
    {
        return -1;
    }

    return queue->top->data;
}

void Print(Queue* queue)
{
    Node* current=queue->top;
    while (current!=NULL)
    {
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");
}

int main()
{
    Queue* queue=QueueInit();
    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Dequeue(queue);
    Enqueue(queue, 4);
    Print(queue);

    printf("Front: %d\n", Front(queue));
    Print(queue);
    return 0;
} 
