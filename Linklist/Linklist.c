#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* Init(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void PrintLinkedList(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int Length(Node* head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

Node* Insert(Node* head, int newData, int pos)
{
    if (pos < 1 || pos > Length(head) + 1)
    {
        return head;
    }

    Node* newNode = Init(newData);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next; 
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

Node* Delete(Node* head, int pos)
{
    if (pos < 1 || pos > Length(head))
    {
        return head;
    }

    if (pos == 1)
    {
        head = head->next;
        return head;
    }

    Node* current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next; 
    }

    current->next = current->next->next;
    return head;
}

int main()
{
    Node* head = Init(1);
    Node* node1 = Init(2);
    Node* node2 = Init(3);
    Node* node3 = Init(4);
    Node* node4 = Init(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    head = Insert(head, 6, 3);
    head = Delete(head, 4);
    PrintLinkedList(head);
}