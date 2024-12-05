#include <stdio.h>
#include <stdlib.h>
struct Node {                                   //Complexity: O(n*log(n))
    int data;
    struct Node* next;
};

struct Node* split(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }
    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct Node* merge(struct Node* first, struct Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

struct Node* MergeSort(struct Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* second = split(head);

    head = MergeSort(head);
    second = MergeSort(second);

    return merge(head, second);
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* createNode(int x) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(9);
    head->next = createNode(8);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);

    head = MergeSort(head);
    printList(head);
    return 0;
}
/*
function split(head) {
    fast = head
    slow = head
    while fast is not NULL and fast.next is not NULL {
        fast = fast.next.next
        if fast is not NULL {
            slow = slow.next
        }
    }
    temp = slow.next
    slow.next = NULL
    return temp
}

function merge(first, second) {
    if first is NULL return second
    if second is NULL return first
    
    if first.data is less than second.data {
        first.next = merge(first.next, second)
        return first
    } else {
        second.next = merge(first, second.next)
        return second
    }
}

function mergeSort(head) {
    if head is NULL or head.next is NULL {
        return head
    }
    
    second = split(head)
    
    head = mergeSort(head)
    second = mergeSort(second)
    
    return merge(head, second)
}

function printList(head) {
    curr = head
    while curr is not NULL {
        print curr.data
        curr = curr.next
    }
    print newline
}

function createNode(x) {
    newNode = allocate memory for Node
    newNode.data = x
    newNode.next = NULL
    return newNode
}

head = createNode(9)
head.next = createNode(8)
head.next.next = createNode(5)
head.next.next.next = createNode(2)

head = mergeSort(head)
printList(head)
*/