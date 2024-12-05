#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void In(struct Node* root) {
 
    if (root == NULL)
        return;
  
    //left
    In(root->left);
 
    printf("%d ", root->data);
  
    //right
    In(root->right);
}

struct Node* Init(int data) {  
    struct Node* node =
      (struct Node*)malloc(sizeof(struct Node));
  
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return node;
}

int main() {
    struct Node* root = Init(1);
    root->left = Init(2);
    root->right = Init(3);
    root->left->left = Init(4);
    root->left->right = Init(5);
    printf("Inorder traversal: ");
    In(root);
    printf("\n");
    return 0;
}
