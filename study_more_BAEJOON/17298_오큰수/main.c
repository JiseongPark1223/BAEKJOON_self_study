#include <stdio.h>

int top = -1, stack[1000001];

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
    int t, arr[1000001], res[1000001];
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
    }
        
    for (int i = t - 1; i >= 0; i--)
    {
        while (top >= 0 && stack[top] <= arr[i]) //오른쪽부터 배열을 비교한다.
        {                                        //확인할 배열의 오른쪽에 더 큰 배열이 있나 확인해본다.
            pop();
        }
        if (top == -1)
        {
            res[i] = -1;
        }
        else
        {
            res[i] = stack[top]; //결과 배열에 오른쪽에서 가장 큰 수인 stack[top]을 저장한다.
        }
        push(arr[i]); //배열을 stack에 저장한다.
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}