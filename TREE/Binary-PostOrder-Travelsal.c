#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void postorderTraverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    postorderTraverse(root->left, result, index);  // Recur for left subtree
    postorderTraverse(root->right, result, index); // Recur for right subtree
    result[(*index)++] = root->val;                // Add current node value
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* result = (int*)malloc(100 * sizeof(int)); // Allocate memory for the result
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    postorderTraverse(root, result, &index);

    *returnSize = index;
    return result;
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize = 0;
    int* postorderResult = postorderTraversal(root, &returnSize);
    printf("Postorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", postorderResult[i]);
    }
    printf("\n");
    free(postorderResult);

    return 0;
}