#include <stdio.h>

int deq[1001], head = 500, tail = 500; //덱을 선언

void push_front(int x) //앞뒤로 push, pop하는 함수 선언
{
    deq[--head] = x;
}

void push_back(int x)
{
    deq[tail++] = x;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int main()
{
    int m, n, num, temp, cnt = 0;
    
    scanf("%d %d", &m, &n);
    
    for (int i = 1; i <= m; i++)
    {
        push_back(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        
        if (deq[head] == num)
        {
            pop_front();
        }
        else
        {
            temp = head; //head, tail이 num과 떨어진 거리를 비교하기 위해 num 위치를 temp에 저장
            
            while (deq[temp] != num)
            {
                temp++;
            }
            
            if (temp - head > tail - 1 - temp) //tail쪽 배열을 앞으로 옮기는게 빠를때
            {
                while (deq[head] != num)
                {
                    push_front(deq[tail - 1]);
                    pop_back();
                    cnt++;
                }
                pop_front();
            }
            else //head쪽 배열을 뒤로 옮기는게 빠를때
            {
                while (deq[head] != num)
                {
                    push_back(deq[head]);
                    pop_front();
                    cnt++;
                }
                pop_front();
            }
        }
    }
    printf("%d", cnt);
    
    return 0;
}