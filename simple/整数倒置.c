#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x);
	
	int digit;
	int ret=0;
	while(x>0){
		digit=x%10;
		printf("%d\n",digit);
		ret=ret*10+digit;
		printf("ret=%d\n",ret);
		x/=10;
	}
	
	return 0;
	
}

/*逆序输出再逆序输出*/
/*#include<stdio.h>

int main( ){
	int x;
	scanf("%d",&x);
	
    int t=0;
	do{
		int d=x%10;
		t=t*10+d;
		x/=10;
    }while(x>0);
    printf("x=%d\n,t=%d\n",x,t);
    
    x=t;
    
	do{
		int d=x%10;
		printf("%d",d);
		if(x>9){
		         printf(" ");
		}
		x/=10;
		
	}while (x>0);
    printf("\n");
	
return 0;

}
*/

/*逆序输出*/
/*
#include<stdio.h>

int main( ){
	int x;
	scanf("%d",&x);
	
    int t=0;

	do{
		int d=x%10;
		printf("%d",d);
		if(x>9){
		         printf(" ");
		}
		x/=10;
		
	}while (x>0);
    printf("\n");
	
return 0;

}
*/
