#include <stdio.h>

int stack[80001], top = -1;

void push(int x)
{
    stack[++top] = x; //스택에 추후에 비교할 값을 저장한다. 스택을 사용한 이유는 나중에 들어온 배열부터 비교하기 위해서 이다.
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
