#include <stdio.h>
#include <math.h>
//Ex1: Calculate ln(2) formula
float loga(int n, int i, float sum) {               //Complexity: O(n)
    if (i >= n) {
        return 0.5 + 0.5 * sum;
    }

    sum += pow(-1, i + 1) / (i * (i + 1));

    return loga(n, i + 1, sum);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    float result = loga(n, 1, 0);
    printf("Result of loga: %f\n", result); 
    return 0;
}
/*
function loga(n, i, sum) {
    if (i >= n) {
        return 0.5 + 0.5 * sum;
    }
    sum += pow(-1, i + 1) / (i * (i + 1));
    return loga(n, i + 1, sum);
}

function main() {
    int n;
    print("Enter the value of n: ");
    n = input();
    float result = loga(n, 1, 0);
    print("Result of loga: " + result);
}
main()
*/

// Ex2: Calculate ln(2) by using pi = 3.14
double calculate_pi(int terms) {                                   //Complexity: O(n)
    double pi = 0.0;
    for (int k = 0; k < terms; k++) {
        pi += (k % 2 == 0 ? 1.0 : -1.0) / (2 * k + 1);
    }
    return pi * 4;
}

double calculate_ln2(int terms) {
    double pi = calculate_pi(terms);
    return pi / 2;
}

int main() {
    int terms;

    printf("Enter the number of terms to calculate Pi: ");
    scanf("%d", &terms);

    double pi = calculate_pi(terms);
    double ln2 = calculate_ln2(terms);

    printf("Approximated value of Pi: %.15f\n", pi);
    printf("Approximated value of ln(2): %.15f\n", ln2);
    
    return 0;
}

/*function calculate_pi(terms)
    pi = 0.0
    for k from 0 to terms
        if k is even 
            pi = pi + 1.0 / (2 * k + 1)
        else
            pi = pi - 1.0 / (2 * k + 1)
    end for
    return pi * 4
end function

function calculate_ln2(terms)
    pi = calculate_pi(terms)
    return pi / 2
end function

function main()
    terms = input("Enter the number of terms to calculate Pi: ")
    
    pi = calculate_pi(terms)
    ln2 = calculate_ln2(terms)
    
    output("Approximated value of Pi: ", pi)
    output("Approximated value of ln(2): ", ln2)
end function
*/
