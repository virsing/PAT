Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.
Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.
Output Specification:
For each test case, simply print the maximum length in a line.
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
题意：给定一个字符串，让你找出其中最长的对称子串。
思路1：字符串中可能包含空格因此要使用getline(cin,string)，定义一个判断最长对称长度的函数，每次根据当前下标向两边拓展长度，分别进行奇对称和偶对称判断。最后输出最大值即可。初始下标从1开始。
参考代码：

#include<algorithm>

#include<iostream>

#include<string>

using namespace std;

int getMaxSymLength(string s,int k){

	int oddLength=1,evenLength=0;

	int i=k-1,j=k+1;

	while(i>=0&&j<s.size()&&s[i]==s[j]){

		i--;j++;

		oddLength+=2;

	}

	i=k-1,j=k;

	while(i>=0&&j<s.size()&&s[i]==s[j]){

		i--;j++;

		evenLength+=2;

	}

	return max(oddLength,evenLength);

}

int main()

{

	int maxLength=0,temp=0;

	string s;

	getline(cin,s);

	if(s.size()<2) cout<<s.size()<<endl;

	else{

		for(int i=1;i<s.size();i++)

		{

			temp=getMaxSymLength(s,i);

			maxLength=max(maxLength,temp);

		}

		cout<<maxLength<<endl;

	}

	return 0;

}
 思路2：动态规划解法，设数组dp[i][j]表示s[i]到s[j]是否是对称串。其数值只能是0或1.状态转移方程如下：
    1.dp[i][j]=dp[i+1][j-1]        若s[i]==s[j]
    2.dp[i][j]=0                      若s[i]!=s[j]
初始化：dp[i][i]=1，即长度为1的字串一定对称。如果s[i]==s[i+1]，dp[i][i+1]=1,，将长度为2的对称串标出。
然后按照字串长度L=3直到L=s.size()，分别进行迭代计算，这样当求较长的对称子串长度时，则可以利用较短的对称子串结果。例如长度为3的dp值求出后，再求长度为4的dp值时，则可以直接根据s[i]==s[j]是否成立，进行状态转移。
参考代码：

#include<string>

#include<iostream>

using namespace std;

const int maxn=1010;

int dp[maxn][maxn]={0};

int main()

{

	int maxLength=0;

	string s;

	getline(cin,s);

	for(int i=0;i<s.size();i++){

		dp[i][i]=1;

		maxLength=1;

		if(i<s.size()-1&&s[i]==s[i+1]){

			dp[i][i+1]=1;

			maxLength=2;

		}

	}

	for(int l=3;l<=s.size();l++)

		for(int i=0;i<=s.size()-l;i++){

			int j=i+l-1;

			if(s[i]==s[j]&&dp[i+1][j-1]==1){

				dp[i][j]=1;

				maxLength=l;

			}

		}

	cout<<maxLength<<endl;

	return 0;

}
