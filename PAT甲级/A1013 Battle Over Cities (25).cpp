It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.
For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~. Then if city~1~ is occupied by the enemy, we must have 1 highway repaired, that is the highway city~2~-city~3~.
Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (&lt1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.
Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
Sample Input

3 2 3

1 2

1 3

1 2 3
Sample Output

1

0

0
题意：给定一个n个城市m条路组成的城市网，问你当某一个城市沦陷后，为确保每两个城市至少有一条路联通，最少需要修几条路。
思路：
1.使用DFS统计联通块，最后联通块数减一就是最少需要修的路的数量。
参考代码：

#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

const int maxn=1010;

const int inf=(0<<31)-2;

int G[maxn][maxn];

bool vis[maxn]={false};

int n,m,k;

void DFS(int u,int p){

	vis[u]=true;

	for(int i=1;i<=n;i++)

	{

		if(i!=p&&!vis[i]&&G[u][i]!=inf)

			DFS(i,p);

	}

}

int main()

{

	scanf("%d%d%d",&n,&m,&k);

	fill(G[0],G[0]+maxn*maxn,inf);

	for(int i=0;i<m;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		G[u][v]=G[v][u]=1;

	}

	for(int i=0;i<k;i++)

	{

		int cnt=0,p;	//cnt表示联通块个数，p表示丢失的城市标号

		memset(vis,0,sizeof(vis));

		scanf("%d",&p);

		for(int u=1;u<=n;u++)

		{

			if(u!=p&&!vis[u]){  //p表示丢失的城市，直接跳过

				cnt++;

				DFS(u,p);

			}

		}

		printf("%d\n",cnt-1);

	}

	return 0;

}
