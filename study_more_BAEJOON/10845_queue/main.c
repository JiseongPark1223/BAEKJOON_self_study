#include <stdio.h>
#include <string.h>

int main()
{
    int n, q[100001], x, start = 0, end = 0; //배열 맨 앞 원소의 위치 start, 맨 뒤 원소의 위치 end
    char str[7];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", str); //뒤에 오는 '\n'값이 들어오는 것을 방지
        
        if (strcmp(str, "push") == 0)
        {
            scanf(" %d", &x); //뒤에 오는 '\n'값이 들어오는 것을 방지
            q[end++] = x;
        }
        else if (strcmp(str, "pop") == 0)
        {
            if (start == end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[start++]);
            }
        }
        else if (strcmp(str, "size") == 0)
        {
            printf("%d\n", end - start);
        }
        else if (strcmp(str, "empty") == 0)
        {
            if (start == end)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (strcmp(str, "front") == 0)
        {
            if (start == end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[start]);
            }
        }
        else
        {
            if (start == end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[end - 1]);
            }
        }
    }
    return 0;
}
//큐는 자료구조의 종류 중 하나로 먼저 집어넣은 데이터가 먼저 나오는 FIFO(First In First Out)형태를 가지고 있다.
//queue는 대기줄을 의미하며 대기줄에서 먼저 줄 선 사람이 먼저 들어가는 것을 생각하면 된다.
//프린터의 출력처리, 프로세스 관리등 데이터가 입력된 시간으로 출력될때 큐가 쓰인다.