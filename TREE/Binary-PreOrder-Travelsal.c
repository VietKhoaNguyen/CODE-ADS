#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    result[(*index)++] = root->val;  // Add current node value
    traverse(root->left, result, index);  // Recur for left subtree
    traverse(root->right, result, index); // Recur for right subtree
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    // Allocate memory for the result array (maximum possible size)
    int* result = (int*)malloc(100 * sizeof(int));  // Adjust size if needed

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int index = 0;  // Tracks the position in the result array
    traverse(root, result, &index);

    *returnSize = index;  // Update the number of elements
    return result;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize = 0;
    int* result = preorderTraversal(root, &returnSize);

    printf("Preorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Free the allocated memory
    return 0;
}
