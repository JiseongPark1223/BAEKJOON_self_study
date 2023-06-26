#include <stdio.h>

int board[302][302], dec[302][302] = {0}, vis[302][302], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, front = 0, rear = 0, all = 0, t = 0, flag = 0;

typedef struct {
    int x, y;
} que;

que q[302 * 302];

void push(int x, int y)
{
    q[rear].x = x;
    q[rear].y = y;
    rear++;
    vis[x][y] = 1;
}

void pop()
{
    front++;
}

void bfs(int x, int y)
{
    push(x, y);
    
    while (front < rear)
    {
        int nx, ny;
        
        for (int i = 0; i < 4; i++)
        {
            nx = q[front].x + dx[i];
            ny = q[front].y + dy[i];
            
            if (board[nx][ny] == 0 && board[q[front].x][q[front].y] > 0)
            {
                dec[q[front].x][q[front].y]++;
            }
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
            
            push(nx, ny);
        }
        pop();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    
    while (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 0 && vis[i][j] == 0)
                {
                    bfs(i, j);
                    all++;
                }
            }
        }
        
        if (all >= 2)
        {
            printf("%d", t);
            return 0;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] -= dec[i][j];
                if (board[i][j] < 0)
                {
                    board[i][j] = 0;
                }
            }
        }
        t++;

        all = 0, flag = 1, front = 0, rear = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dec[i][j] = 0;
                vis[i][j] = 0;
                
                if (board[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }
    
    printf("0");
    return 0;
}