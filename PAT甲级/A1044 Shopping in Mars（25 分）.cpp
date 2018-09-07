1044 Shopping in Mars（25 分）
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:
Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.
If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: NNN (≤105\le 10^5≤10​5​​), the total number of diamonds on the chain, and MMM (≤108\le 10^8≤10​8​​), the amount that the customer has to pay. Then the next line contains NNN positive numbers D1⋯DND_1 \cdots D_ND​1​​⋯D​N​​ (Di≤103D_i\le 10^3D​i​​≤10​3​​ for all i=1,⋯,Ni=1, \cdots , Ni=1,⋯,N) which are the values of the diamonds. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print i-j in a line for each pair of i ≤\le≤ j such that DDDi + ... + DDDj = MMM. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.
If there is no solution, output i-j for pairs of i ≤\le≤ j such that DDDi + ... + DDDj >M> M>M with (DDDi + ... + DDDj −M- M−M) minimized. Again all the solutions must be printed in increasing order of i.
It is guaranteed that the total value of diamonds is sufficient to pay the given amount.
Sample Input 1:

16 15

3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:

1-5

4-6

7-8

11-11
Sample Input 2:

5 13

2 4 5 7 9
Sample Output 2:

2-4

4-5
题意：给定一串n个整数，再给一个m，让你在这n个数字中找出所有和式等于m的区间输出下标（从1开始），若果没有等于m的区间，则输出大于m的最小和式区间。
思路：首先把数组d[]中值，累加到sum[]数组中 ，然后for循环对sum数组二分查找，第一个大于等于sum[i-1]+m的数组值Min，如果该值等于m则说明正好找到串值等于m的区间，如果该值大于m则说明没有等于m的区间。然后再次循环输出所有和式等于Min的区间即可。
参考代码：

#include<cstdio>

using namespace std;

const int maxn=100010;

int n,m,t,Min=(1<<31)-1,d[maxn],sum[maxn];

int binarySearch(int l,int r,int x){

	int mid;

	while(l<r){

		mid=(l+r)/2;

		if(sum[mid]>=x)

			r=mid;

		else l=mid+1;

	}

	return r;

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++){

		scanf("%d",&d[i]);

		if(i==1)

			sum[i]=d[i];

		else sum[i]=sum[i-1]+d[i];

	}

	for(int i=1;i<=n&&Min!=m;i++){

		t=binarySearch(i,n,sum[i-1]+m);

		if(sum[t]-sum[i-1]>=m&&sum[t]-sum[i-1]<=Min)    //这里注意还要>=m

			Min=sum[t]-sum[i-1];

	}

	for(int i=1;i<=n;i++){

		t=binarySearch(i,n,sum[i-1]+m);

		if(sum[t]-sum[i-1]==Min)

			printf("%d-%d\n",i,t);

	}

	return 0;

}
