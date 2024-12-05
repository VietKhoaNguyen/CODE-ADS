#include <stdio.h>
int PrimeNum(int n, int i) {
    if (n <= 1)
        return 0;
    if (i * i > n)
        return 1;
    if (n % i == 0)
        return 0;
    return PrimeNum(n, i + 1); 
}

int SphenicNum(int n, int nums[3], int i, int count) {
    if (count == 3 && n == 1)
        return 1;
        
    if (i > n || count >= 3)
        return 0;

    if (n % i == 0 && PrimeNum(i, 2)) {
        nums[count] = i;
        return SphenicNum(n / i, nums, i + 1, count + 1); 
    }

    return SphenicNum(n, nums, i + 1, count);
}

int main() {
    int num;
    int nums[3] = {0};
    printf("Enter number: ");
    scanf("%d", &num);

    if (SphenicNum(num, nums, 2, 0)) {
        printf("%d is a sphenic number.\n", num);
        printf("Distinct prime numbers p, q, r: %d, %d, %d.\n", nums[0], nums[1], nums[2]);
    } else {
        printf("%d isn't a sphenic number.\n", num);
    }

    return 0;
}
