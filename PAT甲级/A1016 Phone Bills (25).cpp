A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.
Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00
02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
Sample Input:

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10

10

CYLL 01:01:06:01 on-line

CYLL 01:28:16:05 off-line

CYJJ 01:01:07:00 off-line

CYLL 01:01:08:03 off-line

CYJJ 01:01:05:59 on-line

aaa 01:01:01:03 on-line

aaa 01:02:00:01 on-line

CYLL 01:28:15:41 on-line

aaa 01:05:02:24 on-line

aaa 01:04:23:59 off-line
Sample Output:

CYJJ 01

01:05:59 01:07:00 61 $12.10

Total amount: $12.10

CYLL 01

01:06:01 01:08:03 122 $24.40

28:15:41 28:16:05 24 $3.85

Total amount: $28.25

aaa 01

02:00:01 04:23:59 4318 $638.80

Total amount: $638.80
题意：给定一组用户的通话记录，让你计算每一位用户当月的总费用，并按指定格式输出其中的有效记录 。
思路：
1.定义结构体用来存储每条记录，然后定义一个map<username,有效记录>,按照规则把每对有效记录存入用户对应的map中,最后计算输出。

struct record{

	string name;

	int mon,dd,hh,mm,time;

	bool flag;		//flag为真表示on-line，为假表示off-line

}t;
2.对于每条记录时间和费用的计算，首先定义个排序函数按照（用户名，时间）从小到大的顺序排序，然后从较小的on-line-record逐分钟累加到较大的off-line-record，边累加时间边计算费用。

#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<map>

using namespace std;

int charge[24];

struct record{

	string name;

	int mon,dd,hh,mm,time;

	bool flag;		//flag为真表示on-line，为假表示off-line

}t;

bool cmp(record a,record b)

{

	if(a.name!=b.name) return a.name<b.name;

	else return a.time<b.time;

}

int Count(record a,record b,double& money){

	int time=0;

	while(a.dd!=b.dd||a.hh!=b.hh||a.mm!=b.mm)

	{

		time++;

		money+=charge[a.hh];

		a.mm++;

		if(a.mm==60) {

			a.mm=0;

			a.hh++;

			if(a.hh==24){

				a.hh=0;

				a.dd++;

			}

		}

	}

	return time;

}

int main()

{

	int n;

	string status;

	for(int i=0;i<24;i++) cin>>charge[i];

	cin>>n;

	vector<record> rec(n);

	for(int i=0;i<n;i++)

	{

		cin>>t.name;

		scanf("%d:%d:%d:%d",&t.mon,&t.dd,&t.hh,&t.mm);

		cin>>status;

		status=="on-line"?t.flag=true:t.flag=false;

		t.time=t.dd*24*60+t.hh*60+t.mm;

		rec[i]=t;

	}

	sort(rec.begin(),rec.end(),cmp);

	map<string,vector<record>> custom;

	int idx=0;

	while(idx+1<n)	//这个循环用来查找有效记录并存入对应用户的custom中

	{

		if(rec[idx].flag==true&&rec[idx+1].flag==false&&rec[idx+1].name==rec[idx].name) {

			custom[rec[idx].name].push_back(rec[idx]);

			custom[rec[idx+1].name].push_back(rec[idx+1]);

		}

		idx++;

	}

	for(auto it=custom.begin();it!=custom.end();it++)

	{

		vector<record> temp=it->second;

		cout<<it->first;

		printf(" %02d\n",temp[0].mon);

		int time=0;

		double total=0.0;

		for(int i=0;i<temp.size();i+=2)

		{

			double money=0.0;	//money用来统计每条有效记录的总费用，传入函数中之前必须清零

			time=Count(temp[i],temp[i+1],money);

			printf("%02d:%02d:%02d ",temp[i].dd,temp[i].hh,temp[i].mm);

			printf("%02d:%02d:%02d ",temp[i+1].dd,temp[i+1].hh,temp[i+1].mm);

			printf("%d $%.2f\n",time,money/100.0);

			total+=money;

		}

		printf("Total amount: $%.2f\n",total/100);	//注意total总钱数除以100

	}

		return 0;

}
