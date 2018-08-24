One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
Sample Input 1:

8 59

AAA BBB 10

BBB AAA 20

AAA CCC 40

DDD EEE 5

EEE DDD 70

FFF GGG 30

GGG HHH 20

HHH FFF 10
Sample Output 1:

2

AAA 3

GGG 3
Sample Input 2:

8 70

AAA BBB 10

BBB AAA 20

AAA CCC 40

DDD EEE 5

EEE DDD 70

FFF GGG 30

GGG HHH 20

HHH FFF 10
Sample Output 2:
0
题意：给定n条通话记录和时间，将每个人看成一个点，通话时长看作边，如果一张通话网中的人数大于2人并且通话总时长大于给定的k，则称这个网中的所有人是一个团伙Gang，其中通话时间最长的那个人称为这个团伙的头目head，让你求出团伙总数并按字母顺序打印出来头目及团伙内成员数。
思路：本题可以使用并查集或者DFS求解，但并查集比较复杂，对空间要求也很大，以下按照DFS方式求解。
1.由于输入的人名是字符串，定义convert函数，按顺序转换成数字。
2.按输入构造邻接矩阵G（初始化为0）表示每条边的通话时长，用数组w[]表示每个人的通话时长，使用DFS求出联通块数，并在DFS过程中求出该联通块内顶点总数，头目（权重最大的点），团伙总通话时长。最后根据题目要求筛选出符合要求的团伙存入map中，输出即可。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

#include<map>

using namespace std;

const int maxn=2010;

int idNum=0,n,k,GangNum=0;

bool vis[maxn]={false};

int G[maxn][maxn],w[maxn];

string IdToName[maxn];

map<string,int> NameToId;

int convert(string a){

	if(NameToId.find(a)!=NameToId.end()) return NameToId[a];

	else{

		NameToId[a]=idNum;

		IdToName[idNum]=a;

		return idNum++;

	}

}

void DFS(int u,int&head, int& num,int& totalw){

	totalw+=w[u];

	vis[u]=true;

	num++;

	if(w[u]>w[head])

		head=u;

	for(int v=0;v<maxn;v++){

		if(!vis[v]&&G[u][v]!=0){			

			DFS(v,head,num,totalw);

		}

	}

}

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++){

		string a,b;

		int weight;

		cin>>a>>b>>weight;

		int u=convert(a);

		int v=convert(b);

		G[u][v]+=weight;

		G[v][u]+=weight;

		w[u]+=weight;

		w[v]+=weight;

	}

	map<string,int> ans;

	for(int i=0;i<idNum;i++){

		int head=i,num=0,totalw=0;

		if(!vis[i]){

			DFS(i,head,num,totalw);

			if(num>2&&totalw/2>k){

				GangNum++;

				ans[IdToName[head]]=num;

			}

		}

	}

	printf("%d\n",GangNum);

	if(GangNum){

		for(auto it=ans.begin();it!=ans.end();it++){

			cout<<it->first<<" "<<it->second<<endl;

		}

	}

	return 0;

}
