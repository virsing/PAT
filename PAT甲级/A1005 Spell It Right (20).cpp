Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).
Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345
Sample Output:
one five
题意：给定一个数字N（<=10^100),让你累加各位数字，然后以英语的形式输出结果。
思路：
1.把各位英语存放在数组中，然后直接使用。
参考代码：

#include<iostream>

#include<string>

using namespace std;

string english[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()

{

	string s;

	int ans=0;

	cin>>s;

	for(int i=0;i<s.size();i++)

	{

		ans+=s[i]-'0';

	}

	s=to_string(ans);

	for(int i=0;i<s.size();i++)

	{

		cout<<english[s[i]-'0'];

		if(i<s.size()-1) cout<<" ";

	}

	return 0;

}
