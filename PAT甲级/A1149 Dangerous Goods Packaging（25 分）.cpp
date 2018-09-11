1149 Dangerous Goods Packaging（25 分）
When shipping goods with containers, we have to be careful not to pack some incompatible goods into the same container, or we might get ourselves in serious trouble. For example, oxidizing agent （氧化剂） must not be packed with flammable liquid （易燃液体）, or it can cause explosion.
Now you are given a long list of incompatible goods, and several lists of goods to be shipped. You are supposed to tell if all the goods in a list can be packed into the same container.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: N (≤10​4​​), the number of pairs of incompatible goods, and M (≤100), the number of lists of goods to be shipped.
Then two blocks follow. The first block contains N pairs of incompatible goods, each pair occupies a line; and the second one contains M lists of goods to be shipped, each list occupies a line in the following format:
K G[1] G[2] ... G[K]
where K (≤1,000) is the number of goods and G[i]'s are the IDs of the goods. To make it simple, each good is represented by a 5-digit ID number. All the numbers in a line are separated by spaces.
Output Specification:
For each shipping list, print in a line Yes if there are no incompatible goods in the list, or No if not.
Sample Input:

6 3

20001 20002

20003 20004

20005 20006

20003 20001

20005 20004

20004 20006

4 00001 20004 00002 20003

5 98823 20002 20003 20006 10010

3 12345 67890 23333
Sample Output:

No

Yes

Yes
题意：码头上在进行集装箱装运时，有些物品时不能放在一起运输的，例如氧化剂和易燃液体不能放在一起运输。现给定n对相斥的物品，然后给你m张运输清单，问题这m张清单能否进行运输，可以的话输出Yes，否则输出No。
思路：使用unordered_map<int,vector<int>>把所有相斥的物品放在一个对应的vector里，然后对每张运输清单逐一扫描， 若当前物品的相斥物品存在输出No，否则输出Yes。
参考代码：

#include<cstdio>

#include<vector>

#include<cstring>

#include<unordered_map>

using namespace std;

const int maxn=100000;

bool flag[maxn];

unordered_map<int,vector<int>> mp;

int n,m,u,v,t,k;

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){

        scanf("%d%d",&u,&v);

        mp[u].push_back(v);

        mp[v].push_back(u);

    }

    for(int i=0;i<m;i++){

        scanf("%d",&k);

        bool tag=true;

        memset(flag,false,sizeof(flag));

		vector<int> v(k);

        for(int j=0;j<k&&tag;j++){

            scanf("%d",&v[j]);

			flag[v[j]]=true;

		}

		for(int j=0;j<k&tag;j++){

            for(int l=0;l<mp[v[j]].size()&&tag;l++){

                u=mp[v[j]][l];

                if(flag[u]) tag=false;

            }

		}

        printf("%s\n",tag?"Yes":"No");

    }

    return 0;

}
