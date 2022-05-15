#include<stdio.h>
int cha(int x);
int main(){
	int m;
	scanf("%d",&m);
	int s=0;
	int i;
	if(m>20000||m<50){
		printf("error");
		goto jiewei;
	}
	for(i=m-1;i>=1;i--){	
		if(cha(i)==1){
			printf("%6d",i);
			s++;
		}
		if(s==10){
			goto jiewei;
		}
	}
	jiewei:
		return 0;
}

int cha(int x){
    int ret=1;
    int i;
    if(x==1){
            ret=0;
             }
    for(i=2;i<x;i++){
        if(x%i==0){
                   ret=0;
                   
                   break;
                  }else{
                  	
				  }
                    }
    return ret;
}


