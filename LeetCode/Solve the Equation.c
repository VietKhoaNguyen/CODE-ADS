#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseSide(char* side, int* xCoeff, int* constant) {
    int length = strlen(side);
    int i = 0;
    *xCoeff = 0;
    *constant = 0;
    
    // Parsing the side for x terms and constant terms
    while (i < length) {
        int sign = 1; // assume the sign is positive initially
        if (side[i] == '-') {
            sign = -1;  // negative sign
            i++;
        } else if (side[i] == '+') {
            i++; // move over positive sign
        }

        if (side[i] == 'x') {
            *xCoeff += sign * 1; // Coefficient of x is 1 if no coefficient is provided
            i++;
        } else if (side[i] >= '0' && side[i] <= '9') {
            // Parsing the constant part
            int num = 0;
            while (i < length && side[i] >= '0' && side[i] <= '9') {
                num = num * 10 + (side[i] - '0');
                i++;
            }
            *constant += sign * num;
        }
    }
}

char* solveEquation(char* equation) {
    int leftX = 0, leftConst = 0;
    int rightX = 0, rightConst = 0;
    
    // Split the equation into left and right sides
    char* equalSign = strchr(equation, '=');
    *equalSign = '\0'; // Split the string at '='

    // Parse the left and right sides
    parseSide(equation, &leftX, &leftConst);
    parseSide(equalSign + 1, &rightX, &rightConst);
    
    // Move all x terms to one side and constant terms to the other side
    leftX -= rightX;
    rightConst -= leftConst;
    
    // If no x term remains
    if (leftX == 0) {
        if (rightConst == 0) {
            // Infinite solutions
            char* result = (char*)malloc(20 * sizeof(char));
            strcpy(result, "Infinite solutions");
            return result;
        } else {
            // No solution
            char* result = (char*)malloc(20 * sizeof(char));
            strcpy(result, "No solution");
            return result;
        }
    }
    
    // Calculate the value of x
    int x = rightConst / leftX;
    
    // Create the result string
    char* result = (char*)malloc(20 * sizeof(char));
    sprintf(result, "x=%d", x);
    return result;
}

int main() {
    char equation[] = "x+5-3+x=6+x-2";
    char* result = solveEquation(equation);
    printf("%s\n", result);
    free(result);
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseSide(char* side, int* xCoeff, int* constant) {
    int length = strlen(side);
    int i = 0;
    *xCoeff = 0;
    *constant = 0;
    
    // Parsing the side for x terms and constant terms
    while (i < length) {
        int sign = 1; // assume the sign is positive initially
        if (side[i] == '-') {
            sign = -1;  // negative sign
            i++;
        } else if (side[i] == '+') {
            i++; // move over positive sign
        }

        if (side[i] == 'x') {
            *xCoeff += sign * 1; // Coefficient of x is 1 if no coefficient is provided
            i++;
        } else if (side[i] >= '0' && side[i] <= '9') {
            // Parsing the constant part
            int num = 0;
            while (i < length && side[i] >= '0' && side[i] <= '9') {
                num = num * 10 + (side[i] - '0');
                i++;
            }
            *constant += sign * num;
        }
    }
}

char* solveEquation(char* equation) {
    int leftX = 0, leftConst = 0;
    int rightX = 0, rightConst = 0;
    
    // Split the equation into left and right sides
    char* equalSign = strchr(equation, '=');
    *equalSign = '\0'; // Split the string at '='

    // Parse the left and right sides
    parseSide(equation, &leftX, &leftConst);
    parseSide(equalSign + 1, &rightX, &rightConst);
    
    // Move all x terms to one side and constant terms to the other side
    leftX -= rightX;
    rightConst -= leftConst;
    
    // If no x term remains
    if (leftX == 0) {
        if (rightConst == 0) {
            // Infinite solutions
            char* result = (char*)malloc(20 * sizeof(char));
            strcpy(result, "Infinite solutions");
            return result;
        } else {
            // No solution
            char* result = (char*)malloc(20 * sizeof(char));
            strcpy(result, "No solution");
            return result;
        }
    }
    
    // Calculate the value of x
    int x = rightConst / leftX;
    
    // Create the result string
    char* result = (char*)malloc(20 * sizeof(char));
    sprintf(result, "x=%d", x);
    return result;
}

int main() {
    char equation[] = "x+5-3+x=6+x-2";
    char* result = solveEquation(equation);
    printf("%s\n", result);
    free(result);
    return 0;
}
*/