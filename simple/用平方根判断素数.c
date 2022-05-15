#include<stdio.h>
#include<math.h>
//用平方根判断素数 

int main(){
	
    int x;
	scanf("%d",&x);
    int ret=1;
    int i;
    if(x==1||(x%2==0&&x!=2)){
        ret=0;
        }
    for(i=3;i<sqrt(x);i+=2){
        if(x%i==0){
            ret=0;
            break;
        }
    }
	if(ret=0){
		printf("不是素数\n");
	}else{
		printf("是素数\n");
	}   
return ret;
}
