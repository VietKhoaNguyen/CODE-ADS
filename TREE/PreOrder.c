#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Init(int v) {
    struct Node* node =
      (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printPreorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    //left
    printPreorder(node->left);
    //right
    printPreorder(node->right);
}

int main() {
    struct Node* root = Init(1);
    root->left = Init(2);
    root->right = Init(3);
    root->left->left = Init(4);
    root->left->right = Init(5);
    root->right->right = Init(6);
    printf("\n");
    printPreorder(root);
    printf("\n");
    return 0;
}
