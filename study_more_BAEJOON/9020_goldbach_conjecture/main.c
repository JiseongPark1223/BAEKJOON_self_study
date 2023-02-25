#include <stdio.h>

int main()
{
    int num[10001] = {0}, t, n; //소수인 숫자의 배열을 0, 아닌 것을 1로 둔다.
    num[0] = 1, num[1] = 1;
    
    for (int i = 2; i < 5001; i++)
    {
        for (int j = 2*i; j < 10001; j += i)
        {
            num[j] = 1;
        }
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        
        for (int j = n / 2; j > 1; j--)
        {
            if (num[j] == 0 && num[n - j] == 0) //두 개의 소수의 차이가 적어야 하므로 중앙값부터 멀어진다.
            {
                printf("%d %d\n", j, n - j);
                break;
            }
        }
    }
    return 0;
}