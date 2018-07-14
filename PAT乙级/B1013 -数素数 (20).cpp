令P~i~表示第i个素数。现任给两个正整数M <= N <=10^4^，请输出P~M~到P~N~的所有素数。
输入格式：
输入在一行中给出M和N，其间以空格分隔。
输出格式：
输出从P~M~到P~N~的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：

11 13 17 19 23 29 31 37 41 43

47 53 59 61 67 71 73 79 83 89

97 101 103


思路：


1.写一个素数判断函数，然后逐个数字判断。
2.设置两个计数器cnt1用来统计素数个数，cnt2用来控制输出格式。
参考代码：

#include<cstdio>

#include<cmath>

using namespace std;

bool judge(int n)

{

	if(n<=1) return false;

	int sqrtN=sqrt(1.0*n);

	for(int i=2;i<=sqrtN;i++)

	{

		if(n%i==0) return false;

	}

	return true;

}

int main()

{

	int n,m,cnt1=0,cnt2=0;

	scanf("%d%d",&m,&n);

	for(int i=2;cnt1<n;i++)

	{

		if(judge(i)){

			cnt1++;

			if(cnt1>=m&&cnt1<=n){

				cnt2++;

				printf("%d",i);

				if(cnt2%10==0) 

				{

					printf("\n");

					cnt2=0;

				}else if(cnt1<n){

					printf(" ");

				}

			}

		}

	}

	return 0;

}
优化：精简变量和流程
参考代码：

#include<cstdio>

#include<cmath>

using namespace std;

bool judge(int n)

{

	if(n<=1) return false;

	int sqrtN=sqrt(1.0*n);

	for(int i=2;i<=sqrtN;i++)

	{

		if(n%i==0) return false;

	}

	return true;

}

int main()

{

	int n,m,cnt1=0,cnt2=0;

	scanf("%d%d",&m,&n);

	for(int i=2;cnt1<n;i++)

	{

		if(!judge(i)) continue;

		cnt1++;

		if(cnt1<m||cnt1>n) continue;

		printf("%d",i);

		if((cnt1-m+1)%10==0) 	printf("\n");

		else if(cnt1<n)

			printf(" ");

	}

	return 0;

}
