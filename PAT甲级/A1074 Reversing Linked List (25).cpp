Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.
Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5^) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.
Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
Sample Input:

00100 6 4

00000 4 99999

00100 1 12309

68237 6 -1

33218 3 00000

99999 5 68237

12309 2 33218
Sample Output:

00000 4 33218

33218 3 12309

12309 2 00100

00100 1 99999

99999 5 68237

68237 6 -1
题意：给定一个链表，让你每k个节点反转一次，最后不足k个结点则不反转，然后按反转后的顺序输出结果。
思路：
1.将数据储存在数组中，然后从起始节点开始遍历，每k个结点反转一次，直接使用reverse函数进行反转操作（头文件是algorithm），最后输出List链表即可。
2.注意链表中存储的是地址，末位地址输出-1，注意特殊处理。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

const int maxn=100010;

int main()

{

	int n,st,k,sum=0,addr,data[maxn],next[maxn];

	vector<int> List;

	scanf("%d%d%d",&st,&n,&k);

	for(int i=0;i<n;i++)	

	{

		scanf("%d",&addr);

		scanf("%d %d",&data[addr],&next[addr]);

	}

	while(st!=-1){

		List.push_back(st);

		sum++;

		st=next[st];

		if(k>1&&sum%k==0)

			reverse(List.begin()+sum-k,List.begin()+sum);

	}

	for(int i=0;i<sum-1;i++)

	{

		printf("%05d %d %05d\n",List[i],data[List[i]],List[i+1]);

	}

        printf("%05d %d -1\n", List[sum - 1], data[List[sum - 1]]);

	return 0;

}
