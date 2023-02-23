#include <stdio.h>

void print_star(int x, int y, int n) //별과 빈칸을 구분하는 함수
{
    if ((x / n) % 3 == 1 && (y / n) % 3 ==1) //빈칸의 규칙은 자신을 3, 9, 27등으로 나눈 것에 3을 나누면 나머지가 1이 나온다.
    {                                       
        printf(" ");
    }
    else
    {
        if (n / 3 == 0) //n/3이면 n이 1이고 빈칸의 조건에 성립하지 않기 때문에 별을 출력
        {
            printf("*");
        }
        else
        {
            print_star(x, y, n / 3); //재귀함수를 이용하여 3, 9, 27등으로 나눌 수 있게 한다.
        }
    }
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            print_star(i, j, n);
        }
        printf("\n");
    }
    return 0;
}

//문제에서 필요한 것은 빈칸의 규칙성을 찾는 것과 그것을 이용하여 재귀함수로 풀어내는 능력이다.
//3의 배수로 나누어 빈칸을 구한다는 것이 재귀함수의 포인트이다.