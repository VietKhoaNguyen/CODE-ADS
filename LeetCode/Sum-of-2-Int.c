int getSum(int a, int b) {
    while (b != 0) {
        // Calculate the sum without the carry
        int sum = a ^ b;
        
        // Calculate the carry and shift it to the left
        int carry = (a & b) << 1;
        
        // Update a and b for the next iteration
        a = sum;
        b = carry;
    }
    
    return a;  // The result is stored in a after all carries are processed
}
/*recur O(log(max(a,b)))
int getSum(int a, int b) {
    // Base case: no carry left
    if (b == 0) {
        return a;
    }

    // Calculate sum without carry (XOR)
    int sum = a ^ b;
    
    // Calculate carry (AND and shift left)
    int carry = (a & b) << 1;
    
    // Recurse with the sum and the carry
    return getSum(sum, carry);
}
*/