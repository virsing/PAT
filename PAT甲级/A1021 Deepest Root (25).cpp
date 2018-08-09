A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.
Sample Input 1:

5

1 2

1 3

1 4

2 5
Sample Output 1:

3

4

5
Sample Input 2:

5

1 3

1 4

2 5

3 4
Sample Output 2:
Error: 2 components
题意：给定一个n表示顶点数 ，再给n-1条边，问你该图是否连通如果不联通输出联通分量的个数，如果联通，输出所有最深的顶点编号，按升序排列。
思路：
1.使用DFS求联通分量的个数，递归过程把深度最大的顶点加入set集合中。如果联通分量数不为1直接输出联通分量数，如果唯一，说明这n个顶点是一棵联通树，两次DFS。
2.可以证明只要两次DFS即可求出所有顶点。首先从任意一个顶点开始遍历把最远的顶点编号加入set<int>ans1中，然后从ans1中任意一个顶点开始遍历，得到的结果加入set<int>ans2中，则ans1和ans2的并集即为所求，使用set存储结果顶点编号是因为set集合可以自动去重排序。
参考代码：

#include<cstdio>

#include<vector>

#include<set>

#include<cstring>

using namespace std;

const int maxn=10010;

vector<int> adj[maxn];

set<int> ans1,ans2;

bool vis[maxn]={false};

void DFS(int u,int d,int& MaxDepth,set<int>& st){

	vis[u]=true;

	if(d>MaxDepth){

		MaxDepth=d;

		st.clear();

		st.insert(u);

	}else if(d==MaxDepth) {

		st.insert(u);

	}

	for(int i=0;i<adj[u].size();i++){

		if(!vis[adj[u][i]]){

			DFS(adj[u][i],d+1,MaxDepth,st);

		}

	}

}

int main()

{

	int n,u,v,cnt=0,MaxDepth=0;//cnt统计联通分量个数，MaxDepth标记最大深度

	scanf("%d",&n);

	for(int i=1;i<n;i++){

		scanf("%d%d",&u,&v);

		adj[u].push_back(v);

		adj[v].push_back(u);

	}

	for(int i=1;i<=n;i++){	//统计联通子图的个数

		if(!vis[i]){

			cnt++;

			DFS(i,1,MaxDepth,ans1);

		}

	}

	if(cnt!=1) printf("Error: %d components\n",cnt);

	else{

		auto it=ans1.begin();

		memset(vis,false,sizeof(vis));

		DFS(*it,1,MaxDepth,ans2);

		for(auto it=ans2.begin();it!=ans2.end();it++){

			ans1.insert(*it);

		}

		for(auto it=ans1.begin();it!=ans1.end();it++){

			printf("%d\n",*it);

		}

	}

	return 0;

}
