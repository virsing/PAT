Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤40,000), the number of students who look for their course lists, and K (≤2,500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students N​i​​ (≤200) are given in a line. Then in the next line, N​i​​ student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.
Output Specification:
For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.
Sample Input:

11 5

4 7

BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1

1 4

ANN0 BOB5 JAY9 LOR6

2 7

ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6

3 1

BOB5

5 9

AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1

ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:

ZOE1 2 4 5

ANN0 3 1 2 5

BOB5 5 1 2 3 4 5

JOE4 1 2

JAY9 4 1 2 4 5

FRA8 3 2 4 5

DON2 2 4 5

AMY7 1 5

KAT3 3 2 4 5

LOR6 4 1 2 4 5

NON9 0
题意：给定K门课程（编号1--K）以及每门课程的选修名单，然后给n个欲查询学生名单 ，让你按输入顺序输出每个查询的学生的选课编号。
思路：直观思路是使用map和set将姓名和其选课编号对应起来，但会超时，因此使用vector<int>型数组，将所有学生姓名转换成对应下标再将选课编号push进去，最后排序输出。
注意：笔者刚开始以为为了完成全映射例如区分3和A3，AAA3，应该在getid函数中对应加一，但由于姓名限制一定是四位，所以这一步多虑了，无需进行加一，否则sort函数会报错！

int getid(char* name){

	int id=0;

	for(int i=0;i<3;i++){

		id=id*26+name[i]-'A'+1;    //这里+1，要不然3和A3就对应相同了

	}

	id=id*10+name[3]-'0';

	return id;

}
参考代码：

#include<algorithm>

#include<vector>

#include<cstdio>

using namespace std;

const int maxn=26*26*26*10+10;

vector<int> v[maxn];

int getid(char* name){

	int id=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+name[3]-'0';

	return id;

}

int main()

{

	int n,k,idx,num;

	char name[5];

	scanf("%d%d",&n,&k);

	for(int i=0;i<k;i++){

		scanf("%d%d",&idx,&num);

		for(int j=0;j<num;j++){

			scanf("%s",&name);

			int id=getid(name);

			v[id].push_back(idx);

		}

	}

	for(int i=0;i<n;i++){

		scanf("%s",&name);

		int id=getid(name);

		sort(v[id].begin(),v[id].end());

		printf("%s %d",name,v[id].size());

		for(int j=0;j<v[id].size();j++)

			printf(" %d",v[id][j]);

		printf("\n");

	}

	return 0;

}
