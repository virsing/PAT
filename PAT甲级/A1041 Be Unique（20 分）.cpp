Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1,10​4​​]. The first one who bets on a unique number wins. For example, if there are 7 people betting on { 5 31 5 88 67 88 17 }, then the second one who bets on 31 wins.
Input Specification:
Each input file contains one test case. Each case contains a line which begins with a positive integer N (≤10​5​​) and then followed by N bets. The numbers are separated by a space.
Output Specification:
For each test case, print the winning number in a line. If there is no winner, print None instead.
Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
题意：给定n个数，让你找出其中第一个独一无二的数字（即第一个没有重复出现过的数字）输出， 如果没有则输出None。
思路：使用哈希表标记每个数字出现的次数，最后再顺序找出第一个哈希值为1的数字输出。
参考代码：

#include<cstdio>

#include<vector>

using namespace std;

int ht[10010];

int main()

{

	int n,t;

	scanf("%d",&n);

	vector<int> v;

	for(int i=0;i<n;i++){

		scanf("%d",&t);

		ht[t]++;

		v.push_back(t);

	}

	bool flag=false;

	for(int i=0;i<v.size()&&!flag;i++){

		if(ht[v[i]]==1){

			printf("%d\n",v[i]);

			flag=true;

		}	

	}

	if(!flag) printf("None\n");

	return 0;

}
