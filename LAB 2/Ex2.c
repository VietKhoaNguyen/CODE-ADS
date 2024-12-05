#include <stdio.h>
#include <stdlib.h>
/*Assume that a railway train has N railroad cars attached together
such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
corresponds to a node in this list.
- Each car carries a maximum capacity of passengers (int type) and has an id
(char type). Both variables are user-defined values.
- Each car is reserved by a number of passengers (int type) (which should be
less than its capacity). If there are any cars that don’t have any passengers,
they should be removed from the train.
- It is possible to add new cars to the train.
- A function is available to display all cars’ information or the length of the
train.
Implement a program in C/C++ using Linked List to manage the train and test all
functions*/
typedef struct CAR {
    int passenger;
    char ID[20];
    struct CAR* next;
} CAR;

typedef struct TRAIN {
    CAR* head;
} TRAIN;

TRAIN* createTRAIN() {
    TRAIN* train = (TRAIN*)malloc(sizeof(TRAIN));
    train->head = NULL;
    return train;
}

void addCAR(TRAIN* train, char* ID, int passenger){
    CAR* car = (CAR*)malloc(sizeof(CAR));
    int i;
    for (i = 0; ID[i] != '\0' && i < sizeof(car->ID) - 1; i++) {
        car->ID[i] = ID[i];
    }
    car->ID[i] = '\0';
    car->passenger = passenger;
    car->next = NULL;
    
    if (train->head == NULL || passenger> 0) {
        car->next = train->head;
        train->head = car;
    }
    else{
        CAR* current = train->head;
        while (current->next != NULL && current->next->passenger > 0) {
            current = current->next;
        }
        current->next = car;
        
    }
    
}

void deleteCAR(TRAIN* train){
    CAR* current = train->head;
    CAR* prev = NULL;
    
    while(current != NULL){
        if(current->passenger == 0){
            if (prev == NULL) {
                train->head = current->next;
            }
            else{
                prev->next = current->next;
            }
            current = current->next;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
}

int Length(TRAIN* train) {
    int count = 0;
    CAR* current = train->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


void display(TRAIN* train){
    CAR* current = train->head;
    while (current != NULL) {
        printf("%s , %d\n", current->ID, current->passenger);
        current = current->next;
    }
}

int main()
{
    TRAIN* train = createTRAIN();

    addCAR(train, "Car 1", 100);
    addCAR(train, "Car 2", 0);
    addCAR(train, "Car 3", 5);
    addCAR(train, "Car 4", 0);
    addCAR(train, "Car 5", 2);
    addCAR(train, "Car 6", 0);

    deleteCAR(train);
    display(train);

    printf("%d\n", Length(train));
    return 0;
}