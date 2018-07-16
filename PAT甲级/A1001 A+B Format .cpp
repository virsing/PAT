Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input
-1000000 9
Sample Output
-999,991
 
题意：给定两个数a和b，其中 -1000000 <= a, b <= 1000000，让你把a+b按标准格式输出，如样例所示。
思路：
1.将a+b的和转成字符串，然后把结果字符串按照每三个字符就添加一个逗号的顺序存在另一个字符串中即可。
2。注意如果是负数负号不能单独被逗号隔开。
参考代码：

#include<cstdio>

#include<iostream>

#include<string>

using namespace std;

int main() {

	int a,b,cnt=0;

	string res,ans="";

	scanf("%d%d",&a,&b);

	a=a+b;

	res=to_string(a);

	for(int i=res.size()-1;i>=0;--i){

		if(cnt!=0&&cnt%3==0&&res[i]!='-')

			ans+=",";

		ans+=res[i];

		++cnt;

	}

	reverse(ans.begin(),ans.end());

	cout<<ans<<endl;

	return 0;

}
