#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Queue
{
    int* data;
    int size;
    int capacity;
} Queue;

Queue* InitQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);  // Allocate memory for queue data
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

TreeNode* InitTreeNode(int newData)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = newData;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Put(Queue* queue, TreeNode* treeNode)
{
    if (treeNode == NULL) return;

    if (queue->size < queue->capacity)  // Ensure we don't overflow the queue
    {
        queue->data[queue->size] = treeNode->data;
        queue->size++;
    }
    Put(queue, treeNode->left);
    Put(queue, treeNode->right);
}

void PreOrderTraversal(Queue* queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    TreeNode* root = InitTreeNode(10);
    TreeNode* tnode1 = InitTreeNode(4);
    TreeNode* tnode2 = InitTreeNode(8);
    TreeNode* tnode3 = InitTreeNode(13);
    TreeNode* tnode4 = InitTreeNode(20);
    TreeNode* tnode5 = InitTreeNode(90);

    root->left = tnode1;
    tnode1->right = tnode3;
    root->right = tnode2;
    tnode2->right = tnode5;
    tnode2->left = tnode4;

    Queue* head = InitQueue(6);
    Put(head, root);
    PreOrderTraversal(head);

    // Free allocated memory
    free(head->data);
    free(head);
    free(root);
    free(tnode1);
    free(tnode2);
    free(tnode3);
    free(tnode4);
    free(tnode5);

    return 0;
}
