#include <stdio.h>
#include <string.h>

int top;
char stack[103];

void push(char c)
{
    stack[++top] = c;
}

void pop()
{
    top--;
}

int main()
{
    char str[103];
    
    fgets(str, 103, stdin);
    
    while (strcmp(str, ".\n") != 0)
    {
        int len = strlen(str) - 2;
        top = -1;
        
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(')
            {
                push(str[i]);
            }
            else if (str[i] == '[')
            {
                push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (stack[top] == '(')
                {
                    pop();
                }
                else
                {
                    push(str[i]);
                }
            }
            else if (str[i] == ']')
            {
                if (stack[top] == '[')
                {
                    pop();
                }
                else
                {
                    push(str[i]);
                }
            }
            else
            {
                continue;
            }
        }
        
        if (top != -1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
        
        fgets(str, 103, stdin);
    }
    return 0;
}