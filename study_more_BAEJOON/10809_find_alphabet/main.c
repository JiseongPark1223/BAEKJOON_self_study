#include <stdio.h>
#include <string.h>

int main()
{
    char word[101];
    int alpha[26]; //0은 a, 1은 b로 놓고 25는 z로 하여 알파벳 순서를 저장한다.
    
    memset(alpha, -1, sizeof(int) * 26); //문자열에 나오지 않는 알파벳은 -1이 출력 되어야 하기에 -1로 메모리를 설정한다.
    
    scanf("%s", word);
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (alpha[word[i] - 'a'] != -1) //앞에서 나온 알파벳은 건너뛴다.
        {
            continue;
        }
        else
        {
            alpha[word[i] - 'a'] = i; //알파벳의 아스키코드를 이용해 순서를 저장한다.
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", alpha[i]);
    }
    return 0;
}

//memset을 이용해 메모리를 설정하는 것과 아스키코드를 이용해 alpha배열에 알맞을 값을 넣는 것이 문제의 핵심이다.