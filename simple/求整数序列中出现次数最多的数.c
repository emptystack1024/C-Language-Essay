/*求整数序列中出现次数最多的数*/
/*本题要求统计一个整型序列中出现次数最多的整数及其出现次数。

输入格式：
输入在一行中给出序列中整数个数N（0<N≤1000），以及N个整数。数字间以空格分隔。

输出格式：
在一行中输出出现次数最多的整数及其出现次数，数字间以空格分隔。题目保证这样的数字是唯一的。

输入样例：
10 3 2 -1 5 3 4 3 0 3 2
输出样例：
3 4*/
#include<stdio.h>

int main(){
	int geshu;
	scanf("%d",&geshu);
	
	int a[geshu],b[geshu];
	int i,ii;
	
	for(i=0;i<geshu;i++){
		b[i]=0;
	}
	
	int jiancha=0;
	int c;
	for(i=0;i<geshu;i++){
		jiancha=0;
		scanf("%d",&c);
		a[i]=c;
		for(ii=0;ii<geshu;ii++){
			if(a[ii]==c){
				b[ii]++;
				jiancha=1;
			}
		}
		if(jiancha=0){
			b[i]++;
		}
	}
	int* zuiduo=&b[0];
	int* zuidashu=&a[0];
	for(i=0;i<geshu;i++){
		if(b[i]>*zuiduo){
			zuiduo=&b[i];
			zuidashu=&a[i];
		}
	}
	printf("%d %d",*zuidashu,*zuiduo);
	
}


