#include <stdio.h>

long long int gcd(long long int a, long long int b) //유클리드 알고리즘을 이용하여 최대공약수를 구한다.
{
    if (b == 0)
    {
        return a;
    }
    gcd(b, a%b);
}

int main()
{
    long long int a, b;
    
    scanf("%lld %lld", &a, &b);
    
    if (a < b)
    {
        printf("%lld", a*b/gcd(a, b)); //최소공배수는 최대공약수로 나눈 값의 몫을 곱한 값이라는 것을 이용한다.
    }
    else
    {
        printf("%lld", a*b/gcd(a, b));
    }
}
//이 문제의 핵심은 유클리드 알고리즘을 이용할 수 있어야 한다.
//유클리드 알고리즘이란 gcd(a, b) = gcd(b, a%b)이 성립한다는 알고리즘이다.
//또한 최대공약수를 이용하여 최소공배수를 구하는 방법을 알아야 한다.