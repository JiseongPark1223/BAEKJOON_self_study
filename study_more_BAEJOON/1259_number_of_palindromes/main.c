#include <stdio.h>

int reverse(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        reverse = reverse * 10 + n%10;
        n /= 10;
    }
    
    return reverse;
}

int main()
{
    int num;
    
    while (1)
    {
        scanf("%d", &num);
        
        if (num == 0)
        {
            break;
        }
        
        if (num == reverse(num)) //앞으로 읽으나 뒤로 읽으나 값이 같은 숫자이므로 reverse값과 비교한다.
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}