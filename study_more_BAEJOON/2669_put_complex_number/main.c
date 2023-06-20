#include <stdio.h>
#include <stdlib.h>

int board[27][27], vis[27][27] = {0}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, front = 0, rear = 0, all = 0, cnt = 0, res[27 * 27] = {0};

typedef struct {
    int x, y;
} que;

que q[27 * 27];

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
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            
            push(nx, ny);
        }
        pop();
        cnt++; //단지 내 집의 수를 계산한다.
    }
}

int compare(const void *arr1, const void *arr2)
{
    if (*(int *)arr1 > *(int *)arr2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 && vis[i][j] == 0)
            {
                bfs(i, j);
                res[all] = cnt; //단지 내 집의 수를 배열에 저장
                cnt = 0;
                all++; //총 단지 수를 계산
            }
        }
    }
    
    qsort(res, all, sizeof(int), compare); //오름차순으로 배열을 정렬
    
    printf("%d\n", all);
    
    for (int i = 0; i < all; i++)
    {
        printf("%d\n", res[i]);
    }
    
    return 0;
}
