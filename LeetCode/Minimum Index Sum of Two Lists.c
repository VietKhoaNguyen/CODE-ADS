#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    // Hash table: key = string, value = index in list1
    int hashTableSize = 1000; // Arbitrary size, assuming few collisions
    char** hashKeys = (char**)malloc(hashTableSize * sizeof(char*));
    int* hashValues = (int*)malloc(hashTableSize * sizeof(int));
    memset(hashKeys, 0, hashTableSize * sizeof(char*));
    
    // Hashing function
    int hashFunction(char* str) {
        unsigned int hash = 0;
        while (*str) {
            hash = (hash * 31) + *str++;
        }
        return hash % hashTableSize;
    }

    // Insert list1 into hash table
    for (int i = 0; i < list1Size; i++) {
        int hash = hashFunction(list1[i]);
        while (hashKeys[hash] != NULL) { // Linear probing for collisions
            if (strcmp(hashKeys[hash], list1[i]) == 0) {
                break; // Already inserted
            }
            hash = (hash + 1) % hashTableSize;
        }
        hashKeys[hash] = list1[i];
        hashValues[hash] = i;
    }

    // Find matches in list2
    int minIndexSum = list1Size + list2Size; // Large initial value
    char** result = (char**)malloc((list1Size + list2Size) * sizeof(char*));
    int resultCount = 0;

    for (int i = 0; i < list2Size; i++) {
        int hash = hashFunction(list2[i]);
        while (hashKeys[hash] != NULL) {
            if (strcmp(hashKeys[hash], list2[i]) == 0) {
                int indexSum = hashValues[hash] + i;
                if (indexSum < minIndexSum) {
                    minIndexSum = indexSum;
                    resultCount = 0; // Reset result
                    result[resultCount++] = list2[i];
                } else if (indexSum == minIndexSum) {
                    result[resultCount++] = list2[i];
                }
                break;
            }
            hash = (hash + 1) % hashTableSize;
        }
    }

    // Free hash table memory
    free(hashKeys);
    free(hashValues);

    // Set return size and resize result array
    *returnSize = resultCount;
    return result;
}

// Example usage
int main() {
    char* list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    int list1Size = sizeof(list1) / sizeof(list1[0]);
    char* list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    int list2Size = sizeof(list2) / sizeof(list2[0]);

    int returnSize;
    char** result = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);

    printf("Common restaurants with minimum index sum:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Free result memory
    free(result);
    return 0;
}
/*recur O(n+m)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    // Hash table: key = string, value = index in list1
    int hashTableSize = 1000; // Arbitrary size, assuming few collisions
    char** hashKeys = (char**)malloc(hashTableSize * sizeof(char*));
    int* hashValues = (int*)malloc(hashTableSize * sizeof(int));
    memset(hashKeys, 0, hashTableSize * sizeof(char*));

    // Hashing function
    int hashFunction(char* str) {
        unsigned int hash = 0;
        while (*str) {
            hash = (hash * 31) + *str++;
        }
        return hash % hashTableSize;
    }

    // Recursive function to insert into hash table
    void insertIntoHashTable(int index, int i) {
        int hash = hashFunction(list1[i]);
        while (hashKeys[hash] != NULL) { // Linear probing for collisions
            if (strcmp(hashKeys[hash], list1[i]) == 0) {
                break; // Already inserted
            }
            hash = (hash + 1) % hashTableSize;
        }
        hashKeys[hash] = list1[i];
        hashValues[hash] = index;
    }

    // Recursive function to check for common restaurants
    void findCommonRestaurants(int index, int minIndexSum, char** result, int* resultCount) {
        if (index >= list2Size) return;

        int hash = hashFunction(list2[index]);
        while (hashKeys[hash] != NULL) {
            if (strcmp(hashKeys[hash], list2[index]) == 0) {
                int indexSum = hashValues[hash] + index;
                if (indexSum < minIndexSum) {
                    minIndexSum = indexSum;
                    *resultCount = 0; // Reset result
                    result[(*resultCount)++] = list2[index];
                } else if (indexSum == minIndexSum) {
                    result[(*resultCount)++] = list2[index];
                }
                break;
            }
            hash = (hash + 1) % hashTableSize;
        }

        findCommonRestaurants(index + 1, minIndexSum, result, resultCount);
    }

    // Insert list1 into hash table
    for (int i = 0; i < list1Size; i++) {
        insertIntoHashTable(i, i);
    }

    // Find matches in list2 recursively
    int minIndexSum = list1Size + list2Size; // Large initial value
    char** result = (char**)malloc((list1Size + list2Size) * sizeof(char*));
    int resultCount = 0;

    findCommonRestaurants(0, minIndexSum, result, &resultCount);

    // Free hash table memory
    free(hashKeys);
    free(hashValues);

    // Set return size and return result
    *returnSize = resultCount;
    return result;
}

// Example usage
int main() {
    char* list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    int list1Size = sizeof(list1) / sizeof(list1[0]);
    char* list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    int list2Size = sizeof(list2) / sizeof(list2[0]);

    int returnSize;
    char** result = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);

    printf("Common restaurants with minimum index sum:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Free result memory
    free(result);
    return 0;
}
*/