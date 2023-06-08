#include <stdio.h>

int dist[200002] = {0}, q[200002] = {0}, dx[2] = {1, -1};
int n, k, front = 0, rear = 0, go;

void push(int x)
{
    q[rear] = x;
    rear++;
}

void pop()
{
    front++;
}

int main()
{
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < 200002; i++)
    {
        dist[i] = -1;
    }
    
    dist[n] = 0;
    push(n);
    
    while (front < rear)
    {
        int nx;
        
        nx = q[front] * 2;
        if (nx < 0 || dist[nx] >= 0 || nx > 200002)
        {
            ;
        }
        else
        {
            if (nx == k)
            {
                printf("%d", dist[q[front]] + 1);
                return 0;
            }
            else
            {
                dist[nx] = dist[q[front]] + 1;
                push(nx);
            }
        }

        
        for (int j = 0; j < 2; j++)
        {
            nx = q[front] + dx[j];
            
            if (nx < 0  || dist[nx] >= 0 || nx > 200002)
            {
                ;
            }
            else
            {
                if (nx == k)
                {
                    printf("%d", dist[q[front]] + 1);
                    return 0; 
                }
                else
                {
                    dist[nx] = dist[q[front]] + 1;
                    push(nx);
                }
            }
        }
        pop();
    }
    printf("0");
    
    return 0;
}