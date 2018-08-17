Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10​5​​) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
Output Specification:
For each test case you should output the median of the two given sequences in a line.
Sample Input:

4 11 12 13 14

5 9 10 15 16 17
Sample Output:
13
题意：给定两个有序序列长度分别为n，m，让你求他们的中位数下标为（n+m-1）/2，奇数个中位数在中间，偶数个是前一半的最后一个。
思路：
1.输入两个序列并合直接取中，但会超时超内存。
2.使用两个队列q1，q2分别读取这两个序列，然后计算出中位数是第（n+m-1）/2个（下标从0开始），逐个比较q1中队首元素和    q2中队首元素，并将小的出队，最后输出中位数，为了简化代码，将int型最大数inf(=1（<<31)-1)分别入队，这样队列永不为        空，方便比较。新版PAT会导致最后一个案例超内存。
3.优化2的方法，对于序列2，直接边读取，边和q1队首元素比较。

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;

const int inf=(1<<31)-1;

queue<int> q1;

int main()

{

	int n,m,t,t1,t2;

	scanf("%d",&n);

	for(int i=0;i<n;i++) {

		scanf("%d",&t);

		q1.push(t);

	}

	q1.push(inf);

	scanf("%d",&m);

	int cnt=0,mid=(n+m-1)/2;

	for(int i=0;i<m;i++) {

		scanf("%d",&t);

		while(q1.front()<=t&&cnt<mid){			

			cnt++;

			q1.pop();

		}

		if(cnt>=mid) break;			//注意这句不能放在最后，否则下例会输出12

		if(q1.front()>t&&cnt<mid)	//5 9 10 15 16 17

			cnt++;					//4 11 12 13 14

	}

	while(cnt<mid) {

		q1.pop();

		cnt++;

		t=inf;

	}

	printf("%d\n",min(q1.front(),t));

	return 0;

}
