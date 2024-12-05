#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to calculate the height of a tree
int getHeight(struct TreeNode* root) {
    int height = 0;
    while (root != NULL) {
        height++;
        root = root->left;
    }
    return height;
}

// Optimized function to count nodes in a complete binary tree
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (leftHeight == rightHeight) {
        // If the left and right heights are equal, the tree is a perfect binary tree
        return (1 << leftHeight) + countNodes(root->right);  // 2^leftHeight + nodes in the right subtree
    } else {
        // If the left and right heights are different, the tree is not perfect
        return (1 << rightHeight) + countNodes(root->left);  // 2^rightHeight + nodes in the left subtree
    }
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    // Create a binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int nodeCount = countNodes(root);
    printf("Total number of nodes in the tree: %d\n", nodeCount);

    return 0;
}
