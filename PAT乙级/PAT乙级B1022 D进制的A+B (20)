1022 D进制的A+B (20)（20 分）
输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <=10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：
1.由于给定的进制不大于10，所以直接使用一个while循环求出对应的结果，保存在字符串中。

2.注意如果输入两个数都是0，进行特殊处理。
参考代码：

#include<cstdio>

#include<iostream>

#include<string>

using namespace std;

const int maxn=100;

 

int main() {

	int A,B,D,res;

	string ans="";

	scanf("%d%d%d",&A,&B,&D);

	res=A+B;

	while(res!=0){

		int t=res%D;

		res/=D;

		ans+=t+'0';

	}

	if(ans.size()==0) cout<<0<<endl;

	else{

		reverse(ans.begin(),ans.end());

		cout<<ans<<endl;

	}

	return 0;

}
