A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
Sample Input

4 5 0 3

0 1 1 20

1 3 2 30

0 3 4 10

0 2 2 20

2 3 1 20
Sample Output
0 2 3 3 40
 题意：给定一个城市网，n个顶点，m条边，起点s，终点d，接下来给m条边，格式是：顶点u，v以及距离dis和花费cost。
让你求出从起点到终点的最短距离，如果路径不唯一，求花费最少的那一条，保证唯一。
思路：使用dijkstra算法标准模板求就行，使用pre[]存储路径上顶点前驱，cost[][]数组存储花费，c[]存储路径上的最少花费。最后使用DFS输出路径。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;

const int maxn=510;

const int inf=(1<<31)-1;

int G[maxn][maxn],d[maxn],pre[maxn],cost[maxn][maxn],c[maxn];

int n,m,st,ed;

bool vis[maxn]={false};

 

void dijkstra(int s){

	fill(d,d+maxn,inf);

	fill(c,c+maxn,inf);

	d[s]=0;

	c[s]=0;

	for(int i=0;i<n;i++) pre[i]=i;

	for(int i=0;i<n;i++){

		int u=-1,min=inf;

		for(int j=0;j<n;j++){

			if(!vis[j]&&d[j]<min){

				u=j;

				min=d[j];

			}

		}

		if(u==-1) return ;

		vis[u]=true;

		for(int v=0;v<n;v++){

			if(!vis[v]&&G[u][v]!=inf){

				if(d[u]+G[u][v]<d[v]){

					d[v]=d[u]+G[u][v];

					c[v]=c[u]+cost[u][v];

					pre[v]=u;

				}else if(d[u]+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]){

					c[v]=c[u]+cost[u][v];

					pre[v]=u;

				}

			}

		}

	}

}

void DFS(int u){

	if(u==st){

		printf("%d",u);

		return;

	}

	DFS(pre[u]);

	printf(" %d",u);

}

int main()

{

	scanf("%d%d%d%d",&n,&m,&st,&ed);

	fill(G[0],G[0]+maxn*maxn,inf);    //注意图G一定要初始化

	for(int i=0;i<m;i++){

		int u,v,dis,cos;

		scanf("%d %d",&u,&v);

		scanf("%d %d",&dis,&cos);

		G[u][v]=G[v][u]=dis;

		cost[u][v]=cost[v][u]=cos;

	}

	dijkstra(st);

	DFS(ed);

	printf(" %d %d\n",d[ed],c[ed]);

	return 0;

}
