给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9


思路：


1.定义5个变量分别存储a1-a5的结果，再定义5个bool型变量分别标记是否有数据输出，按要求处理即可。
参考代码：

#include<cstdio>

int main()

{

	int n,t,cnt1=0,cnt2=0,a1=0,a2=0,a3=0,a5=0;  //cnt1用来对a2交错求和，cnt2是计数器，用来记录a4的个数

	double a4=0;

	bool f1=false,f2=false,f3=false,f4=false,f5=false;

	scanf("%d",&n);

	for(int i=0;i<n;i++)

	{

		scanf("%d",&t);

		if(t%5==0&&t%2==0) {f1=true;a1+=t;}

		else if(t%5==1) 

		{

				f2=true;

				cnt1++;

				if(cnt1%2==1) a2+=t;

				else a2-=t;

		}else if(t%5==2) {

			f3=true;

			a3++;

		}

		else if(t%5==3){

			f4=true;

			cnt2++;

			a4+=t;

		}else if(t%5==4){

			f5=true;

			if(t>a5) a5=t;

		}

	}

	if(f1==false) printf("N ");

	else printf("%d ",a1);

	if(f2==false) printf("N ");

	else printf("%d ",a2);

	if(f3==false) printf("N ");

	else printf("%d ",a3);

	if(f4==false) printf("N ");

	else printf("%.1f ",a4/cnt2);

	if(f5==false) printf("N\n");

	else printf("%d\n",a5);

	return 0;

}
