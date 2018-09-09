1150 Travelling Salesman Problem（25 分）
The "travelling salesman problem" asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science. (Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)
In this problem, you are supposed to find, from a given list of cycles, the one that is the closest to the solution of a travelling salesman problem.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of cities, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format City1 City2 Dist, where the cities are numbered from 1 to N and the distance Dist is positive and is no more than 100. The next line gives a positive integer K which is the number of paths, followed by K lines of paths, each in the format:
n C​1​​ C​2​​ ... C​n​​
where n is the number of cities in the list, and C​i​​'s are the cities on a path.
Output Specification:
For each path, print in a line Path X: TotalDist (Description) where X is the index (starting from 1) of that path, TotalDist its total distance (if this distance does not exist, output NA instead), and Description is one of the following:
TS simple cycle if it is a simple cycle that visits every city;
TS cycle if it is a cycle that visits every city, but not a simple cycle;
Not a TS cycle if it is NOT a cycle that visits every city.
Finally print in a line Shortest Dist(X) = TotalDist where X is the index of the cycle that is the closest to the solution of a travelling salesman problem, and TotalDist is its total distance. It is guaranteed that such a solution is unique.
Sample Input:

6 10

6 2 1

3 4 1

1 5 1

2 5 1

3 1 8

4 1 6

1 6 1

6 3 1

1 2 1

4 5 1

7

7 5 1 4 3 6 2 5

7 6 1 3 4 5 2 6

6 5 1 4 3 6 2

9 6 2 1 6 3 4 5 2 6

4 1 2 5 1

7 6 1 2 5 4 3 1

7 6 3 2 5 4 1 6
Sample Output:

Path 1: 11 (TS simple cycle)

Path 2: 13 (TS simple cycle)

Path 3: 10 (Not a TS cycle)

Path 4: 8 (TS cycle)

Path 5: 3 (Not a TS cycle)

Path 6: 13 (Not a TS cycle)

Path 7: NA (Not a TS cycle)

Shortest Dist(4) = 8
题意：旅行商问题，给定一张图，然后给定k个路径序列， 如果当前路径访问了所有城市并且是个简单环称为：TS simple cycle。如果访问全部城市但不是简单环称为：TS cycle 。如果不是环称为：Not a TS cycle 。然后按对应格式输出总距离和路径类别。如果路径中有不存在的边总距离为NA。
思路：首先构建邻接矩阵初始化全0，然后对每条路径计算总距离，并用cnt标记剩余未访问的顶点数，flag标记是否有不存在路径。如果有不存在的路径，则总距离输出NA。如果cnt=0&&！flag&&path[0]==path[n-1]（顶点全部访问，没有不存在的边，路径首尾相连）表明是环，若此时路径顶点个数==n+1说明是简单环，否则是环，并标记出最短旅行距离及编号。若首尾不相连或者没有访问全部顶点说明不是环。
参考代码：

#include<cstdio>

#include<vector>

#include<cstring>

using namespace std;

const int maxn=205;

int n,m,u,v,dis,k,G[maxn][maxn];

bool vis[maxn];

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){

        scanf("%d%d%d",&u,&v,&dis);

        G[u][v]=G[v][u]=dis;

    }

    scanf("%d",&k);

    int Min=-1,MinDis;

    for(int i=1;i<=k;i++){

        int num,cnt=n,t,pre,sum=0,flag=0;	//num：顶点个数。cnt：统计路径中未访问的顶点数。sum：路径总和。flag0：路径中是否有不存在的边。

        scanf("%d",&num);

        memset(vis,0,sizeof(vis));

		vector<int> path(num);

        for(int j=0;j<num;j++){

            scanf("%d",&t);

			path[j]=t;

            if(!vis[t]) {

				vis[t]=true;

				cnt--;

			}

            if(j!=0){

				if(G[pre][t])

					sum+=G[pre][t];

				else flag=1;

			}

            pre=t;    

        } 

		if(flag) {	//给定路径有不存在的边

			printf("Path %d: NA (Not a TS cycle)\n",i);

			continue;

		}	

		if(!cnt&&path[0]==path[num-1]&&num>n){

			if(Min==-1){

                Min=i;

                MinDis=sum;

            }else if(sum<MinDis){

                Min=i;

                MinDis=sum;

            }     

			if(num==n+1) printf("Path %d: %d (TS simple cycle)\n",i,sum);

            else printf("Path %d: %d (TS cycle)\n",i,sum);

		}else  printf("Path %d: %d (Not a TS cycle)\n",i,sum); 

	}

    printf("Shortest Dist(%d) = %d\n",Min,MinDis);

    return 0;

}         
