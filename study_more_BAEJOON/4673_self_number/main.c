#include <stdio.h>

int main()
{
    int num[10002] = {0}, temp, sum;
    
    for (int i = 1; i <= 10000; i++) //생성자 있는 숫자를 제거
    {
        sum = i;
        temp = i;
        
        while (temp > 0)
        {
            sum += temp%10; //생성자에 자신의 자릿수를 더함.
            temp /= 10;
        }
        
        if (sum < 10001)
        {
            num[sum] = 1; //sum이 10000이상 가면 stack smash가 발생하므로 조건문을 넣어줌.
        }
    }
    
    for (int i = 1; i <= 10000; i++)
    {
        if (num[i] == 0) //셀프넘버를 출력
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
