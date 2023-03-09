#include <stdio.h>

int main()
{
    char str[5][15] = {0};
    
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", str[i]);
    }
    
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (str[i][j] != '\0') //문자열의 길이가 다른 경우 빈공간에 NULL이 저장 = '\0'
            {                      //NULL을 제외하고 읽어야 한다.
                printf("%c", str[i][j]);
            }
        }
    }
    return 0;
}
//세로읽기 문제의 핵심은 길이가 다른 문자열을 받았을때 빈 공간에 NULL문자가 들어오고
//이것을 예외조항에 추가하여 코드를 구현해야 한다.
