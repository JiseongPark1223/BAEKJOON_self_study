#include <stdio.h>

int board[1002][1002], dist[1002][1002] = {0}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int m, n, front = 0, rear = 0, max = 0; //익은 토마토를 기준으로 하루마다 상하좌우로 하나씩 더 익어간다.
                                        //따라서 익은 토마토를 시작점으로 bfs를 이용하여 거리의 최댓값을 구하면 된다.
typedef struct q {
    int x, y;
} q;

q que[1002 * 1002];

void push(int x, int y)
{
    que[rear].x = x;
    que[rear].y = y;
    rear++;
}

void pop()
{
    front++;
}

int main()
{
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
            
            if (board[i][j] == 1) //시작점이 여러 개인 bfs는 시작점을 모두 push한 후 bfs를 시작한다.
            {
                push(i, j);
            }
            if (board[i][j] == 0)
            {
                dist[i][j] = -1;
            }
        }
    }
    
    while (front < rear) //여러 시작점을 큐에 넣은 순서대로 꺼내어 bfs를 한다.
    {
        int nx, ny;
        
        for (int i = 0; i < 4; i++)
        {
            nx = que[front].x + dx[i];
            ny = que[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
            
            dist[nx][ny] = dist[que[front].x][que[front].y] + 1;
            push(nx, ny);
        }
        pop();
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                printf("-1");
                return 0;
            }
            
            if (dist[i][j] > max)
            {
                max = dist[i][j]; //각 거리순에서 최댓값이 토마토가 다 익는데 걸린 최소 시간이다.
            }
        }
    }
    printf("%d", max);
    
    return 0;
}