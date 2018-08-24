To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.
Output Specification:
For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line There are N accounts and no account is modified where N is the total number of accounts. However, if N is one, you must print There is 1 account and no account is modified instead.
Sample Input 1:

3

Team000002 Rlsp0dfa

Team000003 perfectpwd

Team000001 R1spOdfa
Sample Output 1:

2

Team000002 RLsp%dfa

Team000001 R@spodfa
Sample Input 2:

1

team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:

2

team110 abcdefg222

team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified
题意：给定一组n个账号和密码，让你把密码中的 1 改成 @, 0 改成 %, l 改成 L,  O （大写字母）改成 o.并按照指定格式输出。
思路：注意题目要求按照读入顺序输出，所以不能使用map或者unordered_map存储数据，可以定义结构体存储。
参考代码：

#include<cstdio>

#include<string>

#include<iostream>

#include<vector>

using namespace std;

const int maxn=1010;

struct node{

	string name,password;

}t;

bool modify(string& s){

	bool flag=false;

	string a="10lO";

	for(int i=0;i<s.size();i++){

		if(a.find(s[i])!=-1) 

			flag=true;

		if(s[i]=='1') s[i]='@';

		if(s[i]=='0') s[i]='%';

		if(s[i]=='l') s[i]='L';

		if(s[i]=='O') s[i]='o';

	}

	return flag;

}

int main()

{

	int n,ModifyNum=0;

	cin>>n;

	vector<node> ans;

	for(int i=0;i<n;i++){

		cin>>t.name>>t.password;

		bool flag=modify(t.password);

		if(flag) {

			ModifyNum++;

			ans.push_back(t);

		}

	}

	if(n==1&&ModifyNum==0) 

		cout<<"There is 1 account and no account is modified\n";

	else if(ModifyNum==0)

		cout<<"There are "<<n<<" accounts and no account is modified\n";

	else{

		cout<<ModifyNum<<endl;

		for(int i=0;i<ans.size();i++){

			cout<<ans[i].name<<" "<<ans[i].password<<endl;

		}

	}

	return 0;

}
