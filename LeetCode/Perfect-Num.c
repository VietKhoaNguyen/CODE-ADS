#include <stdio.h>
#include <math.h>

bool checkPerfectNumber(int num) {
    // Special case: numbers less than or equal to 1 cannot be perfect numbers
    if (num <= 1) {
        return false;
    }
    
    int sum = 1; // Start with 1 because 1 is a proper divisor of every number
    
    // Loop through possible divisors up to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;  // Add i as a divisor
            if (i != num / i) {
                sum += num / i;  // Add num / i if it's not the same as i
            }
        }
    }

    return sum == num;  // If the sum of divisors equals the number, it's a perfect number
}
int main() {
    int num = 28;
    if (checkPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}