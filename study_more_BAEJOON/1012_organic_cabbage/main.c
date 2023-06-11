#include <stdio.h>

int board[52][52] = {0}, vis[52][52] = {0}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, k, t, front = 0, rear = 0, p1, p2, cnt = 0;

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
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
            
            vis[nx][ny] = 1;
            push(nx, ny);
        }
        pop();
    }
}

int main()
{
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d %d %d", &m, &n, &k);
        
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &p1, &p2);
            
            board[p2][p1] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && vis[i][j] == 0)
                {
                    bfs(i, j); //배추가 상하좌우로 이어진 곳에서는 애벌래가 1마리 필요하다. (대각선 x)
                    cnt++;     //따라서 bfs로 갯수를 세면 애벌레가 필요한 곳을 알 수 있다.
                }
            }
        }
        printf("%d\n", cnt);
        
        cnt = 0, front = 0, rear = 0; //여러 상황에서 구하기 때문에 변수의 값들을 초기화해준다.
        for (int i = 0; i < 52; i++)
        {
            for (int j = 0; j < 52; j++)
            {
                vis[i][j] = 0;
                board[i][j] = 0;
            }
        }
    }
    return 0;
}
