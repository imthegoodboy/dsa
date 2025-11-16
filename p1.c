/*
LAB PROGRAM - 1
Design, Develop and Implement a Menu Driven Program in C for the following
operations on STACK of Integers (Array Implementation of Stack with maximum
size MAX):

Operations:
a. Push an Element onto Stack
b. Pop an Element from Stack
c. Demonstrate Overflow and Underflow on Stack
d. Display the status of Stack
e. Exit

--------------------------------------------
Sample Input/Output:

1. Push 
2. Pop 
3. Display 
4. Exit
Enter choice: 1
Enter value: 10
10 pushed.

Enter choice: 1
Enter value: 20
20 pushed.

Enter choice: 1
Enter value: 30
30 pushed.

Enter choice: 1
Enter value: 40
Stack Overflow!

Enter choice: 3
Stack elements: 30 20 10

Enter choice: 2
30 popped.

Enter choice: 2
20 popped.

Enter choice: 2
10 popped.

Enter choice: 2
Stack Underflow!

Enter choice: 4
Exiting...
--------------------------------------------
*/

#include <stdio.h>
#define MAX 5  // maximum size of stack

int stack[MAX];
int top = -1;

// Function to push
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed.\n", value);
    }
}

// Function to pop
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d popped.\n", stack[top]);
        top--;
    }
}

// Function to display stack contents
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main menu function
int main()
{
    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
