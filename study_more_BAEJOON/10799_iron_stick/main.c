#include <stdio.h>
#include <string.h>

char stack[100001];
int top;

void push(char x) //stack push
{
    stack[++top] = x;
}

void pop() //stack pop
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
        if (str[i] == '(') //(은 쇠막대기가 시작하는 부분이므로 스택배열에 push한다.
        {
            push(str[i]);
        }
        else
        {
            if (str[i - 1] == '(') //str[i - 1]이 '('이고 현재배열이 ')'이면 레이저란 뜻이다.
            {                      //따라서 쌓인 쇠막대기를 잘린 갯수에 더하고 pop해준다.
                cnt += top;
                pop();
            }
            else
            {
                cnt++; //레이저로 다 짤리고 남는 쇠막대기는 1개이기 때문에 cnt에 1을 더하고 pop한다.
                pop();
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}