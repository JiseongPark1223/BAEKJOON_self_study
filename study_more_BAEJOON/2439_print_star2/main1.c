#include <stdio.h>

int main()
{
    int num;
    
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++)
    {
        for (int j = num - 1 - i; j > 0; j--) //첫번째 for문에서는 공백의 개수를 조절한다.
        {                                     //줄 수가 증가할수록 공백은 줄어들어야 하므로 i값의 증가를 이용한다. 
            printf(" ");
        }
        for (int j = 0; j <= i; j++) //두번째 for문에서는 별의 개수를 조절gka.
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
