Given a sequence of K integers { N~1~, N~2~, ..., N~K~ }. A continuous subsequence is defined to be { N~i~, N~i+1~, ..., N~j~ } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.
Sample Input:

10

-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
题意：给定数组，输出其最大连续子列和，并输出该最大连续子列的第一个元素和最后一个元素（注意不是下标），如果所有元素都是负数，则定义其最大连续子列和为0，输出零之后，再输出整个数组的第一个元素和最后一个元素。
思路：
1.动态规划问题，设置数组dp[]存储最大连续子列和，则有状态转移方程dp[i]=max(dp[i-1]+data[i],data[i])。
2.设置变量mx存储最大的子列和，并用mxL（初始为0）标记该最大子列的左边界，mxR（初始为0）标记右边界，每次变更mx时更新右边界mxR=i，仅当dp[i-1]+data[i]<data[i]时更新左边界为mxL=i。
3.最大子列和mx初始化为-1（不能直接初始化为0，因为最大和mx为0时需要特殊判断输出，整个数列的第一个和最后一个元素）。
参考代码：

#include<cstdio>

using namespace std;

const int maxn=10010;

int data[maxn],dp[maxn]={0};

int main()

{

	int k,mx=-1,mxL=0,mxR=0,temp=0;

	scanf("%d",&k);

	for(int i=0;i<k;i++)

	{

		scanf("%d",&data[i]);

		if(i==0) dp[i]=data[i];

		else if(dp[i-1]+data[i]>data[i]){

			dp[i]=dp[i-1]+data[i];

		}else{

			dp[i]=data[i];

			temp=i;

		}

		if(dp[i]>mx){

			mx=dp[i];

			mxL=temp;

			mxR=i;

		}

	}

	if(mx==-1) printf("0 %d %d\n",data[0],data[k-1]);

	else printf("%d %d %d\n",mx,data[mxL],data[mxR]);

	return 0;

}
