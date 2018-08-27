The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
For example, given a set of coupons { 1 2 4 −1 }, and a set of product values { 7 6 −2 −3 } (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.
Input Specification:
Each input file contains one test case. For each case, the first line contains the number of coupons N​C​​, followed by a line with N​C​​ coupon integers. Then the next line contains the number of products N​P​​, followed by a line with N​P​​ product values. Here 1≤N​C​​,N​P​​≤10​5​​, and it is guaranteed that all the numbers will not exceed 2​30​​.
Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.
Sample Input:

4

1 2 4 -1

4

7 6 -2 -3
Sample Output:
43
题意：给定n1个火星优惠券coupons[]，然后给定n2个产品products[]，如果定义对于products[]中的任意数字，若coupons[i]*products[j]乘积为正则得到对应价值，否则要付对应的费用，每张有优惠券和产品最多少用一次，求能得到的最大价值是多少。
思路：直接对两个数组进行排序，然后把两个数组中对应从大到小的正整数相乘累加，把数组中对应负整数从小到大累加，求和就是最终结果。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

int main()

{

	int n1,n2,ans=0;

	scanf("%d",&n1);

	vector<int> coupons(n1);

	for(int i=0;i<n1;i++) scanf("%d",&coupons[i]);

	scanf("%d",&n2);

	vector<int> products(n2);

	for(int i=0;i<n2;i++) scanf("%d",&products[i]);

	sort(coupons.begin(),coupons.end());

	sort(products.begin(),products.end());

	for(int i=n1-1,j=n2-1;i>=0&&j>=0;i--,j--){

		if(coupons[i]>0&&products[j]>0)

			ans+=coupons[i]*products[j];

		else break;

	}

	for(int i=0;i<n1&&i<n2;i++){

		if(coupons[i]<0&&products[i]<0)

			ans+=coupons[i]*products[i];

		else break;

	}

	printf("%d\n",ans);

	return 0;

}
