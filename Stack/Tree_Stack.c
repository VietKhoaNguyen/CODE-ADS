#include <stdio.h>
#include <stdlib.h>

// Definition of the TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Definition of the Stack structure
typedef struct Stack {
    TreeNode** data;  // Array of TreeNode pointers
    int top;          // Index of the top element
    int capacity;     // Capacity of the stack
} Stack;

// Function to create a new tree node
TreeNode* createTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a stack with a given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (TreeNode**)malloc(capacity * sizeof(TreeNode*));
    stack->top = -1;  // Stack is initially empty
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push a tree node onto the stack
void push(Stack* stack, TreeNode* node) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = node;
}

// Function to pop a tree node from the stack
TreeNode* pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->data[stack->top--];
}

// In-order traversal using a stack
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Create a stack
    Stack* stack = createStack(100);
    TreeNode* current = root;

    while (current != NULL || !isStackEmpty(stack)) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // Current must be NULL at this point, pop from the stack
        current = pop(stack);
        printf("%d ", current->data);  // Print the data

        // Visit the right subtree
        current = current->right;
    }

    // Free the stack memory
    free(stack->data);
    free(stack);
}

int main() {
    // Create a sample tree
    TreeNode* root = createTreeNode(10);
    root->left = createTreeNode(5);
    root->right = createTreeNode(20);
    root->left->left = createTreeNode(3);
    root->left->right = createTreeNode(7);
    root->right->left = createTreeNode(15);
    root->right->right = createTreeNode(25);

    // Perform in-order traversal using a stack
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory for the tree
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
