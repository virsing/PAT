Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.
Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
Input Specification:
Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
Output Specification:
For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
题意：给定一个用科学记数法表示的数，让你用普通格式输出。
 
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
