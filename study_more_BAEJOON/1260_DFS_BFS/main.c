#include <stdio.h>

int vertex, edge, vertex_s, i, j; //정점과 간선을 선언한다.
int graph[1001][1001] = { 0 }, dfs_v[1001] = { 0 }, bfs_v[1001] = { 0 }, q[1001] = { 0 };
//정점이 있는 곳을 graph로 나타내고 dfs와 bfs가 방문한 점을 bfs_v, dfs_v로 표시한다.
void dfs(int vertex, int vertex_s)
{
    dfs_v[vertex_s] = 1;
	printf("%d ", vertex_s);

	for (int w = 1; w <= vertex; w++)
	{
		if (graph[vertex_s][w] == 1 && dfs_v[w] == 0)
		{
			dfs_v[w] = 1;
			dfs(vertex, w); //방문한 정점에서 다른 정점을 찾는다.
		}
	}
}

void bfs(int vertex, int vertex_s)
{
	int front = 0, rear = 0, pop;
	bfs_v[vertex_s] = 1;

	q[rear++] = vertex_s;

	while (front < rear)
	{
		pop = q[front++];
		printf("%d ", pop);

		for (int w = 1; w <= vertex; w++)
		{
			if (bfs_v[w] == 0 && graph[pop][w] == 1)
			{
				q[rear++] = w; //한 정점에 연결된 정점들을 q에 넣고 pop되면 그 정점을 기준으로 연결된 정점을 찾는다.
				bfs_v[w] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &vertex, &edge, &vertex_s);

	for (int w = 0; w < edge; w++)
	{
		scanf("%d %d", &i, &j);

		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	dfs(vertex, vertex_s);
	printf("\n");
	bfs(vertex, vertex_s);

	return 0;
}
