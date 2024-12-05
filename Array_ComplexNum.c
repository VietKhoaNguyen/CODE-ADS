/*
A complex number is given in the form:
    z = a + bi
where a is the real part, b is the imaginary part
A size of a complex number is determined by its modulo:
    |z| = sqrt(a^2 + b^2)
Given an array of complex number
a) Sort this array using iteration
b) Sort this array using recursion
c) Sort this array using iteration + linked list
d) Sort this array using recursion + linked list   
*/
// (a) Sort this array using iteration   // O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float real;
    float imaginary; 
} Complex;

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    printf("%.2f + %.2fi  ", a, b);
}

void displayComplexArray(Complex* arr, int n){
    for (int i = 0; i < n; i++){
        displayComplex(arr[i]);
    }
    printf("\n");
}

float modulo(Complex c){
    float a, b, modulo;
    a = c.real;
    b = c.imaginary;
    modulo = sqrt(a * a + b * b);
    return modulo;
}

void insertValues(Complex* complexArray, int i, float a, float b){
    complexArray[i].real = a;
    complexArray[i].imaginary = b;
}

void bubbleSort(Complex* arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (modulo(arr[j]) > modulo(arr[j + 1])){
                Complex temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    Complex* complexArray;
    int n = 8;
    complexArray = (Complex*) malloc(n * sizeof(Complex));
    
    insertValues(complexArray, 0, 1, 2);
    insertValues(complexArray, 1, 3, 4);
    insertValues(complexArray, 2, 6, 8);
    insertValues(complexArray, 3, 5, 2);
    insertValues(complexArray, 4, 11, 20);
    insertValues(complexArray, 5, 9, 1);
    insertValues(complexArray, 6, 10, 0);
    insertValues(complexArray, 7, 2, 2);

    displayComplexArray(complexArray, n);

    bubbleSort(complexArray, n);

    displayComplexArray(complexArray, n);

    free(complexArray);
    return 0;
}
/*
define Structure Complex {
    real: float
    imaginary: float
}

function displayComplex(c: Complex) {
    a = c.real
    b = c.imaginary
    output("%.2f + %.2fi  ", a, b)
}

function displayComplexArray(arr: pointer to Complex, n: integer) {
    for i from 0 to n-1 {
        displayComplex(arr[i])
    }
    output("
")
}

function modulo(c: Complex) {
    a = c.real
    b = c.imaginary
    modulo = sqrt(a * a + b * b)
    return modulo
}

function insertValues(complexArray: pointer to Complex, i: integer, a: float, b: float) {
    complexArray[i].real = a
    complexArray[i].imaginary = b
}

function bubbleSort(arr: pointer to Complex, n: integer) {
    for i from 0 to n-1 {
        for j from 0 to n-2 {
            if (modulo(arr[j]) > modulo(arr[j + 1])) {
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }
}

function main() {
    complexArray: pointer to Complex
    n = 8
    allocate memory for complexArray of size n
    
    insertValues(complexArray, 0, 1, 2)
    insertValues(complexArray, 1, 3, 4)
    insertValues(complexArray, 2, 6, 8)
    insertValues(complexArray, 3, 5, 2)
    insertValues(complexArray, 4, 11, 20)
    insertValues(complexArray, 5, 9, 1)
    insertValues(complexArray, 6, 10, 0)
    insertValues(complexArray, 7, 2, 2)

    displayComplexArray(complexArray, n)

    bubbleSort(complexArray, n)

    displayComplexArray(complexArray, n)

    deallocate memory for complexArray
    return 0
}
*/


// (b) Sort this array using recursion    // O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float real;
    float imaginary; 
} Complex;

void swap(Complex* x, Complex* y){
    Complex temp = *x;
    *x = *y;
    *y = temp;
}

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    printf("%.2f + %.2fi  ", a, b);
}

void displayComplexArray(Complex* arr, int n){
    for (int i = 0; i < n; i++){
        displayComplex(arr[i]);
    }
    printf("\n");
}

float modulo(Complex c){
    float a = c.real, b = c.imaginary;
    return sqrt(a * a + b * b);
}

void insertValues(Complex* complexArray, int i, float a, float b){
    complexArray[i].real = a;
    complexArray[i].imaginary = b;
}

void bubbleSort(Complex* arr, int i, int n){
    if (i >= n){
        return;
    }
    for (int j = 0; j < n - 1; j++){
        if (modulo(arr[j]) > modulo(arr[j + 1])){
            swap(&arr[j], &arr[j + 1]);
        }
    }
    bubbleSort(arr, i + 1, n);
}

int main(){
    Complex* complexArray;
    int n = 8;
    complexArray = (Complex*) malloc(n * sizeof(Complex));
    
    insertValues(complexArray, 0, 1, 2);
    insertValues(complexArray, 1, 3, 4);
    insertValues(complexArray, 2, 6, 8);
    insertValues(complexArray, 3, 5, 2);
    insertValues(complexArray, 4, 11, 20);
    insertValues(complexArray, 5, 9, 1);
    insertValues(complexArray, 6, 10, 0);
    insertValues(complexArray, 7, 2, 2);

    displayComplexArray(complexArray, n);

    bubbleSort(complexArray, 0, n);

    displayComplexArray(complexArray, n);

    free(complexArray);
    return 0;
}
/*
// Define a structure for representing complex numbers
struct ComplexNumber {
    float real;
    float imaginary;
};

// Function to swap two complex numbers
void swap(ComplexNumber* x, ComplexNumber* y) {
    ComplexNumber temp = *x;
    *x = *y;
    *y = temp;
}

// Function to display a complex number in the form a + bi
void displayComplexNumber(ComplexNumber c) {
    float a = c.real;
    float b = c.imaginary;
    print(a + " + " + b + "i");
}

// Function to display an array of complex numbers
void displayComplexNumberArray(ComplexNumber* arr, int n) {
    for (int i = 0; i < n; i++) {
        displayComplexNumber(arr[i]);
    }
    print("\n");
}

// Function to calculate the modulus of a complex number
float calculateModulus(ComplexNumber c) {
    float a = c.real;
    float b = c.imaginary;
    return sqrt(a * a + b * b);
}

// Function to insert values into a complex number array
void insertValuesIntoArray(ComplexNumber* complexArray, int index, float a, float b) {
    complexArray[index].real = a;
    complexArray[index].imaginary = b;
}

// Function to perform bubble sort on an array of complex numbers based on their moduli
void bubbleSortComplexNumbers(ComplexNumber* arr, int index, int size) {
    if (index >= size) {
        return;
    }
    for (int j = 0; j < size - 1; j++) {
        if (calculateModulus(arr[j]) > calculateModulus(arr[j + 1])) {
            swap(&arr[j], &arr[j + 1]);
        }
    }
    bubbleSortComplexNumbers(arr, index + 1, size);
}

// Main function to demonstrate the usage of the defined functions
int main() {
    ComplexNumber* complexNumberArray;
    int arraySize = 8;
    complexNumberArray = (ComplexNumber*) malloc(arraySize * sizeof(ComplexNumber));
    
    insertValuesIntoArray(complexNumberArray, 0, 1, 2);
    insertValuesIntoArray(complexNumberArray, 1, 3, 4);
    insertValuesIntoArray(complexNumberArray, 2, 6, 8);
    insertValuesIntoArray(complexNumberArray, 3, 5, 2);
    insertValuesIntoArray(complexNumberArray, 4, 11, 20);
    insertValuesIntoArray(complexNumberArray, 5, 9, 1);
    insertValuesIntoArray(complexNumberArray, 6, 10, 0);
    insertValuesIntoArray(complexNumberArray, 7, 2, 2);

    displayComplexNumberArray(complexNumberArray, arraySize);

    bubbleSortComplexNumbers(complexNumberArray, 0, arraySize);

    displayComplexNumberArray(complexNumberArray, arraySize);

    free(complexNumberArray);
    return 0;
}
*/

// (c) iteration + Linklist         // O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float real;
    float imaginary; 
} Complex;

void swap(Complex* x, Complex* y){
    Complex temp = *x;
    *x = *y;
    *y = temp;
}

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    printf("%.2f + %.2fi  ", a, b);
}

float modulo(Complex c){
    float a = c.real, b = c.imaginary;
    return sqrt(a * a + b * b);
}

// Linked List
struct Node{
    Complex data;
    struct Node *next;
};

struct Node *createNode(float a, float b){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    Complex c;
    c.real = a;
    c.imaginary = b;
    newNode->data = c;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, float a, float b){
    struct Node *newNode = createNode(a, b);
    if (*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL){
        displayComplex(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bubbleSort(struct Node *head){
    if (head == NULL){
        return;
    }

    int swapped;
    struct Node *j;
    struct Node *i = NULL;

    do {
        swapped = 0;
        j = head;
        while (j->next != i){
            if (modulo(j->data) > modulo(j->next->data)){
                swap(&j->data, &j->next->data);
                swapped = 1;
            }
            j = j->next;
        }
        i = j;
    } while (swapped);
}

int main(){
    struct Node *head = NULL;
    
    insertNode(&head, 1, 2);
    insertNode(&head, 3, 4);
    insertNode(&head, 6, 8);
    insertNode(&head, 5, 2);
    insertNode(&head, 11, 20);
    insertNode(&head, 9, 1);
    insertNode(&head, 10, 0);
    insertNode(&head, 2, 2);
    
    printList(head);
    bubbleSort(head);
    printList(head);

    return 0;
}
/*// Define a data structure for Complex numbers
Complex {
    float real
    float imaginary
}

// Function to swap two Complex numbers
function swap(Complex *x, Complex *y):
    temp = *x
    *x = *y
    *y = temp

// Function to display a Complex number
function displayComplex(c):
    a = c.real
    b = c.imaginary
    output(a + " + " + b + "i")

// Function to calculate the modulus of a Complex number
function modulo(c):
    a = c.real
    b = c.imaginary
    modulo = square_root(a * a + b * b)
    return modulo

// Define a Node for Linked List
Node {
    Complex data
    Node next
}

// Function to create a new Node with a Complex number
function createNode(a, b):
    newNode = new Node
    c.real = a
    c.imaginary = b
    newNode.data = c
    newNode.next = NULL
    return newNode

// Function to insert a new Node at the end of the Linked List
function insertNode(head, a, b):
    newNode = createNode(a, b)
    if (head == NULL):
        head = newNode
    else:
        temp = head
        while (temp.next != NULL):
            temp = temp.next
        temp.next = newNode

// Function to print all Complex numbers in the Linked List
function printList(head):
    temp = head
    while (temp != NULL):
        displayComplex(temp.data)
        temp = temp.next
    output("\n")

// Function to perform Bubble Sort on the Linked List based on the modulus of Complex numbers
function bubbleSort(head):
    if (head == NULL):
        return
    
    swapped = 0
    i = NULL
    do:
        swapped = 0
        j = head
        while (j.next != i):
            if (modulo(j.data) > modulo(j.next.data)):
                swap(&j.data, &j.next.data)
                swapped = 1
            j = j.next
        i = j
    while (swapped)

// Main function to test the Linked List and Bubble Sort
function main():
    head = NULL
    
    insertNode(&head, 1, 2)
    insertNode(&head, 3, 4)
    insertNode(&head, 6, 8)
    insertNode(&head, 5, 2)
    insertNode(&head, 11, 20)
    insertNode(&head, 9, 1)
    insertNode(&head, 10, 0)
    insertNode(&head, 2, 2)
    
    printList(head)
    bubbleSort(head)
    printList(head)*/


//(d) recursion + Linklist     // O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float real;
    float imaginary;
} Complex;

void swap(Complex* x, Complex* y){
    Complex temp = *x;
    *x = *y;
    *y = temp;
}

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    printf("%.2f + %.2fi  ", a, b);
}

float modulo(Complex c){
    float a = c.real, b = c.imaginary;
    return sqrt(a * a + b * b);
}

// Linked List
struct Node{
    Complex data;
    struct Node *next;
};

struct Node *createNode(float a, float b){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    Complex c;
    c.real = a;
    c.imaginary = b;
    newNode->data = c;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, float a, float b){
    struct Node *newNode = createNode(a, b);
    if (*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL){
        displayComplex(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bubbleSort(struct Node *head, int swapped){
    if (head == NULL || head->next == NULL){
        return;
    }
    struct Node* j = head;
    swapped = 0;

    while (j->next != NULL){
        if (modulo(j->data) > modulo(j->next->data)){
            swap(&j->data, &j->next->data);
            swapped = 1;
        }
        j = j->next;
    }

    if (swapped){
        bubbleSort(head, swapped);
    }
}

int main(){
    struct Node *head = NULL;

    insertNode(&head, 1, 2);
    insertNode(&head, 3, 4);
    insertNode(&head, 6, 8);
    insertNode(&head, 5, 2);
    insertNode(&head, 11, 20);
    insertNode(&head, 9, 1);
    insertNode(&head, 10, 0);
    insertNode(&head, 2, 2);

    printList(head);

    bubbleSort(head, 0);

    printList(head);

    return 0;
}
/*define structure Complex {
    real: float
    imaginary: float
}

function swap(x: pointer to Complex, y: pointer to Complex) {
    temp = dereference x
    dereference x = dereference y
    dereference y = temp
}

function displayComplex(c: Complex) {
    a = c.real, b = c.imaginary
    print(a, " + ", b, "i  ")
}

function modulo(c: Complex) {
    a = c.real, b = c.imaginary
    return squareRoot(a * a + b * b)
}

define structure Node {
    data: Complex
    next: pointer to Node
}

function createNode(a: float, b: float) {
    newNode = allocate memory for Node
    c = Complex 
    c.real = a
    c.imaginary = b
    newNode.data = c
    newNode.next = NULL
    return newNode
}

function insertNode(head: pointer to pointer to Node, a: float, b: float) {
    newNode = createNode(a, b)
    if dereference head == NULL {
        dereference head = newNode
    } else {
        temp = dereference head
        while temp.next != NULL {
            temp = temp.next
        }
        temp.next = newNode
    }
}

function printList(head: pointer to Node) {
    temp = head
    while temp != NULL {
        displayComplex(temp.data)
        temp = temp.next
    }
    print("\n")
}

function bubbleSort(head: pointer to Node, swapped: int) {
    if head == NULL OR head.next == NULL {
        return
    }
    j = head
    swapped = 0
    
    while j.next != NULL {
        if modulo(j.data) > modulo(j.next.data) {
            swap(address of j.data, address of j.next.data)
            swapped = 1
        }
        j = j.next
    }
    
    if swapped {
        bubbleSort(head, swapped)
    }
}

function main() {
    head = NULL
    
    insertNode(address of head, 1, 2)
    insertNode(address of head, 3, 4)
    insertNode(address of head, 6, 8)
    insertNode(address of head, 5, 2)
    insertNode(address of head, 11, 20)
    insertNode(address of head, 9, 1)
    insertNode(address of head, 10, 0)
    insertNode(address of head, 2, 2)
    
    printList(head)
    
    bubbleSort(head, 0)
    
    printList(head)
    
    return 0
}*/