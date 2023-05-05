#include <stdio.h>

void binary(int n) //-2진수에서는 각 조건에 따라 다른 계산법을 적용해야한다.
{
    if (n == 1) //1이 나오면 1을 출력후 종료
    {
        printf("1");
        return;
    }
    else
    {
        if (n % 2 == 0) //짝수인 경우 나머지는 0이고 몫에 값을 더할 필요가 없다.
        {
            binary(n/-2);
            printf("0");
        }
        else //홀수인 경우
        {
            if (n > 0) //양수인 경우에는 몫에 값을 더할 필요없고 나머지가 1이다.
            {
                binary(n/-2);
                printf("1");
            }
            else //음수인 경우 몫에 1을 더해주어야 나머지가 1이 출력된다.
            {
                binary(n/-2 + 1);
                printf("1");
            }
        }
    }
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    if (n == 0) //0을 입력받는 경우 예외
    {
        printf("0");
    }
    else
    {
        binary(n);
    }
    
    return 0;
}