A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 10^10^) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.
Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
Sample Input 1:
67 3
Sample Output 1:

484

2
Sample Input 2:
69 3
Sample Output 2:

1353

3
题意：给定一个正整数n（不超过10^10)和最大操作次数k，让你判断它是否是回文数，如果是输出该回文数和操作次数cnt，如果 不是则逆转n然后与n相加，检查结果数字是否回文，如果还不是继续操作知道达到最大步数k，最后输出k步以后的数字，和步数。
思路：写一个判断回文的函数和一个逆转并相加的函数，然后每次逆转都判断一次，最后输出即可。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

#include<algorithm>

using namespace std;

bool judge(string s){

	for(int i=0;i<s.size();i++){

		if(s[i]!=s[s.size()-1-i])

		return false;

	}

	return true;

}

string add(string s){

	string r=s,ans="";

	reverse(r.begin(),r.end());

	int carry=0;

	for(int i=s.size()-1;i>=0;i--){

		int t=s[i]-'0'+r[i]-'0'+carry;

		ans+=t%10+'0';

		carry=t/10;

	}

	if(carry) ans+='1';

	reverse(ans.begin(),ans.end());

	return ans;

}

int main()

{

	string s;

	int k,cnt=0;

	cin>>s>>k;

	for(int i=0;i<k&&!judge(s);i++){

		cnt++;

		s=add(s);

	}

	cout<<s<<endl<<cnt<<endl;

	return 0;

}
