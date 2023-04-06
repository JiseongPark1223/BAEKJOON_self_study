#include <stdio.h>
#include <string.h>

int top = -1;
char stack[102], str[102]; //fgets함수의 경우 개행문자를 문자열을 읽고 저장한 후 문자열 끝에 NULL을 저장한다.
                           //따라서 문자열의 길이가 최대 100이므로 개행문자와 NULL문자를 고려해 배열의 원소를 102개로 설정해야한다.
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
    
    fgets(str, 102, stdin);
    
    while (str[0] != '.')
    {
        top = -1;
        len = strlen(str) - 2; //.과 개행문자를 고려
        
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (stack[top] == '(') //짝지어져야 하기때문에 stack[top]의 문자가 (일때만 pop한다.
                {
                    pop();
                }
                else
                {
                    push(str[i]);
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (stack[top] == '[') //짝지어져야 하기때문에 stack[top]의 문자가 [일때만 pop한다.
                {
                    pop();
                }
                else
                {
                    push(str[i]);
                    break;
                }
            }
            else
            {
                continue;
            }
        }
        
        if (top != -1) //짝지어져 괄호가 균형이 맞다면 모두 pop하면 top은 처음값인 -1이 된다.
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
        fgets(str, 102, stdin);
    }
    return 0;
}