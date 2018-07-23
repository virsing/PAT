给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 10^5^)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。
接下来有N行，每行格式为：
Address Data Next
其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
输入样例：

00100 6 4

00000 4 99999

00100 1 12309

68237 6 -1

33218 3 00000

99999 5 68237

12309 2 33218
输出样例：

00000 4 33218

33218 3 12309

12309 2 00100

00100 1 99999

99999 5 68237

68237 6 -1
思路：
1.由于地址只有5位，不妨开个数组，第一次遍历直接以地址作为下标，存储链表结点。然后使用双端队列 每k个节点逆序输出一次。具体用法参考：双端队列deque用法介绍
2.注意k为0或1时链表按原顺序输出。另外输出第一个节点时注意特判，与后面格式不同。
参考代码：

#include<cstdio>

#include<deque>

using namespace std;

const int maxn=100010;

struct node{

	int addr,data,next;	//分别表示链表结点当前地址，数据，下一结点地址

}List[maxn],temp;

int main()

{

	int n,start,k,p,cnt=0;

	deque<node> q;

	scanf("%d%d%d",&start,&n,&k);

	for(int i=0;i<n;i++)	//这个循环存储所有结点

	{

		scanf("%d%d%d",&temp.addr,&temp.data,&temp.next);

		List[temp.addr]=temp;

	}

	p=start;

	bool flag=false;	//用来标记第一个输出的结点

	while(p!=-1)	//这个循环用来逆转并输出链表结点

	{

		cnt++;

		q.push_back(List[p]);

		p=List[p].next;

		if(k>1&&cnt%k==0){	//k小于2直接原顺序输出

			while(!q.empty())

			{

				node t=q.back();

				q.pop_back();

				if(!flag){

					printf("%05d %d",t.addr,t.data);

					flag=true;

				}else{

					printf(" %05d\n%05d %d",t.addr,t.addr,t.data);

				}

			}

		}

		

	}

	while(!q.empty())		//最后不足k个节点时或k小于2时直接原顺序输出

	{

		node t=q.front();

		q.pop_front();

		if(!flag){

			printf("%05d %d",t.addr,t.data);

			flag=true;

		}else{

			printf(" %05d\n%05d %d",t.addr,t.addr,t.data);

		}

	}

	printf(" -1\n");

	return 0;

}
优化：
1.直接使用reverse函数进行反转操作（头文件是algorithm）。
2.链表中存储的是地址。
参考代码：

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

const int maxn=100010;

int main()

{

	int n,st,k,sum=0,addr,data[maxn],next[maxn];

	vector<int> List;

	scanf("%d%d%d",&st,&n,&k);

	for(int i=0;i<n;i++)	

	{

		scanf("%d",&addr);

		scanf("%d %d",&data[addr],&next[addr]);

	}

	while(st!=-1){

		List.push_back(st);

		sum++;

		st=next[st];

		if(k>1&&sum%k==0)

			reverse(List.begin()+sum-k,List.begin()+sum);

	}

	for(int i=0;i<sum-1;i++)

	{

		printf("%05d %d %05d\n",List[i],data[List[i]],List[i+1]);

	}

        printf("%05d %d -1\n", List[sum - 1], data[List[sum - 1]]);

	return 0;

}
