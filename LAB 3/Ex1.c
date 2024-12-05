#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100
/*Suppose we would like to implement a queue system for a commercial website.
Given that the website offers a list of items, each item has a limited quantity in
stock. Implement a queue of customers, and each customer can buy only a few
products among the available items.
- Determine the item name, quantity, and price in stock.
- Specify a queue of n customers; each customer can buy k products from one
item (k is different for each customer).
- Customers take turns to enter (enqueue) and leave (dequeue) the queue according to the FIFO order to purchase wanted products.
- If a customer successfully purchases products, display a message and reduce
the number of products in stock. Otherwise, display a warning message if the
item has been run out*/
struct Item {
    char name[50];
    int quantity;
    double price;
};

struct Customer {
    char name[50];
    char itemWanted[50];
    int quantityWanted;
};

struct Queue {
    struct Customer customers[MAX_CUSTOMERS];
    int front;
    int rear;
    int size;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(struct Queue *q) {
    return q->size == 0;
}

int isFull(struct Queue *q) {
    return q->size == MAX_CUSTOMERS;
}
void enqueue(struct Queue *q, struct Customer c) {
    if (isFull(q)) {
        printf("Queue is full, cannot add more customers.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_CUSTOMERS;
    q->customers[q->rear] = c;
    q->size++;
}
struct Customer dequeue(struct Queue *q) {
    struct Customer c = {"", "", 0};
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return c;
    }
    c = q->customers[q->front];
    q->front = (q->front + 1) % MAX_CUSTOMERS;
    q->size--;
    return c;
}
void initItems(struct Item items[], int nItems) {
    for (int i = 0; i < nItems; i++) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter quantity in stock for %s: ", items[i].name);
        scanf("%d", &items[i].quantity);
        printf("Enter price for %s: ", items[i].name);
        scanf("%lf", &items[i].price);
    }
}

void displayItems(struct Item items[], int nItems) {
    printf("\nItems in stock:\n");
    for (int i = 0; i < nItems; i++) {
        printf("%s: %d available at $%.2f each\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void processPurchase(struct Customer c, struct Item items[], int nItems) {
    int found = 0;
    for (int i = 0; i < nItems; i++) {
        if (strcmp(items[i].name, c.itemWanted) == 0) {
            found = 1;
            if (items[i].quantity >= c.quantityWanted) {
                items[i].quantity -= c.quantityWanted;
                printf("%s successfully purchased %d of %s\n", c.name, c.quantityWanted, c.itemWanted);
            } else {
                printf("Sorry, %s, not enough stock of %s. Only %d left.\n", c.name, c.itemWanted, items[i].quantity);
            }
            break;
        }
    }
    if (!found) {
        printf("Item %s not found in stock.\n", c.itemWanted);
    }
}
int main() {
    int nItems;
    printf("Enter number of items in stock: ");
    scanf("%d", &nItems);

    struct Item items[MAX_ITEMS];
    initItems(items, nItems);

    struct Queue customerQueue;
    initQueue(&customerQueue);

    int choice;
    do {
        printf("\n1. Display items\n2. Add customer to queue\n3. Process next customer\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayItems(items, nItems);
                break;
            case 2: {
                if (isFull(&customerQueue)) {
                    printf("Queue is full, cannot add more customers.\n");
                } else {
                    struct Customer c;
                    printf("Enter customer's name: ");
                    scanf("%s", c.name);
                    printf("Enter item wanted: ");
                    scanf("%s", c.itemWanted);
                    printf("Enter quantity wanted: ");
                    scanf("%d", &c.quantityWanted);
                    enqueue(&customerQueue, c);
                }
                break;
            }
            case 3: {
                if (isEmpty(&customerQueue)) {
                    printf("No customers in the queue.\n");
                } else {
                    struct Customer c = dequeue(&customerQueue);
                    processPurchase(c, items, nItems);
                }
                break;
            }
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
