1148 Werewolf - Simple Version（20 分）
Werewolf（狼人杀） is a game in which the players are partitioned into two parties: the werewolves and the human beings. Suppose that in a game,
player #1 said: "Player #2 is a werewolf.";
player #2 said: "Player #3 is a human.";
player #3 said: "Player #4 is a werewolf.";
player #4 said: "Player #5 is a human."; and
player #5 said: "Player #4 is a human.".
Given that there were 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. Can you point out the werewolves?
Now you are asked to solve a harder version of this problem: given that there were NNN players, with 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. You are supposed to point out the werewolves.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer NNN (5≤N≤1005 \le N \le 1005≤N≤100). Then NNN lines follow and the iii-th line gives the statement of the iii-th player (1≤i≤N1 \le i \le N1≤i≤N), which is represented by the index of the player with a positive sign for a human and a negative sign for a werewolf.
Output Specification:
If a solution exists, print in a line in ascending order the indices of the two werewolves. The numbers must be separated by exactly one space with no extra spaces at the beginning or the end of the line. If there are more than one solution, you must output the smallest solution sequence -- that is, for two sequences A=a[1],...,a[M]A = { a[1], ..., a[M] }A=a[1],...,a[M] and B=b[1],...,b[M]B = { b[1], ..., b[M] }B=b[1],...,b[M], if there exists 0≤k<M0 \le k < M0≤k<M such that a[i]=b[i]a[i]=b[i]a[i]=b[i] (i≤ki \le ki≤k) and a[k+1]<b[k+1]a[k+1]<b[k+1]a[k+1]<b[k+1], then AAA is said to be smaller than BBB. In case there is no solution, simply print No Solution.
Sample Input 1:

5

-2

+3

-4

+5

+4
Sample Output 1:
1 4
Sample Input 2:

6

+6

+3

+1

-5

-2

+4
Sample Output 2 (the solution is not unique):
1 5
Sample Input 3:

5

-2

-3

-4

-5

-1
Sample Output 3:
No Solution
题意：在简化版狼人杀游戏中，给定n名玩家，其中有两个狼人，其余为人类，所有玩家中恰有两人说谎，且说谎的人中一个是狼人一个是人类，现给出n个玩家的说法，编号从1到n，正数表示所指定的玩家为人类，负数表示所制定的玩家是狼人 。让你找出这两个狼人并按id从小到大输出编号，如果狼人标号不唯一，则输出编号较小的那一组狼人，如果无解输出No Solution。
思路：刚开始枚举每一对玩家代表说谎的玩家发现非常复杂且难以实现，后来改为枚举每一对玩家表示狼人，i从1到n，j从i+1到n，用数组a[]储存每个玩家的真实身份，a[k]=-1 表示k为狼人，a[k]=1表示k是人类，数组d[]存储每个玩家所说的身份，然后k从1到n枚举每一名玩家所说的话，看其是否说谎，如果说谎则有a[abs(d[k])]*d[k]<0，最后如果说谎的总人数为2且一名为人类一名为狼人则为正确答案，此时有a[lie[0]]+a[lie[1]]==0。由于假设狼人是从1到n枚举的，该答案即为最小编号。注意：每次枚举，数组a[]和谎言数组lie都必须初始化！因此需要在二轮循环内定义或初始化！（该思路参考了柳婼大佬的博客）
参考代码：

#include<cstdio>

#include<vector>

#include<cmath>

using namespace std;

const int maxn=105;

int n,d[maxn];

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&d[i]);

	}

	for(int i=1;i<=n;i++){

		for(int j=i+1;j<=n;j++){

			vector<int> lie,a(n+1,1);

			a[i]=a[j]=-1;

			for(int k=1;k<=n;k++)

				if(a[abs(d[k])]*d[k]<0) lie.push_back(k);

			if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0){

				printf("%d %d\n",i,j);

				return 0;

			}

		}

	}

	printf("No Solution\n");

	return 0;

}
