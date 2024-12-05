#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
struct Node* insertEnd(struct Node* root, int item) {
  
    struct Node* temp = createNode(item);
    if (root == NULL)
        return temp;

    struct Node* last = root;
    while (last->next != NULL) 
        last = last->next;

    last->next = temp;
    return root;
}

struct Node* arrayToList(int arr[], int n) {
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEnd(root, arr[i]);
    }
    return root;
}

void display(struct Node* root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}
