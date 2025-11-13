#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <math.h>
#include <ctype.h>

int evaluatePostfix(char expression[])
{
    Stack s;
    createStack(&s);
    for (int i=0; expression[i]!='\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(&s,(int)expression[i]-'0');
        }
        else
        {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (expression[i])
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            case '-':
                push(&s, operand1 - operand2);
                break;
            case '*':
                push(&s, operand1 * operand2);
                break;
            case '/':
                push(&s, operand1 / operand2);
                break;
            case '^':
                push(&s, pow(operand1,operand2));
                break;
            default:
                printf("Invalid operator: %c\n", expression[i]);
                exit(EXIT_FAILURE);
            }
        }
    }
    return pop(&s);
}

int main()
{
    char expression[] = "823^/23*+51*-";  // Postfix expression: 3 * 2 + 5
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
