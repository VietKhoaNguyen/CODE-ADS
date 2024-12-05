#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

int Length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int FindPivot(int* a, int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (a[j] < pivot) {
            int temp = a[j];
            a[j] = a[++i];
            a[i] = temp;
        }
    }
    int temp = a[end];
    a[end] = a[++i];
    a[i] = temp;
    return i;
}

void QuickSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = FindPivot(arr, start, end);
    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

Node* Sort(Node* head) {
    Node* cur1 = head;
    int n = Length(head);

    int* arr = (int*)malloc(sizeof(int) * n);
    int i = 0;

    while (cur1 != NULL) {
        arr[i] = cur1->data;
        cur1 = cur1->next;
        i++;
    }

    QuickSort(arr, 0, n - 1);

    i = 0;
    Node* cur2 = head;
    while (i < n) {
        cur2->data = arr[i];
        i++;
        cur2 = cur2->next;
    }

    free(arr);
    return head;
}

void push(Node** headRef, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    push(&head, 12);
    push(&head, 4);
    push(&head, 8);
    push(&head, 3);
    push(&head, 15);

    printf("Original List:\n");
    printList(head);
    head = Sort(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
