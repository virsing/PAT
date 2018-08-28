Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given { 32, 321, 3214, 0229, 87 }, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
Input Specification:
Each input file contains one test case. Each case gives a positive integer N (≤10​4​​) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the smallest number in one line. Notice that the first digit must not be zero.
Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287
题意：给定n个非负整数，让你把他组合成一个最小数，
思路：基于贪心思想，定义比较函数cmp，将这n个数字按照从小到大的组合方式排序，注意不是大小顺序！

bool cmp(string a,string b){

	return a+b<b+a;

}
 然后去掉最终结果的前导零（如果结果为全零记得保留一位）输出。另外，注意输入时不能直接去掉每个数字前面的零，例如输入2 01 001，最终结果是101，而如果当成整数输入则得到两个1，输出11，这是不符合题意的，需要把每个单独的数字前面的零加入比较。
参考代码：

#include<cstdio>

#include<iostream>

#include<algorithm>

#include<vector>

#include<string>

using namespace std;

bool cmp(string a,string b){

	return a+b<b+a;

}

int main()

{

	int n;

	string s,ans="";

	cin>>n;

	vector<string> d;

	for(int i=0;i<n;i++) {

		cin>>s;

		d.push_back(s);

	}

	sort(d.begin(),d.end(),cmp);

	for(int i=0;i<d.size();i++){

		ans+=d[i];

	}

	while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);

	cout<<ans<<endl;

	return 0;

}
