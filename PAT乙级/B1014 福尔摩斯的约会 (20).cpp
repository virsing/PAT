大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE2984akDfkkkkggEdsb s&hgsfdkd&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
输出格式：
在一行中输出约会的时间，格式为“DAYHH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
输入样例：

3485djDkxh4hhGE 

2984akDfkkkkggEdsb 

s&hgsfdk 

d&Hyscvnm
输出样例：
THU 14:04
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.模拟题按题意要求输出即可，注意，日期是七天，对应字母范围是A-G，小时对应的是0-9以及大写字母A-N。

参考代码：

#include<cstdio>

#include<string>

#include<iostream>

#include<map>

using namespace std;

string day[8]={"MON ","TUE ","WED ","THU ","FRI ","SAT ","SUN "};

map<string,string> mp;

int main()

{

	string s1,s2,s3,s4;

	cin>>s1>>s2>>s3>>s4;

	bool flag=false;

	for(int i=0;i<s1.size()&&i<s2.size();i++)

	{

		if(s1[i]>='A'&&s1[i]<='G'&&s1[i]==s2[i]&&!flag)

		{

			cout<<day[s1[i]-'A'];

			flag=true;

		}else if(flag&&s1[i]==s2[i]&&((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='A'&&s1[i]<='N'))){

			if(s1[i]>='0'&&s1[i]<='9')

				cout<<"0"<<s1[i]-'0'<<":";

			else if(s1[i]>='A'&&s1[i]<='N')

				cout<<10+s1[i]-'A'<<":";

			break;

		}

	}

	for(int i=0;i<s3.size()&&i<s4.size();i++)

	{

		if(s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z')))

		{

			printf("%02d\n",i);

			break;

		}

	}

	return 0;

}
