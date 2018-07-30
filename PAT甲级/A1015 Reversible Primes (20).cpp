A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.
Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
Sample Input:

73 10

23 2

23 10

-2
Sample Output:

Yes

Yes

No
题意：给定一个正整数n，和一个进制d，如果n在10进制下是素数,并且将其d进制逆转之后再转换成10进制数,仍然是素数，则输出Yes，否则输出No。
思路：自己编写两个进制转换函数，以及素数判断函数按要求操作即可。
参考代码：

#include<cstdio>

#include<iostream>

#include<string>

#include<cmath>

using namespace std;

bool judge(int n)

{

	if(n<=1) return false;

	int sqrtN=(int)sqrt(1.0*n);

	for(int i=2;i<=sqrtN;i++)

	{

		if(n%i==0)

			return false;

	}

	return true;

}

string intToA(int n,int radix)

{

	string ans="";

	do{

		ans+=n%radix+'0';	

		n/=radix;

	}while(n!=0);	//使用do{}while（）以防止输入为0的情况

	return ans;	//此时的字符串正好存储逆置后的结果

}

int main()

{

	int n,radix;

	while(cin>>n,n>=0)

	{

		cin>>radix;

		string s;

		if(!judge(n)) {

			printf("No\n");

			continue;

		}

		s=intToA(n,radix);	

		n=0;

		for(int i=0;i<s.size();i++)

		{

			n=n*radix+s[i]-'0';

		}

		if(judge(n)) printf("Yes\n");

		else printf("No\n");

	}

	return 0;

}
