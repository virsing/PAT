This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input

2 1 2.4 0 3.2

2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
 题意：给定两个多项式（格式为k 指数1 系数1 指数2 系数2……指数k 系数k），让你按输入格式输出其乘积。
思路：
1.考虑如果直接开两个1000的数组，用下标直接当指数，在相乘的时候，复杂度为1000*1000，可能会超时，所以定义一个结构体存储第一个多项式，然后用第二个多项式的每一项与第一个多项式的每一项相乘，结果存储在数组ans中。
2.注意每个多项式不超过1000，但相乘后可能会达到2000，所以数组大小要超过2000。
参考代码：

#include<cstdio>

#include<cmath>

#include<vector>

using namespace std;

const int maxn=2010;

double ans[maxn]={0};

struct node{

	int exp;

	double coe;

	node(int e=0,double c=0):exp(e),coe(c){};

};

int main()

{

	int k1,k2,exp,num=0;

	double coe;

	scanf("%d",&k1);

	vector<node> a(k1);

	for(int i=0;i<k1;i++)

	{

		scanf("%d%lf",&exp,&coe);

		a[i]=node(exp,coe);

	}

	scanf("%d",&k2);

	for(int i=0;i<k2;i++)

	{

		scanf("%d%lf",&exp,&coe);

		for(int j=0;j<k1;j++)

		{

			ans[exp+a[j].exp]+=coe*a[j].coe;	//注意原来的数可能不是零，这里需要与原来的数相加。

		}

	}

	for(int i=0;i<maxn;i++)

	{

		if(ans[i]!=0) num++;

	}

	printf("%d",num);

	for(int i=maxn;i>=0&&num;i--)

	{

		if(ans[i]!=0){

			printf(" %d %.1f",i,ans[i]);

			num--;

		}

	}

	return 0;

}
