This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.
Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade​F​​−grade​M​​. If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.
Sample Input 1:

3

Joe M Math990112 89

Mike M CS991301 100

Mary F EE990830 95
Sample Output 1:

Mary EE990830

Joe Math990112

6
Sample Input 2:

1

Jean M AA980920 60
Sample Output 2:

Absent

Jean AA980920

NA
题意：给定一组n个学生的记录，让你找出其中女生中最高成绩那条记录和男生最低成绩的那条记录，按格式输出，如果两个都存在输出其成绩之差，否则输出NA 。
思路：定义结构体存储整条记录，再定义一个Fmax存储女生最高成绩，Mmin存储男生最低成绩，最后输出。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

using namespace std;

struct node{

	string name,id;

	char gender;

	int grade;

}Fmax,Mmin,t;

int main()

{

	int n;

	bool flag1=false,flag2=false;

	cin>>n;

	Fmax.grade=-1;

	Mmin.grade=101;

	for(int i=0;i<n;i++){

		cin>>t.name>>t.gender>>t.id>>t.grade;

		if(t.gender=='M'&&t.grade<Mmin.grade){

			Mmin=t;

			flag1=true;

		}else if(t.gender=='F'&&t.grade>Fmax.grade){

			Fmax=t;

			flag2=true;

		}

	}

	if(flag2) cout<<Fmax.name<<" "<<Fmax.id<<endl;

	else cout<<"Absent\n";

	if(flag1) cout<<Mmin.name<<" "<<Mmin.id<<endl;

	else cout<<"Absent\n";

	if(flag1&&flag2) cout<<Fmax.grade-Mmin.grade<<endl;

	else cout<<"NA\n";

	return 0;

}
 
