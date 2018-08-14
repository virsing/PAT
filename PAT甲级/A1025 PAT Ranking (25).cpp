Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
Sample Input:

2

5

1234567890001 95

1234567890005 100

1234567890003 95

1234567890002 77

1234567890004 85

4

1234567890013 65

1234567890011 25

1234567890014 100

1234567890012 85
Sample Output:

9

1234567890005 1 1 1

1234567890014 1 2 1

1234567890001 3 1 2

1234567890003 3 1 2

1234567890004 5 1 4

1234567890012 5 2 2

1234567890002 7 1 5

1234567890013 8 2 3

1234567890011 9 2 4
题意：给定n个考场考生的pat成绩，让你给这些考生做出总排名和考场内排名，最后输出。 
思路：定义结构体存储考生编号，成绩，考场号，考场内排名。总排名可以直接输出。然后每输入完一个考场的学生人数就给这些考生排一次序，保存考场内排名，最后在总体排名，输出即可。在排名时，如果考生i和考生i-1分数相同则rank[i]=rank[i-1],否则rank[i]=考生当前人次i。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

struct node{

	string id;

	int locNum,locRank,score;

}t;

bool cmp(node a,node b){

	if(a.score!=b.score) return a.score>b.score;

	else return a.id<b.id;

}

int main()

{

	int n,num,cnt=0;	//cnt统计到目前的考生总数 

	scanf("%d",&n);

	vector<node> d;

	for(int i=1;i<=n;i++){

		scanf("%d",&num);

		for(int j=0;j<num;j++){

			cnt++;

			cin>>t.id>>t.score;

			t.locNum=i;

			d.push_back(t);

		}

		sort(d.begin()+cnt-num,d.begin()+cnt,cmp);

		d[cnt-num].locRank=1;

		for(int j=2;j<=num;j++){

			if(d[cnt-num+j-1].score==d[cnt-num+j-2].score)

				d[cnt-num+j-1].locRank=d[cnt-num+j-2].locRank;

			else 

				d[cnt-num+j-1].locRank=j;

		}

	}

	sort(d.begin(),d.end(),cmp);

	cout<<cnt<<endl;

	int r=1;	//记录上一个排名 

	cout<<d[0].id<<" 1 "<<d[0].locNum<<" "<<d[0].locRank<<endl;

	for(int i=2;i<=cnt;i++){

		cout<<d[i-1].id;

		if(d[i-1].score!=d[i-2].score) 

			r=i;

		cout<<" "<<r<<" "<<d[i-1].locNum<<" "<<d[i-1].locRank<<endl;

	}

	return 0;

}
