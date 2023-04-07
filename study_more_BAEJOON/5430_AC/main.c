#include <stdio.h>
#include <stdlib.h>

char str[100001], arr[300001];
int q[100001], front, rear;

void push(int x)
{
    q[rear++] = x;
}

void print()
{
    if (front < rear) 
    {
        printf("[%d", q[front]);
        for (int i = front + 1; i < rear; i++)
        {
            printf(",%d", q[i]);
        }
        printf("]\n");
    }
    else if (rear < front) //rear가 더 작으면 한번 뒤집힌 경우이므로 뒤에서 부터 출력
    {
        printf("[%d", q[front - 1]);
        for (int i = front - 2; i >= rear; i--)
        {
            printf(",%d", q[i]);
        }
        printf("]\n");
    }
    else
    {
        printf("[]\n");
    }
}

void swap()
{
    int tmp, *a = &front, *b = &rear;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int t, num, error_flag;
    
    scanf("%d", &t);
    
    while (t--)
    {
        front = 0, rear = 0, error_flag = 0;
        
        scanf("%s %d %s", str, &num, arr);
        
        for (int i = 1; arr[i]; i++)
        {
            if ('0' <= arr[i] && arr[i] <= '9') //배열에서 숫자만 입력받음
            {
                push(atoi(&arr[i])); //atoi함수는 숫자만 반환, 숫자가 아니면 반환 x
            }
            while ('0' <= arr[i] && arr[i] <= '9')
            {
                i++;
            }
        }
        
        for (int i = 0; str[i]; i++)
        {
            if (str[i] == 'R')
            {
                swap();
            }
            else //str[i] == 'D'
            {
                if (front < rear)
                {
                    front++;
                }
                else if (front > rear)
                {
                    front--;
                }
                else
                {
                    error_flag = 1;
                    break;
                }
            }
        }
        
        if (error_flag == 1)
        {
            printf("error\n");
        }
        else
        {
            print();
        }
    }
    return 0;
}