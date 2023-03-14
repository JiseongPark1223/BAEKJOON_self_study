#include <stdio.h>
#include <string.h>

int main()
{
    int t, len1, len2;
    char str1[1001], str2[1001];
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        int alpha1[26] = {0}, alpha2[26] = {0}, flag = 0;
        
        scanf("%s %s", str1, str2);
        
        len1 = strlen(str1);
        len2 = strlen(str2);
        
        if (len1 != len2) //두 문장의 길이가 다르면 Impossible
        {
            printf("Impossible\n");
        }
        else
        {
            for (int i = 0; i < len1; i++)
            {
                alpha1[str1[i] - 'a']++; //각 문장의 스펠링을 저장
                alpha2[str2[i] - 'a']++;
            }
            
            for (int i = 0; i < 26; i++)
            {
                if (alpha1[i] != alpha2[i]) //서로의 문장에 없는 알파벳이 있으면 Impossible
                {
                    flag = 1;
                }
            }
            if (flag != 1)
            {
                printf("Possible\n");
            }
            else
            {
                printf("Impossible\n");
            }
        }
    }
    return 0;
}
//이 문제의 핵심은 각 문장의 알파벳을 배열로 넣고 그 배열을 비교하는 것이다.
//문제를 푸는 과정에서 하나의 배열로 두 문장을 담고 비교하려는 것이 패착이었다.
