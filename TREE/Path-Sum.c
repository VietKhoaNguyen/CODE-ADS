#include <limits.h>  // For INT_MAX

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if there exists a path with the given sum
int hasPathSum(struct TreeNode* root, int targetSum) {
    // Base case: If the node is NULL, no path exists
    if (root == NULL) {
        return 0;  // return 0 for false
    }
    
    // If it's a leaf node, check if the current value equals the target sum
    if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum ? 1 : 0;  // return 1 for true if it matches, else 0
    }
    
    // Recursively check the left and right subtrees, subtracting the current node's value from the target sum
    int newTarget = targetSum - root->val;
    return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
}
