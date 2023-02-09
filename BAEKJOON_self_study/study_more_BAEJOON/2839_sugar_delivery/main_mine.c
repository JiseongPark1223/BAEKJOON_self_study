#include <stdio.h>

int main()
{
    int n, cnt = 0;
    
    scanf("%d", &n);
    
    while (n > 0)
    {
        if (n % 5 == 0) //설탕이 5kg으로 나누어 떨어지면 그것이 최소 봉지수
        {
            cnt = n/5;
            n = 0;
        }
        else
        {
            while (n > 0)
            {
                n -= 3; //3kg봉지를 늘리며 5kg로 나누어 떨이지는지 본다.
                
                if (n < 0)
                {
                    cnt = -1;
                    break;
                }
                cnt++;
                
                if (n % 5 == 0)
                {
                    cnt = cnt + n/5;
                    n = 0;
                }
            }
        }
    }
    
    printf("%d", cnt);

    return 0;
}

//3kg와 5kg 봉지 중 5kg로 나누어떨어지면 그것이 최솟값이다.
//나누어 떨어지지 않으면 3kg봉지로 설탕을 줄이며 5kg 봉지로 나누어떨어지는지 본다.
//3kg을 기준으로 잡은 이유는 5kg으로 나누어떨어지는 것이 최소이기 때문이다.