#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int main()
{
    int n, s, arr[100001], res[100001] = {0}, min;
    
    scanf("%d %d", &s, &n);
    
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < s; i++) //수빈이가 각 동생들에 갈 수 있는 거리의 최대는 각 동생들과 수빈이 거리의 최대공약수이다.
    {
        res[i] = fabs(n - arr[i]);
    }
    
    min = gcd(res[0], res[1]);
    
    for (int i = 0; i < s; i++) //최대공약수 중 최소 값을 구해야 모든 동생들에게 도달할 수 있다.
    {
        if (min > gcd(min, res[i]))
        {
            min = gcd(min, res[i]);
        }
    }
    
    printf("%d", min);
    
    return 0;
}
