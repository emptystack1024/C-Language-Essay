/*7-7 输出数组元素 (15分)
本题要求编写程序，对顺序读入的n个整数，顺次计算后项减前项之差，并按每行三个元素的格式输出结果。
输入格式：
输入的第一行给出正整数n（1<n≤10）。随后一行给出n个整数，其间以空格分隔。

输出格式：
顺次计算后项减前项之差，并按每行三个元素的格式输出结果。数字间空一格，行末不得有多余空格。

输入样例：
10
5 1 7 14 6 36 4 28 50 100
输出样例：
-4 6 7
-8 30 -32
24 22 50
*/
#include<stdio.h> 
int main(){
	int num,i;
	scanf("%d",&num);
	int b[num];
	if(num>1&&num<=10){
		for(i=0;i<num;i++){
			scanf("%d",&b[i]);
		}
	}
	int c[num];
	for(i=0;i<num;i++){
		c[i]=b[i];
	}
	for(i=0;i<num;i++){
		b[i]=c[i+1]-b[i];
	}
	int geshu=0;
	for(i=0;i<num-1;i++){
		if(geshu==3){
			geshu=0;
			printf("\n");
		}else if(i!=0){
			printf(" ");
		}
		printf("%d",b[i]);
		geshu++;
	}
	return 0;
}

/*标准答案*/
/*
#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);//读入
        if(i>0) a[i-1]=a[i]-a[i-1];//作差
    }
    for(i=0;i<n-1;i++){    //注意最后一个不要输出，因为作差后只有n-1项是有效的
        printf("%d",a[i]);
        if((i+1)%3==0) printf("\n"); //到3换行
        else if(i<n-2) printf(" ");  //未到最后一行以及最后一个数字空格
    }
    return 0;
}
*/


/*不用数组*/
/*
#include<stdio.h>
int main(){
    int n,i,temp,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        b=temp;
        if(i>0) a=b-a;
        else a=b;
        if(i>0) printf("%d",a);
        if(i>0&&i%3==0) printf("\n");
        else if(i>0&&i<n-1) printf(" ");
        a=b;
    }
    return 0;
} 
*/
