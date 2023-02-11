#include <stdio.h>
#include <stdlib.h> //qsort함수가 내장되어 있음

int compare(const void *arr1, const void *arr2)
{
    if (*(int *)arr1 > *(int *)arr2)
    {
        return 1; //두 원소를 교환하는 compare함수를 실행함.
    }
    else
    {
        return -1; //compare함수를 실행하지 않음.
    }
}

int main()
{
    int arr[1000001], t;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, t, sizeof(arr[0]), compare); //(정렬하려는 배열, 배열 원소의 총 수, 원소 하나의 크기, compare함수)
    
    for (int i = 0; i < t; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            continue;
        }
        else
        {
            printf("%d\n", arr[i]);
        }
    }
    return 0;
}
//기준값에 의한 분할을 통해서 정렬하는 방범이다.
//퀵정렬의 장점: 실행시간이 O(NlogN)으로 빠른 편이다.
//퀵정렬의 단점: pivot에 의해 성능 차이가 심하고 최악의 경우 O(N^2)가 걸리게 된다.