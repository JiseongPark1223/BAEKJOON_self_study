#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *arr1, const void *arr2)
{
    if (strlen((char *)arr1) > strlen((char *)arr2))
    {
        return 1;
    }
    else if (strlen((char *)arr1) < strlen((char *)arr2))
    {
        return -1;
    }
    else
    {
        return strcmp((char *)arr1, (char *)arr2);
    }
}

int main()
{
    int n;
    char arr[20000][51];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    
    qsort(arr, n, sizeof(arr[0]), compare);
    
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i] , arr[i + 1]) != 0 || i == n - 1) //중복되는 단어는 하나만 출력해야 한다.
        {                                                   //따라서 같지 않아야 하지만 마지막 단어는 출력해야 하므로 i == n - 1의 조건을 넣어준다.
            printf("%s\n", arr[i]);
        }
    }
    return 0;
}
//문제에 제한시간이 있으므로 bubblesort로 정렬하면 시간초과가 됨.
//따라서 bubblesort보다 더 시간이 적게 소요되는 qsort를 사용해야 함.
//qsort(arr, arr_size, sizeof(arr[0]), compare)의 형태로 이루어진다.
//compare함수의 출력값이 1이면 실행 -1이면 실행하지 않는다.