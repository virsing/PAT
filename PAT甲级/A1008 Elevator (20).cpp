The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.
Output Specification:
For each test case, print the total time on a single line.
Sample Input:
3 2 3 1
Sample Output:
41
题意：给定一个电梯的调度序列，上升一层需要6s，下降一层需要4s，每到一层需要停留5s，让你求调度完成耗费的总时间，假定初始状态电梯在0th层。
参考代码：

#include<cstdio>

#include<cmath>

using namespace std;

int main()

{

	int n,cur=0,next,total=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++)

	{

		scanf("%d",&next);

		if(next>=cur){

			total+=(next-cur)*6+5;

			cur=next;

		}else{

			total+=abs(next-cur)*4+5;

			cur=next;

		}

	}

	printf("%d\n",total);

}
