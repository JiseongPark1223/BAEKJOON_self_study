#include <stdio.h>

int main()
{
    int fibo[42][2] = {0}, t, n;
    fibo[0][0] = 1, fibo[1][0] = 0, fibo[0][1] = 0, fibo[1][1] = 1;
    //0과 1이 몇번 사용되는지 묻는 문제로 0과 1을 따로 두어 갯수를 구한다.
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d", &n);
        
        for (int i = 2; i <= n; i++)
        {
            fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0]; //dp프로그래밍을 이용해 시간초과 없이 문제를 풀어야 한다.
            fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
        }
        
        printf("%d %d\n", fibo[n][0], fibo[n][1]);
    }
    return 0;
}
