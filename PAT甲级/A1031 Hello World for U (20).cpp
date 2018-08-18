Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d

e  l

l  r

lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n~1~ characters, then left to right along the bottom line with n~2~ characters, and finally bottom-up along the vertical line with n~3~ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n~1~ = n~3~ = max { k| k <= n~2~ for all 3 <= n~2~ <= N } with n~1~
n~2~ + n~3~ - 2 = N.
Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.
Output Specification:
For each test case, print the input string in the shape of U as specified in the description.
Sample Input:
helloworld!
Sample Output:

h   !

e   d

l   l

lowor
题意：给定一个字符串，让你打印成‘u'型。 要求如下：1.n1==n3。 2.n2>=n1。 3.n1+n2+n3=N+2。
思路：依题意有2*n1+n2=N+2===>n2=N+2-2*n1.
           并且n2>=n1可得:
           n1<=(N+2)/3;
           n2=N+2-2*n1;
将字符按要求存储在二维数组中然后打印即可，注意二维数组一定要初始化为空格！！！！否则会出错。
参考代码：

#include<cstdio>

#include<string>

#include<cstring>

#include<iostream>

using namespace std;

char ans[80][80];

int main()

{

	int n,n1,n2,k=0;

	memset(ans,' ',sizeof(ans));

	string s;

	cin>>s;

	n=s.size();

	n1=(n+2)/3;

	n2=n+2-2*n1;

	for(int i=0;i<n1-1;i++) ans[i][0]=s[k++];

	for(int j=0;j<n2;j++) ans[n1-1][j]=s[k++];

	for(int i=n1-2;i>=0;i--) ans[i][n2-1]=s[k++];

	for(int i=0;i<n1;i++){

		for(int j=0;j<n2;j++){

			printf("%c",ans[i][j]);

		}

		printf("\n");

	}

	return 0;

}
