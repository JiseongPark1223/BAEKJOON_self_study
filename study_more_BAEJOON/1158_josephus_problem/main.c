#include <stdio.h>

int main()
{
    int arr[5002] = {0}, n, k, q;
    
    scanf("%d %d", &n, &k); //n명이 원으로 둘러 앉을때 k번째 사람을 제거하는 순서
    
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    
    printf("<%d", arr[k]); //처음 제거하는 사람은 무조건 k번째 사람이다.
    arr[k] = 0; //제거된 사람 배열에는 0을 저장
    q = k;
    
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        while (cnt != k)
        {
            q++;
            if (arr[q] != 0) 
            {
                cnt++;
            }
            if (q > n)
            {
                q = 0;
            }
        }
        printf(", %d", arr[q]);
        arr[q] = 0;
    }
    printf(">");
    return 0;
}
//이 문제의 핵심은 제거 안된 사람과 제거된사람을 판별하는 구현과 마지막 번호 사람에서 첫번쨰로 돌아가는 구현이 핵심이다.