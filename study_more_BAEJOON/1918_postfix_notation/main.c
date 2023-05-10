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
        if (str[i] == '(') //'('인 상황에서는 stack에 push한다.
        {
            push(str[i]);
        }
        else if (str[i] == ')') //')'는 괄호가 끝났다는 의미이기 때문에 '('가 나올때까지 pop한다.
        {
            while (stack[top] != '(')
            {
                printf("%c", stack[top]);
                pop();
            }
            pop();
        }
        else if (str[i] == '+' || str[i] == '-') //+와 -보다 출력우선 순위가 낮은 것은 '('인 경우이다.
        {
            while (top >= 0 && stack[top] != '(') //top이 -1인 경우는 스택에 아무것도 있는 않은 경우이므로 없다.
            {
                    printf("%c", stack[top]);
                    pop();
            }
            push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/') //*와 /보다 출력우선 순위가 낮은 것은 '(', +, -이다.
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
    
    if (top != -1) //스택에 남아있는 연산자를 출력한다.
    {
        while (top != -1)
        {
            printf("%c", stack[top]);
            pop();
        }
    }
    return 0;
}
