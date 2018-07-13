本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A= B * Q + R成立。
输入格式：
输入在1行中依次给出A和B，中间以1空格分隔。
输出格式：
在1行中依次输出Q和R，中间以1空格分隔。
输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.本题是大整数除法运算，可以使用字符串读取大整数，再逐位处理。
2.注意，输入大整数为0时，输出商也为0.如果商的高位部分是‘0’例如，0017366，要处理掉前缀0，再输出。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

using namespace std;

int main()

{

	string A,Q="";

	int i=0,B,r=0;

	cin>>A>>B;

	while(i<A.size())

	{

		r=r*10+A[i++]-'0';

		if(r>=B)

		{ Q+=(r/B+'0');r%=B;}

		else Q+='0';

	}

	for(i=0;i<Q.size()&&Q[i]=='0';i++);

	Q=Q.substr(i);

	if(Q.size()==0) cout<<"0 "<<r<<endl;

	else cout<<Q<<" "<<r<<endl;

	return 0;

}
