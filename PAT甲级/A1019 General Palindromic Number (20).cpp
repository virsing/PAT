A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard ‎符号‎ with k+1 digits a~i~ as the sum of (a~i~b^i^) for i from 0 to k. Here, as usual, 0 <= a~i~ < b for all i and a~k~ is non-zero. Then N is palindromic if and only if a~i~ = a~k-i~ for all i. Zero is written 0 in any base and is also palindromic by definition.
Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.
Input Specification:
Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9^ is the decimal number and 2 <= b <= 10^9^ is the base. The numbers are separated by a space.
Output Specification:
For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "a~k~ a~k-1~ ... a~0~". Notice that there must be no extra space at the end of output.
Sample Input 1:
27 2
Sample Output 1:

Yes

1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:

No

4 4 1
题意：给定一个十进制数n，和进制b，问你n在b进制下是否回文，如果是输出Yes，否则输出No，并输出b进制下的n。
思路：注意进制b范围时2<=b<=10^9,所以要用vector<int> 来存储转换后的结果，再判断回文。
参考代码：

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

vector<int> itoa(int n,int b)

{

	vector<int> ans;

	do{

		ans.push_back(n%b);

		n/=b;

	}while(n);

	reverse(ans.begin(),ans.end());

	return ans;

}

int main()

{

	vector<int> ans;

	int n,b;

	cin>>n>>b;

	ans=itoa(n,b);

	bool flag=true;

	for(int i=0;i<ans.size()&&flag;i++){

		if(ans[i]!=ans[ans.size()-1-i]) 

			flag=false;

	}

	if(flag) cout<<"Yes\n"<<ans[0];

	else cout<<"No\n"<<ans[0];

	for(int i=1;i<ans.size();i++){

		cout<<" "<<ans[i];

	}

	cout<<endl;

	return 0;

}
