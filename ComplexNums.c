/*
A complex num is given in the form:
    z = a + bi
where a is the real part, b is the imaginary part
A size of a complex number is determined by its modulo:
    |z| = sqrt(a^2 + b^2)
Given an array of complex num
a) use Iteration
b) Recursion
c) Interation + Linklist
d) Recursion + linklist
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// (a): Iteration
double modulus(double a, double b) {
    return sqrt(a * a + b * b);
}

void iterative_modulus(double complex_array[][2], double moduli[], int size) {
    for (int i = 0; i < size; i++) {
        moduli[i] = modulus(complex_array[i][0], complex_array[i][1]);
    }
}
int main() {
    double complex_numbers[4][2] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}};
    double moduli[4];

    iterative_modulus(complex_numbers, moduli, 4);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", moduli[i]);
    }

    return 0;
}

// (b): Recursion O(n)
void recursive_modulus(double complex_array[][2], int i, double result[], int size) {
    if (i == size) {
        return;
    }
    else {
        double real = complex_array[i][0];
        double imag = complex_array[i][1];
        result[i] = sqrt(real*real + imag*imag);
        recursive_modulus(complex_array, i + 1, result, size);
    }
}

int main() {
    double complex_numbers[4][2] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}};
    double result[4];

    recursive_modulus(complex_numbers, 0, result, 4);

    for (int i = 0; i < 4; i++) {
        printf("%f\n", result[i]);
    }

    return 0;
}

// (c): Interation + Linklist
typedef struct ListNode {
    int value[2];
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
} LinkedList;

void append(LinkedList* ll, int value[2]) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value[0] = value[0];
    new_node->value[1] = value[1];
    new_node->next = NULL;

    if (ll->head == NULL) {
        ll->head = new_node;
    } else {
        ListNode* current = ll->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

double* calculate_moduli(LinkedList* ll) {
    double* moduli = (double*)malloc(sizeof(double) * 100); 
    int idx = 0;
    ListNode* current = ll->head;
    while (current) {
        int a = current->value[0];
        int b = current->value[1];
        moduli[idx++] = sqrt(a * a + b * b);
        current = current->next;
    }
    return moduli;
}

int main() {
    LinkedList ll;
    ll.head = NULL;
    int complex_numbers[][2] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}};
    int num_complex_numbers = sizeof(complex_numbers) / sizeof(complex_numbers[0]);

    for (int i = 0; i < num_complex_numbers; i++) {
        append(&ll, complex_numbers[i]);
    }

    double* moduli = calculate_moduli(&ll);
    for (int i = 0; i < num_complex_numbers; i++) {
        printf("%lf\n", moduli[i]);
    }

    free(moduli); 
    return 0;
}

// (d): Recursion + linklist
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

// Linked list struct
typedef struct LinkedList {
    ListNode* head;
} LinkedList;

void append(LinkedList* list, int value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void calculate_moduli_recursive(ListNode* node, double* result, int index) {
    if (node == NULL) {
        return;
    }
    int a = node->value / 10;
    int b = node->value % 10;
    double modulus = sqrt(a*a + b*b);
    result[index] = modulus;
    calculate_moduli_recursive(node->next, result, index + 1);
}

void calculate_moduli(LinkedList* list, double* result) {
    calculate_moduli_recursive(list->head, result, 0);
}

int main() {
    LinkedList ll;
    ll.head = NULL;
    int complex_numbers[] = {34, 11, 2, -34};
    int size = sizeof(complex_numbers) / sizeof(complex_numbers[0]);
    for (int i = 0; i < size; i++) {
        append(&ll, complex_numbers[i]);
    }
    
    double result[size];
    calculate_moduli(&ll, result);
    
    for (int i = 0; i < size; i++) {
        printf("%.2f ", result[i]);
    }
    
    return 0;
}
