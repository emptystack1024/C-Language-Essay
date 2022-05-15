#include<stdio.h>
int main(){
	int c=0;
	int min;
	int d,i;

	scanf("%d",&c);

	int a[c];
	for(i=0;i<c;i++){
		scanf("%d",&d);
		a[i]=d;
	}
	min=a[0];
	for(i=1;i<c;i++){
		if(a[i]<min)
			min=a[i];
	} 
	printf("min = %d",min);
	return 0;
}
