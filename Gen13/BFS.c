#include <stdio.h>
#include <stdlib.h>
/*This problem requires to traverse and display a tree using the following process:
- Visit a node and find its child nodes.
- Put the child nodes into the queue.
- Pop a node in the queue and repeat the process until all nodes are visited.
Justify and print the traversal result for the below tree.*/
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node* nodes[100];
    int front, rear;
} Queue;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, Node* node) {
    queue->nodes[queue->rear++] = node;
}

Node* dequeue(Queue* queue) {
    return queue->nodes[queue->front++];
}

void bfsTraversal(Node* root) {
    if (root == NULL) {
        return; 
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    printf("Breadth-First Traversal (BFS):\n");
 
    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }

    printf("\n");
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->right = newNode(13);
    root->right->left = newNode(20);
    root->right->right = newNode(90);
    bfsTraversal(root);

    return 0;
}
