月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得72 + 45/2 = 94.5（亿元）。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
输入样例：

3 20

18 15 10

75 72 45
输出样例：
94.50
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.使用结构体存储每类月饼的总量，总售价以及单价。按单价由高到低排序，再求出最高利润。
2.注意每类月饼的库存以及总售价可能是浮点数。
参考代码：

#include<cstdio>

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

struct node{

	double price,store,unit;

}t;

bool cmp(node a,node b)

{

	return a.unit>b.unit;

}

int main()

{

	int N;

	double D,profit=0;

	scanf("%d%lf",&N,&D);

	vector<node> data(N);

	for(int i=0;i<N;i++)	scanf("%lf",&data[i].store);

	for(int i=0;i<N;i++) 

	{

		scanf("%lf",&data[i].price);

		data[i].unit=data[i].price/data[i].store;

	}

	sort(data.begin(),data.end(),cmp);

	for(int i=0;i<N&&D!=0;i++)

	{

		if(D>=data[i].store){

			profit+=data[i].price;

			D-=data[i].store;

		}else {

			profit+=data[i].unit*D;

			D=0;

		}

	}

	printf("%.2f\n",profit);

	return 0;

}
