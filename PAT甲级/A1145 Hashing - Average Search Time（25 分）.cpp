1145 Hashing - Average Search Time（25 分）
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table first. Then try to find another sequence of integer keys from the table and output the average search time (the number of comparisons made to find whether or not the key is in the table). The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive‎增量‎only) is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive numbers: MSize, N, and M, which are the user-defined table size, the number of input numbers, and the number of keys to be found, respectively. All the three numbers are no more than 10​4​​. Then N distinct positive integers are given in the next line, followed by M positive integer keys in the next line. All the numbers in a line are separated by a space and are no more than 10​5​​.
Output Specification:
For each test case, in case it is impossible to insert some number, print in a line X cannot be inserted. where X is the input number. Finally print in a line the average search time for all the M keys, accurate up to 1 decimal place.
Sample Input:

4 5 4

10 6 4 15 11

11 4 15 2
Sample Output:

15 cannot be inserted.

2.8
题意：给定一个Msize代表哈希表表长，再给出n个正整数让你构建一个哈希表（给定的Msize可能不是素数，若不是则需要找出大于Msize的最小素数作为哈希表长），使用除留余数法构造哈希表，平方探测法解决冲突（只往正的方向探测），若这n个数字中有数字X不能插入则输出：X cannot be inserted. 然后给m个待查数字，让你输出平均查找长度。
思路：首先判断给定的Msize是否为素数，若不是找到大于它的最小素数。在构造哈希表时，令int pos=(t+j*j)%Msize;其中t为待插数字，pos为位置，若经过Msize轮插入操作都未成功，则说明数字t无法插入，输出之。最后求平均查找长度时，令int pos=(t+j*j)%Msize;如果有ht[pos]==t||ht[pos]==0则说明找到该数字或者该数字不存在跳出循环，否则，经过Msize+1轮循环然后跳出。注意查询轮次 j=0直到j=Msize;共计Msize+1次说明未找到并返回。
参考代码：

#include<cstdio>

#include<cmath>

#include<vector>

using namespace std;

int Msize,n,m,t;

bool isPrime(int n){

	if(n<2) return false;

	int sqrtN=(int)sqrt(1.0*n);

	for(int i=2;i<=sqrtN;i++){

		if(n%i==0) 

			return false;

	}

	return true;

}

int main()

{

	scanf("%d%d%d",&Msize,&n,&m);

	while(!isPrime(Msize)) Msize++;

	vector<int> ht(Msize,0);

	for(int i=0;i<n;i++){

		scanf("%d",&t);

		bool flag=false;

		for(int j=0;j<Msize&&!flag;j++){

			int pos=(t+j*j)%Msize;

			if(ht[pos]==0){

				ht[pos]=t;

				flag=true;

			}

		}

		if(!flag) printf("%d cannot be inserted.\n",t);

	}

	int total=0;

	for(int i=0;i<m;i++){

		scanf("%d",&t);

		for(int j=0;j<=Msize;j++){

			total++;

			int pos=(t+j*j)%Msize;

			if(ht[pos]==t||ht[pos]==0){

				break;

			}

		}

	}

	printf("%.1f\n",(float)total/m);

	return 0;

}
