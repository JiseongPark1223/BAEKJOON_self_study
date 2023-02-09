#include <stdio.h>
#include <string.h>

int main()
{
    char word[1000001];
    int len, cnt = 0;
    
    scanf("%[^\n]s", word); //줄바꿈 문자 \n이 나오기 전까지의 문자열을 입력받는다.
    
    len = strlen(word);
    
    for (int i = 0; i < len; i++)
    {
        if (word[i] == ' ')
        {
                cnt++;
        }
    }
    
    if (word[0] == ' ') //문장의 단어의 갯수이므로 문장사이의 공백이 아닌 시작과 끝 공백은 갯수에서 제외한다.
    {
        cnt--;
    }
    if (word[len - 1] == ' ')
    {
        cnt--;
    }
    
    printf("%d", cnt + 1);
    return 0;
}

//%s로 입력받으면 공백에서 문자열 입력이 끝난다. 따라서 %[^\n]은 줄바꿈 문자가 나오기 전까지는 입력받는다. 
//문장에서 단어의 갯수는 문장사이의 공백 + 1을 하고 시작과 끝에 공백이 있다면 갯수에서 제외한다.