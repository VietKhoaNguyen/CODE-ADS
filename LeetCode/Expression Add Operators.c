#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long eval(long long num1, long long num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    return 0;
}

// Function to add operators to the string 'num' such that the result equals target
char** addOperators(char* num, int target, int* returnSize) {
    int len = strlen(num);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory to store the resulting expressions
    char** result = (char**)malloc(0);
    *returnSize = 0;

    // A stack-like approach: we use two arrays to store partial expressions and their evaluated values
    // We start by treating the first digit as a possible starting point for the expression
    char** expressions = (char**)malloc(sizeof(char*));
    int* values = (int*)malloc(sizeof(int));
    expressions[0] = (char*)malloc(2 * sizeof(char));
    expressions[0][0] = num[0];
    expressions[0][1] = '\0';  // Null-terminate
    values[0] = num[0] - '0';  // Store its value

    int size = 1;  // Start with one expression

    // Iterate through each subsequent digit in the input number
    for (int i = 1; i < len; i++) {
        // Create temporary arrays for the new expressions and values
        char** newExpressions = (char**)malloc(size * 3 * sizeof(char*));
        int* newValues = (int*)malloc(size * 3 * sizeof(int));
        int newSize = 0;

        // For each existing expression, try adding the three operators (+, -, *)
        for (int j = 0; j < size; j++) {
            char* expr = expressions[j];
            int currentVal = values[j];

            // Add the current digit as a new operand
            char* newExpr = (char*)malloc(strlen(expr) + 2);  // Extra space for operator and digit
            sprintf(newExpr, "%s%c", expr, num[i]);
            newExpressions[newSize] = newExpr;
            newValues[newSize] = currentVal * 10 + (num[i] - '0');  // Treating the digit as part of the current number
            newSize++;

            // Add the '+' operator and evaluate
            newExpr = (char*)malloc(strlen(expr) + 3);  // Space for operator and new number
            sprintf(newExpr, "%s+%c", expr, num[i]);
            newExpressions[newSize] = newExpr;
            newValues[newSize] = eval(currentVal, num[i] - '0', '+');
            newSize++;

            // Add the '-' operator and evaluate
            newExpr = (char*)malloc(strlen(expr) + 3);  // Space for operator and new number
            sprintf(newExpr, "%s-%c", expr, num[i]);
            newExpressions[newSize] = newExpr;
            newValues[newSize] = eval(currentVal, num[i] - '0', '-');
            newSize++;

            // Add the '*' operator and evaluate
            newExpr = (char*)malloc(strlen(expr) + 3);  // Space for operator and new number
            sprintf(newExpr, "%s*%c", expr, num[i]);
            newExpressions[newSize] = newExpr;
            newValues[newSize] = eval(currentVal, num[i] - '0', '*');
            newSize++;
        }

        // Free the old arrays and update expressions and values to the new ones
        free(expressions);
        free(values);
        expressions = newExpressions;
        values = newValues;
        size = newSize;
    }

    // Now filter and store the expressions that match the target value
    for (int i = 0; i < size; i++) {
        if (values[i] == target) {
            result = (char**)realloc(result, (*returnSize + 1) * sizeof(char*));
            result[*returnSize] = expressions[i];
            (*returnSize)++;
        }
    }

    // Clean up remaining memory
    free(expressions);
    free(values);

    return result;
}

int main() {
    char num[] = "123";
    int target = 6;
    int returnSize = 0;

    char** result = addOperators(num, target, &returnSize);

    printf("Results: \n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);  // Free each generated expression
    }
    free(result);  // Free the result array

    return 0;
}
/*recur O(4^n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long eval(long long num1, long long num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    return 0;
}

// Recursive helper function
void backtrack(char* num, int target, int start, long long currentVal, long long lastOperand, 
               char* expr, int* returnSize, char*** result) {
    // If we have processed the entire string
    if (start == strlen(num)) {
        if (currentVal == target) {
            // Allocate space for the result and add the expression
            (*result) = (char**)realloc(*result, (*returnSize + 1) * sizeof(char*));
            (*result)[*returnSize] = strdup(expr); // Make a copy of the expression
            (*returnSize)++;
        }
        return;
    }

    char digit = num[start];
    int len = strlen(expr);

    // Case 1: Treat the current digit as part of the current operand
    expr[len] = digit;
    expr[len + 1] = '\0';
    long long newVal = currentVal * 10 + (digit - '0');
    backtrack(num, target, start + 1, newVal, newVal, expr, returnSize, result);

    // Case 2: Add '+' operator and recurse
    if (start > 0) {
        expr[len] = '+';
        expr[len + 1] = digit;
        expr[len + 2] = '\0';
        backtrack(num, target, start + 1, currentVal + (digit - '0'), digit - '0', expr, returnSize, result);
    }

    // Case 3: Add '-' operator and recurse
    if (start > 0) {
        expr[len] = '-';
        expr[len + 1] = digit;
        expr[len + 2] = '\0';
        backtrack(num, target, start + 1, currentVal - (digit - '0'), -(digit - '0'), expr, returnSize, result);
    }

    // Case 4: Add '*' operator and recurse
    if (start > 0) {
        expr[len] = '*';
        expr[len + 1] = digit;
        expr[len + 2] = '\0';
        backtrack(num, target, start + 1, currentVal - lastOperand + lastOperand * (digit - '0'), lastOperand * (digit - '0'), expr, returnSize, result);
    }
}

// Main function to add operators and generate the expressions
char** addOperators(char* num, int target, int* returnSize) {
    *returnSize = 0;
    char** result = NULL;

    // Temporary string to build the current expression
    char expr[strlen(num) * 2 + 1]; // Max possible length of expression with operators
    expr[0] = '\0'; // Initialize the string as empty

    // Start the recursive backtracking
    backtrack(num, target, 0, 0, 0, expr, returnSize, &result);

    return result;
}

int main() {
    char num[] = "123";
    int target = 6;
    int returnSize = 0;

    char** result = addOperators(num, target, &returnSize);

    // Print results
    printf("Results: \n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // Free each result string
    }
    free(result); // Free the result array

    return 0;
}
*/