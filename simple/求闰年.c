#include<stdio.h>
int main(){
	int a,b;
	scanf("%d",&a);
	if(a>2100||a<=2000){	
		printf("Invalid year!");
		goto err;
		}
	switch(a){
	case (2001):
		printf("None");
		break;
	case (2002):
		printf("None");
		break;
	case (2003):
		printf("None");
		break;
	default:
		if(a<=2100&&a>2003){		
			for(b=2003;b<=a;b++){
				if(b%4==0&&b%100!=0||b%400==0){
					printf("%d\n",b);
				}
			}
		}
		break;
	}
	err:
	return 0;
}
