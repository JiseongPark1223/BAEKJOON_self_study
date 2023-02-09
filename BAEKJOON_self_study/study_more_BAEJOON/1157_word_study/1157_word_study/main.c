#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000001] = {0};
    int max = 0, maxnum = 0, len, alpha[26], cnt = 0;
    
    scanf("%s", arr);
    
    len = strlen(arr);
    
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 'Z') //소문자로 입력받은 문자를 대문자로 바꾼다.
        {
            arr[i] -= 32;
        }
        alpha[arr[i] - 65]++; //alpha라는 배열로 0 = a로 시작해서 25 = z로 한다.
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > max)
        {
            max = alpha[i];
            maxnum = i; //알파벳의 번째를 maxnum에 저장한다.
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == max)
        {
            cnt++;
        }
    }
    
    if (cnt > 1) //최댓값이 겹치면 ?를 출력한다.
    {
        printf("?");
    }
    
    else
    {
        printf("%c", 'A' + maxnum);
    }
    
    return 0;
}
//알파벳을 아스키코드를 이용하여 배열로 표현하는 과정이 핵심이다.