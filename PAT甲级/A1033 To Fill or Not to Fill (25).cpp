With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: C~max~ (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; D~avg~ (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P~i~, the unit gas price, and D~i~ (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
Sample Input 1:

50 1300 12 8

6.00 1250

7.00 600

7.00 150

7.10 0

7.20 200

7.50 400

7.30 1000

6.85 300
Sample Output 1:
749.17
Sample Input 2:

50 1300 12 2

7.10 0

7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
 题意：给定Cmax，D，Davg，N分别表示油箱容量，目的地距离，单位油量的行驶距离，总加油站数量，让你求出到达目的距离的最低花费，如果不能到达目的地则输出最远行驶距离。
思路：使用贪心算法解决问题。将站点按距离远近排序。设当前站now，使用for循环寻找从当前站满油箱状态能够到达的站中，下一个比当前站油价更低的站nextMin。
1.如果当前站now油价比下一个更低价格的站nextMin油价更低，则在当前站加满油，保持以最低油价，跑最远的距离。
2.如果nextMin站油价比当前站更低，则把油加到恰好行驶到nextMin站，然后加更低价格的油，如果油箱中的油足够到nextMin站，则不加油。
3.注意，开始时油箱为空，所以如果起始站距离不为零，则汽车无法启动，行驶距离为0.
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

int N;

double Cmax,D,Davg;

struct node{

	double unit,dis;

}cur;

bool cmp(node a,node b)

{

	if(a.dis!=b.dis) return a.dis<b.dis;

	else return a.unit<b.unit;

}

int main()

{

	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);

	vector<node> st(N+1);

	for(int i=0;i<N;i++){

		scanf("%lf%lf",&st[i].unit,&st[i].dis);

	}

	st[N].dis=D;

	st[N].unit=0;

	sort(st.begin(),st.end(),cmp);

	if(st[0].dis!=0) {

		printf("The maximum travel distance = 0.00\n");

		return 0;

	}

	double curDist=0,curTank=0,curCost=0,totalCost=0;

	int now=0;

	while(now<N){

		int nextMin=now+1;	//nextMin标记第一个比当前油站价格更低的站

		for(int j=now+1;j<=N&&st[now].dis+Cmax*Davg>=st[j].dis;j++){

			if(st[j].unit<st[now].unit) {

				nextMin=j;

				break;

			}

		}

		if(st[now].dis+Cmax*Davg<st[nextMin].dis){

			printf("The maximum travel distance = %.2f\n",st[now].dis+Cmax*Davg);

			return 0;

		}

		double dif=st[nextMin].dis-st[now].dis;

		if(st[nextMin].unit<=st[now].unit){	//下一单价最小的站比当前站更低

			if(curTank>=dif/Davg){	//油量足够到nextMin站

				curTank-=dif/Davg;

				curDist=st[nextMin].dis;	

			}else{

			curCost+=(dif/Davg-curTank)*st[now].unit;

			curTank=0;

			}

		}else{		//当前站单价低

			curCost+=(Cmax-curTank)*st[now].unit;

			curTank=Cmax-dif/Davg;

		}

		now=nextMin;

	}

	printf("%.2f\n",curCost);

	return 0;

}
