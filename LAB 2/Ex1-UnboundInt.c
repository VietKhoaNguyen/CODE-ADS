#include <stdio.h>
#include <stdlib.h>
/*Suppose that we use a List data structure to represent unbounded
integers.
- the first element refers to the sign: 1 is positive and -1 is negative.
- each element in the list represents one digit of these integers.
Implement and test the program in C/C++ using an Array-based List (Static or
Dynamic) to manage this unbounded integers:
- add new digits at any place in an integer.
- remove a digit at a specfic position in an integer.
- calculate the sum of all digits from an unbounded integer.
- display the whole number on the screen.*/
typedef struct UnboundedIntegers {
    int size;
    int* digit;
    int sign;
}MyIntegers;

void UnboundedIntegers( MyIntegers* num ,int capacity) {
    num->digit = (int*)malloc(capacity * sizeof(int));
    num->size = 0;
}

void setSign(MyIntegers* num, int s) {
    if (s == 1 || s == -1) {
        num->sign = s;
    } else {
        printf("positive\n");
        num->sign = 1;
    }
}

void addDigit(MyIntegers* num, int data) {
    num->digit[num->size++] = data;
}

void insertDigit(MyIntegers* num, int data, int position) {
    if (position < 0 || position > num->size) {
        printf("Invalid \n");
    } else {
        for (int i = num->size; i > position; --i) {
            num->digit[i] = num->digit[i - 1];
        }
        num->digit[position] = data;
        ++num->size;
    }
}

void deleteDigit(MyIntegers* num, int position) {
    if (position < 0 || position >= num->size) {
        printf("Invalid \n");
        return;
    }
    for (int i = position; i < num->size - 1; ++i) {
        num->digit[i] = num->digit[i + 1];
    }
    --num->size;
}

int sumDigit(MyIntegers* num) {
    int sum = 0;
    for (int i = 0; i < num->size; ++i) {
        sum += num->digit[i];
    }
    return sum;
}

void displayDigit(MyIntegers* num) {
    if (num->size == 0) {
        printf("0\n");
    }
    if (num->sign == -1) {
        printf("-");
    }
    for (int i = 0; i < num->size; i++) {
        printf("%d", num->digit[i]);
    }
    printf("\n");
}
int main()
{
    MyIntegers MyIntegers;
    UnboundedIntegers(&MyIntegers, 5);
    setSign(&MyIntegers, -1);
    addDigit(&MyIntegers, 1);
    addDigit(&MyIntegers, 2);
    addDigit(&MyIntegers, 3);
    addDigit(&MyIntegers, 4);
    addDigit(&MyIntegers, 5);
    insertDigit(&MyIntegers, 2, 4);
    printf("%d\n", sumDigit(&MyIntegers));
    displayDigit(&MyIntegers);
}