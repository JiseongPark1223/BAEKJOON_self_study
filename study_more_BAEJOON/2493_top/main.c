#include <stdio.h>

int main()
{
    int t, top = -1;
    int h[500001] = {0}, stack[500001] = {0}, res[500001] = {0};
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &h[i]); //탑의 높이를 받는다.
    }
    
    for (int i = t; i > 0; i--)
    {
        while (top >= 0 && h[stack[top]] < h[i]) //뒤의 탑보다 낮으면 stack배열에 저장, 뒤의 탑보다 높으면 res배열에 그 탑의 순서를 저장한다.
        {
            res[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }
    
    for (int i = 1; i <= t; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}
//이 문제의 핵심은 앞의 탑보다 낮으냐 높으냐를 기준으로 낮으면 stack배열에 저장하여 자신보다 높은 탑이 나올때까지 기다리고
//높으면 그 탑의 순서를 자신의 순서 res배열에 저장하는 것이다.
//여러 배열을 이용한 구현에서 오류가 있었던 것 같다.