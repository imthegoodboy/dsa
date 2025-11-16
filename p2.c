/*
LAB PROGRAM - 2

Design, Develop and Implement a Program in C for converting an Infix Expression
to Postfix Expression. The program should support both parenthesized and
non-parenthesized expressions with operators:

Operators Supported:
+ (Addition)
- (Subtraction)
* (Multiplication)
/ (Division)
% (Remainder)
^ (Power)

Operands: Alphanumeric (A-Z, a-z, 0-9)

Example:
Input:   A+B*(C-D)
Output:  ABCD-*+

Input:   (A+B)*C-D
Output:  AB+C*D-
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertToPostfix();
void push(char);
char pop();
int precedence(char);

char infix[30], postfix[30], stack[30];
int top = -1;

int main()
{
    printf("Enter a valid infix expression:\n");
    scanf("%s", infix);

    convertToPostfix();

    printf("\nInfix Expression    : %s\n", infix);
    printf("Postfix Expression  : %s\n", postfix);

    return 0;
}

// Convert infix to postfix
void convertToPostfix()
{
    int i = 0, j = 0;
    char symbol, temp;
    push('#');  // Stack bottom marker

    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (isalnum(symbol)) // Operand (A-Z, a-z, 0-9)
        {
            postfix[j++] = symbol;
        }
        else
        {
            switch (symbol)
            {
                case '(':
                    push(symbol);
                    break;

                case ')':
                    temp = pop();
                    while (temp != '(')
                    {
                        postfix[j++] = temp;
                        temp = pop();
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (precedence(stack[top]) >= precedence(symbol))
                    {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;

                default:
                    printf("\nInvalid character encountered in expression!\n");
                    exit(0);
            }
        }
        i++;
    }

    // Pop remaining operators
    while (top > 0)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate the postfix string
}

// Push element to stack
void push(char item)
{
    top++;
    stack[top] = item;
}

// Pop element from stack
char pop()
{
    char item = stack[top];
    top--;
    return item;
}

// Operator precedence function
int precedence(char symbol)
{
    switch (symbol)
    {
        case '#': return -1;
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3; // Highest precedence
    }
    return -1;
}
