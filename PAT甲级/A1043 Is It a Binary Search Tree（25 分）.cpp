1043 Is It a Binary Search Tree（25 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in a line YES if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or NO if not. Then if the answer is YES, print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input 1:

7

8 6 5 7 10 8 11
Sample Output 1:

YES

5 7 6 8 11 10 8
Sample Input 2:

7

8 10 11 8 6 7 5
Sample Output 2:

YES

11 8 10 7 5 6 8
Sample Input 3:

7

8 6 8 5 10 9 11
Sample Output 3:
NO
题意：给定n个数字问你它是否为二叉排序树的先序序列，或者镜像二叉排序树（即交换二叉排序树所有结点的左右子树）的先序序列，如果是则输出YES，然后输出对应的后序遍历序列或镜像后序遍历序列，否则输出NO。
思路：按题意写出二叉排序树的建立函数，再分别写出二叉树的前序遍历函数preOrder，镜像前序遍历函数MpreOrder，后序遍历函数postOrder以及镜像后序遍历函数MpostOrder。然后把前序遍历结果和镜像前序遍历结果与原始序列比较，根据是否相同判断并对应输出后序或镜像后序序列即可。注意镜像函数只需交换左右子树的访问顺序即可。
参考代码：

#include<vector>

#include<cstdio>

using namespace std;

int n;

vector<int> origin,pre,post,Mpre,Mpost;

struct node{

	int data;

	node* lchild;

	node* rchild;

	node(int v=0):data(v),lchild(NULL),rchild(NULL){}

};

void Insert(node*& root,int x){

	if(root==NULL){

		root=new node(x);

		return ;

	}else if(x<root->data) Insert(root->lchild,x);

	else Insert(root->rchild,x);

}

void preOrder(node* root){

	if(root==NULL) return;

	pre.push_back(root->data);

	preOrder(root->lchild);

	preOrder(root->rchild);

}

void MpreOrder(node* root){

	if(root==NULL) return;

	Mpre.push_back(root->data);

	MpreOrder(root->rchild);

	MpreOrder(root->lchild);

}

void postOrder(node* root){

	if(root==NULL) return;

	postOrder(root->lchild);

	postOrder(root->rchild);

	post.push_back(root->data);

}

void MpostOrder(node* root){

	if(root==NULL) return;

	MpostOrder(root->rchild);

	MpostOrder(root->lchild);

	Mpost.push_back(root->data);

}

int main()

{

	scanf("%d",&n);

	origin.resize(n);

	node* root=NULL;

	for(int i=0;i<n;i++) {

		scanf("%d",&origin[i]);

		Insert(root,origin[i]);

	}

	preOrder(root);

	MpreOrder(root);

	if(origin==pre){

		postOrder(root);

		printf("YES\n");

		for(int i=0;i<n;i++){

			printf("%d",post[i]);

			if(i<n-1) printf(" ");

		}

	}else if(origin==Mpre){

		MpostOrder(root);

		printf("YES\n");

		for(int i=0;i<n;i++){

			printf("%d",Mpost[i]);

			if(i<n-1) printf(" ");

		}

	}else printf("NO\n");

	return 0;

}
