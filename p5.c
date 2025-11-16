/*
LAB PROGRAM - 5

Design, Develop and Implement a Menu Driven Program in C for the following
operations on Double Ended QUEUE (DEQUE) of integers
(Array Implementation of Queue with maximum size MAX)

Operations Supported:
a. Insertion / Deletion at FRONT end of DEQUE
b. Insertion / Deletion at REAR end of DEQUE
c. Display the status of DEQUE
d. Exit

Example Input/Output:

--- Deque Operations Menu ---
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter choice: 2
Enter integer to insert at rear: 10
10 inserted at rear.

Enter choice: 2
Enter integer to insert at rear: 20
20 inserted at rear.

Enter choice: 1
Enter integer to insert at front: 5
5 inserted at front.

Enter choice: 5
Deque elements: 5 10 20

Enter choice: 3
5 deleted from front.

Enter choice: 4
20 deleted from rear.

Enter choice: 5
Deque elements: 10

Enter choice: 6
Exiting program.
----------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Check if full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int data) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = data;
    printf("%d inserted at front.\n", data);
}

// Insert at rear
void insertRear(int data) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = data;
    printf("%d inserted at rear.\n", data);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    int deletedItem = deque[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("%d deleted from front.\n", deletedItem);
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    int deletedItem = deque[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }

    printf("%d deleted from rear.\n", deletedItem);
}

// Display DEQUE
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n--- Deque Operations Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2:
                printf("Enter integer to insert at rear: ");
                scanf("%d", &data);
                insertRear(data);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
