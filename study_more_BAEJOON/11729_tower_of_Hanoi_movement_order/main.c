#include <stdio.h>

void hanoi(int n, int from, int to)
{
    if (n == 1) //옮길 원판이 1개 밖에 남지 않을때
    {
        printf("%d %d\n", from, to); //옮기는 위치 출력
    }
    if (n >= 2)
    {
        int mid = 6 - from - to;
        hanoi(n - 1, from, mid); //n번째 원판이 to 위치로 가기 위해서는 1부터 n - 1번째 원판까지는 남는 공간 mid로 가야한다.
        hanoi(1, from, to); //n번째 원판만 남으면 to로 향한다.
        hanoi(n - 1, mid, to); //1부터 n - 1번째 원판까지 to로 옮긴다.
    }
}

int main()
{
    int num;
    
    scanf("%d", &num);
    
    printf("%d\n", (1 << num)- 1); //옮긴 횟수는 원판의 갯수는 2의 갯수제곱 - 1이기때문에 비트연산자를 이용해 2의 제곱을 표현한다.
    
    hanoi(num, 1, 3);
    return 0;
}