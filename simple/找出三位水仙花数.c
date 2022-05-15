#include<stdio.h>
#include<math.h>
int main(){
	int M,N;
	scanf("%d %d",&M,&N);
	if(N>999){
		printf("Invalid Value.");
		goto jiewei;
		}		
	if(M<100&&N<=999){
		printf("Invalid Value.");
		goto jiewei;
		}
	if(M>N){
		printf("Invalid Value.");
		goto jiewei;
		}
	int i;
	int he,g,s,b;
	for(i=M;i<=N;i++){
		b=i/100;
		s=(i%100)/10;
		g=i%10;
		he=pow(b,3)+pow(g,3)+pow(s,3);
		if(he==i)
			printf("%d\n",i);
	}
	jiewei: 
	return 0;
	
}
