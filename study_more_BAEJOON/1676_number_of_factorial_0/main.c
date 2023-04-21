#include <stdio.h>

int main()
{
    int n, cnt2 = 0, cnt5 = 0;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i *= 2) //2의 갯수를 구한다.
    {                               
        cnt2 += (n/i);
    }
    
    for (int i = 5; i <= n; i *= 5) //5의 갯수를 구한다.
    {
        cnt5 += (n/i);
    }
    
    printf("%d", cnt2 > cnt5 ? cnt5 : cnt2);
    
    return 0;
}
//마지막 자리에 오는 0의 갯수는 2*5, 10의 갯수로 정해진다.
//따라서 2와 5중 더 적은 쪽이 10의 갯수 즉 0의 갯수가 된다.