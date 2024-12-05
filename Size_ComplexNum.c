    // EXAMPLE FOR FINAL BY LS

    /* A complex num is given is this form:
        |z| = a + bi
    a: real part, b: imaginary part
    A size of a complex: |z| = sqrt(a^2 + b^2)
    Use array*/

    // (a): Iteration    //O(n)
    float modulus(float real, float imaginary) {
        return sqrt(real * real + imaginary * imaginary);
    }

    void iterative(float complex_array[][2], int size, float moduli[]) {
        for (int i = 0; i < size; i++) {
            moduli[i] = modulus(complex_array[i][0], complex_array[i][1]);
        }
    }

    int main() {
        float complex_numbers[][2] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}};
        int size = sizeof(complex_numbers) / sizeof(complex_numbers[0]);
        float moduli[size];

        iterative(complex_numbers, size, moduli);

        for (int i = 0; i < size; i++) {
            printf("%.2f\n", moduli[i]);
        }

        return 0;
    }
    /*function modulus(real, imaginary) {
        return squareRoot(real * real + imaginary * imaginary);
    }

    function iterative_modulus(complex_array, size, moduli) {
        for (int i = 0; i < size; i++) {
            moduli[i] = modulus(complex_array[i][0], complex_array[i][1]);
        }
    }

    function main() {
        float complex_numbers[][] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}};
        int size = sizeof(complex_numbers) / sizeof(complex_numbers[0]);
        float moduli[size];

        iterative_modulus(complex_numbers, size, moduli);

        for (int i = 0; i < size; i++) {
            printf("%.2f\n", moduli[i]);
        }

        return 0;
    }*/


    // (b): recursion       //O(n)
    double modulus(double real, double imaginary) {
        return sqrt(real * real + imaginary * imaginary);
    }

    void recursive(double complex_array[], double moduli[], int size, int i) {
        if (i == size) {
            return;
        }
        
        moduli[i] = modulus(complex_array[2*i], complex_array[2*i + 1]);
        modulus(complex_array, moduli, size, i + 1);
    }

    int main() {
        double complex_numbers[] = {3, 4, 1, 1, 0, 2, -3, -4};
        int size = sizeof(complex_numbers) / sizeof(double) / 2;

        double moduli[size];
        modulus(complex_numbers, moduli, size, 0);

        for (int i = 0; i < size; i++) {
            printf("%lf\n", moduli[i]);
        }

        return 0;
    }
    /*function calculate_modulus(real, imaginary):
        return sqrt(real * real + imaginary * imaginary)

    function recursive_modulus(complex_array, moduli, size, i):
        if i == size:
            return
        
        moduli[i] = calculate_modulus(complex_array[2*i], complex_array[2*i + 1])
        recursive_modulus(complex_array, moduli, size, i + 1)

    function main():
        double complex_numbers[] = {3, 4, 1, 1, 0, 2, -3, -4}
        int size = sizeof(complex_numbers) / sizeof(double) / 2
        double moduli[size]
        
        recursive_modulus(complex_numbers, moduli, size, 0)
        
        for i from 0 to size-1:
            print(moduli[i])

    main()*/


    // (c): Interation + Linklist         //O(n)
    typedef struct ListNode {
        int value[2];
        struct ListNode* next;
    } ListNode;

    typedef struct LinkedList {
        ListNode* head;
    } LinkedList;

    void append(LinkedList* list, int value[2]) {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->value[0] = value[0];
        new_node->value[1] = value[1];
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

    float* calculate_moduli(LinkedList* list) {
        int length = 0;
        ListNode* current = list->head;

        while (current != NULL) {
            length++;
            current = current->next;
        }

        float* moduli = (float*)malloc(length * sizeof(float));
        current = list->head;
        int index = 0;
        while (current != NULL) {
            float a = current->value[0];
            float b = current->value[1];
            moduli[index] = sqrt(a * a + b * b);
            current = current->next;
            index++;
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

        float* moduli = calculate_moduli(&ll);

        for (int i = 0; i < num_complex_numbers; i++) {
            printf("%.2f\n", moduli[i]);
        }

        free(moduli);

        return 0;
    }
    /*
    Define a structure ListNode {
        int value[2];
        ListNode* next;
    }

    Define a structure LinkedList {
        ListNode* head;
    }

    Function append(list: LinkedList*, value[2]: int):
        new_node = allocate memory for ListNode
        new_node->value[0] = value[0]
        new_node->value[1] = value[1]
        new_node->next = NULL
        
        if list->head is NULL:
            list->head = new_node
        else:
            current = list->head
            while current->next is not NULL:
                current = current->next
            current->next = new_node

    Function calculate_moduli(list: LinkedList*) -> float*:
        length = 0
        current = list->head
        
        while current is not NULL:
            length++
            current = current->next
        
        moduli = allocate memory for array of floats of length
        current = list->head
        index = 0
        
        while current is not NULL:
            a = current->value[0]
            b = current->value[1]
            moduli[index] = square root of (a * a + b * b)
            current = current->next
            index++
        
        return moduli

    Function main():
        ll: LinkedList
        ll.head = NULL
        
        complex_numbers[][] = {{3, 4}, {1, 1}, {0, 2}, {-3, -4}}
        num_complex_numbers = length of complex_numbers
        
        for i from 0 to num_complex_numbers:
            append(&ll, complex_numbers[i])
        
        moduli = calculate_moduli(&ll)
        
        for i from 0 to num_complex_numbers:
            print moduli[i]
        
        free(moduli)
        
        return 0
    */


    // (d): Recursion + Linklist          //O(n)
    struct Node {
        int value;
        struct Node* next;
    };

    struct LinkedList {
        struct Node* head;
    };

    void append(struct LinkedList* linkedList, int value) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->next = NULL;
        
        if (linkedList->head == NULL) {
            linkedList->head = new_node;
        } else {
            struct Node* current = linkedList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void recursive(struct Node* node) {
        if (node == NULL) {
            return;
        }
        
        int a = node->value;
        int modulus = abs(a);
        printf("%d\n", modulus);
        
        recursive(node->next);
    }

    void calculate_moduli(struct LinkedList* linkedList) {
        recursive(linkedList->head);
    }

    int main() {
        struct LinkedList ll;
        ll.head = NULL;
        
        int complex_numbers[] = {3, 4, 1, 1, 0, 2, -3, -4};
        int num_size = sizeof(complex_numbers) / sizeof(complex_numbers[0]);
        
        for (int i = 0; i < num_size; i += 2) {
            int real = complex_numbers[i];
            int img = complex_numbers[i + 1];

            int complex_num = real + img * I;
            append(&ll, complex_num);
        }
        
        calculate_moduli(&ll);
        
        return 0;
    }
    /*
    struct Node {
        int value;
        struct Node* next;
    };

    struct LinkedList {
        struct Node* head;
    };

    void append(struct LinkedList* linkedList, int value) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->next = NULL;
        
        if (linkedList->head == NULL) {
            linkedList->head = new_node;
        } else {
            struct Node* current = linkedList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void recursive(struct Node* node) {
        if (node == NULL) {
            return;
        }
        
        int a = node->value;
        int modulus = abs(a);
        printf("%d\n", modulus);
        
        recursive(node->next);
    }

    void calculate_moduli(struct LinkedList* linkedList) {
        recursive(linkedList->head);
    }

    int main() {
        struct LinkedList ll;
        ll.head = NULL;
        
        int complex_numbers[] = {3, 4, 1, 1, 0, 2, -3, -4};
        int num_size = sizeof(complex_numbers) / sizeof(complex_numbers[0]);
        
        for (int i = 0; i < num_size; i += 2) {
            int real = complex_numbers[i];
            int img = complex_numbers[i + 1];

            int complex_num = real + img * I;
            append(&ll, complex_num);
        }
        
        calculate_moduli(&ll);
        
        return 0;
    }
    */