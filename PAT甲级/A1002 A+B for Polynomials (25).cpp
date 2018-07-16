This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
Output
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input

2 1 2.4 0 3.2

2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
题意：给定两个多项式，让你求和并输出结果。
思路：
1.使用两个double型数组分别存储这两个多项式，然后求和，输出。
2.注意如果系数为零则不予输出，但如果整个数组全为零，最终结果输出一个零。
参考代码：

#include<cstdio>

using namespace std;

int main() {

	int k,exp,cnt=0;;

	double coe,a[1010]={0},b[1010]={0};

	for(int l=0;l<2;++l){

		scanf("%d",&k);

		for(int i=0;i<k;++i){

			scanf("%d %lf",&exp,&coe);

			if(l==0) a[exp]=coe;

			else b[exp]=coe;

		}

	}

	for(int i=0;i<1001;++i)

	{

		a[i]+=b[i];

		if(a[i]!=0.0)

			cnt++;

	}

	if(!cnt){

		printf("0\n");

	}else{

		printf("%d",cnt);

		for(int i=1000;i>=0;--i){

			if(a[i]==0) continue;

			printf(" %d %.1f",i,a[i]);

		}

	}

	return 0;

}
