#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to compute depth and update diameter
int dfs(struct TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;  // Base case: The depth of a null node is 0
    }
    
    // Recursively find the depth of the left and right subtrees
    int leftDepth = dfs(root->left, diameter);
    int rightDepth = dfs(root->right, diameter);
    
    // Update the diameter: The longest path might pass through this node
    *diameter = fmax(*diameter, leftDepth + rightDepth);
    
    // Return the depth of the current node
    return 1 + fmax(leftDepth, rightDepth);
}

// Main function to find the diameter
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    dfs(root, &diameter);
    return diameter;
}

// Utility function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    int result = diameterOfBinaryTree(root);
    printf("Diameter of the binary tree: %d\n", result);  // Expected output: 3
    
    return 0;
}
