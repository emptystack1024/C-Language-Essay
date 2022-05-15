#include<stdio.h>

int main( ){
	int a,b;
	int min;
	
	scanf("%d %d",&a,&b);
	if(a<b){
		min=a;
	}else{
		min=b;
	}
	int ret=0;
	int i;
	for(i=1;i<min;i++){
		if(b%i==0){
			ret=i;
		}
	}

printf("%d和%d的最大公约数是%d\n",a,b,ret);

return 0;
}


/*最大公约数（辗转相除法）*/
/*
#include<stdio.h>

int main( ){
	int a,b;
	int t;
	int c,d;
	
	printf("请输入要求最大公约数的数是：\n");
	scanf("%d %d",&a,&b);
	
	c=a;
	d=b;
	
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}

printf("%d和%d的最大公约数是%d\n",c,d,a);

return 0;
}
*/
