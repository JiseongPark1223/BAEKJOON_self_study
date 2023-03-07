#include <stdio.h>
#include <math.h>

int main()
{
    int n, num[10] = {0}, max = 0;
    double cnt = 0; 
    
    scanf("%d", &n);
    
    while (n > 0)
    {
        num[n%10]++; //방번호의 각자리수를 num 배열에 저장
        n /= 10;
    }
    
    num[6] += num[9]; //9와 6은 같이 쓸 수 있으므로 두 수를 합한다.
    
    for (int i = 0; i < 9; i++)
    {
        if (i == 6)
        {
            cnt = ceil(num[i] / 2.0); //3개의 숫자가 필요하면 2세트가 필요하기 때문에 2로 나눈 값을 올림한다.
        }
        else
        {
            cnt = num[i];
        }
        
        if (cnt > max)
        {
            max = cnt;
        }
    }
    
    printf("%d", max);
    return 0;
}
//이 문제의 핵심은 6과 9의 예외조항을 잘 만드는 것이다.
//특히 9와 6이 홀수개 필요할때의 조건을 잘 생각해 구현해야 한다.
