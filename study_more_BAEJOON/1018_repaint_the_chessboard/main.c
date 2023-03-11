#include <stdio.h>

int main()
{
    int x, y, cnt = 0, min = 33;
    char board[50][50] = {0};
    
    scanf("%d %d", &y, &x);
    
    for (int i = 0; i < y; i++)
    {
        scanf("%s", board[i]);
    }
    
    for (int i = 0; i <= x - 8; i++)
    {
        for (int j = 0; j <= y - 8; j++)
        {
            for (int k = i; k < 8 + i; k++)
            {
                for (int l = j; l < 8 + j; l++)
                {
                    if ((k + l)%2 == 0 && board[l][k] != 'W') //각 좌표를 더한 값이 짝수이면 W
                    {
                        cnt++;
                    }
                    if ((k + l)%2 != 0 && board[l][k] != 'B') //각 좌표를 더한 값이 홀수이면 B
                    {
                        cnt++;
                    }
                }
            }
            if (cnt > 32) //다시 칠해야하는 수가 32가 넘어가면 W와 B의 순서를 바꾸는 것이 낫다.
            {
                cnt = 64 - cnt;
            }
            if (min > cnt)
            {
                min = cnt;
            }
            cnt = 0;
            
        }
    }
    printf("%d", min);
}
//이 문제의 핵심은 좌표를 더했을때 홀짝의 규칙이 있다는 것과 다시 칠해야 하는 값이 32를 넘어가는 순간
//W와 B의 순서를 바꾸어 칠하는게 더 적다는 것을 파악해야 한다.