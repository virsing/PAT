Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:

7

2 3 1 5 7 6 4

1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
题意：给定二叉树中序和后序序列，让你输出其层序遍历序列。
思路：首先根据中序和后序建立二叉树，然后层序遍历即可。
参考代码： 

#include<queue>

#include<cstdio>

using namespace std;

struct node{

	int data;

	node* lchild;

	node* rchild;

	node(int d):data(d),lchild(NULL),rchild(NULL){}

};

vector<int> in,post;

node* Create(int inl,int inr,int postl,int postr)

{

	if(postl>postr) return NULL;

	node* root=new node(post[postr]);

	int k=inl;

	while(k<=inr&&in[k]!=post[postr]) k++;

	int numleft=k-inl;

	root->lchild=Create(inl,k-1,postl,postl+numleft-1);

	root->rchild=Create(k+1,inr,postl+numleft,postr-1);

	return root;

}

void BFS(node* root)

{

	if(root==NULL) return;

	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node* p=q.front();

		q.pop();

		if(p!=root) printf(" %d",p->data);

		else printf("%d",p->data);

		if(p->lchild!=NULL) q.push(p->lchild);

		if(p->rchild!=NULL) q.push(p->rchild);

	}

}

int main()

{

	int n;

	scanf("%d",&n);

	in.resize(n);

	post.resize(n);

	for(int i=0;i<n;i++) scanf("%d",&post[i]);

	for(int i=0;i<n;i++) scanf("%d",&in[i]);

	node* root=Create(0,n-1,0,n-1);

	BFS(root);

	return 0;

}
优化：在使用中序和后序建树的过程中，每层节点都是按照从左往右的顺序依次访问，因此开设一个数组下表作为层号，将建树过程每次访问的结点依次加入，最后按层号输出即为层序遍历。
参考代码：

#include<cstdio>

using namespace std;

const int maxn=35;

vector<int> in(maxn),post(maxn);

vector<int> level[maxn];

void Create(int inl,int inr,int postl,int postr,int d)

{

	if(postl>postr) return ;

	level[d].push_back(post[postr]);

	int k=inl;

	while(k<=inr&&in[k]!=post[postr]) k++;

	int numleft=k-inl;

	Create(inl,k-1,postl,postl+numleft-1,d+1);

	Create(k+1,inr,postl+numleft,postr-1,d+1);

}

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=0;i<n;i++) scanf("%d",&post[i]);

	for(int i=0;i<n;i++) scanf("%d",&in[i]);

	Create(0,n-1,0,n-1,1);

	printf("%d",level[1][0]);

	for(int i=2;i<maxn;i++){

		for(int j=0;j<level[i].size();j++){

			printf(" %d",level[i][j]);

		}

	}

	printf("\n");

	return 0;

}
