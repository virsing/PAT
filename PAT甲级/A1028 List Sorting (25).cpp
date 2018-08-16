Excel can sort records according to any column. Now you are supposed to imitate this function.
Input
Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).
Output
For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
Sample Input 1

3 1

000007 James 85

000010 Amy 90

000001 Zoe 60
Sample Output 1

000001 Zoe 60

000007 James 85

000010 Amy 90
Sample Input 2

4 2

000007 James 85

000010 Amy 90

000001 Zoe 60

000002 James 98
Sample Output 2

000010 Amy 90

000002 James 98

000007 James 85

000001 Zoe 60
Sample Input 3

4 3

000007 James 85

000010 Amy 90

000001 Zoe 60

000002 James 90
Sample Output 3

000001 Zoe 60

000007 James 85

000002 James 90

000010 Amy 90
题意：给定n个学生，和序列编号k，让你按照第k列对学生进行排序。如果k=1，按id升序排列，k=2，按姓名非降序排列，k=3，按照成绩非降序排列，如果姓名或成绩相同，则按照id升序排列。
思路： 定义一个全局的k，在排序函数中对应k的值进行排列。注意使用string类型的id和name会导致最后一组数据超时，改为int型id，char[]型name，排序函数中由于姓名按照非降序排列，所以当姓名不同时，应该返回strcmp(a.name,b.name)<=0;
参考代码：

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<vector>

#include<iomanip>

using namespace std;

struct node{

	int id,grade;

	char name[9];

}t;

int n,k;

bool cmp(node a,node b){

	if(k==1) return a.id<b.id;

	else if(k==2){

		if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<=0;

		else return a.id<b.id;

	}else {

		if(a.grade!=b.grade) return a.grade<=b.grade;

		else return a.id<b.id;

	}

}

int main(){

	scanf("%d%d",&n,&k);

	vector<node> ans;

	for(int i=0;i<n;i++){

		scanf("%d %s %d",&t.id,&t.name,&t.grade);

		ans.push_back(t);

	}

	sort(ans.begin(),ans.end(),cmp);

	for(int i=0;i<n;i++){

		printf("%06d %s %d\n",ans[i].id,ans[i].name,ans[i].grade);

	}

	return 0;

}
