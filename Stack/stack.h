#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
typedef int type;

typedef struct
{
    int top;
    type items[MAX];
} Stack;
void createStack(Stack *s)
{
    s->top = -1;
}

int isstackempty(Stack s)
{
    return s.top == -1;
}

int isstackfull(Stack s)
{
    return s.top == MAX - 1;
}

void push(type item, Stack *s)
{
    if (isstackfull(*s))
        printf("Stack Over Flow\n");
    else
        s->items[++s->top] = item;
}

type pop(Stack *s)
{
    if (isstackempty(*s))
    {
        printf("Stack UnderFlow\n");
        return 0;
    }
    return s->items[s->top--];
}

type peekTop(Stack s)
{
    if (!isstackempty(s))
        return s.items[s.top];
    else
    {
        printf("Stack is empty!\n");
        return 0;
    }
}

type peekBottom(Stack s)
{
    if (!isstackempty(s))
        return s.items[0];
    else
    {
        printf("Stack is empty!\n");
        return 0;
    }
}

int size(Stack s)
{
    return isstackempty(s) ? 0 : s.top + 1;
}

void distroyStack(Stack *s)
{
    s->top = -1;
}

void copyStack(Stack old, Stack *s)
{
    s->top = old.top;
    for (int i = 0; i <= old.top; i++)
        s->items[i] = old.items[i];
}

void printStack(Stack s)
{
    printf("[Top -> Bottom] ");
    while (!isstackempty(s))
        printf("%d ", pop(&s));
    printf("\n");
}

void reverseStack(Stack *s)
{
    Stack temp;
    createStack(&temp);
    while (!isstackempty(*s))
        push(pop(s), &temp);
    *s = temp;
}

void SortStack(Stack *s)
{
    Stack temp;
    createStack(&temp);

    while (!isstackempty(*s))
    {
        int item = pop(s);
        while (!isstackempty(temp) && peekTop(temp) > item)
            push(pop(&temp), s);
        push(item, &temp);
    }
    *s = temp;
}

int isStackEqual(Stack a, Stack b)
{
    if (a.top != b.top)
        return 0;
    for (int i = 0; i <= a.top; i++)
    {
        if (a.items[i] != b.items[i])
            return 0;
    }
    return 1;
}

int searchStack(Stack s, int value)
{
    for (int i = 0; i <= s.top; i++)
        if (s.items[i] == value)
            return i;
    return -1;
}
void traverseStack(Stack s, void (*func)(type *))
{
    for (int i = s.top; i >= 0; i--)
    {
        func(&s.items[i]);
    }
}
int maxInStack(Stack s)
{
    if (isstackempty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    int max = s.items[0];
    for (int i = 1; i <= s.top; i++)
        if (s.items[i] > max)
            max = s.items[i];
    return max;
}

int minInStack(Stack s)
{
    if (isstackempty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    int min = s.items[0];
    for (int i = 1; i <= s.top; i++)
        if (s.items[i] < min)
            min = s.items[i];
    return min;
}

Stack mergeStacks(Stack a, Stack b)
{
    Stack result;
    createStack(&result);
    for (int i = 0; i <= a.top; i++)
        push(a.items[i], &result);
    for (int i = 0; i <= b.top; i++)
        push(b.items[i], &result);
    return result;
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    createStack(&s);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];
        if (isspace(c))
            continue;

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c, &s);
        }
        else if (c == ')')
        {
            while (!isstackempty(s) && peekTop(s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // remove '('
        }
        else // operator
        {
            while (!isstackempty(s) && precedence(peekTop(s)) >= precedence(c))
                postfix[j++] = pop(&s);
            push(c, &s);
        }
    }

    while (!isstackempty(s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

void postfixToInfix(char postfix[], char infix[])
{
    Stack s;
    createStack(&s);
    char temp[2 * MAX][MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];
        if (isspace(c))
            continue;

        if (isalnum(c))
        {
            char operand[2] = {c, '\0'};
            strcpy(temp[++top], operand);
        }
        else
        {
            char op2[MAX], op1[MAX], expr[MAX];
            strcpy(op2, temp[top--]);
            strcpy(op1, temp[top--]);

            snprintf(expr, sizeof(expr), "(%s%c%s)", op1, c, op2);
            strcpy(temp[++top], expr);
        }
    }

    strcpy(infix, temp[top]);
}
double evaluatePostfix(char postfix[])
{
    double stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];
        if (isspace(c))
            continue;

        if (isdigit(c))
        {
            stack[++top] = c - '0'; // تحويل char إلى رقم
        }
        else
        {
            double val2 = stack[top--];
            double val1 = stack[top--];
            double result;

            switch (c)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            case '^':
                result = pow(val1, val2);
                break;
            default:
                printf("Unknown operator: %c\n", c);
                return 0;
            }
            stack[++top] = result;
        }
    }
    return stack[top];
}
