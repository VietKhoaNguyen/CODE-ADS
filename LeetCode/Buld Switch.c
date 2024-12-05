#include <stdio.h>
#include <math.h>

int bulbSwitch(int n) {
    // The number of bulbs that remain on is equal to the number of perfect squares ≤ n
    return (int)sqrt(n);
}

int main() {
    int n = 10;
    printf("The number of bulbs that remain on for n = %d is: %d\n", n, bulbSwitch(n));  // Output: 3
    return 0;
}
/*recur O(sqrt(n))
#include <stdio.h>
#include <math.h>

int bulbSwitchHelper(int n, int current) {
    // Base case: if current * current is greater than n, stop recursion
    if (current * current > n) {
        return current - 1;
    }
    // Recursive case: check for the next number
    return bulbSwitchHelper(n, current + 1);
}

int bulbSwitch(int n) {
    return bulbSwitchHelper(n, 1);  // Start checking from 1
}

int main() {
    int n = 10;
    printf("The number of bulbs that remain on for n = %d is: %d\n", n, bulbSwitch(n));  // Output: 3
    return 0;
}
*/