#include <stdio.h>
void factorize(int n, int divisor) {                     //Complexity: O(sqrt(n))
    if (n == 1) {
        return;
    }

    if (n % divisor == 0) {
        printf("%d ", divisor);
        factorize(n / divisor, divisor);
    }
    else {
        factorize(n, divisor + 1); 
    }
}

int main() {
    int n;

    printf("Enter a number to factorize: ");
    scanf("%d", &n);
    printf("Prime factors of %d are: ", n);
    factorize(n, 2);
    
    return 0;
}

/*function factorize(n, divisor) {
    if (n == 1) {
        return;
    }

    if (n % divisor == 0) {
        print(divisor);
        factorize(n / divisor, divisor);
    }
   else {
        factorize(n, divisor + 1); 
    }
}

function main() {
    int n;
    
    print("Enter a number to factorize: ");
    n = input();
    print("Prime factors of " + n + " are: ");
    factorize(n, 2);
}

main();*/