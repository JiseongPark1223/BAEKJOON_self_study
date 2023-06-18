#include <stdio.h>

char board[102][102];
int vis[102][102], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, front = 0, rear = 0, rgb = 0, rg = 0; //정상과 적록색약을 따로 구분한다.

typedef struct {
    int x, y;
} que;

que q[102 * 102];

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
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[q[front].x][q[front].y] != board[nx][ny] || vis[nx][ny] == 1) continue;
            //각 구역이 비교하는 색깔과 같은지 다른지 비교하는 조건이 있어야 한다.
            push(nx, ny);
        }
        pop();
    }
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                bfs(i, j);
                rgb++;
            }
        }
    }
    
    front = 0, rear = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = 0;
            if (board[i][j] == 'G')
            {
                board[i][j] = 'R'; //적록색약은 빨강색과 초록색을 같은 구역으로 보기 때문에 초록색 구역을 빨간색으로 바꾼다.
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                bfs(i, j);
                rg++;
            }
        }
    }
    printf("%d %d", rgb, rg);
    
    return 0;
}
