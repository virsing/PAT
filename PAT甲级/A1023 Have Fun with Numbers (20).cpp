Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
Input Specification:
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
Sample Input:
1234567899
Sample Output:

Yes

2469135798
题意：给定一个不超过20位的正整数n，让你把n乘以2，然后判断2倍的n是否为原来n的另一种排列组合（0-9每个数字出现的次数相同），如果是输出Yes，否则输出No，然后第二行输出2倍的n。
思路：大整数加法，使用字符串存储n，然后使用哈希表ht统计n每个数字的出现次数，最后如果2倍n的对应ht全部为0则说明n和2n是同一组数字的不同排列组合。最后别忘了加进位carry！
参考代码：

#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

int ht[10]={0};

int main()

{

	string str,ans="";

	int carry=0;	//标记进位

	bool flag=true;	//标记是否满足特性 

	cin>>str;

	for(int i=str.size()-1;i>=0;i--){

		int t=str[i]-'0';

		ht[t]++;

		t=2*t+carry;

		carry=t/10;

		ans+=t%10+'0';

		ht[t%10]--;

	}

	if(carry) {

		ans+=carry+'0';

		ht[1]--;

	}

	reverse(ans.begin(),ans.end());

	for(int i=0;i<10&&flag;i++) {

		if(ht[i]!=0)

			flag=false;

	}

	flag==true?printf("Yes\n"):printf("No\n"); 

	cout<<ans<<endl;

	return 0;

}
