Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:
The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.
For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer~1~ is served at window~1~ while customer~2~ is served at window~2~. Customer~3~ will wait in front of window~1~ and customer~4~ will wait in front of window~2~. Customer~5~ will wait behind the yellow line.
At 08:01, customer~1~ is done and customer~5~ enters the line in front of window~1~ since that line seems shorter now. Customer~2~ will leave at 08:02, customer~4~ at 08:06, customer~3~ at 08:07, and finally customer~5~ at 08:10.
Input
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).
The next line contains K positive integers, which are the processing time of the K customers.
The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.
Output
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.
Sample Input

2 2 7 5

1 2 6 4 3 534 2

3 4 5 6 7
Sample Output

08:07

08:06

08:10

17:00

Sorry
题意：假设某银行有n个窗口，每个窗口前可排m人，给定总人数k，如果总人数大于n*m，则其他所有编号大于n*m的人要排到黄线外，然后每当有人服务完毕后，黄线外的人选择一个时间最快的窗口队列排过去，如果有多个窗口同时结束，则选择编号最小的队列排队。银行开始服务时间是08：00，关闭时间是17：00，如果有人在关闭时间还没开始服务，则输出sorry，否则输出查询人员对应的服务结束时间。
思路：
1.定义来给你个结构体，一个用来存放输入数据，以及最总的结束时间，另一个用来存放窗口排队情况；

struct node{

	int time,end;

};

struct windows{    

	int popTime,endTime;    //分别表示窗口队首人员结束时间，以及队尾人员的结束时间

	queue<node> q;

};
2.最后输出的是人员的服务结束时间，而判断是否输出sorry则根据开始服务时间是否超过17：00，以结束时间减去服务时间获取开始时间计算。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;

const int maxn=1010;

int n,m,k,Q,idx=0;

struct node{

	int time,end;

};

struct windows{

	int popTime,endTime;

	queue<node> q;

};

int main()

{

	scanf("%d%d%d%d",&n,&m,&k,&Q);

	vector<node> List(k);

	vector<windows> win(21);

	int st=8*60,ed=17*60;

	for(int i=0;i<k;i++)

	{

		scanf("%d",&List[i].time);

	}

	for(idx=0;idx<n*m&&idx<k;idx++)

	{

		if(idx<n)	

		{

			List[idx].end=st+List[idx].time;	

			win[idx].popTime=List[idx].end;	//如果编号小于n，同时更新窗口队列队首结束时间

		}else{

			List[idx].end=win[idx%n].endTime+List[idx].time;

		}

		win[idx%n].endTime=List[idx].end;	//更新队尾结束时间

		win[idx%n].q.push(List[idx]);	//人员入队

	}

	for(;idx<k;idx++)

	{

		int minIdx=0;	//保存最早结束的窗口队列编号

		for(int j=1;j<n;j++)

		{

			if(win[j].popTime<win[minIdx].popTime)

				minIdx=j;

		}

		win[minIdx].q.pop();

		win[minIdx].popTime=win[minIdx].q.front().end;

		win[minIdx].endTime=win[minIdx].endTime+List[idx].time;

		List[idx].end=win[minIdx].endTime;

		win[minIdx].q.push(List[idx]);

	}

	for(int i=0;i<Q;i++)

	{

		int id;

		scanf("%d",&id);

		if(List[id-1].end-List[id-1].time>=ed)	//以开始时间小于17：00为截断标准。

			printf("Sorry\n");

		else printf("%02d:%02d\n",List[id-1].end/60,List[id-1].end%60);

	}

	return 0;

}
