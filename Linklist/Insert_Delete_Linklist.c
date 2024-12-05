#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* Init(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int LengthLinkedList(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* Insert(Node* head, int pos, int newData)
{
    if (pos < 1 || pos > LengthLinkedList(head) + 1)
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

     Node*  current = head;
     for (int i = 1; i < pos - 1; i++)
     {
         current = current->next;
     }

    newNode->next = current->next;
    current->next = newNode;
}

Node* Delete(Node* head, int pos)
{
    if (pos<1 || pos>LengthLinkedList(head))
    {
        return head;
    }
    if (pos==1)
    {
        head=head->next;
        return head;
    }

    Node* cur= head;
    for (int i = 1; i < pos-1; i++)
    {
        cur=cur->next;
    }
    cur->next=cur->next->next;
    return head;
}

int main() {
  
}
