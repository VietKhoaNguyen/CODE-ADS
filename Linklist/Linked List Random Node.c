#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Solution struct definition
typedef struct {
    struct ListNode* head;
} Solution;

// solutionCreate initializes the Solution object with the linked list head.
Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    return obj;
}

// solutionGetRandom picks a random node from the list.
int solutionGetRandom(Solution* obj) {
    struct ListNode* current = obj->head;
    int result = current->val;
    int n = 1;
    
    // Reservoir sampling to select a random element.
    while (current != NULL) {
        if (rand() % n == 0) {
            result = current->val;
        }
        current = current->next;
        n++;
    }
    
    return result;
}

// solutionFree frees the allocated memory for the Solution object.
void solutionFree(Solution* obj) {
    free(obj);
}

// Example usage:
int main() {
    // Creating a simple linked list: 1 -> 2 -> 3
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    // Create the Solution object
    Solution* obj = solutionCreate(head);
    
    // Get a random value
    srand(time(NULL)); // Seed for randomness
    printf("Random node value: %d\n", solutionGetRandom(obj));
    
    // Free the allocated memory
    solutionFree(obj);
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Solution struct definition
typedef struct {
    struct ListNode* head;
} Solution;

// Recursive helper function to get a random node from the list.
int getRandomRecursive(struct ListNode* current, int n, int result) {
    if (current == NULL) {
        return result;  // Base case: when the list is empty, return the result
    }

    // Reservoir sampling: pick the current node with probability 1/n
    if (rand() % n == 0) {
        result = current->val;
    }

    // Recur to the next node in the list, with n incremented
    return getRandomRecursive(current->next, n + 1, result);
}

// solutionCreate initializes the Solution object with the linked list head.
Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    return obj;
}

// solutionGetRandom picks a random node from the list using recursion.
int solutionGetRandom(Solution* obj) {
    srand(time(NULL));  // Seed for randomness
    return getRandomRecursive(obj->head, 1, obj->head->val);  // Start with the head node
}

// solutionFree frees the allocated memory for the Solution object.
void solutionFree(Solution* obj) {
    free(obj);
}

// Example usage:
int main() {
    // Creating a simple linked list: 1 -> 2 -> 3
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    // Create the Solution object
    Solution* obj = solutionCreate(head);
    
    // Get a random value
    printf("Random node value: %d\n", solutionGetRandom(obj));
    
    // Free the allocated memory
    solutionFree(obj);
    
    return 0;
}
*/