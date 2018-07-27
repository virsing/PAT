To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A

310101     98 85 88 90

310102     70 95 88 84

310103     82 87 94 88

310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.
Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.
Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".
Sample Input

5 6

310101 98 85 88

310102 70 95 88

310103 82 87 94

310104 91 91 91

310105 85 90 90

310101

310102

310103

310104

310105

999999
Sample Output

1 C

1 M

1 E

1 A

3 A

N/A
题意：给定n学生的四门成绩，然后给出m位待查寻排名的同学的id，让你输出其最好的排名以及科目缩写 。如果某位同学的排名有并列按A>C>M>E的顺序输出其最高排名。
思路：
1.定义两个结构体，一个Grade，用于成绩排序，一个Rank用于统计排名。

struct Grade{

	int id,grade[4];

}t;

struct Rank{

	int rank[4];

};
2.注意：在成绩排序时，如果两个人成绩相同，则其排名也是相同的。如98，95，95，90对应排名为1，2，2，4.
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

#include<map>

using namespace std;

int k=0;

char name[4]={'A','C','M','E'};

struct Grade{

	int id,grade[4];

}t;

struct Rank{

	int rank[4];

};

bool cmp(Grade a,Grade b)

{

	if(a.grade[k]!=b.grade[k]) return a.grade[k]>b.grade[k];

	else return a.id<b.id;

	}

map<int,Rank> mp;

int main()

{

	int n,m,id;

	scanf("%d%d",&n,&m);

	vector<Grade> vec(n);

	for(int i=0;i<n;i++)

	{

		scanf("%d%d%d%d",&t.id,&t.grade[1],&t.grade[2],&t.grade[3]);	

		t.grade[0]=(t.grade[1]+t.grade[2]+t.grade[3])/3;

		vec[i]=t;

	}

	for( k=0;k<4;k++)

	{

		sort(vec.begin(),vec.end(),cmp);

		for(int i=0;i<n;i++)	//完成排名统计工作

		{

			if(i==0){

				mp[vec[i].id].rank[k]=1;

			}else if(vec[i].grade[k]==vec[i-1].grade[k]){

				mp[vec[i].id].rank[k]=mp[vec[i-1].id].rank[k];

			}else mp[vec[i].id].rank[k]=i+1;

		}

	}

	for(int i=0;i<m;i++)

	{

		scanf("%d",&id);

		if(mp.find(id)!=mp.end()){	//学号存在，则输出其排名

			int mn=0;

			for(int j=1;j<4;j++)	//寻找最好排名

			{

				if(mp[id].rank[mn]>mp[id].rank[j])

					mn=j;

			}

			printf("%d %c\n",mp[id].rank[mn],name[mn]);

		}else printf("N/A\n");

	}

	return 0;

}
