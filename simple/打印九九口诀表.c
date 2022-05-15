#include<stdio.h>
int main(){
	int N;
	int a;
	int i;//ÐÐÊý 
	scanf("%d",&N);
	if(N==1){
		printf("1*1=1   ");
		goto jiewei;
	}
	if(N>9){
		printf("error");
	}
	for(i=1;i<=N;i++){
		for(a=1;a<=i;a++){
			printf("%d*%d=%-4d",a,i,a*i);
			if(i==a){
				printf("\n");
			}
		}
		
	}
	jiewei:
	return 0;
}
