#include <stdio.h>

int map[502][502], vis[502][502] = {0}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, front = 0, rear = 0, cnt = 0, width, max = 0;

typedef struct q {
    int x, y;
} q;

q que[502 * 502];

void push(int x, int y)
{
    que[rear].x = x;
    que[rear].y = y;
    rear++;
    vis[x][y] = 1;
}

void pop()
{
    front++;
}

void bfs(int x, int y)
{
    int nx, ny;
    
    while (front < rear)
    {
        for (int i = 0; i < 4; i++)
        {
            nx = que[front].x + dx[i];
            ny = que[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] != 1 || vis[nx][ny] == 1) continue;
            
            vis[nx][ny] = 1;
            push(nx, ny);
            width++;
        }
        pop();
    }
    
    if (width > max)
    {
        max = width;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && vis[i][j] == 0)
            {
                width = 1;
                cnt++;
                push(i, j);
                bfs(i, j);
            }
        }
    }
    
    printf("%d\n%d", cnt, max);
    
    return 0;
}
