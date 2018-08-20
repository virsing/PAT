To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.
\ Figure 1
You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).
Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 10^5^), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.
Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.
Sample Input 1:

11111 22222 9

67890 i 00002

00010 a 12345

00003 g -1

12345 D 67890

00002 n 00003

22222 B 23456

11111 L 00001

23456 e 67890

00001 o 00010
Sample Output 1:
67890
Sample Input 2:

00001 00002 4

00001 a 10001

10001 s -1

00002 a 10002

10002 t -1
Sample Output 2:
-1
 题意：给定两个链表，起始地址st1，st2，链表长度n，如果这两个链表所存储的单词，有公共的后缀，输出其第一个公共后缀地址，否则输出-1.
思路：定义结构体存储每个链表的数据data和下结点地址next。直接用地址代表下标访问结点。首先求出这两个单词的长度差设为cnt，如果这两个单词有公共后缀，那么让较长的单词首先遍历cnt个单位，然后再让这两个单词一起向后遍历，若存在公共后缀，则当二者地址相同时即为答案，否则为-1.
参考代码：

#include<cstdio>

#include<algorithm>

using namespace std;

const int maxn=100010;

struct node{

	int data,next;

};

node l[maxn];

int main()

{

	int n,st1,st2,addr,data,next;

	scanf("%d%d%d",&st1,&st2,&n);

	for(int i=0;i<n;i++){

		scanf("%d",&addr);

		scanf(" %c %d",&l[addr].data,&l[addr].next);

	}

	int p=st1,len1=0,len2=0;

	while(p!=-1)  {

		len1++;

		p=l[p].next;

	}

	p=st2;

	while(p!=-1){

		len2++;

		p=l[p].next;

	}

	if(len1<len2) {	//保证st1指向较长的单词 

		swap(len1,len2);

		swap(st1,st2);

	}

	for(int i=0;i<len1&&i<len1-len2;i++) st1=l[st1].next;

	while(st1!=-1&&st2!=-1&&st1!=st2) {

		st1=l[st1].next;

		st2=l[st2].next;

	}

	if(st1==-1) printf("-1\n");

	else printf("%05d\n",st1);

	return 0;

}
