/*
4. Design, Develop and Implement a Menu Driven Program in C for the following
   Operations on Circular QUEUE of integers (Array Implementation with MAX size)

   Operations:
   a. Insert an Element into Circular QUEUE
   b. Delete an Element from Circular QUEUE
   c. Demonstrate Overflow and Underflow situations
   d. Display the status of Circular QUEUE
   e. Exit

   Example (MAX = 5):
   -----------------------------------------
   Input:
       1 (Insert) -> 10
       1 (Insert) -> 20
       1 (Insert) -> 30
       3 (Display)
       2 (Delete)
       3 (Display)
       4 (Exit)

   Output:
       10 inserted into the queue.
       20 inserted into the queue.
       30 inserted into the queue.
       Circular Queue elements: 10 20 30
       Front: 0, Rear: 2
       10 deleted from the queue.
       Circular Queue elements: 20 30
       Front: 1, Rear: 2
       Exiting program.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the Circular Queue

int cQueue[MAX];
int front = -1;
int rear = -1;

// Function to check if queue is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert Element
void insertElement() {
    int element;
    if (isFull()) {
        printf("\nCircular Queue Overflow: Cannot insert element.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &element);

        if (front == -1)  // Inserting first element
            front = 0;

        rear = (rear + 1) % MAX;
        cQueue[rear] = element;
        printf("%d inserted into the queue.\n", element);
    }
}

// Delete Element
void deleteElement() {
    int deletedItem;
    if (isEmpty()) {
        printf("\nCircular Queue Underflow: Cannot delete element.\n");
    } else {
        deletedItem = cQueue[front];

        if (front == rear) {    // Only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("%d deleted from the queue.\n", deletedItem);
    }
}

// Display Queue
void displayQueue() {
    int i;
    if (isEmpty()) {
        printf("\nCircular Queue is Empty.\n");
    } else {
        printf("\nCircular Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d ", cQueue[i]);
        }
        printf("%d\n", cQueue[i]); // Print last element
        printf("Front: %d, Rear: %d\n", front, rear);
    }
}

// Main Menu
int main() {
    int choice;

    printf("Circular Queue Operations Menu:\n");
    printf("1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Display Status\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertElement(); break;
            case 2: deleteElement(); break;
            case 3: displayQueue(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
