1151 LCA in a Binary Tree（30 分）
The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.
Given any two nodes in a binary tree, you are supposed to find their LCA.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the binary tree, respectively. In each of the following two lines, N distinct integers are given as the inorder and preorder traversal sequences of the binary tree, respectively. It is guaranteed that the binary tree can be uniquely determined by the input sequences. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.
Output Specification:
For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the binary tree, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..
Sample Input:

6 8

7 2 3 4 6 5 1 8

5 3 7 2 6 4 8 1

2 6

8 1

7 9

12 -3

0 8

99 99
Sample Output:

LCA of 2 and 6 is 3.

8 is an ancestor of 1.

ERROR: 9 is not found.

ERROR: 12 and -3 are not found.

ERROR: 0 is not found.

ERROR: 99 and 99 are not found.
题意：给定二叉树的中序和先序序列，求最近公共祖先。
思路：如果先根据中序和先序序列建树，然后再求最近公共祖先会导致两个case超时，以下方法不建二叉树，直接根据两个序列求最近公共祖先。在中序序列中，如果结点a，b在root左边，则最近公共祖先在root的左子树中，如果a，b在root右边，则最近公共祖先在root的右边，如果a和b分别在root的两侧说明root就是其最近公共祖先。由于给定的结点数值范围为整数，可能为负，所以使用unordered_map存储每个结点在中序的位置 。在每层递归中，根据先序序列中的根节点，可以推出其在中序序列的位置。（该思路参考了柳婼大佬的博客，多谢提点）。
参考代码：

#include<cstdio>

#include<vector>

#include<unordered_map>

using namespace std;

const int maxn=10005;

int n,m,a,b;

vector<int> in,pre;

unordered_map<int,int> Inpos,flag;

void LCA(int inl,int inr,int preroot,int a,int b){

	if(inl>inr) return;

	int inroot=Inpos[pre[preroot]];	//求出根节点在中序的位置

	if(Inpos[a]<inroot&&Inpos[b]<inroot)

		LCA(inl,inroot-1,preroot+1,a,b);

	else if((Inpos[a]<inroot&&Inpos[b]>inroot)||(Inpos[a]>inroot&&Inpos[b]<inroot))

		printf("LCA of %d and %d is %d.\n",a,b,pre[preroot]);

	else if(Inpos[a]>inroot&&Inpos[b]>inroot){

		int rchildRoot=preroot+(inroot-inl)+1;

		LCA(inroot+1,inr,rchildRoot,a,b);

	}else if(pre[preroot]==a)

		printf("%d is an ancestor of %d.\n",a,b);

	else if(pre[preroot]==b)

		printf("%d is an ancestor of %d.\n",b,a);

}

int main()

{

	scanf("%d%d",&m,&n);

	in.resize(n);

	pre.resize(n);

	for(int i=0;i<n;i++){

		scanf("%d",&in[i]);

		Inpos[in[i]]=i;

	}

	for(int i=0;i<n;i++)

		scanf("%d",&pre[i]);

	for(int i=0;i<m;i++){

		scanf("%d%d",&a,&b);

		if(Inpos.find(a)==Inpos.end()&&Inpos.find(b)==Inpos.end())

			printf("ERROR: %d and %d are not found.\n",a,b);

		else if(Inpos.find(a)==Inpos.end()||Inpos.find(b)==Inpos.end())

			printf("ERROR: %d is not found.\n",Inpos.find(a)==Inpos.end()?a:b);

		else LCA(0,n-1,0,a,b);

	}

	return 0;

}
