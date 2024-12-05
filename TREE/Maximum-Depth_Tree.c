// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to calculate the maximum depth of a binary tree
int maxDepth(struct TreeNode* root) {
    // Base case: If the tree is empty (root is NULL), return 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively calculate the depth of the left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // The depth of the current node is 1 + the maximum depth of its subtrees
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
