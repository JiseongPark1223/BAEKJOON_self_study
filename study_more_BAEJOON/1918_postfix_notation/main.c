#include <stdio.h>
#include <string.h>

int top = -1;
char stack[101];

void push(char x)
{
    stack[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    int len;
    char str[101];
    
    scanf("%s", str);
    
    len = strlen(str);
    
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (stack[top] != '(')
            {
                printf("%c", stack[top]);
                pop();
            }
            pop();
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (top >= 0 && stack[top] != '(')
            {
                    printf("%c", stack[top]);
                    pop();
            }
            push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (top >= 0 && stack[top] != '(' && stack[top] != '+' && stack[top] != '-')
            {
                printf("%c", stack[top]);
                pop();
            }
            push(str[i]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    
    if (top != -1)
    {
        while (top != -1)
        {
            printf("%c", stack[top]);
            pop();
        }
    }
    return 0;
}