#include<stdio.h>
int main(){
	int d;
	int b,c=0;
	double he;

	int i;
	double e=0;
	int f=0;
	scanf("%d",&c);
	if(c==0){
		e=0;
		f=0;
	}
	int a[c];
	for(i=0;i<c;i++){
		scanf("%d",&d);
		a[i]=d;
		he+=d;
	}
	for(i=0;i<c;i++){
		e=(1.0*he)/c;
		if(a[i]>=60){
			f++;
		}
	}
	printf("average = %.1f\n",e);
	printf("count = %d",f);
	
	return 0;
	
} 
