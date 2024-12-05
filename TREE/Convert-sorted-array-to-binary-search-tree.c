// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a BST from a sorted subarray
struct TreeNode* helper(int* nums, int left, int right) {
    // Base case: if the current subarray is empty, return NULL
    if (left > right) {
        return NULL;
    }

    // Find the middle element
    int mid = left + (right - left) / 2;

    // Create a new node with the middle element
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = NULL;
    root->right = NULL;

    // Recursively build the left and right subtrees
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);

    return root;
}

// Main function to convert a sorted array to a BST
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}
