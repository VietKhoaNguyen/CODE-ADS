#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val1;
    int val2;
    struct Node* next;
}Node;

Node* Init(int val1, int val2)
{
    Node* new= (Node*)malloc(sizeof(Node));
    new->val1=val1;
    new->val2=val2;
    new->next=NULL;
    return new;
}

Node* Insert(Node* node, int val1, int val2)
{
    Node* new=Init(val1,val2);
    if (node==NULL)
    {
        node=new;
        return node;
    }
    Node* cur=node;
    while (cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=new;
    return node;

}
void PrintLinkedList(Node* head)
{
    while (head != NULL)
    {
        printf("%d, ", head->val1);
        printf("%d \n", head->val2);

        head = head->next;
    }

    printf("\n");
}

int Gcd(int a, int b)
{
    int min=a;
    if (min>b)
    {
        min=b;
    }
    for (int  i = min; i > 0; i--)
    {
        if (a%i==0 && b%i==0)
        {
            return i;
        }

    }
    return -1;
}

void FindCoPrime(int a[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (Gcd(a[i],a[j])==1)
            {
                printf("%d, %d are coprime\n", a[i],a[j]);
            }

        }

    }

}

Node* FindCoPrimelink(int a[],int n,Node* head)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (Gcd(a[i],a[j])==1)
            {
                head = Insert(head, a[i],a[j]);
            }

        }

    }
    return head;

}

int main()
{
    int a[10]={2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    Node* head=NULL;
    head = FindCoPrimelink(a,10,head);
    PrintLinkedList(head);
}
