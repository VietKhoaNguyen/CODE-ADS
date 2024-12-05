#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Init(int data) {
    struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return Init(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data); //left
    } else if (data > root->data) {
        root->right = insert(root->right, data);//right
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 12);
    insert(root, 10);
    insert(root, 14);
    insert(root, 13);
    insert(root, 17);
    insert(root, 22);
    insert(root, 2);
    inorder(root);
    return 0;
}
