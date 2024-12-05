#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for number words
char* belowTwenty[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* thousands[] = {"", "Thousand", "Million", "Billion"};

void appendWords(char* result, const char* word) {
    if (strlen(result) > 0) {
        strcat(result, " ");
    }
    strcat(result, word);
}

void numberToWordsHelper(int num, char* result) {
    if (num >= 100) {
        appendWords(result, belowTwenty[num / 100]);
        appendWords(result, "Hundred");
        num %= 100;
    }
    if (num >= 20) {
        appendWords(result, tens[num / 10]);
        num %= 10;
    }
    if (num > 0) {
        appendWords(result, belowTwenty[num]);
    }
}

char* numberToWords(int num) {
    if (num == 0) {
        char* zero = (char*)malloc(5 * sizeof(char));
        strcpy(zero, "Zero");
        return zero;
    }

    char* result = (char*)malloc(1024 * sizeof(char));
    result[0] = '\0';

    int unitIndex = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char temp[256] = {0};
            numberToWordsHelper(num % 1000, temp);
            if (strlen(temp) > 0) {
                if (strlen(result) > 0) {
                    strcat(temp, " ");
                }
                strcat(temp, thousands[unitIndex]);
                if (strlen(result) > 0) {
                    strcat(temp, " ");
                }
                strcat(temp, result);
                strcpy(result, temp);
            }
        }
        num /= 1000;
        unitIndex++;
    }

    return result;
}

// Example usage
int main() {
    int num = 1234567;
    char* result = numberToWords(num);
    printf("Number in words: %s\n", result);
    free(result);
    return 0;
}
/*recur O(log10 n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* belowTwenty[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* thousands[] = {"", "Thousand", "Million", "Billion"};

void appendWords(char* result, const char* word) {
    if (strlen(result) > 0) {
        strcat(result, " ");
    }
    strcat(result, word);
}

void numberToWordsRecursive(int num, int unitIndex, char* result) {
    if (num == 0) return;

    numberToWordsRecursive(num / 1000, unitIndex + 1, result);

    int remainder = num % 1000;
    if (remainder != 0) {
        char temp[256] = {0};
        if (remainder >= 100) {
            appendWords(temp, belowTwenty[remainder / 100]);
            appendWords(temp, "Hundred");
            remainder %= 100;
        }
        if (remainder >= 20) {
            appendWords(temp, tens[remainder / 10]);
            remainder %= 10;
        }
        if (remainder > 0) {
            appendWords(temp, belowTwenty[remainder]);
        }
        if (strlen(thousands[unitIndex]) > 0) {
            appendWords(temp, thousands[unitIndex]);
        }

        if (strlen(result) > 0) {
            strcat(temp, " ");
        }
        strcat(temp, result);
        strcpy(result, temp);
    }
}

char* numberToWords(int num) {
    if (num == 0) {
        char* zero = (char*)malloc(5 * sizeof(char));
        strcpy(zero, "Zero");
        return zero;
    }

    char* result = (char*)malloc(1024 * sizeof(char));
    result[0] = '\0';

    numberToWordsRecursive(num, 0, result);

    return result;
}

// Example usage
int main() {
    int num = 1234567;
    char* result = numberToWords(num);
    printf("Number in words: %s\n", result);
    free(result);
    return 0;
}
*/