#include<stdio.h>
//排除偶数判断素数 
int main(){
	
    int x;
	scanf("%d",&x);
    int ret=1;
    int i;
    if(x==1||(x%2==0&&x!=2))
        ret=0;
    for(i=3;i<x;i+=2){
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


