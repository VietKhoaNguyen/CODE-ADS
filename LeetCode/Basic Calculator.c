#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Helper function to evaluate the stack
int evaluateStack(int* stack, int* stackTop) {
    int result = stack[0];
    for (int i = 1; i <= *stackTop; i += 2) {
        char operator = stack[i];
        int operand = stack[i + 1];
        if (operator == '+') {
            result += operand;
        } else if (operator == '-') {
            result -= operand;
        }
    }
    *stackTop = 0;
    stack[0] = result;
    return result;
}

int calculate(char* s) {
    int stack[1000]; // Stack to store numbers and operators
    int stackTop = 0;
    int num = 0;
    int sign = 1; // Current sign (+1 or -1)
    int result = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (isdigit(c)) {
            // Build the number
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            // Apply the current number to the result
            result += sign * num;
            num = 0;

            // Update the sign
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            // Push current result and sign onto the stack
            stack[stackTop++] = result;
            stack[stackTop++] = sign;
            result = 0;
            sign = 1;
        } else if (c == ')') {
            // Apply the current number to the result
            result += sign * num;
            num = 0;

            // Pop from the stack
            result = stack[--stackTop] * result + stack[--stackTop];
        }
    }

    // Apply the last number to the result
    result += sign * num;
    return result;
}

// Example usage
int main() {
    char expression[] = "1 + 2 - (3 + 4) + 10";
    printf("Result: %d\n", calculate(expression)); // Expected output: 6
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Helper function to parse a number
int parseNumber(const char** s) {
    int num = 0;
    while (isdigit(**s)) {
        num = num * 10 + (**s - '0');
        (*s)++;
    }
    return num;
}

// Recursive function to evaluate the expression
int evaluate(const char** s) {
    int result = 0;
    int sign = 1; // Default to positive
    while (**s != '\0') {
        char c = **s;

        if (isdigit(c)) {
            // Parse the number and update the result
            int num = parseNumber(s);
            result += sign * num;
        } else if (c == '+') {
            // Update the sign to positive
            sign = 1;
            (*s)++;
        } else if (c == '-') {
            // Update the sign to negative
            sign = -1;
            (*s)++;
        } else if (c == '(') {
            // Start a new recursive call for the sub-expression
            (*s)++;
            int subResult = evaluate(s);
            result += sign * subResult;
        } else if (c == ')') {
            // End the current recursive call
            (*s)++;
            break;
        } else {
            // Skip whitespace or unexpected characters
            (*s)++;
        }
    }
    return result;
}

// Main function to evaluate an expression string
int calculate(char* s) {
    const char* str = s; // Use a pointer for recursive parsing
    return evaluate(&str);
}

// Example usage
int main() {
    char expression[] = "1 + (2 - (3 + 4)) + 10";
    printf("Result: %d\n", calculate(expression)); // Expected output: 6
    return 0;
}
*/