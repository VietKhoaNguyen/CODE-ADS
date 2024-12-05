#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void sortedInsert(struct Node** head_ref, struct Node* newNode) {
    struct Node* current;


    if (*head_ref == NULL || (*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
       
        current = *head_ref;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

struct Node* insertionSort(struct Node* head) {
    struct Node* sorted = NULL;

    struct Node* current = head;
    while (current != NULL) {
   
        struct Node* next = current->next;
     
        sortedInsert(&sorted, current);
    
        current = next;
    }

    return sorted;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

int main() {
    struct Node* head = NULL;

    append(&head, 12);
    append(&head, 7);
    append(&head, 9);
    append(&head, 1);
    append(&head, 5);

    printf("Original list: ");
    printList(head);

    head = insertionSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}

/*
function createNode(val) {
    newNode = create a new Node
    newNode.data = val
    newNode.next = NULL
    return newNode
}

function sortedInsert(head_ref, newNode) {
    current = NULL
    
    if head_ref is NULL or head_ref.data >= newNode.data then
        newNode.next = head_ref
        head_ref = newNode
    else
        current = head_ref
        while current.next is not NULL and current.next.data < newNode.data
            current = current.next
        newNode.next = current.next
        current.next = newNode
    end if
}

function insertionSort(head) {
    sorted = NULL
    current = head

    while current is not NULL
        next = current.next
        sortedInsert(&sorted, current)
        current = next
    end while

    return sorted
}

function printList(head) {
    while head is not NULL
        print head.data
        head = head.next
    end while
    print a new line
}

function append(head_ref, new_data) {
    newNode = createNode(new_data)
    last = head_ref

    if head_ref is NULL then
        head_ref = newNode
        return
    end if

    while last.next is not NULL
        last = last.next
    end while

    last.next = newNode
}

head = NULL

append(head, 12)
append(head, 7)
append(head, 9)
append(head, 1)
append(head, 5)

print "Original list: "
printList(head)

head = insertionSort(head)

print "Sorted list: "
printList(head)
*/