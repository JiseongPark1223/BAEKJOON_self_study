#include <stdio.h>

int top = -1, stack[1000001], cnt[1000001] = {0}, res[1000001] = {0}, str[1000001], n, num;

void push(int x)
{
    stack[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &str[i]);
        cnt[str[i]]++; //원소의 갯수를 이용해 결과를 출력해야 하므로 cnt에 원소의 갯수를 저장
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        while (top >= 0 && cnt[stack[top]] <= cnt[str[i]]) //스택에 있는 원소의 갯수와 현 배열의 원소 갯수를 비교
        {
            pop(); //현 배열의 원소 갯수가 더 크면 stack에 있는 원소 갯수를 차감.
        }
        if (top == -1)
        {
            res[i] = -1;
        }
        else
        {
            res[i] = stack[top];
        }
        push(str[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}
