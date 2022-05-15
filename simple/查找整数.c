/*本题要求从输入的N个整数中查找给定的X。如果找到，输出X的位置（从0开始数）；如果没有找到，输出“Not Found”。

输入格式：
输入在第一行中给出两个正整数N（≤20）和X，第二行给出N个整数。数字均不超过长整型，其间以空格分隔。

输出格式：
在一行中输出X的位置，或者“Not Found”。

输入样例1：
5 7
3 5 7 1 9
输出样例1：
2
输入样例2：
5 7
3 5 8 1 9
输出样例2：
Not Found
*/
#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int shuzu[a];
	int i;
	int jishu=0; 
	if(a<=20){
		for(i=0;i<a;i++){
			scanf("%d",&shuzu[i]);}
		int* shu=shuzu;
		for(i=-1;i<a;i++){
			shu+=1;
			if(*shu==b){
				printf("%d",i+2);
				jishu=1;
			}
		}
		if(jishu==0){
			printf("Not Found");	}
	}
	return 0;
}


/*标准答案*/
/*#include<stdio.h>
int main() {
	int n,x,i=0;
	int arr[20];
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int flag=0;
	for(i=0;i<n;i++){
		if(arr[i]==x){
			printf("%d",i);
			flag=1;
		}
	}
	if(flag==0){
		printf("Not Found");
	} 
	return 0;
}
*/
