1147 Heaps（30 分）
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
Your job is to tell if a given complete binary tree is a heap.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 100), the number of trees to be tested; and N (1 < N ≤ 1,000), the number of keys in each tree, respectively. Then M lines follow, each contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.
Output Specification:
For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all. Then in the next line print the tree's postorder traversal sequence. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.
Sample Input:

3 8

98 72 86 60 65 12 23 50

8 38 25 58 52 82 70 60

10 28 15 12 34 9 8 56
Sample Output:

Max Heap

50 60 65 72 12 23 86 98

Min Heap

60 58 52 38 82 70 25 8

Not Heap

56 12 34 28 9 8 15 10
题意：给定n个层序序列让你判断这些序列是大顶堆还是小顶堆，然后输出其后序遍历序列。 
思路：数据下表从0开始，堆是完全二叉树其下满足如下特性，设当前点是a[i]，若孩子结点存在，则其左孩子为a[2*i+1],右孩子为a[2*i+2];若当前点为a[i]，则其双亲结点为a[(i-1)/2]。对于大顶堆，任意非根结点满足a[i]<=a[(i-1)/2]，对于小顶堆，任意非根结点满足a[i]>=a[(i-1)/2],有一个节点不满足条件则不是堆。至于后序遍历序列，知道了各结点的联系后，设当前点下标root，则左孩子root*2+1,右孩子root*2+2，然后进行后序遍历输出序列即可。（30分大题，竟然只要40行代码就解决了，难道是故意放水的，O(∩_∩)O）
参考代码：

#include<cstdio>

using namespace std;

int m,n,a[1010];

bool isMaxHeap(int a[]){

	for(int i=n-1;i>0;i--)

		if(a[i]>a[(i-1)/2])

			return false;

	return true;

}

bool isMinHeap(int a[]){

	for(int i=n-1;i>0;i--)

		if(a[i]<a[(i-1)/2])

			return false;

	return true;

}

void postOrder(int root,bool& flag){

	if(root<n){

		int lchild=root*2+1,rchild=root*2+2;

		postOrder(lchild,flag);

		postOrder(rchild,flag);

		printf("%s%d",flag?" ":"",a[root]);

		flag=true;

	}

}

int main()

{

	scanf("%d%d",&m,&n);

	for(int k=0;k<m;k++){

		for(int i=0;i<n;i++)

			scanf("%d",&a[i]);

		bool flag=false;

		if(isMaxHeap(a)) printf("Max Heap\n");

		else if(isMinHeap(a)) printf("Min Heap\n");

		else printf("Not Heap\n");			

		postOrder(0,flag);

		printf("\n");

	}

	return 0;

}
