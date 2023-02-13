#include <stdio.h>

int isPrime(int n) //소수를 구하는 함수
{
    if (n == 1) //1은 소수가 아니기 때문에 0을 리턴
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int num1, num2, sum = 0, min = 0;
    
    scanf("%d %d", &num1, &num2);
    
    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i)) //소수이면 isPrime함수가 1을 출력해 if문을 실행한다.
        {
            if (min == 0)
            {
                min = i; //첫번째로 오는 소수가 최솟값이다.
            }
            sum += i;
        }
    }
    
    printf("%d\n%d", sum, min);
    return 0;
}