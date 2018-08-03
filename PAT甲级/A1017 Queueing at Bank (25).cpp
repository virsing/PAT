Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
Sample Input:

7 3

07:55:00 16

17:00:01 2

07:59:59 15

08:01:00 60

08:00:00 30

08:00:02 2

08:03:00 10
Sample Output:
8.2
题意：假设某银行有n位客户，k个窗口，让你模拟银行排队系统，计算所有客户的平均等待时间 。
思路：
1.，首先以结构体存储客户的到达时间和服务时间，由于输入客户的到达时间为乱序，所以先排序，然后按序处理，在定义一个结构体edTime[k]存储每个窗口的结束时间，然后每次挑出最早结束的窗口分配给下一位客户即可，并累加等待时间total，在累加总等待时间时，如果当前最早结束的窗口时间edTime[min]小于下一位待服务的客户到达时间，则客户等待时间为0，如果大于下一位客户到达时间则total累加（窗口结束时间-客户到达时间）。
2.如果客户在17：00之后到达则不再服务，也不计入平均等待时间（等于17：00到达的则继续服务），注意，如果客户在17：00及之前到达，而因为排队等到了17：00之后没有得到服务，也是计入平均等待时间的！！！
3.如果符合要求的客户为零，直接输出：0.0。为了时间比较方便，将所有时间统一为秒计算，如果某位客户要求服务的时间超过一小时，将强制压缩为1小时。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

struct node{

	int arrive,serve;

}t;

bool cmp(node a,node b)

{

	return a.arrive<b.arrive;

}

int main()

{

	int n,k,st,ed,total=0;

	scanf("%d%d",&n,&k);

	st=8*60*60;

	ed=17*60*60;

	vector<node> rec;

	vector<int> edTime(k,st);

	for(int i=0;i<n;i++)

	{

		int hh,mm,ss,serve;

		scanf("%d:%d:%d %d",&hh,&mm,&ss,&serve);

		int arrive=hh*3600+mm*60+ss;

		if(arrive>ed) continue;

		t.arrive=arrive;

		t.serve=serve>60?3600:serve*60;	//服务时间是分钟要转换为秒,并且超过60分的要压缩为60分钟

		rec.push_back(t);

	}

	sort(rec.begin(),rec.end(),cmp);

	for(int idx;idx<rec.size();idx++)

	{

		int minIdx=0;

		for(int i=1;i<k;i++)

		{

			if(edTime[i]<edTime[minIdx])

				minIdx=i;

		}

		if(edTime[minIdx]<=rec[idx].arrive)	//窗口闲置等待顾客的情况

		{

			edTime[minIdx]=rec[idx].arrive+rec[idx].serve;

		}else {								//顾客等窗口的情况

			total+=edTime[minIdx]-rec[idx].arrive;

			edTime[minIdx]+=rec[idx].serve;		

		}

	}

	if(rec.size()==0) printf("0.0\n");

	else printf("%.1f\n",total/60.0/rec.size());

	return 0;

}
