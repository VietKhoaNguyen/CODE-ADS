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
/*recur O(sqrt(n))
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sumDivisors(int num, int i, int sum) {
    // Base case: if i exceeds the square root of num
    if (i * i > num) {
        return sum;
    }
    
    if (num % i == 0) {
        sum += i;  // Add divisor i
        if (i != num / i) {
            sum += num / i;  // Add the complement divisor (num / i) if it's not the same as i
        }
    }
    
    // Recurse with the next number
    return sumDivisors(num, i + 1, sum);
}

bool checkPerfectNumber(int num) {
    // Special case: numbers less than or equal to 1 cannot be perfect numbers
    if (num <= 1) {
        return false;
    }
    
    // Start recursion to find the sum of divisors
    int sum = sumDivisors(num, 2, 1);  // Start from 2 because 1 is already considered
    
    // A perfect number is one where the sum of its divisors equals the number itself
    return sum == num;
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
*/