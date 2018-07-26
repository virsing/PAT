Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.
Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.
Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
题意：给定四个正整数， N1 N2 tag radix，问你能否找到一个进制使得N1和N2相等。其中一个数进制已知，tag==1 N1为radix进制，tag==2，N2为radix进制。如果能找到输出进制，如果不能输出Impossible.
思路：
1首先将已知进制的数（假设为N1，如果时N2，则把两数交换一下即可），转成10进制方便比较，然后再把另一个数N2，使用二分法逐个进行进制转换成10进制，与N1比较，（注意：题目默认已知数转成10进制后不会溢出，虽然没有说明），但N2在进制转换过程中可能会溢出，此时说明进制太大。
2.写一个任意进制转10进制的函数toD（），再写一个二分查找进制数的函数findRadix（），再写一个查找进制下界的函数findMinR（）。
3.注意题目中数据要使用long long型，否则会溢出，因此所有数据标注为long long，别搞错了。另外，虽然题中所给数在0-9，a-z之间，但进制可能会超过36，非常大，只是在表示时只是用这些数表示，所以进制上界是N2和下界中的较大者。
参考代码：

#include<cstdio>

#include<cmath>

#include<iostream>

#include<string>

using namespace std;

long long toD(string n,long long radix){		//任意进制数转为10进制

	long long ans=0;

	for(int i=0;i<n.size();i++)

	{

		if(n[i]>='0'&&n[i]<='9')

			ans=ans*radix+n[i]-'0';

		else{

			ans=ans*radix+n[i]-'a'+10;

		}

	}

	return ans;

}

long long findRadix(long long n,string n2)	//注意输入变量为长整型！

{

	int findMinR(string n);

	long long mid,left,right;

	left=findMinR(n2);	//确定进制下界

	right=max(left,n);	//确定进制上界

	while(left<=right){

		mid=(left+right)/2;

		long long t=toD(n2,mid);	

		if(t==n) return mid;

		else if(t>n||t<0) right=mid-1;

		else left=mid+1;

	}

	return -1;

}

int findMinR(string n)		//找进制下界函数

{

	char t='0';

	for(int i=0;i<n.size();i++)

	{

		if(n[i]>t) t=n[i];

	}

	if(t>='0'&&t<='9') return t-'0'+1;

	else return t-'a'+11;

}

int main()

{

	string n1,n2;

	int tag,radix;

	long long ans;

	cin>>n1>>n2>>tag>>radix;

	if(tag==2) swap(n1,n2);

	ans=findRadix(toD(n1,radix),n2);

	if(ans==-1) printf("Impossible\n");

	else printf("%d\n",ans);

	return 0;

}
