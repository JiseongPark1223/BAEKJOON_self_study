#include <stdio.h>

int map[502][502], vis[502][502] = {0}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //그림, 방문 표시 배열, 상하좌우를 살필 배열을 선언한다.
int n, m, front = 0, rear = 0, cnt = 0, width, max = 0;

typedef struct q {
    int x, y;
} q; //x와 y 값 두개이므로 구조체를 선언하여 큐에 넣는다.

q que[502 * 502];

void push(int x, int y)
{
    que[rear].x = x;
    que[rear].y = y;
    rear++;
    vis[x][y] = 1; //큐에 넣을때 방문표시를 해준다.
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
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //그림크기에서 나간 범위는 포함하지 않는다.
            if (map[nx][ny] != 1 || vis[nx][ny] == 1) continue;//그림에 표시되어 있지 않거나 방문한 적이 있는 경우 포함하지 않는다.
            
            vis[nx][ny] = 1; //위 조건에 걸리지 않았다면 방문한적 없는 색칠된 그림이므로 방문표시를 하고 큐에 넣는다.
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
