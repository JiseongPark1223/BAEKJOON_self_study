#include <stdio.h>

int reverse(int num) //백의 자리 수와 일의 자리 수를 바꾸는 함수 선언
{
    int temp;
    temp = num - (num/100)*100 - num%10;
    num = (num%10)*100 + temp + (num/100);
    return num;
}

int main()
{
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    num1 = reverse(num1); //함수로 자리 수를 바꿈.
    num2 = reverse(num2);
    
    if (num1 > num2) //바꾼 수 중 더 큰 수를 출력.
    {
        printf("%d", num1);
    }
    else
    {
        printf("%d", num2);
    }
    return 0;
}
