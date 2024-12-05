int findNthDigit(int n) {
    long long length = 1;  // Length of the number of digits (1 for 1-digit, 2 for 2-digit, etc.)
    long long count = 9;   // Number of numbers with that many digits (9 for 1-digit, 90 for 2-digit, etc.)
    long long start = 1;   // The first number with that many digits (1 for 1-digit, 10 for 2-digit, etc.)
    
    // Find which range the Nth digit belongs to
    while (n > length * count) {
        n -= length * count;   // Decrease n by the number of digits in the current range
        length++;              // Move to the next range of numbers (e.g., 2-digit numbers, 3-digit numbers, etc.)
        count *= 10;           // Increase the count (from 9 for 1-digit numbers to 90 for 2-digit numbers, etc.)
        start *= 10;           // Increase the starting number (from 1 for 1-digit numbers to 10 for 2-digit numbers, etc.)
    }
    
    // Determine the exact number containing the nth digit
    long long num = start + (n - 1) / length;  // The number that contains the digit
    int digitIndex = (n - 1) % length;          // The index of the digit within that number
    
    // Convert the number to a string and return the digit at the given index
    char numStr[20];
    sprintf(numStr, "%lld", num);  // Convert the number to a string
    return numStr[digitIndex] - '0';  // Return the digit as an integer
}
/*recur O(log(n))
int findNthDigitHelper(int n, long long length, long long count, long long start) {
    // Base case: If the current range contains the Nth digit
    if (n <= length * count) {
        // Find the exact number containing the Nth digit
        long long num = start + (n - 1) / length;
        int digitIndex = (n - 1) % length;

        // Convert the number to a string and return the digit at the given index
        char numStr[20];
        sprintf(numStr, "%lld", num);  // Convert the number to a string
        return numStr[digitIndex] - '0';  // Return the digit as an integer
    }

    // Recursive case: Move to the next group
    return findNthDigitHelper(n - length * count, length + 1, count * 10, start * 10);
}

int findNthDigit(int n) {
    // Start with the 1-digit numbers (length = 1, count = 9, start = 1)
    return findNthDigitHelper(n, 1, 9, 1);
}
*/