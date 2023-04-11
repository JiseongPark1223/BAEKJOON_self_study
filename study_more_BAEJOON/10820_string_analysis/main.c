#include <stdio.h>
#include <string.h>

int main()
{
    char str[103];
    int big, small, space, num, len;
    
    while (fgets(str, 103, stdin))
    {
        if (feof(stdin)) //feof함수를 이용해 eof인지 아닌지 본다.
        {
            break;
        }
        
        big = 0, small = 0, space = 0, num = 0;
        
        len = strlen(str);
        
        for (int i = 0; i < len; i++) //각 문자와 숫자 공백의 갯수를 센다.
        {
            if ('a' <= str[i] && str[i] <= 'z')
            {
                small++;
            }
            else if ('A' <= str[i] && str[i] <= 'Z')
            {
                big++;
            }
            else if (str[i] == ' ')
            {
                space++;
            }
            else if ('0' <= str[i] && str[i] <= '9')
            {
                num++;
            }
            else
            {
                continue;
            }
        }
        printf("%d %d %d %d\n", small, big, num, space);
    }
    return 0;
}
//난이도가 높은 문제는 아니였지만 파일 EOF처리에서 오류가 있었다.
//feof함수를 이용하면 더욱 쉽게 처리할 수 있다. 