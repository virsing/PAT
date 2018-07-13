给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
例如，我们从6767开始，将得到
7766 - 6677 = 1089\9810 - 0189 = 9621\9621 - 1269 = 8352\8532 - 2358 = 6174\7641 - 1467 = 6174\... ...
现给定任意4位正整数，请编写程序演示到达黑洞的过程。
输入格式：
输入给出一个(0, 10000)区间内的正整数N。
输出格式：
如果N的4位数字全相等，则在一行内输出“N - N =0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
输入样例1：
6767
输出样例1：

7766 - 6677 = 1089

9810 - 0189 = 9621

9621 - 1269 = 8352

8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.题目要求按四位数字的格式输出，所以按照字符串读入和处理比较方便。写两个函数一个string转int，一个int转string。转换   函数内部使用stringstream处理，具体用法参考：点击打开链接
2.转化成整型做差后，注意补0，使用s.insert(0,4-s.length(),'0')进行补零操作。
3.特殊情况下，如果输入6174，也要进行一次操作，所以使用do{}while（）语句先执行一次，比较方便。
4.注意题目数据范围（0，10000），输入可能不足4位，需要先进行一次补零操作。否则有几个case过不了。
参考代码：

#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

#include<sstream>

using namespace std;

int sti(string s)

{

	stringstream stream;

	int ans;

	stream<<s;

	stream>>ans;

	return ans;

}

string its(int d)

{

	stringstream stream;

	string ans;

	stream<<d;

	stream>>ans;

	return ans;

}

bool cmp(char a,char b){ return a>b;}

int main()

{

	string s,t,ans;

	cin>>s;

	s.insert(0,4-s.length(),'0');

	do{

		t=s;

		sort(s.begin(),s.end(),cmp);

		sort(t.begin(),t.end());

		cout<<s<<" - "<<t<<" = ";

		s=its(sti(s)-sti(t));

		s.insert(0,4-s.length(),'0');

		cout<<s<<endl;

	}while(s!="6174"&&s!="0000");

	return 0;

}
