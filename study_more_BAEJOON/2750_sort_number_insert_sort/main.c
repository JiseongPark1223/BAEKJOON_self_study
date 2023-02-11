#include <stdio.h>

int main()
{
    int t, arr[1001], key;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i < t; i++)
    {
        key = arr[i]; 
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) //앞의 배열된 부분과 비교
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; //자신의 알맞은 위치를 삽입
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
//insert sort은 배열의 앞요소부터 이미 정렬된 배열 부분과 비교해 key값의 위치를 삽입해 넣는 것을 말한다.
//시간 복잡도는 bubble sort와 유사하여 유용하지는 않다.