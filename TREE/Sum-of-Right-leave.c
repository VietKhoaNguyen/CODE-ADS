#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfRightLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: if the tree is empty
    }

    int sum = 0;

    // Check if the right child is a leaf
    if (root->right && root->right->left == NULL && root->right->right == NULL) {
        sum += root->right->val; // Add the value of the right leaf
    }

    // Recursively calculate the sum for left and right subtrees
    sum += sumOfRightLeaves(root->left);
    sum += sumOfRightLeaves(root->right);

    return sum;
}

// Helper function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int result = sumOfRightLeaves(root);
    printf("The sum of right leaves is %d.\n", result);

    return 0;
}
