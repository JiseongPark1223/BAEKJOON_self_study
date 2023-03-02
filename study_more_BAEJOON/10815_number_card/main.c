#include <stdio.h>
#include <stdlib.h>

int compare(const void *arr1, const void *arr2) //qsort compare 함수, 오름차순 정렬로 설정한다.
{   
    if (*(int *)arr1 > *(int *)arr2)
    {
        return 1; //문자열을 교체
    }
    else
    {
        return -1; //그 외에는 교체하지 않음.
    }
}

int binary_search(int arr[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start)/2; //이진탐색 알고리즘은 mid를 중심으로 값을 찾아가는 방식을 말한다.
        if (arr[mid] == key) //값을 찾으면 1을 반환
        {
            return 1;
        }
        else if (arr[mid] < key) //값이 mid보다 크면 다음 탐색 시작위치를 mid + 1로 한다.
        {
            start = mid + 1;
        }
        else //key < arr[mid] //값이 mid보다 작으면 다음 탐색 끝위치를 mid - 1로 한다.
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int n, m, num[500001], card[500001];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    
    qsort(num, n, sizeof(int), compare);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &card[i]);
    }
    
    for (int i = 0; i < m; i++)
    {
        card[i] = binary_search(num, 0, n - 1, card[i]);
        printf("%d ", card[i]);
    }
    return 0;
}
//이 문제는 선형탐색 알고리즘으로 하면 시간이 오래걸려 시간초과가 난다.
//따라서 qsort함수로 오름차순 정렬을 한 후 이진탐색 알고리즘을 이용해 시간 복잡도를 O(N)에서 O(logN)으로 줄일 수 있다.
