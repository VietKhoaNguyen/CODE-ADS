#include <stdio.h>

int findComplement(int num) {
    // Create a mask with the same number of bits as num, all set to 1
    int mask = 1;
    while (mask <= num) {
        mask <<= 1; // Shift the mask left to find the length of bits in num
    }
    
    // The complement is the mask minus num
    return mask - 1 - num;
}

int main() {
    int num = 5;
    printf("The complement of %d is %d\n", num, findComplement(num));
    return 0;
}
