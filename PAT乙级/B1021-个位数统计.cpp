#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string s;
	cin>>s;
	map<int,int> mp;
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]-'0']++;
	}
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		printf("%d:%d\n",it->first,it->second);
	}
	return 0;
}
