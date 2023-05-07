#include <stdio.h>
#include <string.h>

int main()
{
    int len, i = 0, temp = 0;
    char arr[1000001];
    
    scanf("%s", arr);
    
    len = strlen(arr);
    
    if (len % 3 == 0) //2진수를 8진수로 바꾸는 과정은 3자리씩 끊어 8진수로 바꾼다.
    {                 //그 과정에서 앞에 시작배열 숫자들은 따로 처리해준다.
        temp += (arr[i] - '0');
        temp *= 2;
        temp += (arr[i + 1] - '0');
        temp *= 2;
        temp += (arr[i + 2] - '0');
        i += 3;
        
        printf("%d", temp);
    }
    else if (len % 3 == 1)
    {
        temp += (arr[i] - '0');
        i += 1;
        
        printf("%d", temp);
    }
    else
    {
        temp += (arr[i] - '0');
        temp *= 2;
        temp += (arr[i + 1] - '0');
        i += 2;
        
        printf("%d", temp);
    }
    
    for (i; i < len; i+=3) //앞부분 숫자들을 처리해주면 나머지 2진수 숫자를 8진수로 바꾸어 출력한다.
    {
        temp = 0;
        temp += (arr[i] - '0');
        temp *= 2;
        temp += (arr[i + 1] - '0');
        temp *= 2;
        temp += (arr[i + 2] - '0');
        
        printf("%d", temp);
    }
    
    return 0;
}