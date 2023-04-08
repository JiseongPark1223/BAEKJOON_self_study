#include <stdio.h>
#include <stdlib.h>

int n, m, have_card[500001], find_card[500001], res[500001], u, l;

int compare(const void *arr1, const void *arr2)
{
    if (*(int *)arr1 > *(int *)arr2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int upper_bound(int start, int end, int *arr, int key) //찾고자 하는 수가 끝난 배열의 다음 위치를 구한다.
{
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (arr[mid] <= key)
        {
            start = mid + 1;
        }
        else // arr[mid] > key
        {
            end = mid - 1;
        }
    }
    return start;
}

int lower_bound(int start, int end, int *arr, int key) //찾고자 하는 배열이 시작하는 배열의 이전 위치를 구한다.
{
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else // arr[mid] >= key
        {
            end = mid - 1;
        }
    }
    return end;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &have_card[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &find_card[i]);
    }
    
    qsort(have_card, n, sizeof(int), compare);
    
    for (int i = 0; i < m; i++)
    {
        u = upper_bound(0, n - 1, have_card, find_card[i]);
        l = lower_bound(0, n - 1, have_card, find_card[i]);
        printf("%d ", u - l - 1);
    }
    return 0;
}