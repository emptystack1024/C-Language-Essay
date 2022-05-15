int narcissistic( int number );
void PrintN( int m, int n );
#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic( int number ){
	int a,b,c,d,e;
	a=number/10000;
	b=(number/1000)%10;
	c=(number/100)%10;
	d=(number%100)/10;
	e=number%10;
	if(number<1000){
	
		if(number==a*a*a+b*b*b+c*c*c+d*d*d+e*e*e){
			return 1;
		}else{
			return 0;
		}
	}
	else{
		if(number==a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d+e*e*e*e){
			return 1;
		}else{
			return 0;
		}
	}
}
void PrintN( int m, int n ){
	int i;
	i=m+1;
	for(i;i<n;i++){
		if(narcissistic(i)==1){
			printf("%d\n",i);
		} 
	}
}
/*水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例如：153=1 
3
 +5 
3
 +3 
3
 。 本题要求编写两个函数，一个判断给定整数是否水仙花数，另一个按从小到大的顺序打印出给定区间(m,n)内所有的水仙花数。

函数接口定义：
int narcissistic( int number );
void PrintN( int m, int n );
函数narcissistic判断number是否为水仙花数，是则返回1，否则返回0。

函数PrintN则打印开区间(m, n)内所有的水仙花数，每个数字占一行。题目保证100≤m≤n≤10000。*/
