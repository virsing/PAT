A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input

2 1

01 1 02
Sample Output
0 1
 题意：给定一个家族树，让你求每层没有孩子的节点个数是多少。
思路：
1.使用树的静态写法。

struct node{

	int data;  //data存储节点中的数据，本题中每个节点只有编号没有数据，可以省略。

	vector<int> child;

}Node[maxn];
2.定义一个level[110]数组存储每层的叶结点个数（没有孩子的结点）,再定义一个maxlevel存储树的最大深度。
3.使用DFS递归遍历家族树，传入参数当前结点root和深度d，逐个结点统计。
参考代码：

#include<cstdio>

#include<vector>

using namespace std;

const int maxn=110;

struct node{

	int data;

	vector<int> child;

}Node[maxn];

int level[110]={0},maxlevel=1;//统计每层的叶结点个数，标记树的最大深度

void DFS(int root,int d)

{

	if(d>maxlevel) maxlevel=d;

	if(Node[root].child.empty()) {

		level[d]++;

		return ;

	}

	for(int i=0;i<Node[root].child.size();i++)

	{

		DFS(Node[root].child[i],d+1);    //递归遍历子结点

	}

}

int main()

{

	int n,m,k,id,child;

	scanf("%d%d",&n,&m);

	for(int i=0;i<m;++i)

	{

		scanf("%d%d",&id,&k);

		for(int j=0;j<k;j++)

		{

			scanf("%d",&child);

			Node[id].child.push_back(child);

			Node[id].data=id;

		}

	}

	DFS(1,1);

	for(int i=1;i<=maxlevel;i++)

	{

		printf("%d",level[i]);

		if(i<maxlevel) printf(" ");

	}

	return 0;

}
