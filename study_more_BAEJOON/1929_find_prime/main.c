#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, arr[1000001] = {0};
    arr[1] = 1; //1은 소수가 아니기 때문에 제외한다.
    
    scanf("%d %d", &m, &n);
    
    for (int i = 2; i*i <= n; i++) //최댓값의 제곱근 이후에는 곱셈이 대칭이기 때문에 제곱근까지 곱한다.
    {
        for (int j = 2; j <= n; j++)
        {
            arr[i * j] = 1;
        }
    }
    
    for (int i = m; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
//에라토스테네스의 체는 소수를 구하는 방법 중 하나이다.
//2부터 시작해서 그 수를 제외한 배수를 제외하면서 소수를 구하는 방식이다.