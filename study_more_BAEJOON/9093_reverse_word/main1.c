#include <stdio.h>
#include <string.h>

void reverse(int start, int end, char arr[]) //문자열을 reverse하는 함수
{
    int q = 0, mid = start + (end - start)/2;
    char temp;
    
    for (int i = start; i <= mid; i++)
    {
        temp = arr[i];
        arr[i] = arr[end - q];
        arr[end - q] = temp;
        q++;
    }
}

int main()
{
    int t;
    char str[1001];
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf( " %[^\n]s", str); //문자열 뒤에 오는 '\n'문자를 방지하기 위해 앞을 한칸 남긴다.
        
        int len = strlen(str);
        int start = 0;
        for (int j = 0; j <= len; j++)
        {
            if (str[j] == ' ' || str[j] == '\0') //공백이 있거나 NULL문자가 나오기 전까지의 문자열을 reverse한다.
            {
                reverse(start, j - 1, str);
                start = j + 1; //reverse이후 다음 문자열 시작점을 가리킨다. 
            }
        }
        printf("%s\n", str);
    }
    return 0;
}