#include <stdio.h>
void bfs(int n, int adj[][n], int s);


void main()
{	printf("Enter number of vertices :- ");
	int n;
	scanf("%d", &n);
	int adj[n][n];
	printf("Enter adjacency matrix :-\n");
	for(int i = 0; i < n; i++)
	{
    	for(int j = 0; j < n; j++)
    	{
        	scanf("%d", &adj[i][j]);
    	}
	}

	printf("Enter start vertex (0 to %d) :- ", n - 1);
	int s;
	scanf("%d", &s);
	bfs(n, adj, s);
}
void bfs(int n, int adj[][n], int s)
{	int visited[n];
	for(int i = 0; i < n; i++)
    	visited[i] = 0;
	int queue[n];
	int front = 0, rear = 0;
	visited[s] = 1;
	queue[rear++] = s;
	printf("BFS traversal :- ");
	while(front < rear)
	{
    	int u = queue[front++];
    	printf("%d ", u);
    	for(int v = 0; v < n; v++)
    	{
        	if (adj[u][v] && !visited[v])
        	{
            	visited[v] = 1;
            	queue[rear++] = v;
        	}
    	}
	}
	printf("\n");
}
