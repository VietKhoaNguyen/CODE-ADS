#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate Reverse Polish Notation
int evalRPN(char** tokens, int tokensSize) {
    int stack[1000];  // Stack to hold numbers
    int stackTop = -1; // Stack pointer
    
    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        
        // If the token is a number, push it onto the stack
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack[++stackTop] = atoi(token);  // Convert string to integer and push to stack
        } else {
            // Pop two numbers from the stack
            int num2 = stack[stackTop--];
            int num1 = stack[stackTop--];
            
            // Apply the operator
            if (strcmp(token, "+") == 0) {
                stack[++stackTop] = num1 + num2;
            } else if (strcmp(token, "-") == 0) {
                stack[++stackTop] = num1 - num2;
            } else if (strcmp(token, "*") == 0) {
                stack[++stackTop] = num1 * num2;
            } else if (strcmp(token, "/") == 0) {
                stack[++stackTop] = num1 / num2;
            }
        }
    }
    
    // The final result is at the top of the stack
    return stack[stackTop];
}

// Example usage
int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;
    
    int result = evalRPN(tokens, tokensSize);
    printf("Result: %d\n", result);  // Expected output: 9
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Recursive helper function to evaluate RPN
int evaluateRPNRecursive(char** tokens, int tokensSize, int* index) {
    // Base case: when we have processed all tokens, return
    if (*index >= tokensSize) {
        return 0;
    }

    char* token = tokens[*index];
    (*index)++;  // Move to the next token

    // If the token is a number, return it as the result
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        return atoi(token);
    }

    // Otherwise, it's an operator, so we need to evaluate the left and right operands
    int left = evaluateRPNRecursive(tokens, tokensSize, index);
    int right = evaluateRPNRecursive(tokens, tokensSize, index);

    // Apply the operator
    if (strcmp(token, "+") == 0) {
        return left + right;
    } else if (strcmp(token, "-") == 0) {
        return left - right;
    } else if (strcmp(token, "*") == 0) {
        return left * right;
    } else if (strcmp(token, "/") == 0) {
        return left / right;
    }

    return 0; // Default case (shouldn't reach here for valid RPN)
}

// Wrapper function for evaluation
int evalRPN(char** tokens, int tokensSize) {
    int index = 0;
    return evaluateRPNRecursive(tokens, tokensSize, &index);
}

// Example usage
int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;

    int result = evalRPN(tokens, tokensSize);
    printf("Result: %d\n", result);  // Expected output: 9
    
    return 0;
}
*/