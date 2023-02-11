#include <stdio.h>

int main()
{
    int t, num, arr[10002] = {0}, max = 0; //arr는 원소 갯수의 배열, max는 원소의 최댓값을 나타낸다.
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &num);
        arr[num]++;
        
        if (max < num)
        {
            max = num;
        }
    }
    
    for (int i = 1; i <= max; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = 0; j < arr[i]; j++) //원소의 갯수에 맞추어 알맞은 원소를 출력한다.
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
//counting sort는 주어진 배열의 값의 범위가 작은 경우 빠른 속도를 갖는 알고리즘
//입력된 원소의 갯수와 원소의 최댓값을 이용하여 구성한 배열이다.