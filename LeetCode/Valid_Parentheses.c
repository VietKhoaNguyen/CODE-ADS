#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    // Use a stack to store the opening parentheses
    char stack[10000];  // Stack to hold characters
    int top = -1;  // Stack pointer
    
    // Loop through the string
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        
        // If the character is an opening parenthesis, push it to the stack
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        // If the character is a closing parenthesis
        else if (c == ')' || c == '}' || c == ']') {
            // Check if the stack is empty (no matching opening parenthesis)
            if (top == -1) {
                return false;
            }
            // Pop from the stack and check if it matches the current closing parenthesis
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    // If the stack is empty, the string is valid
    return top == -1;
}

int main() {
    char s[] = "{[]}";
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidRecursive(char* s, int index, char* stack, int top) {
    // Base case: If we've processed the whole string, the stack should be empty
    if (index == strlen(s)) {
        return top == -1;
    }

    char c = s[index];

    // If it's an opening parenthesis, push it onto the stack
    if (c == '(' || c == '{' || c == '[') {
        stack[++top] = c;
        return isValidRecursive(s, index + 1, stack, top);
    }
    
    // If it's a closing parenthesis, check if it matches the last opened parenthesis
    if (c == ')' || c == '}' || c == ']') {
        if (top == -1) {  // Stack is empty, no matching opening parenthesis
            return false;
        }
        char topChar = stack[top--];
        if ((c == ')' && topChar != '(') ||
            (c == '}' && topChar != '{') ||
            (c == ']' && topChar != '[')) {
            return false;
        }
        return isValidRecursive(s, index + 1, stack, top);
    }

    // If character is neither a closing nor opening parenthesis, just skip it
    return isValidRecursive(s, index + 1, stack, top);
}

bool isValid(char* s) {
    char stack[10000];  // Stack to hold parentheses
    return isValidRecursive(s, 0, stack, -1);  // Start recursion with initial values
}

int main() {
    char s[] = "{[]}";
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
*/