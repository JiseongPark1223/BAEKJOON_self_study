#include <stdio.h>

int main()
{
    int t, num[100001], stack[100001], count = 1, top = -1, res_idx = 0, idx = 0;
    char res[200001]; //+와 -를 저장하는 배열
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &num[i]);
    }
    
    while (1)
    {
        if (stack[top] < num[idx]) //stack배열에 num[idx]까지 push한다.
        {
            stack[++top] = count; //순서대로 stack배열에 넣는다.
            count++;
            res[res_idx] = '+';
            res_idx++;
        }
        else if (stack[top] == num[idx]) //stack배열과 num[idx]값이 같은면 pop한다.
        {
            res[res_idx] = '-';
            res_idx++;
            idx++;
            top--;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
        
        if (res_idx == 2*t) //+,-로 이루어져있으므로 총 갯수의 2배이다.
        {
            break;
        }
    }
    
    for (int i = 0; i < res_idx; i++)
    {
        printf("%c\n", res[i]);
    }
    return 0;
}