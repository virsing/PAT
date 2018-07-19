At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.
Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
Sample Input:

3

CS301111 15:30:28 17:00:10

SC3021234 08:00:00 11:25:25

CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
题意：给定一组记录，让你找出这组记录中第一个到来打开锁的人，以及最后一个离开并锁上门的人。
思路：
1.把时间统一成秒，方便比较大小。

#include<cstdio>

#include<iostream>

#include<string>

using namespace std;

const int Max=(1<<31)-2;

struct rec{

	string id;

	int come,leave;

}firstIn,lastOut,t; //分别标记第一个到来的人，最后一个离开的人，临时变量

int main()

{

	int m,hh,mm,ss;

	firstIn.come=Max;	//初始化时间为无限大

	lastOut.leave=0;	//初始化为0

	scanf("%d",&m);

	for(int i=0;i<m;i++)

	{

		cin>>t.id;

		scanf("%d:%d:%d",&hh,&mm,&ss);

		t.come=hh*3600+mm*60+ss;

		scanf("%d:%d:%d",&hh,&mm,&ss);

		t.leave=hh*3600+mm*60+ss;

		if(t.come<firstIn.come) firstIn=t;

		if(t.leave>lastOut.leave) lastOut=t;

	}

	cout<<firstIn.id<<" "<<lastOut.id<<endl;

	return 0;

}
