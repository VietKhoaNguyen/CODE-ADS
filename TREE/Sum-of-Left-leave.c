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

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: if the tree is empty
    }

    int sum = 0;

    // Check if the left child is a leaf
    if (root->left && root->left->left == NULL && root->left->right == NULL) {
        sum += root->left->val; // Add the value of the left leaf
    }

    // Recursively calculate the sum for left and right subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

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

    int result = sumOfLeftLeaves(root);
    printf("The sum of left leaves is %d.\n", result);

    return 0;
}
