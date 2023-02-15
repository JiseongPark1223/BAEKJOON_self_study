#include <stdio.h>

int main()
{
    int n, cnt = 0, ans = 665, temp = 0;
    
    scanf("%d", &n);
    
    while (cnt != n)
    {
        ans++;
        temp = ans;
        while (temp != 0)
        {
            if (temp % 1000 == 666)
            {
                cnt++;
                break;
            }
            else
            {
                temp /= 10;
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}