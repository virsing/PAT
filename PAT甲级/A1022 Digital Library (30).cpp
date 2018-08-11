A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
Sample Input:

3

1111111

The Testing Book

Yue Chen

test code debug sort keywords

ZUCS Print

2011

3333333

Another Testing Book

Yue Chen

test code sort keywords

ZUCS Print2

2012

2222222

The Testing Book

CYLL

keywords debug book

ZUCS Print2

2011

6

1: The Testing Book

2: Yue Chen

3: keywords

4: ZUCS Print

5: 2011

3: blablabla
Sample Output:

1: The Testing Book

1111111

2222222

2: Yue Chen

1111111

3333333

3: keywords

1111111

2222222

3333333

4: ZUCS Print

1111111

5: 2011

1111111

2222222

3: blablabla

Not Found
题意：给定n本书，每本书按以下格式输入，书籍编号，书名，作者，关键词，出版社，出版年份。然后给出m个问题，每个问题对应的数字是待查询的类别，让你把对应的书籍编号输出来，如果没有输出：Not Found。
思路：
1.使用map<string,set<int>>，建立对应类别与书籍id的映射，来完成O（1）时间内查询书籍编号并开始输出。
 2.在关键字的输入上，使用while（cin>>Kw)逐个输入，并插入关键字对应map中，每输完一个关键词，使用getchar吸收后面的字符，如果是换行符'\n'，说明关键字输入完毕，跳出循环。
3.建立统一的输出函数，根据问题编号对应传参数到输出函数中，注意map一定要使用引用，否则会有一组数据超时。
参考代码：

#include<cstdio>

#include<map>

#include<set>

#include<string>

#include<iostream>

using namespace std;

const int maxn=10010;

map<string,set<int>> title,author,kword,publisher,year;

void output(map<string,set<int>>& mp,string q){

	if(mp.find(q)==mp.end()) printf("Not Found\n");

	for(auto it=mp[q].begin();it!=mp[q].end();it++)

			printf("%07d\n",*it);

}

int main(){

	int n,m;

	string inquery;

	cin>>n;

	for(int i=0;i<n;i++){

		int id;

		string Au,Ti,Kw,Pu,Ye;

		scanf("%d\n",&id);	//这里从cin转成getline需要吸收换行符

		getline(cin,Ti);

		title[Ti].insert(id);

		getline(cin,Au);

		author[Au].insert(id);

		while(cin>>Kw){

			kword[Kw].insert(id);

			char t;

			t=getchar();

			if(t=='\n') break;

		}

		getline(cin,Pu);

		publisher[Pu].insert(id);

		cin>>Ye;

		year[Ye].insert(id);

	}

	cin>>m;

	getchar();

	for(int i=0;i<m;i++){

		int tag;

		scanf("%d: ",&tag);

		getline(cin,inquery);

		cout<<tag<<": "<<inquery<<endl;

		if(tag==1) output(title,inquery);

		else if(tag==2)output(author,inquery);

		else if(tag==3)output(kword,inquery);

		else if(tag==4)output(publisher,inquery);

		else if(tag==5) output(year,inquery);

	}

	return 0;

}
 
