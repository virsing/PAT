宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
现给出一批考生的德才分数，请根据司马光的理论给出录取排名。
输入格式：
输入第1行给出3个正整数，分别为：N（<=10^5^），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0,100]内的整数。数字间以空格分隔。
输出格式：
输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
输入样例：

14 60 80

10000001 64 90

10000002 90 60

10000011 85 80

10000003 85 80

10000004 80 85

10000005 82 77

10000006 83 76

10000007 90 78

10000008 75 79

10000009 59 90

10000010 88 45

10000012 80 100

10000013 90 99

10000014 66 60
输出样例：

12

10000013 90 99

10000012 80 100

10000003 85 80

10000011 85 80

10000004 80 85

10000007 90 78

10000006 83 76

10000005 82 77

10000002 90 60

10000014 66 60

10000008 75 79

10000001 64 90
作者: CHEN, Li
单位: PAT联盟
时间限制: 200ms
内存限制: 64MB
代码长度限制: 16KB

思路：


1.定义一个结构体存储学号，德分和才分，然后可以使用set容器重载运算符，进行自动排序。
注意：set容器重载运算符写法。

struct node{

	int s1,s2,id;

	//string id;

	bool friend operator<(node a,node b){

		if(a.s1+a.s2>b.s1+b.s2) return true;

		if(a.s1+a.s2==b.s1+b.s2&&a.s1>b.s1) return true;

		if(a.s1+a.s2==b.s1+b.s2&&a.s1==b.s1&&a.id<b.id) return true;

		return false;        //这句必须有，否则会出错。

	}

}t;
参考代码：

#include<cstdio>

#include<set>

using namespace std;

struct node{

	int s1,s2,id;

	//string id;

	bool friend operator<(node a,node b){

		if(a.s1+a.s2>b.s1+b.s2) return true;

		if(a.s1+a.s2==b.s1+b.s2&&a.s1>b.s1) return true;

		if(a.s1+a.s2==b.s1+b.s2&&a.s1==b.s1&&a.id<b.id) return true;

		return false;

	}

}t;

set<node> v1,v2,v3,v4;

int main()

{

	int n,L,H,cnt=0;

	scanf("%d%d%d",&n,&L,&H);

	for(int i=0;i<n;i++)

	{

		scanf("%d%d%d",&t.id,&t.s1,&t.s2);

		if(t.s1<L||t.s2<L) continue;

		else if(t.s1>=H&&t.s2>=H)

			v1.insert(t);

		else if(t.s1>=H)

			v2.insert(t);

		else if(t.s1<H&&t.s2<H&&t.s1>=t.s2)

			v3.insert(t);

		else v4.insert(t);

		cnt++;

	}

	printf("%d\n",cnt);

	set<node>::iterator it;

	for(it=v1.begin();it!=v1.end();it++)	printf("%08d %d %d\n",it->id,it->s1,it->s2);

	for(it=v2.begin();it!=v2.end();it++)	printf("%08d %d %d\n",it->id,it->s1,it->s2);

	for(it=v3.begin();it!=v3.end();it++)	printf("%08d %d %d\n",it->id,it->s1,it->s2);

	for(it=v4.begin();it!=v4.end();it++)	printf("%08d %d %d\n",it->id,it->s1,it->s2);

	return 0;

}
