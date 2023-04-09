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
        while (top >= 0 && stack[top] <= arr[i])
        {
            pop();
        }
        if (top == -1)
        {
            res[i] = -1;
        }
        else
        {
            res[i] = stack[top];
        }
        push(arr[i]);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}