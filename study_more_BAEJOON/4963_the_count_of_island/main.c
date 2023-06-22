#include <stdio.h>

int board[52][52], vis[52][52];
int dx[8] = {1, 0, -1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1}; //대각선에 놓인 섬도 갯수에 포함하는 것이기 때문에 대각선 방향에 대한 조건도 추가한다.
int n, m, front = 0, rear = 0, cnt = 0;

typedef struct {
    int x, y;
} que;

que q[52 * 52];

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

void bfs(int x, int y) //bfs를 이용하여 섬의 갯수를 파악한다.
{
    push(x, y);
    
    while (front < rear)
    {
        int nx, ny;
        
        for (int i = 0; i < 8; i++)
        {
            nx = q[front].x + dx[i];
            ny = q[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            
            push(nx, ny);
        }
        pop();
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    
    while (m != 0 && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &board[i][j]);
                vis[i][j] = 0;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && vis[i][j] == 0)
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
        
        cnt = 0, front = 0, rear = 0; //큐와 갯수를 초기화한다.
        
        scanf("%d %d", &m, &n);
    }
    return 0;
}