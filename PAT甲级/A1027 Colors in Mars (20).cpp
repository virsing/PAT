People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.
Input
Each input file contains one test case which occupies a line containing the three decimal color values.
Output
For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.
Sample Input
15 43 71
Sample Output
#123456
题意：给定一个颜色的RGB值，让你把它转成对应的13进制数值并输出。
思路：直接转换然后输出。
参考代码： 

#include<cstdio>

#include<string>

#include<iostream>

#include<algorithm>

#include<iomanip>

using namespace std;

string convert(int a){

	string ans="";

	do{

		int t=a%13;

		if(t>=10) ans+='A'+t-10;

		else ans+=t+'0';

		a/=13;

	} while(a);

	reverse(ans.begin(),ans.end());

	return ans;

}

int main()

{

	int color[3];

	string c[3];

	for(int i=0;i<3;i++){

		scanf("%d",&color[i]);

		c[i]=convert(color[i]);

	}

	cout<<"#";

	for(int i=0;i<3;i++){

		cout<<setw(2)<<setfill('0')<<c[i];

	}

	cout<<endl;

	return 0; 

}
