As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.\ All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input

5 6 0 2

1 2 1 5 3

0 1 1

0 2 2

0 3 1

1 2 1

2 4 1

3 4 1
Sample Output
2 4
题意：给定一个城市网，有n个顶点表示城市，m条边表示公路，每条公路有边权表示距离，另外每个城市还有点权表示救援小队的人数，然后给你起始顶点C1，终点城市C2，让你输出C1到C2最短路径的条数和最短路径上聚集的救援小组人数的最大值。
思路：
1.使用dijksra算法求最短路径即可，另外由于有第二标尺点权，还要求最短路径总数，所以增设两个数组w[]和num[]分别表示当前城市收集到的最大点权以及到当前城市的最短路径数量。
注意：
1.数组下标为0-n-1。
2.在迪杰斯特拉算法中当最短路径一样更新点权w[]时,不论w[u]+weight[v]>w[v]是否成立，都要让num[v]+=num[u];因为最短路径条数仅与第一标尺有关，与点权无关。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

const int maxn=510;

const int inf=(1<<31)-2;

int n,m,st,ed;

int d[maxn],weight[maxn],num[maxn]={0},w[maxn]={0};

bool vis[maxn]={false};

struct node{

	int v,dis;

	node(int _v=0,int _dis=0):v(_v),dis(_dis){}

};

vector<node> adj[maxn];

void dijkstra(int s){

	fill(d,d+maxn,inf);

	d[s]=0;

	num[s]=1;

	w[s]=weight[s];

	for(int i=0;i<n;++i){

		int u=-1,MIN=inf;

		for(int j=0;j<n;++j)

		{

			if(!vis[j]&&d[j]<MIN)

			{

				u=j;

				MIN=d[j];

			}

		}

		if(u==-1) return;

		vis[u]=true;

		for(int j=0;j<adj[u].size();j++)

		{

			int v=adj[u][j].v,dis=adj[u][j].dis;

			if(!vis[v]){

				if(d[u]+dis<d[v]){

					d[v]=d[u]+dis;

					w[v]=w[u]+weight[v];

					num[v]=num[u];

				}else if(d[u]+dis==d[v])

				{

					if(w[u]+weight[v]>w[v])

						w[v]=w[u]+weight[v];

					num[v]+=num[u];

				}

			}

		}

	}

}

int main()

{

	scanf("%d%d%d%d",&n,&m,&st,&ed);

	for(int i=0;i<n;++i) scanf("%d",&weight[i]);

	for(int i=0;i<m;i++)

	{

		int u,v,t;

		scanf("%d%d%d",&u,&v,&t);

		adj[u].push_back(node(v,t));

		adj[v].push_back(node(u,t));

	}

	dijkstra(st);

	printf("%d %d\n",num[ed],w[ed]);

	return 0;

}
