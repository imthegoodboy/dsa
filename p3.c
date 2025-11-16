/*
3. Design, Develop and Implement a Program in C for the following Stack Application:
   Evaluation of Suffix (Postfix) Expression with single digit operands 
   and operators: +, -, *, /, %, ^

   Example:
   Input  : 231*+9-
   Steps  : 2 + (3 * 1) - 9  =  -4
   Output : -4
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int element);
int pop();
int evaluateExpression(char *expression);

int main() {
    char expression[MAX];

    printf("Enter a suffix (postfix) expression: ");
    scanf("%s", expression);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(0);
    } else {
        stack[++top] = element;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    } else {
        return stack[top--];
    }
}

int evaluateExpression(char *expression) {
    int i, op1, op2, result;

    for (i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');  // Convert char to int
        } else {
            op2 = pop();
            op1 = pop();

            switch (expression[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator\n");
                    exit(0);
            }
            push(result);
        }
    }

    return pop();
}
