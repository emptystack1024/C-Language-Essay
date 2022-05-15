/*
使用函数输出指定范围内的完数
本题要求实现一个计算整数因子和的简单函数，并利用其实现另一个函数，输
出两正整数m和n（0<m≤n≤10000）之间的所有完数。所谓完数就是该数恰好等
于除自身外的因子之和。例如：6=1+2+3，其中1、2、3为6的因子。

函数接口定义：
int factorsum( int number );
void PrintPN( int m, int n );
其中函数factorsum须返回int number的因子和；函数PrintPN要逐行输出给
定范围[m, n]内每个完数的因子累加形式的分解式，每个完数占一行，格式
为“完数 = 因子1 + 因子2 + ... + 因子k”，其中完数和因子均按递增顺序
给出。如果给定区间内没有完数，则输出一行“No perfect number”。

输入样例1：
6 30
输出样例1：
6 is a perfect number
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
输入样例2：
7 25
输出样例2：
No perfect number
*/
#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
    
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int factorsum( int number )
{
	int sum=0, i;
	
	if ( number==1 ) {
		return number;
	}
	
	for ( i=1; i<=number/2; i++ ) {
		if ( number%i==0 ) {
			sum += i;
		}
	}
	
	return sum;
}

void PrintPN( int m, int n )
{
	int i,j,count=0;
	for ( i=m; i<=n; i++ ) {
		if ( factorsum(i)==i ) {
			int ret=0; //用于判断输出是否结束（即左右式子是否已相等） 
			count=1;
			printf("%d = ", i);
			
			if ( i==1 ) {
				printf("%d", i);
			}
			
			for ( j=1; j<i; j++ ) {
				if( i%j==0 ) {
					printf("%d", j);
					ret += j;
					if ( ret!=i ) {
						printf(" + ");
					}
				}
			}
			printf("\n");
		}
	}
	if ( count==0 ) {
		printf("No perfect number");
	}
}
