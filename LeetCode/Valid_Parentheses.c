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
