#include <stdio.h>
#include <math.h>

int sumFourDivisors(int* nums, int numsSize) {
    int totalSum = 0;

    // Function to calculate the sum of divisors for a number
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int sum = 0;
        int count = 0;
        
        // Check divisors from 1 to sqrt(num)
        for (int j = 1; j * j <= num; j++) {
            if (num % j == 0) {
                // j is a divisor, add it to the sum
                sum += j;
                count++;
                
                // If j and num / j are different, add num / j as well
                if (j != num / j) {
                    sum += num / j;
                    count++;
                }
            }
        }
        
        // If the number has exactly four divisors, add the sum to the total
        if (count == 4) {
            totalSum += sum;
        }
    }

    return totalSum;
}

int main() {
    int nums[] = {21, 4, 7};
    int numsSize = 3;
    int result = sumFourDivisors(nums, numsSize);
    printf("Sum of four divisors: %d\n", result);
    return 0;
}
/*recur O(sqrt(n))
#include <stdio.h>
#include <math.h>

int findDivisorsSum(int num, int currentDivisor, int* count) {
    // Base case: if the current divisor exceeds sqrt(num), return the sum
    if (currentDivisor * currentDivisor > num) {
        return 0;
    }

    int sum = 0;
    
    // If currentDivisor divides num, add it and its pair (num / currentDivisor)
    if (num % currentDivisor == 0) {
        sum += currentDivisor;
        (*count)++;
        
        // Avoid adding the square root twice if it's a perfect square
        if (currentDivisor != num / currentDivisor) {
            sum += num / currentDivisor;
            (*count)++;
        }
    }
    
    // Recur with the next divisor
    return sum + findDivisorsSum(num, currentDivisor + 1, count);
}

int sumFourDivisorsRecursive(int* nums, int numsSize, int index) {
    if (index == numsSize) {
        return 0;
    }

    int num = nums[index];
    int count = 0;
    int sum = findDivisorsSum(num, 1, &count);

    // If the number has exactly four divisors, add the sum to the result
    if (count == 4) {
        return sum + sumFourDivisorsRecursive(nums, numsSize, index + 1);
    }

    // Otherwise, skip this number and continue to the next one
    return sumFourDivisorsRecursive(nums, numsSize, index + 1);
}

int sumFourDivisors(int* nums, int numsSize) {
    return sumFourDivisorsRecursive(nums, numsSize, 0);
}

int main() {
    int nums[] = {21, 4, 7};
    int numsSize = 3;
    int result = sumFourDivisors(nums, numsSize);
    printf("Sum of four divisors: %d\n", result);
    return 0;
}
*/