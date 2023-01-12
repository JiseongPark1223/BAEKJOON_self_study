#include <stdio.h>

int main()
{
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%d\n", (a+b)%c);
    printf("%d\n", ((a%c)+(b%c))%c);
    printf("%d\n", (a*b)%c);
    printf("%d\n", ((a%c)*(b%c))%c);
    
    return 0;
}

//set
//a mod c = T, b mod c = S
//a = T + ic (i는 임의의 정수), b = S + jc (j는 임의의 정수)
//(a + b) mod c = ((T + ic) + (S + jc)) mod c 
//              = ((T + S) + (i + j)c) mod c
//              = (T + S) mod c, (i + j)c는 나머지 값을 구할떄 관계없는 값이다.
//              = ((a mod c) + (b mod c)) mod c

//(a * b) mod c = ((T + ic)(S + jc)) mod c
//              = (TS + T*jc + S*ic + ic*jc) mod c
//              = (TS + (T*j + S*i)c + (i*j)c) mod c, (T*j + S*i)c와 (i*j)c는 c로 나누어 떨어지므로 관계없는 값
//              = (TS) mod c
//              = ((a mod c) * (b mod c)) mod c 