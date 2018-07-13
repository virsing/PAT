大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：

10

C J

J B

C B

B B

B C

C C

C B

J B

B C

J J
输出样例：

5 3 2

2 3 5

B B
作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.设置两个数组wa[3],wb[3]分别表示甲乙各自使用什么手势获胜，在设置ta，tb，la，lb表示各自的平局数和负数。
2.注意，使用字符读入时需要吸收掉换行符，可以使用getchar()；另外，全局变量如在局部区域重新定义，会被局部覆盖导致数据出错。如下：

[cpp] view plain copy


 
<code class="language-cpp">int k1=0;  
    for(int i=0;i<3;i++)   
        {  
            if(wa[i]>wa[k1]) k1=i;  
            if(wb[i]>wb[k2]) k2=i;  
    }</code>  
退出循环后，k1==0，因为局部重新定义了，导致数据无效。
参考代码：

#include<cstdio>

#include<iostream>

using namespace std;

int n,k1=0,k2=0,wa[3],wb[3],ta=0,tb=0,la=0,lb=0;

char str[3]={'B','C','J'};

int main()

{

	char t1,t2;

	scanf("%d\n",&n);

	for(int i=0;i<n;i++)

	{

		scanf("%c %c",&t1,&t2);getchar();

		if(t1=='C'&&t2=='J')	{wa[1]++;lb++;}

		else if(t1=='B'&&t2=='C')	{wa[0]++;lb++;}

		else if(t1=='J'&&t2=='B')	{wa[2]++;lb++;}

		else if(t2=='C'&&t1=='J')	{wb[1]++;la++;}

		else if(t2=='B'&&t1=='C')	{wb[0]++;la++;}

		else if(t2=='J'&&t1=='B')	{wb[2]++;la++;}

		else	{ta++;tb++;}

	}

	cout<<wa[0]+wa[1]+wa[2]<<" "<<ta<<" "<<la<<endl;

	cout<<wb[0]+wb[1]+wb[2]<<" "<<tb<<" "<<lb<<endl;

	for(int i=0;i<3;i++)	

		{

			if(wa[i]>wa[k1]) k1=i;

			if(wb[i]>wb[k2]) k2=i;

	}

	printf("%c %c\n",str[k1],str[k2]);

	return 0;

}
