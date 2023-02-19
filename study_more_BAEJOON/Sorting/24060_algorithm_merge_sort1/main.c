#include <stdio.h>
#include <stdlib.h>

int *arr, size, order, sort[500001], cnt = 0;

void merge(int arr[], int start, int mid, int end) //정렬을 병합할 함수를 선언
{
    int i = start;
    int j = mid + 1;
    int k = start;
    
    while (i <= mid && j <= end) //오름차순으로 정렬한다.
    {
        if (arr[i] <= arr[j])
        {
            sort[k] = arr[i]; //sort에 정렬시킨다.
            i++;
        }
        else
        {
            sort[k] = arr[j];
            j++;
        }
        k++;
    }
    
    if (i > mid) //정렬을 나눈 쪽 중 한쪽이 먼저 채워진 경우
    {
        for (int t = j; t <= end; t++) //나머지쪽을 차례대로 채운다.
        {
            sort[k] = arr[t];
            k++;
        }
    }
    else
    {
        for (int t = i; t <= mid; t++)
        {
            sort[k] = arr[t];
            k++;
        }
    }
    
    for (int i = start; i <= end; i++) //arr에 정렬을 복사한다.
    {
        arr[i] = sort[i];
        cnt++;
        if (cnt == order)
        {
            printf("%d", arr[i]);
        }
    }
}

void merge_sort(int arr[], int start, int end) //정렬을 나눌 함수를 선언
{
    if (start < end) //정렬을 최소한으로 나눈다.
    {
        int mid = start + (end - start)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    scanf("%d %d", &size, &order);
    
    arr = malloc(sizeof(int) * size); 
    
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    merge_sort(arr, 0, size - 1);
    
    if (cnt < order)
    {
        printf("-1");
    }
    return 0;
}
//merge sort란 정렬되지 않은 리스트들을 하나의 원소만 남게 분할한 후 정복, 결합의 과정을 통해 정렬하는 알고리즘을 말한다.
//시간복잡도는 O(nlogn)이다.
//위 알고리즘의 핵심을 재귀를 이용한 함수의 이해와 start, mid, end 변수를 활용하는 것이다.