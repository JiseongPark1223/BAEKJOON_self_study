#include <stdio.h>
 
int main()
{
    int arr[10] = {0}, n; //0 ~ 9의 갯수를 arr에 저장한다.
    
    scanf("%d", &n);
    
    while (n != 0)
    {
        arr[n%10]++; //각자릿수를 해당 배열에 추가
        n /= 10;
    }
    
    for (int i = 9; i >= 0; i--)
    {
        while (arr[i] != 0)
        {
            printf("%d", i);
            arr[i]--;
        }
    }
    
    return 0;
}