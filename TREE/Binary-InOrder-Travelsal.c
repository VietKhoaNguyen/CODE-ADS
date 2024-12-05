#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    inorderTraverse(root->left, result, index);  // Recur for left subtree
    result[(*index)++] = root->val;             // Add current node value
    inorderTraverse(root->right, result, index); // Recur for right subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* result = (int*)malloc(100 * sizeof(int)); // Allocate memory for the result
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    inorderTraverse(root, result, &index);

    *returnSize = index;
    return result;
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize = 0;

    int* inorderResult = inorderTraversal(root, &returnSize);
    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", inorderResult[i]);
    }
    printf("\n");
    free(inorderResult);

      return 0;
}