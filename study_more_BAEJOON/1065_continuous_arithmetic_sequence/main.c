#include <stdio.h>

int d(int num)
{
    int n1, n2, n3;
    if (num < 100)
    {
        return 1;
    }
    else if (num == 1000)
    {
        return 0;
    }
    else
    {
        n1 = num / 100;
        n2 = (num - n1*100) / 10;
        n3 = (num - n1*100) % 10;
        
        if (n1 - n2 == n2 - n3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int check[1001] = {0}, n, cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        check[i] = d(i);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (check[i] == 1)
        {
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
//한수의 조건에 맞추어 수를 구분 짓는 함수를 만드는 것이 핵심이다.
//1부터 100보다 작으면 무조건 등차수열이기에 한수로 들어간다, 또한 1000은 무조건 한수가 아니다.
//3자리수는 각 자리수로 나누어 비교하여 한수인지 아닌지 판단한다, 이후 갯수를 센다.