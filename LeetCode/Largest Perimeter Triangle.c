#include <stdio.h>

// Function to check if a triangle is valid
int is_valid_triangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Function to find the largest perimeter triangle
void largest_perimeter_triangle(int a, int b, int c) {
    int max_perimeter = 0;
    int max_a = 0, max_b = 0, max_c = 0;

    for (int i = a; i <= b; i++) {
        for (int j = i; j <= c; j++) {
            for (int k = j; k <= c; k++) {
                if (is_valid_triangle(i, j, k)) {
                    int perimeter = i + j + k;
                    if (perimeter > max_perimeter) {
                        max_perimeter = perimeter;
                        max_a = i;
                        max_b = j;
                        max_c = k;
                    }
                }
            }
        }
    }

    printf("Largest Perimeter Triangle: %d, %d, %d\n", max_a, max_b, max_c);
    printf("Perimeter: %d\n", max_perimeter);
}

int main() {
    int a, b, c;
    printf("Enter three sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    largest_perimeter_triangle(a, b, c);
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Function to check if a triangle is valid
int is_valid_triangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Recursive function to find the largest perimeter triangle
int largest_perimeter_triangle_recursive(int a, int b, int c, int max_perimeter) {
    if (a > c) {
        return max_perimeter;
    }

    int perimeter = a + b + c;
    if (is_valid_triangle(a, b, c) && perimeter > max_perimeter) {
        max_perimeter = perimeter;
    }

    return largest_perimeter_triangle_recursive(a + 1, b, c, max_perimeter);
}

int main() {
    int a, b, c;
    printf("Enter three sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    int max_perimeter = 0;
    max_perimeter = largest_perimeter_triangle_recursive(a, b, c, max_perimeter);

    printf("Largest Perimeter Triangle: %d, %d, %d\n", a, b, c);
    printf("Perimeter: %d\n", max_perimeter);
    return 0;
}*/