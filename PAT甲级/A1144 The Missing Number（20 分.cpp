1144 The Missing Number（20 分）
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10​5​​). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.
Output Specification:
Print in a line the smallest positive integer that is missing from the input list.
Sample Input:

10

5 -25 9 6 1 3 4 2 5 17
Sample Output:
7
题意：给定一串int型数字，让你找出没在这串数字中出现的最小正整数。
思路：由于数据在int范围内，所以不能直接开hash数组标记存在，定义一个全局序号k（初始=1），然后使用set容器存储数据，由于set可以自动排序和去重，因此把所有正整数存进去后，然后从第一个数字开始读取set中的数字，若 发现当前set中数字和序号k不同则说明k是第一个没有在set中出现的正整数，输出即可，如果整个set全部有序，注意最后特判输出k。
参考代码：

#include<cstdio>

#include<set>

using namespace std;

set<int> st;

int main()

{

	int n,t,k=1;

	scanf("%d",&n);

	for(int i=0;i<n;i++){

		scanf("%d",&t);

		if(t>0)

			st.insert(t);

	}

	bool flag=false;

	for(auto it=st.begin();it!=st.end()&&!flag;it++){

		if(*it!=k) {

			printf("%d\n",k);

			flag=true;

		}

		k++;

	}

	if(!flag) printf("%d\n",k);

	return 0;

}
