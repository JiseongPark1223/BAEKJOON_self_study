#include <stdio.h>
#include <stdlib.h>

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

int binary_search(int start, int end, int arr[], int key)
{
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else // key < arr[mid]
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int t, num[100002], x, cnt = 0;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &num[i]);
    }
    
    scanf("%d", &x); 
    
    qsort(num, t, sizeof(int), compare); //qsort함수를 통해 배열을 오름차순으로 정렬한다.
    
    for (int i = 0; i < t; i++)
    {
        if (binary_search(0, t - 1, num, x - num[i])) //x - num[i]를 이진탐색으로 찾아 cnt에 추가한다.
        {
            cnt++;
        }
    }
    
    printf("%d", cnt/2); //합이 이루어지는 쌍이므로 2를 나누어준다.
    return 0;
}
//이 문제의 핵심은 이진탐색으로 x-num[i]을 찾는 것을 생각해내는 것이다.
//그리고 쌍을 구하라고 하였기 때문에 cnt/2를 출력해야 한다.