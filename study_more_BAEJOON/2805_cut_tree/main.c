#include <stdio.h>

int compare(const void *arr1, const void *arr2) //qsort로 배열을 내림차순으로 정렬
{
    if (*(int *)arr1 < *(int *)arr2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int binary_search(int start, int end, int size, int key, int *arr)
{
    long long int cnt; //나무의 갯수는 최대 1,000,000이고 나무의 높이는 1,000,000,000이므로 int형 범위를 넘을 수 있음.
    int cnt_max = 0;
    while (start <= end)
    {
        cnt = 0;
        int mid = start + (end - start)/2;
        
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > mid) //절단기 높이보다 큰 것만 cnt에 더함
            {
                cnt += (arr[i] - mid);
            }
            if (cnt > key)
            {
                break;
            }
        }
        
        if (cnt >= key) //나무의 길이가 key보다 길다는 것은 절단기의 높이가 낮다는 뜻
        {
            if (cnt_max < mid) //위 조건이 성립하는 절단기 높이 중 가장 큰 것이 절단기 높이의 최댓값
            {
                cnt_max = mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return cnt_max;
}

int main()
{
    int n, m, arr[1000001], res;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare); //배열을 내림차순으로 정렬
    
    res = binary_search(1, arr[0], n, m, arr); //이분탐색으로 선형탐색보다 시간을 적게 쓴다.
    
    printf("%d", res);
    
    return 0;
}
