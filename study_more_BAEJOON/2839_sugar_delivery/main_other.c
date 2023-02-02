#include <stdio.h>

int main()
{
    int num, s3 = 0, s5 = 0, result; 
    
    scanf("%d", &num);
    
    while (num != 0)
    {
        if (num % 5 == 0)
        {
            s5 = num/5;
            num = 0;
        }
        else
        {
            num -= 3;
            s3++;
        }
        
        if (num < 3 && num != 0) //0을 제외하고 3보다 작거나 음수인 수에 -1출력
        {
            printf("-1");
            return 0;
        }
    }
    result = s3 + s5; //3kg 설탕 봉지수와 5kg 설탕 봉지수를 합함.
    
    printf("%d", result);
    return 0;
}

//설탕 봉지수를 따로 변수로 놓아 코드가 단순함.
//-1이 출력되는 조건을 따로 빼놓아서 가독성이 좋음.