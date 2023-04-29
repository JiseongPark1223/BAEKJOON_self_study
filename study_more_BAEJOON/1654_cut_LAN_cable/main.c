#include <stdio.h> //이분탐색 응용문제
#include <stdlib.h>

int compare(const void *arr1, const void *arr2) //내림차순으로 배열을 정렬
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

int binary_search(long long int start, long long int end, int *arr, int size, int key) //길이가 int형 정수의 최댓값까지 가능하다. 
{                                                                                      //따라서 start와 end의 자료형을 int로 하면 overflow로 while문이 무한 반복된다.
    long long int cnt = 0;
    int cnt_max = 0;
    
    while (start <= end) //이분탐색을 이용해 자른 갯수가 일치하는 최대 랜선의 길이는 구함.
    {
        cnt = 0;
        long long int mid = start + (end - start)/2;
        
        for (int i = 0; i < size; i++)
        {
            cnt += (arr[i]/mid);
            
            if (cnt > key) //자른 랜선의 갯수가 찾던 갯수보다 크면 for문 정지
            {
                break;
            }
        }
        if (cnt >= key) //자른 랜선의 갯수가 같아도 더 길게 자를수 있는 경우도 있음.(cnt > key인 경우는 찾는 길이보다 더 짧다는 뜻)
        {
            if (cnt_max < mid) //따라서 위 경우가 성립하는 최댓값이 정답
            {
                cnt_max = mid;
            }
            start = mid + 1;
        }
        else //cnt < key
        {
            end = mid - 1;
        }
    }
    return cnt_max;
}

int main()
{
    int k, n, arr[10001], res;
    
    scanf("%d %d", &k, &n);
    
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, k, sizeof(int), compare);
    
    res = binary_search(1, arr[0], arr, k, n);
    
    printf("%d", res);
    
    return 0;
}
