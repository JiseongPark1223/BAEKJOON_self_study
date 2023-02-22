#include <stdio.h>

int main()
{
    int ans = 1, n, temp = 0, save = 0, res = 0, flag = 0;
    
    scanf("%d", &n);
    

    while (ans < n) //브루스포스 알고리즘을 이용하여 n값의 분해합을 찾는다.
    {
        temp = ans;
            
        while (temp > 0)
        {
            res += temp%10; //각 자릿수를 더한다.
            temp /= 10;
        }
            
        res = res + ans; //자신의 값을 더한후 n값과 비교한다.
            
        if (res == n)
        {
            printf("%d", ans);
            flag = 1;
            break;
        }
        ans++;
        res = 0;
    }

    if (flag == 0) //분해합이 없는 경우 0을 출력한다.
    {
        printf("0");
    }
    return 0;
}