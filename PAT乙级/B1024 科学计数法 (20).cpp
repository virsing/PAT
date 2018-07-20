科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
输入格式：
每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
输出格式：
对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
 思路：
1.首先标记出小数点位置，指数E的位置，然后根据指数的正负分两种情况讨论是末位加零还是前面补零。
参考代码：

#include<string>

#include<iostream>

using namespace std;

int main()

{

	string s;

	cin>>s;

	if(s[0]=='-') cout<<s[0];

	int idxp=2,idxe=0,cnt=0,exp=0;

	while(idxe<s.size()&&s[idxe]!='E') idxe++;  //标记E的位置

	cnt=idxe-idxp-1;    //cnt标记小数点后面的位数

	exp=stoi(s.substr(idxe+1));

	if(exp>=0){

		cout<<s[1]; 	//首先输出整数部分

		if(exp>=cnt){

			exp-=cnt;	  //用exp表示数字末尾还需要补零的个数

			for(int i=3;i<idxe;i++)

			{

					cout<<s[i];

			}

			while(exp--) cout<<'0';

		}else{

			for(int i=3;i<idxe;i++)

			{

				if(i==exp+3)

					cout<<'.';

				cout<<s[i];

			}

		}

	}else{

		cout<<"0.";

		exp=-exp-1; //转成整数表示数字前面补零的个数

		while(exp--) cout<<'0';

		for(int i=1;i<idxe;i++)

		{

			if(s[i]!='.')

				cout<<s[i];

		}

	}

	cout<<endl;

	return 0;

}
