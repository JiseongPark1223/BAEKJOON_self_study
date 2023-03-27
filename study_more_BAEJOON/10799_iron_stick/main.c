#include <stdio.h>
#include <string.h>

char stack[100001];
int top;

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
    int len, cnt = 0;
    char str[100001];
    
    scanf("%s", str);
    
    len = strlen(str);
    top = -1;
    
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else
        {
            if (str[i - 1] == '(')
            {
                cnt += top;
                pop();
            }
            else
            {
                cnt++;
                pop();
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}