#include <stdio.h>

int board[102][102], dist[102][102], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, front = 0, rear = 0; //bfs를 이용한 거리문제는 시작점으로 부터 떨어진 거리를 구하는 방식으로 해결한다.
                               //dist를 모두 -1로 놓은 후 시작점의 dist를 0으로 하고 1칸 떨어진 곳마다 1을 더한다.
typedef struct q {
    int x, y;
} q;

q que[102 * 102];

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
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &board[i][j]);
            dist[i][j] = -1;
        }
    }
    
    dist[0][0] = 0;
    push(0, 0);
    
    while (front < rear)
    {
        int nx, ny;
        
        for (int i = 0; i < 4; i++)
        {
            nx = que[front].x + dx[i];
            ny = que[front].y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            
            dist[nx][ny] = dist[que[front].x][que[front].y] + 1;
            push(nx, ny);
        }
        pop();
    }
    printf("%d", dist[n - 1][m - 1] + 1); //시작점도 1개로 계산하기 때문에 1을 더해준다.
    
    return 0;
}