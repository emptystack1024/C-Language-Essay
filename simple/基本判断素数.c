#include<stdio.h>
//基本判断素数 
int main(){
	
    int x;
	scanf("%d",&x);
    int ret=1;
    int i;
    if(x==1){
            ret=0;
             }
    for(i=2;i<x;i++){
        if(x%i==0){
                   ret=0;
                   printf("不是素数");
                   break;
                  }else{
                  	printf("是素数");
				  }
                    }
    return ret;
}
