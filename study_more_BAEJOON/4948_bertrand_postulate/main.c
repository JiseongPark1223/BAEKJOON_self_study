#include <stdio.h>

int main()
{
    int num[246913] = {0}, n, cnt = 0;
    num[0] = 1, num[1] = 1; //소수가 아닌 수들은 배열에 1을 저장한다.
    
    scanf("%d", &n);
    
    for (int i = 2; i <= 246912; i++)
    {
        if (num[i] == 1)
        {
            continue;
        }
        else
        {
            for (int j = 2; i * j <= 246912; j++)
            {
                num[i * j] = 1; 
            }
        }
    }
    
    while (n != 0)
    {
        for (int i = n + 1; i <= 2*n; i++) //베르트랑의 공준 조건에서 소수가 몇 개인지 갯수를 센다.
        {
            if (num[i] == 0) //배열 값에 0이 있으면 소수이다.
            {
                cnt++;
            }
        }
        
        printf("%d\n", cnt);
        cnt = 0;
        
        scanf("%d", &n);
    }
    return 0;
}