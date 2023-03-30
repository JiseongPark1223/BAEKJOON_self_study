#include <stdio.h>

int stack[80001], top = -1;

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
    int n, num;
    long long int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        
        while (top >= 0 && stack[top] <= num) //각 배열의 원소가 몇개의 원소에게 보여지는냐를 기준으로 while을 구성
        {
            pop(); //stack에 쌓인 배열보다 값이 크면 stack을 pop하면서 비교
        }
        push(num);
        cnt += top;
    }
    printf("%lld", cnt);
    
    return 0;
}