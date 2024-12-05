#include <stdio.h>
// Check prime number
int PrimeNum(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
// Check sphenic number
int SphenicNum(int n, int distinctNums[3]) {
    int count = 0;
    for (int i = 2; i <= n && count < 3; i++) {
        if (n % i == 0 && PrimeNum(i)) {
            distinctNums[count] = i;
            count++;
            n /= i;
        }
    }
    return (count == 3 && n == 1);
}

int main() {
    int num;
    int distinctNums[3] = {0}; 
    printf("Enter number: ");
    scanf("%d", &num);
    if (SphenicNum(num, distinctNums)) {
        printf("%d is sphenic number.\n", num);
        printf("distinct prime numbers p, q, r: %d, %d, %d.\n", distinctNums[0], distinctNums[1], distinctNums[2]);
    } else {
        printf("%d isn't sphenic number.\n", num);
    }
    return 0;
}

// Pseudo Code                                                   // Complexity: O(sqrt(n))
//function PrimeNum(n) {
//    if (n <= 1)
//        return 0;
//    for i from 2 to √n
//        if n mod i == 0
//            return 0;
//    return 1;
//}

//function SphenicNum(n, distinctNums[3]) {
//    count = 0;
//    for i from 2 to n and count < 3
//        if n mod i == 0 and PrimeNum(i)
//            distinctNums[count] = i;
//            count++;
//            n = n / i;
//    return (count == 3 and n == 1);
//}

//function main() {
//    num;
//    distinctNums[3] = {0};
//    print("Enter number: ");
//    num = input();
//    if SphenicNum(num, distinctNums)
//        print(num + " is sphenic number.");
//        print("distinct prime numbers p, q, r: " + distinctNums[0] + ", " + distinctNums[1] + ", " + distinctNums[2] + ".");
//    else
//        print(num + " isn't sphenic number.");
//    end
//}

