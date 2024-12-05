#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void Post(struct Node* root) {
 
    if (root == NULL)
        return;
  
    //left
    Post(root->left);
    //right
    Post(root->right);

    printf("%d ", root->data);
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
    printf("Postorder traversal: ");
    Post(root);
    printf("\n");
    return 0;
}
