#include <stdio.h>

char board[1002][1002];
int dist1[1002][1002] = {0}, dist2[1002][1002] = {0}; //dist1은 불이 옮기는데 걸린 시간, dist2는 사람이 옮기는데 걸린 시간을 측정한다.
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, front = 0, rear = 0;

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
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
            
            if (board[i][j] == 'F')
            {
                push(i, j);
                dist1[i][j] = 0;
            }
        }
    }
    
    while (front < rear) //불이 옮겨붙는데 걸리는 최소시간을 bfs를 이용해 구한다.
    {
        int nx, ny;
        
        for (int i = 0; i < 4; i++)
        {
            nx = que[front].x + dx[i];
            ny = que[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            
            dist1[nx][ny] = dist1[que[front].x][que[front].y] + 1;
            push(nx, ny);
        }
        pop();
    }
    
    front = 0, rear = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'J')
            {
                push(i, j);
                dist2[i][j] = 0;
            }
        }
    }
    
    while (front < rear) //지훈이가 탈출하는데 걸리는 최소시간을 구한다.
    {
        int nx, ny;
        
        for (int i = 0; i < 4; i++)
        {
            nx = que[front].x + dx[i];
            ny = que[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                printf("%d", dist2[que[front].x][que[front].y] + 1);
                return 0;
            }
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if (dist1[nx][ny] != -1 && dist2[que[front].x][que[front].y] + 1 >= dist1[nx][ny]) continue;
            //불이 간 장소 중에서 불이 옮겨붙는 시간보다 지훈이가 탈출한 시간이 크거나 같으면 안된다.
            dist2[nx][ny] = dist2[que[front].x][que[front].y] + 1;
            push(nx, ny);
        }
        pop();
    }
    
    printf("IMPOSSIBLE"); //탈출이 불가능하면 IMPOSSIBLE을 출력
    return 0;
}
