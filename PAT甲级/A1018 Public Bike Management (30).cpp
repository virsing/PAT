There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
\ Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S~3~, we have 2 different shortest paths:
1. PBMC -> S~1~ -> S~3~. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S~1~ and then take 5 bikes to S~3~, so that both stations will be in perfect conditions.
2. PBMC -> S~2~ -> S~3~. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: C~max~ (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; S~p~, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers C~i~ (i=1,...N) where each C~i~ is the current number of bikes at S~i~ respectively. Then M lines follow, each contains 3 numbers: S~i~, S~j~, and T~ij~ which describe the time T~ij~ taken to move betwen stations S~i~ and S~j~. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0-&gtS~1~->...-&gtS~p~. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of S~p~ is adjusted to perfect.
Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.
Sample Input:

10 3 3 5

6 7 0

0 1 1

0 2 1

0 3 3

1 3 1

2 3 1
Sample Output:
3 0-&gt2-&gt3 0
题意：给定杭州市公共自行车管理系统，每个站点自行车上限Cmax，n个站点，每个站点现有的自行车数量，问题站编号sp以及m条路径即距离，（假定起点id：0），定义站点最佳状态自行车数量恰好为Cmax/2.让你求从起点0号到问题站sp的最短路径，如果路径不唯一求需要携带的自行车数量最少的那一条，如果还不唯一，求需要带回的自行车数量最少的那一条，保证唯一。
思路：本题需要dijkstra+DFS，定义全局最少携带MinNeed，全局最少带回MinRemain,因为MinNeed和MinRemain的传递不满足最优子结构，不能简单相加，所以必须求出整条路径才能算出来。首先用dijkstra（）算法求出最短路径和前驱结点数组pre[]，然后使用DFS求最佳路径,计算最少携带和最少带回数量。刚开始输入时，把所有站点车辆减去Cmax/2，这样就能根据站点车子正负直接判断是过少还是过多，因为在从起点出发的路上需要把所有站点调制最佳状态，所以每到一个站点，如果车辆过少,数量t<0,就累加至need中，如果车辆过多根据need值，判断处理remain，(当站点车子数量t<0时，并不能直接使用remain抵消，因为前面的站点在去的路上就需要调整好，所以前面如果站点车辆过少，累加至need中）。最后注意pre[]数组是倒置的需要从后往前输出。
 
参考代码：

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<vector>

#include<cstring>

using namespace std;

const int maxn=510;

const int inf=(1<<31)-2;

struct node{

	int v,dis;

	node(int _v=0,int _dis=0):v(_v),dis(_dis){}

}t;

vector<node> adj[maxn];

int d[maxn],weight[maxn];

int Cmax,n,sp,m;

bool vis[maxn]={false};

vector<int> pre[maxn],path,temp;

void dijkstra(int s)

{

	fill(d,d+maxn,inf);

	d[s]=0;

	for(int i=0;i<=n;i++){

		int u=-1,Min=inf;

		for(int j=0;j<=n;j++){

			if(!vis[j]&&d[j]<Min){

				Min=d[j];

				u=j;

			}

		}

		if(u==-1) return;

		vis[u]=true;

		for(int j=0;j<adj[u].size();j++){

			int v=adj[u][j].v,dis=adj[u][j].dis;

			if(!vis[v]){

				if(d[u]+dis<d[v]){

					d[v]=d[u]+dis;

					pre[v].clear();

					pre[v].push_back(u);

				}else if(d[u]+dis==d[v]){

					pre[v].push_back(u);

				}

			}

		}

	}

}

int MinNeed=inf,MinRemain=inf;//存储最终需要携带的自行车和带回的自行车

void DFS(int u)

{

	if(u==0){

		temp.push_back(u);

		int need=0,remain=0;

		for(int i=temp.size()-1;i>=0;i--){

			int t=weight[temp[i]];

			if(t>=0){	//当前站点车辆多于一半情况

				remain+=t;

			}else{		//当前站点车辆不足一半

				if(remain>=abs(t)) remain-=abs(t);

				else {

					need+=abs(t)-remain;

					remain=0;

				}

			}

		}

		if(need<MinNeed){

			MinNeed=need;

			MinRemain=remain;

			path=temp;

		}else if(need==MinNeed&&remain<MinRemain){

			MinRemain=remain;

			path=temp;

		}

		temp.pop_back();

		return;

	}

	temp.push_back(u);

	for(int i=0;i<pre[u].size();i++)

		DFS(pre[u][i]);

	temp.pop_back();

}

int main()

{

	scanf("%d%d%d%d",&Cmax,&n,&sp,&m);

	for(int i=1;i<=n;i++) {

		scanf("%d",&weight[i]);

		weight[i]-=Cmax/2;

	}

	for(int i=0;i<m;i++)

	{

		int u,v,dis;

		scanf("%d %d %d",&u,&v,&dis);

		adj[u].push_back(node(v,dis));

		adj[v].push_back(node(u,dis));

	}

	dijkstra(0);

	DFS(sp);

	printf("%d 0",MinNeed);

	for(int i=path.size()-2;i>=0;i--){

		printf("->%d",path[i]);

	}

	printf(" %d\n",MinRemain);

	return 0;

}
